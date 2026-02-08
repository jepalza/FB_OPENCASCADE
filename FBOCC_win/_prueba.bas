' Joseba Epalza <jepalza> gmail punto com , enero 2026
' C-WRAPPER de las librerias OpenCascade < https://dev.opencascade.org/ > version 7.6
' empleando las rutinas de < https://github.com/marcuswu/occwrapper > con ligeras modificaciones
' aun esta poco avanzado, solo comprobados tres tipos de entidades y dos formas de salida de ficheros



#include "windows.bi"
#include "fbgfx.bi"

#include "FBOCCWrapper.bi"
#Inclib "FBOCCWrapper"


Dim shared As long  pia,pib ' valores devueltos por OCC de sus manejadores de ventanas

dim shared as TopoDSShape shap0,shap1,shap2,shap3
dim shared as TopToolsListOfShape shap00,shap11,shap22,shap33
'dim shared as ShapeIterator iter
	
Dim As Any Ptr pThread	
sub OCC_Thread(ByVal p As Any Ptr)
	dim as long pp1=0'=Cast(long, p)
	dim as long pp2=0'=Cast(long, p)
	dim as long pp3=0'=Cast(long, p)
	while 1
		if pp1=1 then
			print OCCViewer_Add(cast(long ptr,shap0),0)
			print OCCViewer_Add(cast(long ptr,shap1),0)
			pp1=2
		end if
		if pp2=1 then
			print OCCViewer_Add(cast(long ptr,shap2),0)
			pp2=2
		end if
		if pp3=1 then
			print OCCViewer_Add(cast(long ptr,shap33),0)
			pp3=2
		end if
		if multikey(FB.SC_1) andalso pp1=0 then pp1=1:pp2=1
		if multikey(FB.SC_2) andalso pp2=0 then pp2=1
		if multikey(FB.SC_3) andalso pp3=0 then pp3=1
	wend
end sub


' diferentes inicializadores, sin probar...
'  pa=BRepBuilder_Init()
'  xx=BRepBuilderAPIMakeWire_Init()
'  pb=BRepAlgoAPIFuse_Init()
'  pd=GPropGProps_Init()
'  pe=gpPln_Init()
'  pf=gpTrsf_Init()
'  pg=StlAPIWriter_Init()
'  pi=TopoDSCompound_Init()
	

	
	
' el circulo no me sirve para visualizar aun
'	dim as gcTrimmedCurve cir
'	ll=gpPnt_Init(11.1,22.2,33.3)
'	cir=gcMakeCircle(ll,14)
'	print "circulo:";cir
'  shap1=BRepBuilderAPIMakeShape_Shape(cir)


	
	

	' booleanas CUT
   dim as BRepAlgoAPICut booleancut=BRepAlgoAPICut_Init()

   dim as TopToolsListOfShape booleanargs=TopToolsListOfShape_Init() ' elemento sobre el que vamos a cortar
   dim as TopToolsListOfShape booleantool=TopToolsListOfShape_Init() ' elemento que cortara al anterior

	' ESFERA
	dim as BRepPrimAPIMakeSphere Sphere
	'                gpAx2_Init -> origen,                 giro,               direccion
	dim as gpAx2 ax0=gpAx2_Init( gpPnt_Init(-25,25,25) , gpPnt_Init(0,1,0) , gpPnt_Init(0,0,1) )
	Sphere=BRepPrimAPIMakeSphere_Init(ax0,50)
	shap0=BRepPrimAPIMakeSphere_Shape(Sphere)
	shap00=TopToolsListOfShape_Append(booleantool,shap0)
		
	' CUBO
	dim as BRepPrimAPIMakeBox cube
	'                gpAx2_Init -> origen,           giro,               direccion
	dim as gpAx2 ax1=gpAx2_Init( gpPnt_Init(0,0,0) , gpPnt_Init(0,1,0) , gpPnt_Init(0,0,1) )
	cube=BRepPrimAPIMakeBox_Init(ax1,100,100,100)
	shap1=BRepPrimAPIMakeBox_Shape(cube)
	shap11=TopToolsListOfShape_Append(booleanargs,shap1)
	
	' CUBOIDE
	dim as BRepPrimAPIMakeBox box
	'                gpAx2_Init -> origen,                    giro,               direccion
	dim as gpAx2  ax2=gpAx2_Init( gpPnt_Init(-10,-10,-10) , gpPnt_Init(0,0.5,0.5) , gpPnt_Init(0,0,1) )
'	dim as gpTrsf gpTrsf2=gpTrsf_Init()
'	dim as gpVec  gpVec2 =gpPnt_Init(10,10,10)
'	gpTrsf_SetTranslation(gpTrsf2 ,gpVec2)
	box=BRepPrimAPIMakeBox_Init(ax2,50,200,50)
	shap2=BRepPrimAPIMakeBox_Shape(box)
	'shap22=TopToolsListOfShape_Append(booleantool,shap2)
	
' prueba de chaflanes, sin exito	
'	dim as BRepFilletAPIMakeChamfer chamf=BRepFilletAPIMakeChamfer_Init(shap22)
'	BRepFilletAPIMakeChamfer_Add(shap22,shap2,10)
'	shap22=BRepFilletAPIMakeFillet_Shape(shap22)
	
	' cortar CUBO con CUBOIDE
	dim as BRepAlgoAPIBooleanOperation cut
	cut=BRepAlgoAPICut_ToBooleanOperation(booleancut)

	BRepAlgoAPIBooleanOperation_SetArguments(cut,booleanargs)		
	BRepAlgoAPIBooleanOperation_SetTools(cut,booleantool)
	BRepAlgoAPIBooleanOperation_Build(cut)

	' recupero el resultado
   shap33=BRepAlgoAPIBooleanOperation_Shape(cut)

	BRepAlgoAPICut_Free(booleancut)	
   ' BRepAlgoAPIBooleanOperation_Free(cut)
	
	dim as IGESControlWriter FileIGES=IGESControlWriter_Init()
	IGESControlWriter_Add(FileIGES,shap33,0)
	IGESControlWriter_Add(FileIGES,shap0,0)
	IGESControlWriter_Add(FileIGES,shap1,0)
	IGESControlWriter_Add(FileIGES,shap2,0)
	IGESControlWriter_Write(FileIGES,strptr("_prueba.igs"))
	IGESControlWriter_Free(FileIGES)	

	dim as STEPControlWriter FileSTEP=STEPControlWriter_Init()
	STEPControlWriter_Add(FileSTEP,shap33,0)
	STEPControlWriter_Add(FileSTEP,shap0,0)
	STEPControlWriter_Add(FileSTEP,shap1,0)
	STEPControlWriter_Add(FileSTEP,shap2,0)
	STEPControlWriter_Write(FileSTEP,strptr("_prueba.step"))
	STEPControlWriter_Free(FileSTEP)	
	
	
' **************************************	
	' inicio la multitarea que permite el control de elementos dentro de OCC
	pThread = ThreadCreate(@OCC_Thread)
	
		' inicio OCC
		OCCViewer_Init(@pia,@pib)

	' cierro OCC (nota: por ahora no vuelve desde 'OCC_Thread', queda pendiente de revisar
	ThreadWait(pThread)
' **************************************