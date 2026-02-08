// Joseba Epalza , 2026
// simple visualizador de objetos creados en tiempo real dentro de FreeBasic

#include <windows.h>

#include "occviewer.h"

#include <AIS_InteractiveContext.hxx>
#include <AIS_Shape.hxx>
#include <AIS_ViewController.hxx>
#include <OpenGl_GraphicDriver.hxx>
#include <OSD.hxx>
#include <V3d_View.hxx>
#include <V3d_Viewer.hxx>

#include <Aspect_Handle.hxx>
#include <Aspect_DisplayConnection.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeCone.hxx>
#include <Message.hxx>
#include <Message_Messenger.hxx>

#include <TopAbs_ShapeEnum.hxx>

#include <WNT_WClass.hxx>
#include <WNT_Window.hxx>

// globales para la multitarea de FreeBasic
Handle(AIS_InteractiveContext) myContextGlobal;
Handle(V3d_View) myViewGlobal;

//! Sample single-window viewer class.
class OccWinViewer : public AIS_ViewController
{
public:
  Handle(AIS_InteractiveContext) myContext;
  Handle(V3d_View) myView;
  Handle(V3d_Viewer) aViewer;
  Handle(WNT_Window) aWindow;
  
  //! Main constructor.
  OccWinViewer()
  {
    // graphic driver setup
    Handle(Aspect_DisplayConnection) aDisplay = new Aspect_DisplayConnection();
    Handle(Graphic3d_GraphicDriver) aDriver = new OpenGl_GraphicDriver (aDisplay);

    // viewer setup
    //Handle(V3d_Viewer) 
	 aViewer = new V3d_Viewer (aDriver);
    aViewer->SetDefaultLights();
    aViewer->SetLightOn();

    // view setup
    myView = new V3d_View (aViewer);

    const TCollection_AsciiString aClassName ("MyWinClass");
    Handle(WNT_WClass) aWinClass = new WNT_WClass (aClassName.ToCString(), &windowProcWrapper,
                                                   CS_VREDRAW | CS_HREDRAW, 0, 0,
                                                   ::LoadCursor (NULL, IDC_ARROW));
    aWindow = new WNT_Window ("OCCT Viewer", aWinClass,  WS_OVERLAPPEDWINDOW,
                                                 100, 100, 512, 512, Quantity_NOC_BLACK);
    ::SetWindowLongPtrW ((HWND )aWindow->NativeHandle(), GWLP_USERDATA, (LONG_PTR )this);

    myView->SetWindow (aWindow);
    myView->SetBackgroundColor (Quantity_NOC_GRAY50);
    myView->TriedronDisplay (Aspect_TOTP_LEFT_LOWER, Quantity_NOC_WHITE, 0.1);
    myView->ChangeRenderingParams().RenderResolutionScale = 2.0f;

    // interactive context and demo scene
    myContext = new AIS_InteractiveContext (aViewer);

	 // Cubo de ejemplo
    // TopoDS_Shape aShape = BRepPrimAPI_MakeBox (100, 100, 100).Solid();
    // Handle(AIS_InteractiveObject) aShapePrs = new AIS_Shape (aShape);
    // myContext->Display (aShapePrs, AIS_Shaded, 0, false);
    // myView->FitAll (0.01, false);

	 // actualiza vista
    aWindow->Map();
    myView->Redraw();
  }

  //! Return context.
  const Handle(AIS_InteractiveContext)& Context() const { return myContext; }

  //! Return view.
  const Handle(V3d_View)& View() const { return myView; }
  
  //! Return viewer.
  const Handle(V3d_Viewer)& Viewer() const { return aViewer; }

private:
  //! Handle expose event.
  virtual void ProcessExpose() override
  {
    if (!myView.IsNull())
    {
      FlushViewEvents (myContext, myView, true);
    }
  }

  //! Handle window resize event.
  virtual void ProcessConfigure (bool theIsResized) override
  {
    if (!myView.IsNull() && theIsResized && !myView->Window().IsNull())
    {
      myView->Window()->DoResize();
      myView->MustBeResized();
      myView->Invalidate();
      FlushViewEvents (myContext, myView, true);
    }
  }

  //! Handle input.
  virtual void ProcessInput() override
  {
    if (!myView.IsNull())
    {
      ProcessExpose();
    }
  }


  //! Window message handler.
  static LRESULT WINAPI windowProcWrapper (HWND theWnd, UINT theMsg, WPARAM theParamW, LPARAM theParamL)
  {
    if (theMsg == WM_CLOSE)
    {
      exit (0);
      return 0;
    }

    if (OccWinViewer* aThis = (OccWinViewer* )::GetWindowLongPtrW (theWnd, GWLP_USERDATA))
    {
      WNT_Window* aWindow = dynamic_cast<WNT_Window* >(aThis->myView->Window().get());
      MSG aMsg = { theWnd, theMsg, theParamW, theParamL };
      if (aWindow->ProcessMessage (*aThis, aMsg))
      {
        return 0;
      }
    }
    return ::DefWindowProcW (theWnd, theMsg, theParamW, theParamL);
  }
};







// ---------------------------- EXPORT DLL -------------------------------
int OCCViewer_Init( // devuelve los punteros a los manejadores de ventanas para que FreeBasic los emplee
		Handle(V3d_View) FBView,
		Handle(AIS_InteractiveContext) FBContext )
{
	OccWinViewer aViewer;
   OSD::SetSignal (false);

	// las devuelve a FreeBasic por si son necesarias
	FBView=aViewer.myView; 
	FBContext=aViewer.myContext;	
	
	// y las asigna a globales para que FreeBasic pueda hacer cambios
   myContextGlobal=FBContext;
   myViewGlobal=FBView;
  
  // WinAPI message loop
  MSG aMsg = {};
  for (;;) // infinito, nunca sale
  {
    if (GetMessageW (&aMsg, NULL, 0, 0) <= 0)
    {
      return 0;
    }
     TranslateMessage(&aMsg);
     DispatchMessageW(&aMsg);
  }
  
  return 1; // nunca vuelve, pero lo dejo por si acaso
}


int OCCViewer_Add(TopoDS_Shape aisShape, int mode)
{
	// Handle(AIS_InteractiveObject) ToShape = new AIS_Shape(aisShape);
	Handle(AIS_Shape) ToShape = new AIS_Shape(aisShape);

	//WinApp.myContext->SetColor(WinApp.myContext->Current(),Quantity_NOC_BLUE1);

	myContextGlobal->Display (ToShape, mode, 0, true); //AIS_Shaded, mode, false);
	myContextGlobal->SetDisplayMode(ToShape,AIS_Shaded, true);

   myViewGlobal->FitAll (0.01, false);
   myViewGlobal->Redraw();
	 
	return 1; // correcto
}


