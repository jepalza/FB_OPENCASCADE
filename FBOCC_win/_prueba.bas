' Joseba Epalza <jepalza> gmail punto com , enero 2026
' C-WRAPPER para OpenCascade < https://dev.opencascade.org/ > version 7.7 x32 (noviembre 2022)
' empleando las rutinas de < https://github.com/marcuswu/occwrapper > con ligeras modificaciones
' aun esta poco avanzado, solo comprobados tres tipos de entidades y dos formas de salida de ficheros



#include "windows.bi"
#include "fbgfx.bi"

#include "FBOCCWrapper.bi"
#Inclib "FBOCCWrapper"

' objetos globales para multitarea
dim shared as TopoDSShape bolaShape,cuboShape,cajaShape,resultadoBOOLEAN
Dim shared As long arg0,arg1 ' valores devueltos por OCC de sus manejadores de ventanas

Dim As Any Ptr pThread	
sub OCC_Thread(ByVal p As Any Ptr)
	dim as long obj=0'=Cast(long, p)
	while 1 ' bucle infinito
		if arg0<>0 and obj=0 then ' no entra hasta que el visualizador se ha inicializado (arg0<>0)
			OCCViewer_Add(cast(long ptr,bolaShape),0)
			OCCViewer_Add(cast(long ptr,cuboShape),0)
			OCCViewer_Add(cast(long ptr,cajaShape),0)
			OCCViewer_Add(cast(long ptr,resultadoBOOLEAN),0)
			obj=1 ' solo una vez
		end if
	wend
end sub

	
' ESFERA
dim as BRepPrimAPIMakeSphere bola
dim as gpAx2 bolaAX2=gpAx2_Init( gpPnt_Init(125,0,75) , gpPnt_Init(0,0,1) , gpPnt_Init(1,0,0) )  ' sin giros, direccion X
bola=BRepPrimAPIMakeSphere_Init(bolaAX2,75)
bolaShape=BRepPrimAPIMakeSphere_Shape(bola)


' CUBO
dim as BRepPrimAPIMakeBox cubo
dim as gpAx2 cuboAX2=gpAx2_Init( gpPnt_Init(0,0,0) , gpPnt_Init(0,0,1) , gpPnt_Init(1,0,0) ) ' sin giros, direccion X
cubo=BRepPrimAPIMakeBox_Init(cuboAX2,100,100,100)
cuboShape=BRepPrimAPIMakeBox_Shape(cubo)


' CAJA (cubo rectangular) girado X45º
dim as BRepPrimAPIMakeBox caja
dim as gpAx2  cajaAX2=gpAx2_Init( gpPnt_Init(-10,-10,-10) , gpPnt_Init(0,1,0) , gpPnt_Init(0,0,1) ) ' sin giros, direccion Z
caja=BRepPrimAPIMakeBox_Init(cajaAX2,50,200,50) ' creo un cuerpo alargado en la pos. -10,-10,-10 SIN giros, solo horizontal
dim as gpAx1  giroAX1=gpAx1_Init( gpPnt_Init(-10,-10,-10) , gpPnt_Init(1,0,0)) ' creo un punto de giro -10,-10,-10 en X
dim as gpTrsf gpTrsf0=gpTrsf_Init()
gpTrsf_SetRotation(gpTrsf0 ,giroAX1,0.707) ' creo una matriz de giro en X45º
cajaShape=BRepPrimAPIMakeBox_Shape(caja)
dim as BRepBuilderAPITransform transformacion=BRepBuilderAPITransform_InitWithShapeTrsf(cajaShape,gpTrsf0)
cajaShape=BRepBuilderAPITransform_Shape(transformacion)


' se crean listas de objetos con los que trabajar
dim as TopToolsListOfShape booleanargs=TopToolsListOfShape_Init() ' elemento sobre el que vamos a cortar
dim as TopToolsListOfShape booleantool=TopToolsListOfShape_Init() ' elementos que cortaran al anterior
dim as TopToolsListOfShape cuboList=TopToolsListOfShape_Append(booleanargs,cuboShape) ' la variable no se emplea
dim as TopToolsListOfShape bolaList=TopToolsListOfShape_Append(booleantool,bolaShape) ' la variable no se emplea 
dim as TopToolsListOfShape cajaList=TopToolsListOfShape_Append(booleantool,cajaShape) ' la variable no se emplea
	
	
' cortar CUBO con ESFERA
dim as BRepAlgoAPICut booleancut=BRepAlgoAPICut_Init()
dim as BRepAlgoAPIBooleanOperation cortar=BRepAlgoAPICut_ToBooleanOperation(booleancut) ' operacion CORTAR (CUTTING)
BRepAlgoAPIBooleanOperation_SetArguments(cortar,booleanargs) ' elemento sobre el que cortar		
BRepAlgoAPIBooleanOperation_SetTools(cortar,booleantool) ' elementos de corte (en este ejemplo son dos: caja y esfera)
BRepAlgoAPIBooleanOperation_Build(cortar) ' realiza la operacion
resultadoBOOLEAN=BRepAlgoAPIBooleanOperation_Shape(cortar) ' recupero el resultado
BRepAlgoAPICut_Free(booleancut) ' liberar operacion de corte, ya no es necesaria


' operaciones opcionales solo para visualizar los objetos usados
' desplazo los objetos empleados en la operacion de corte Booleana, para exportar y verlos con claridad
dim as gpAx3 origen,destino
origen =gpAx3_Init(gpPnt_Init(0,0,0) , gpPnt_Init(0,0,1) , gpPnt_Init(1,0,0) ) ' punto de origen
destino=gpAx3_Init(gpPnt_Init(0,-200,0) , gpPnt_Init(0,0,1) , gpPnt_Init(1,0,0) ) ' punto de destino
gpTrsf_SetTransformation(gpTrsf0,origen,destino) ' translacion de origen a destino
transformacion=BRepBuilderAPITransform_InitWithShapeTrsf(cuboShape,gpTrsf0)
cuboShape=BRepBuilderAPITransform_Shape(transformacion)
'
origen =gpAx3_Init(gpPnt_Init(0,0,0) , gpPnt_Init(0,0,1) , gpPnt_Init(1,0,0) ) ' punto de origen
destino=gpAx3_Init(gpPnt_Init(300,-200,0) , gpPnt_Init(0,0,1) , gpPnt_Init(1,0,0) ) ' punto de destino
gpTrsf_SetTransformation(gpTrsf0,origen,destino) ' translacion de origen a destino
transformacion=BRepBuilderAPITransform_InitWithShapeTrsf(bolaShape,gpTrsf0)
bolaShape=BRepBuilderAPITransform_Shape(transformacion)
'
origen =gpAx3_Init(gpPnt_Init(0,0,0) , gpPnt_Init(0,0,1) , gpPnt_Init(1,0,0) ) ' punto de origen
destino=gpAx3_Init(gpPnt_Init(-200,-200,0) , gpPnt_Init(0,0,1) , gpPnt_Init(1,0,0) ) ' punto de destino
gpTrsf_SetTransformation(gpTrsf0,origen,destino) ' translacion de origen a destino
transformacion=BRepBuilderAPITransform_InitWithShapeTrsf(cajaShape,gpTrsf0)
cajaShape=BRepBuilderAPITransform_Shape(transformacion)



' exportar IGES
dim as IGESControlWriter FileIGES=IGESControlWriter_Init()
IGESControlWriter_Add(FileIGES,resultadoBOOLEAN,0)
IGESControlWriter_Add(FileIGES,bolaShape,0)
IGESControlWriter_Add(FileIGES,cuboShape,0)
IGESControlWriter_Add(FileIGES,cajaShape,0)
IGESControlWriter_Write(FileIGES,strptr("_prueba.igs"))                                                                                                                   
IGESControlWriter_Free(FileIGES)	


' exportar STEP
dim as STEPControlWriter FileSTEP=STEPControlWriter_Init()
STEPControlWriter_Add(FileSTEP,resultadoBOOLEAN,0)
STEPControlWriter_Add(FileSTEP,bolaShape,0)
STEPControlWriter_Add(FileSTEP,cuboShape,0)
STEPControlWriter_Add(FileSTEP,cajaShape,0)
STEPControlWriter_Write(FileSTEP,strptr("_prueba.step"))
STEPControlWriter_Free(FileSTEP)	

	
' **************************************	
	' inicio la multitarea que permite el control de elementos dentro de OCC

	pThread = ThreadCreate(@OCC_Thread)
	
		' inicio OCC (NOTA: las variables arg0 y arg1 no son de utilidad aun)
		OCCViewer_Init(@arg0,@arg1)

	' cierro OCC (NOTA: por ahora no vuelve desde 'OCC_Thread', queda pendiente de revisar
	ThreadWait(pThread)
' **************************************
