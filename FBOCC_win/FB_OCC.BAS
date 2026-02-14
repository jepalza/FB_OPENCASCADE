' Freebasic C-Wrapper OpenCascade V0.3
'
' Joseba Epalza <jepalza> gmail punto com , Enero-Febrero 2026
'
' no hay limite de uso de este codigo, es libre dde uso 100% (solo pido una mencion si lo empleas)
'
' C-WRAPPER para OpenCascade < https://dev.opencascade.org/ > version 7.7 x32 (noviembre 2022)
' empleando las rutinas de < https://github.com/marcuswu/occwrapper > con ligeras modificaciones
' licencias de sus respectivos autores, segun se indica en su pagina WEB


#include "windows.bi"
#include "fbgfx.bi"

#include "res\Res.bi"

#include "FBOCCWrapper.bi"
#Inclib "FBOCCWrapper"

' objetos globales para multitarea
dim shared as TopoDSShape bolaShape,cuboShape,cajaShape,resultadoBOOLEAN
Dim shared As long ctx,vwr ' valores devueltos por OCC de sus manejadores de ventanas (context y viewer)
									' 		nota: ctx y vwr SIN utilidad actual, para el futuro


' manejadores globales de ventanas
Dim Shared WinFRM As HWND ' la ventana principal de menus y que contiene a la de OCC
Dim Shared OCCWin As HWND ' la ventana de OCC
Dim Shared hWndAbout As HWND
'Dim Shared hWndMain  As HWND

' instancia global para menus y ventanas "hijo"
Dim Shared hinst_  As HINSTANCE

dim shared as integer OCC_Activo=0 


' menus de iconos graficos
#Include Once "win/commdlg.bi"
#Include Once "win/commctrl.bi"
Dim Shared As HWND hWndToolBar 
Dim Shared As integer altoiconos=16  ' medidas iconos graficos de menus
Dim Shared As integer anchoiconos=17 ' este 17 es por un ejemplo empleado, pero siempre es mejor cuadrado
Dim Shared As Integer numbotones=9   ' numero de botones graficos a mostrar


	

' ventana
dim Shared as long winAncho=800
dim Shared as long winAlto=600

' raton
dim shared as integer mx,my,v1,v2,mxold,myold,mb

' teclado
dim shared as integer CTRL_Pulsado=0




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



'''''''''''''''''''''''''''''
'      elegir ficheros      '
'''''''''''''''''''''''''''''
Function ControlArchivos(ByVal HWndFile as HWND ) as String
    Dim ofn as OPENFILENAME
    Dim filename as ZString * MAX_PATH+1
    
    With ofn
        .lStructSize         = SizeOf( OPENFILENAME )
        .hwndOwner           = HWndFile
        .hInstance           = GetModuleHandle( Null )
        .lpstrFilter         = StrPtr(!"Todos los ficheros, (*.*)\0*.*" ) '\0*.*\0Bas Files, (*.BAS)\0*.bas\0\0" )
        .lpstrCustomFilter   = Null
        .nMaxCustFilter      = 0
        .nFilterIndex        = 1
        .lpstrFile           = @filename
        .nMaxFile            = SizeOf( filename )
        .lpstrFileTitle      = Null
        .nMaxFileTitle       = 0
        .lpstrInitialDir     = Null
        .lpstrTitle          = @"Selecciona fichero"
        .Flags               = OFN_EXPLORER 'Or OFN_FILEMUSTEXIST Or OFN_PATHMUSTEXIST
        .nFileOffset         = 0
        .nFileExtension      = 0
        .lpstrDefExt         = Null
        .lCustData           = 0
        .lpfnHook            = Null
        .lpTemplateName      = Null
    End With

    If( GetOpenFileName( @ofn ) = False ) Then Return ""
	
    Return filename
End Function
'''''''''''''''''''''''''''''''''''''''''''''''''
'''''''''''''''''''''''''''''''''''''''''''''''''



Sub exportar_cad(LW as integer)
	if LW=IDM_STP then
		' exportar STEP
		Dim As String fich=ControlArchivos(WinFRM)
		dim as STEPControlWriter FileSTEP=STEPControlWriter_Init()
		STEPControlWriter_Add(FileSTEP,resultadoBOOLEAN,0)
		STEPControlWriter_Add(FileSTEP,bolaShape,0)
		STEPControlWriter_Add(FileSTEP,cuboShape,0)
		STEPControlWriter_Add(FileSTEP,cajaShape,0)
		STEPControlWriter_Write(FileSTEP,strptr(fich))
		STEPControlWriter_Free(FileSTEP)	
		print "STEP Correcto!"
	EndIf
	if LW=IDM_IGS then
		' exportar IGES
		Dim As String fich=ControlArchivos(WinFRM)
		dim as IGESControlWriter FileIGES=IGESControlWriter_Init()
		IGESControlWriter_Add(FileIGES,resultadoBOOLEAN,0)
		IGESControlWriter_Add(FileIGES,bolaShape,0)
		IGESControlWriter_Add(FileIGES,cuboShape,0)
		IGESControlWriter_Add(FileIGES,cajaShape,0)
		IGESControlWriter_Write(FileIGES,strptr(fich))                                                                                                                   
		IGESControlWriter_Free(FileIGES)	
		print "IGES Correcto!"
	EndIf
end sub




Function AboutDlgProc cdecl(hDlg as HWND, message as UINT, wParam_ as WPARAM, lParam_ as LPARAM) as LRESULT
   select case (message)
   case WM_INITDIALOG
       return cast(INT_PTR,TRUE)
   case WM_COMMAND
         if LOWORD(wParam_) = IDOK OrElse LOWORD(wParam_) = IDCANCEL then
            EndDialog(hDlg, LOWORD(wParam_))
            return cast(INT_PTR,TRUE)
			endif
   End Select
   return cast(INT_PTR,FALSE)
End Function



Function WndProc cdecl(ByVal hwnd_ As HWND, _
                 ByVal msg_ As UINT, _
                 ByVal wParam_ As WPARAM, _
                 ByVal lParam_ As LPARAM) As LRESULT
	Dim rc As RECT ' para coger las medidas de la ventana al hacer RESIZE
	
	Select Case msg_
		Case WM_CREATE
         hWndToolBar = CreateWindowEx(0, TOOLBARCLASSNAME, NULL, WS_CHILD Or WS_VISIBLE, 0, 0, 8, 0,_
													hWnd_, cast(HMENU,ID_TBR_TOOLBAR), hInst_, NULL) 
         if hWndToolBar=0 Then MessageBox(NULL, "ToolBar 1", "Error", MB_OK Or MB_ICONERROR) : return 0 
			
			' Send the TB_BUTTONSTRUCTSIZE message, which is required for backward compatibility.
         SendMessage(hWndToolBar, TB_BUTTONSTRUCTSIZE, cast(WPARAM,sizeof(TBBUTTON)), 0) 
         
			' espacio para iconos (marco donde se alojara), creo que no es necesario
			SendMessage(hWndToolBar, TB_SETBITMAPSIZE, cast(WPARAM,0), cast(LPARAM,MAKELONG(anchoiconos, altoiconos))) 

			' para cargar una barra continua de iconos seguidos
			' importante indicar en 'numbotones' cuantos iconos lleva (misma variable que para crearlos)
			dim as HIMAGELIST hImgList = ImageList_Create(anchoiconos, altoiconos, ILC_COLOR, numbotones, 0 )
			if (hImgList=0) then MessageBox(NULL, "ToolBar 2", "Error", MB_OK Or MB_ICONERROR) : return 0 
			dim as HBITMAP hBitmapImage = cast(HBITMAP,LoadImage(hInst_, _
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





		' -----------------------------------------
		' multiples llamadas
		Case WM_COMMAND
			dim as integer LW=LoWord(wParam_)
			
	      If LW=IDM_SALIR  Then 
				if (MessageBox(NULL, "¿Quieres Salir?", "Vamos a finalizar...", MB_YESNO)=IDYES) then
					sendmessage hwnd_,WM_DESTROY,0,0
				endif
			endif

			' menus exportar IGES o STEP
	      If LW=IDM_STP OrElse LW=IDM_IGS  Then exportar_cad(LW)
			
			' mensaje IDD_ABOUT
	      If LW=IDD_ABOUT Then DialogBox(hInst_, MAKEINTRESOURCE(IDD_ABOUT), hWnd_, cast(WNDPROC,@AboutDlgProc))
		' -------------------------------------------
		
		
		' el teclado se recoge en la ventana principal, no en la secundaria
		case WM_KEYDOWN
			if (GetKeyState(VK_CONTROL) and &h8000) then CTRL_Pulsado=1

		case WM_KEYUP
			CTRL_Pulsado=0		
		
			
		Case WM_SIZE
			' cojo medidas de la ventana principal
			' para hacer que la secundaria quede dentro del marco sin "pisar" iconos
			If wParam_ <> SIZE_MINIMIZED Then GetClientRect(hWnd_, @rc)
			dim as LONG x1 = rc.left +4
         dim as LONG y1 = rc.top +32 ' este es para no "pisar" los iconos de los menus
         dim as LONG x2 = rc.right -4-4
         dim as LONG y2 = rc.bottom -32-4
         MoveWindow(OCCWin, x1, y1, x2, y2, TRUE) ' actualizo ventana OCC
			UpdateWindow(OCCWin)
			if OCC_Activo then OCCViewer_Update(2) ' =2 refresca la pantalla a las nuevas medidas
						
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



' ventana secundaria HIJO de la principal, esta es para el sistema grafico del OCC
Function OCCProc cdecl(ByVal hwnd_ As HWND, _
                 ByVal msg_ As UINT, _
                 ByVal wParam_ As WPARAM, _
                 ByVal lParam_ As LPARAM) As LRESULT
	Dim rc As RECT ' para coger las medidas de la ventana al hacer RESIZE
	
	Select Case msg_
		Case WM_CREATE
			' nada aun
			
		Case WM_SYSCOMMAND
			' nada aun

		' -----------------------------------------
		' multiples llamadas
		Case WM_COMMAND
			dim as integer LW=LoWord(wParam_)
			' nada aun
		' -------------------------------------------

		Case WM_SIZE
			' aqui no hacemos nada, se hace en la principal

		
		
		' ==================== RATON ========================
		Case WM_MOUSEMOVE
			'if OCC_Activo then OCCViewer_Update(21)
			mxold=mx
			myold=my
			mx=loword(lParam_)
			my=hiword(lParam_)
			'print mx,my
			' rotaciones boton medio o rueda
			if OCC_Activo and mb=31 and CTRL_Pulsado then 
				if mxold<>mx then v1=(mxold-mx):mxold=mx
				if myold<>my then v2=(myold-my):myold=my
				OCCViewer_Update(0,,,-v1,-v2,2) '2=rotar
			endif
			' translaciones boton derecho
			if OCC_Activo and mb=21 and CTRL_Pulsado then 
				if mxold<>mx then v1=(mxold-mx):mxold=mx
				if myold<>my then v2=(myold-my):myold=my
				OCCViewer_Update(0,,,-v1,v2,3) '3=mover
			endif
			' lupas boton izquierdo 
			if OCC_Activo and mb=11 and CTRL_Pulsado then 
				if mxold<>mx then v1=(mxold-mx):mxold=mx
				if myold<>my then v2=(myold-my):myold=my
				OCCViewer_Update(0,0,0,-v2,v1,4) '4=lupa
			endif
			
		case WM_LBUTTONUP
			'print "L0"
			mb=10
			
		case WM_LBUTTONDOWN
			'print "L1"
			mb=11
			' seleccion de objeto al pulsar raton sobre el
			if OCC_Activo and mb=11 and CTRL_Pulsado=0 then 
				OCCViewer_Update(0,mx,my,mx+1,my+1,1) '1=seleccion
			endif

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

		'Case WM_DESTROY
		' nota: aqui NO hacemos la destruccion de ventana, se hace en el principal

		Exit Function

	End Select
	Return DefWindowProc(hwnd_, msg_, wParam_, lParam_)
End Function





Function WINMAIN (ByVal hInst As HINSTANCE, ByVal hPrevInst As HINSTANCE, _
                      lpszCmdLine As ZString Ptr, ByVal nCmdShow As Long) As Long
	Dim msg_          As  MSG
	
	Dim szClassName1  As ZString * 128 ' ventana uno para menus
	Dim szClassName2  As ZString * 128 ' esta para OCC
	
	Dim wcex1         As WNDCLASSEX 
	Dim wcex2         As WNDCLASSEX 	

	 
	' instancia para la barra de menus y ventanas "hijos"
	hInst_=hInst
	
	' =======================================================================================
	' ventana principal, marco para contener menus e iconos ademas del propio OCC como "hijo"
	szClassName1 = "OCC_FB_PADRE" 
	 
	wcex1.cbSize = Sizeof(wcex1)
	wcex1.style  = CS_VREDRAW OR CS_HREDRAW
	wcex1.lpfnWndProc = cast(WNDPROC,@WndProc)
	wcex1.cbClsExtra = 0
	wcex1.cbWndExtra = 0
	wcex1.hInstance = hInst
	wcex1.hIcon   = LoadIcon(NULL, ByVal IDI_APPLICATION )
	wcex1.hIconSm = LoadIcon(NULL, ByVal IDI_APPLICATION)
	wcex1.hCursor = LoadCursor(NULL, ByVal IDC_ARROW)
	wcex1.hbrBackground = Cast(HBRUSH,COLOR_BTNFACE + 1)
	wcex1.lpszMenuName = MAKEINTRESOURCE(IDR_MENUS)
	'wcex1.lpszMenuName = Null
	wcex1.lpszClassName = StrPtr(szClassName1)
 
	If RegisterClassEx(@wcex1) = 0 Then Return FALSE
   ' si usamos RESOURCES para leer la configuracion de la ventana principal, esto no es necesario
	WinFRM = CreateWindowEx(WS_EX_CONTROLPARENT, _
                        szClassName1,   _
                        "OpenCASCADE OCC 7.7 FreeBasic", _ ' titulo de la ventana
                        WS_OVERLAPPEDWINDOW, _
                        CW_USEDEFAULT, _
                        CW_USEDEFAULT,  _
                        winAncho+16+4, _ ' +16+4 para que entre el marco
                        winAlto +64+4, _ ' +64+4 para dejar sitio a menus
                        NULL, _
                        NULL, _
                        hInst, _
                        ByVal NULL)

	' =====================================================
	' ventana secundaria, propiamente la de OPENCASCADE OCC
	szClassName2 = "OCC_FB2_HIJO" 
	wcex2.cbSize = Sizeof(wcex2)
	wcex2.style  = CS_VREDRAW OR CS_HREDRAW
	wcex2.lpfnWndProc = cast(WNDPROC,@OCCProc)
	wcex2.cbClsExtra = 0
	wcex2.cbWndExtra = 0
	wcex2.hInstance = hInst
	wcex2.hIcon   = LoadIcon(NULL, ByVal IDI_APPLICATION )
	wcex2.hIconSm = LoadIcon(NULL, ByVal IDI_APPLICATION)
	wcex2.hCursor = LoadCursor(NULL, ByVal IDC_ARROW)
	wcex2.hbrBackground = Cast(HBRUSH,COLOR_BTNFACE + 1)
	wcex2.lpszMenuName = null
	'wcex2.lpszMenuName = Null
	wcex2.lpszClassName = StrPtr(szClassName2)
 
	If RegisterClassEx(@wcex2) = 0 Then Return FALSE
	OCCWin = CreateWindowEx(WS_EX_CONTROLPARENT, _
                        szClassName2,   _
                        "OCC7.7", _ ' titulo, pero no se muestra en este caso, no tiene marco
                        WS_CHILD, _
                        0, _
                        0,  _
                        winAncho, _ ' se autoajusta en crear el proceso
                        winAlto, _ ' se autoajusta en crear el proceso
                        WinFRM, _
                        NULL, _
                        null, _
                        ByVal NULL)


	ShowWindow(WinFRM, SW_SHOWNORMAL) ' ventana padre principal para menus
	ShowWindow(OCCWin, SW_SHOWNORMAL) ' ventana hijo secundaria para OCC
	UpdateWindow WinFRM
	UpdateWindow OCCWin
	
	' crea una ventana OCC
	OCC_Activo=OCCViewer_Init(cast(long,OCCWin),@ctx,@vwr) ' nota: ctx y vwr SIN utilidad actual, para el futuro
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
 		