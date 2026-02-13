
' Joseba Epalza <jepalza> gmail punto com , enero 2026
' C-WRAPPER para OpenCascade < https://dev.opencascade.org/ > version 7.7 x32 (noviembre 2022)
' empleando las rutinas de < https://github.com/marcuswu/occwrapper > con ligeras modificaciones
' aun esta poco avanzado, solo comprobados tres tipos de entidades y dos formas de salida de ficheros


#include "windows.bi"
#include "fbgfx.bi"

#include "res\Res.bi"

#include "FBOCCWrapper.bi"
#Inclib "FBOCCWrapper"

' objetos globales para multitarea
dim shared as TopoDSShape bolaShape,cuboShape,cajaShape,resultadoBOOLEAN
Dim shared As long ctx,vwr ' valores devueltos por OCC de sus manejadores de ventanas (context y viewer)
									' 		nota: ctx y vwr SIN utilidad actual, para el futuro


' manejadores de ventanas
Dim Shared WinFRM As HWND
Dim Shared hWndAbout As HWND
Dim Shared hWndMain  As HWND

dim shared as integer OCC_Activo=0 


' menus de iconos graficos
#Include Once "win/commdlg.bi"
#Include Once "win/commctrl.bi"
Dim Shared As HWND hWndToolBar 
Dim Shared As integer altoiconos=16  ' medidas iconos graficos de menus
Dim Shared As integer anchoiconos=17 ' este 17 es por un ejemplo empleado, pero siempre es mejor cuadrado
Dim Shared As Integer numbotones=9   ' numero de botones graficos a mostrar

' instancia a la barra de menus
Dim Shared As HINSTANCE hInst_menu
	

' ventana
dim Shared as long winAncho=800
dim Shared as long winAlto=600

' raton
dim shared as integer mx,my,v1,v2,mxold,myold,mb





sub Demo()
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

		OCCViewer_Add(cast(long ,bolaShape),0)
		OCCViewer_Add(cast(long ,cuboShape),0)
		OCCViewer_Add(cast(long ,cajaShape),0)
		OCCViewer_Add(cast(long ,resultadoBOOLEAN),0)
end sub










Function WndProc(ByVal hwnd_ As HWND, _
                 ByVal msg_ As UINT, _
                 ByVal wParam_ As WPARAM, _
                 ByVal lParam_ As LPARAM) As LRESULT
 
	Dim rc As RECT
	Select Case msg_
		Case WM_CREATE
         hWndToolBar = CreateWindowEx(0, TOOLBARCLASSNAME, NULL, WS_CHILD Or WS_VISIBLE, 0, 0, 8, 0,_
													hWnd_, cast(HMENU,ID_TBR_TOOLBAR), hInst_menu, NULL) 
         if hWndToolBar=0 Then MessageBox(NULL, "ToolBar 1", "Error", MB_OK Or MB_ICONERROR) : return 0 
			
			' Send the TB_BUTTONSTRUCTSIZE message, which is required for backward compatibility.
         SendMessage(hWndToolBar, TB_BUTTONSTRUCTSIZE, cast(WPARAM,sizeof(TBBUTTON)), 0) 
         
			' espacio para iconos (marco donde se alojara), creo que no es necesario
			'SendMessage(hWndToolBar, TB_SETBITMAPSIZE, cast(WPARAM,0), cast(LPARAM,MAKELONG(anchoiconos, altoiconos))) 

			' para cargar una barra continua de iconos seguidos
			' importante indicar en 'numbotones' cuantos iconos lleva (misma variable que para crearlos)
			dim as HIMAGELIST hImgList = ImageList_Create(anchoiconos, altoiconos, ILC_COLOR, numbotones, 0 )
			if (hImgList=0) then MessageBox(NULL, "ToolBar 2", "Error", MB_OK Or MB_ICONERROR) : return 0 
			dim as HBITMAP hBitmapImage = cast(HBITMAP,LoadImage(hInst_menu, _
				 MAKEINTRESOURCE( ID_TOOLBAR_LARGA ), _ ' AQUI EL NOMBRE DEL BMP
				 IMAGE_BITMAP, numbotones * anchoiconos, altoiconos, _
				 LR_COPYFROMRESOURCE or LR_SHARED  ))
			' este sistema pilla un BMP largo con varios iconos seguidos, y los pega automatico todos seguidos
			' un sistema muy curioso y util, por que solo tenemos UN icono largo (importante indicar cuantos lleva)
			if (hBitmapImage=0) then MessageBox(NULL, "ToolBar 3", "Error", MB_OK Or MB_ICONERROR) : return 0 
			ImageList_Add(hImgList, hBitmapImage, NULL)
			SendMessage(hWndToolBar, TB_SETIMAGELIST, cast(WPARAM,0), cast(LPARAM,hImgList))

			' y creamos los botones
			Dim As TBBUTTON tbb(numbotones-1)
			
			' definimos el tipo de botones: pueden ser estandar, peques, grandes, tec... ver internes
			Dim As TBADDBITMAP tbbits 
			tbbits.hInst= HINST_COMMCTRL 
			tbbits.nID = IDB_STD_SMALL_COLOR ' IDB_STD_LARGE_COLOR ' para iconos de 24x24
			SendMessage(hWndToolBar,TB_ADDBITMAP, 0, cast(LPARAM,@tbbits)) 'tapar este y el boton cambia forma

			' el boton se redimensiona segun el tamaño del texto a mostrar, en caso de indicarlo
			' si supera al icono, se agranda
			tbb( 0) = type( 0 , ID_BOTON0 , TBSTATE_ENABLED , TBSTYLE_BUTTON)
			tbb( 1) = type( 1 , ID_BOTON1 , TBSTATE_ENABLED , TBSTYLE_BUTTON) 'pueden ser TBSTYLE_AUTOSIZE
			tbb( 2) = type( 2 , ID_BOTON2 , TBSTATE_ENABLED , TBSTYLE_BUTTON)
			tbb( 3) = type( 3 , ID_BOTON3 , TBSTATE_ENABLED , TBSTYLE_BUTTON)
			tbb( 4) = type( 4 , ID_BOTON3 , TBSTATE_ENABLED , TBSTYLE_BUTTON)
			tbb( 5) = type( 5 , ID_BOTON3 , TBSTATE_ENABLED , TBSTYLE_BUTTON)
			tbb( 6) = type( 6 , ID_BOTON3 , TBSTATE_ENABLED , TBSTYLE_BUTTON)
			tbb( 7) = type( 7 , ID_BOTON3 , TBSTATE_ENABLED , TBSTYLE_BUTTON)
			tbb( 8) = type( 8 , ID_BOTON3 , TBSTATE_ENABLED , TBSTYLE_BUTTON)

			' *****************************************
			' ya podemos mostrar los botones
			' nota:en fb "ubound(tbb)+1"  equivale a "sizeof(tbb)/sizeof(TBBUTTON)"
         SendMessage(hWndToolBar, TB_ADDBUTTONS, ubound(tbb)+1, cast(LPARAM,@tbb(0))) 
         'SendMessage(hWndToolBar, TB_AUTOSIZE, 0, 0) ' para autosize
			
			
			
		Case WM_SYSCOMMAND
'			If (wParam_ And &hFFF0) = SC_CLOSE Then
'				SendMessage (hWnd_, WM_DESTROY, wParam_, lParam_)
'				Exit Function
'			End If

		Case WM_COMMAND
			dim as integer LW=LoWord(wParam_)
			
	      If LW=32780 or LW=ID_BOTON0 Then '32776 es el ID del menu de "fichero/nuevo" en RES.RC
				if (MessageBox(NULL, "¿Quieres Salir?", "Vamos a salir...", MB_YESNO)=IDYES) then
					sendmessage hwnd_,WM_DESTROY,0,0
				endif
			endif

	      If LW=IDM_ABOUT Then ShowWindow(hWndAbout, SW_SHOW)

			
		Case WM_SIZE
			If wParam_ <> SIZE_MINIMIZED Then
				GetClientRect(hWnd_, @rc)
			End If
			' refresca OCC
			if OCC_Activo then OCCViewer_Update(2) ' =2 refresca la pantalla a las nuevas medidas
		
		
		
		' ==================== RATON ========================
		Case WM_MOUSEMOVE
			'if OCC_Activo then OCCViewer_Update(21)
			mxold=mx
			myold=my
			mx=loword(lParam_)
			my=hiword(lParam_)
			'print mx,my
			' rotaciones boton izquierdo
			if OCC_Activo and mb=11 then 
				if mxold<>mx then v1=(mxold-mx):mxold=mx
				if myold<>my then v2=(myold-my):myold=my
				OCCViewer_Update(0,,,-v1,-v2,mb)
			endif
			' translaciones boton derecho
			if OCC_Activo and mb=21 then 
				if mxold<>mx then v1=(mxold-mx):mxold=mx
				if myold<>my then v2=(myold-my):myold=my
				OCCViewer_Update(0,,,-v1,v2,mb)
			endif
			' lupas boton medio o rueda
			if OCC_Activo and mb=31 then 
				if mxold<>mx then v1=(mxold-mx):mxold=mx
				if myold<>my then v2=(myold-my):myold=my
				OCCViewer_Update(0,0,0,v2,v1,mb)
			endif
						
		case WM_LBUTTONUP
			'print "L0"
			mb=10
			
		case WM_LBUTTONDOWN
			'print "L1"
			mb=11

		case WM_RBUTTONUP
			'print "R0"
			mb=20
			
		case WM_RBUTTONDOWN
			'print "R1"
			mb=21
			
		case WM_MBUTTONUP
			'print "M0"
			mb=30
			
		case WM_MBUTTONDOWN
			'print "M1"
			mb=31
		' ====================================================				
						
						
						
						
		Case WM_CLOSE
			sendmessage hwnd_,WM_DESTROY,0,0
			Return TRUE
		 
		Case WM_DESTROY
			PostQuitMessage(0)
			Return TRUE

		Exit Function

	End Select
	
	Return DefWindowProc(hwnd_, msg_, wParam_, lParam_)
End Function


Function WINMAIN (ByVal hInst As HINSTANCE, ByVal hPrevInst As HINSTANCE, _
                      lpszCmdLine As ZString Ptr, ByVal nCmdShow As Long) As Long
	Dim msg_          As  MSG
	Dim szClassName   As ZString * 128
	Dim szWindowTitle As ZString * 128
	Dim wcex          As WNDCLASSEX
	 
	' instancia para la barra de menus
	hInst_menu=hInst
	
	szClassName = "OCC_FB" ' puede ser cualquier nombre
	szWindowTitle = "OCC OpenCascade FreeBasic" ' puede ser cualquier nombre
	 
	wcex.cbSize = Sizeof(wcex)
	wcex.style  = CS_VREDRAW OR CS_HREDRAW
	wcex.lpfnWndProc = @WndProc
	wcex.cbClsExtra = 0
	wcex.cbWndExtra = 0
	wcex.hInstance = hInst
	wcex.hIcon   = LoadIcon(NULL, ByVal IDI_APPLICATION )
	wcex.hIconSm = LoadIcon(NULL, ByVal IDI_APPLICATION)
	wcex.hCursor = LoadCursor(NULL, ByVal IDC_ARROW)
	wcex.hbrBackground = Cast(HBRUSH,COLOR_BTNFACE + 1)
	wcex.lpszMenuName = MAKEINTRESOURCE(IDR_MENUS)
	'wcex.lpszMenuName = Null
	wcex.lpszClassName = StrPtr(szClassName)
 
	If RegisterClassEx(@wcex) = 0 Then
		MessageBeep(0)
		Return FALSE
		Exit Function
	End If

   ' si usamos RESOURCES para leer la configuracion de la ventana principal, esto no es necesario
	WinFRM = CreateWindowEx(WS_EX_CONTROLPARENT, _
                        szClassName,   _
                        "OpenCASCADE OCC 7.7 FreeBasic", _
                         WS_OVERLAPPEDWINDOW, _
                         CW_USEDEFAULT, _
                         0,  _
                         winAncho+16+4, _ ' +16+4 para que entre el marco
                         winAlto +64+4, _ ' +64+4 para dejar sitio a menus
                        NULL, _
                        NULL, _
                        hInst, _
                        ByVal NULL)


	' ventanas de dialogo de menus
	' para crear una ventana flotante desde RESOURCES
	hWndAbout = CreateDialog( hinst, _ ' HINSTANCE o NULL
						MAKEINTRESOURCE(IDD_ABOUT) , _ 
						WinFRM, _
						Cast(WndProc, null) )


	ShowWindow(WinFRM, SW_SHOWNORMAL)
	UpdateWindow WinFRM
	
	' crea una ventana OCC
	OCC_Activo=OCCViewer_Init(cast(long,WinFRM),@ctx,@vwr) ' nota: ctx y vwr SIN utilidad actual, para el futuro
	'print "manejadores OCC:";ctx,vwr
	
	' genera una Demostracion de BOOLEANAS
	Demo()
		
	' message loop
	While GetMessage(@msg_, NULL, 0, 0)
		TranslateMessage(@msg_)
		DispatchMessage(@msg_)
	Wend
 
	Return  FALSE
End Function


End WINMAIN(getmoduleHandle(0),NULL,Command,SW_SHOW)
 		