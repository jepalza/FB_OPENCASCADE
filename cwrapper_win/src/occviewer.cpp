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
HWND FreeBasicWin;
  Handle(V3d_Viewer) aViewer;
  
//! Sample single-window viewer class.
class OccWinViewer : public AIS_ViewController
{
public:
  Handle(AIS_InteractiveContext) myContext;
  Handle(V3d_View) myView;
  // Handle(V3d_Viewer) aViewer;
  Handle(WNT_Window) aWindow;
  
  //! Main constructor.
  OccWinViewer()
  {
    // graphic driver setup
    Handle(Aspect_DisplayConnection) aDisplay = new Aspect_DisplayConnection();
    Handle(Graphic3d_GraphicDriver) aDriver = new OpenGl_GraphicDriver (aDisplay);

    // viewer setup
	aViewer = new V3d_Viewer (aDriver);
    aViewer->SetDefaultLights();
    aViewer->SetLightOn();


	// ventana segun propiedades creadas en FreeBasic
    ::SetWindowLongPtrW ((HWND)FreeBasicWin, GWLP_USERDATA, (LONG_PTR )this);
	aWindow = new WNT_Window(FreeBasicWin);
	// aWindow->SetPos(40,40,400,400); // no hace nada? 

    // view setup
    myView = new V3d_View (aViewer);
    myView->SetWindow (aWindow);
    myView->SetBackgroundColor (Quantity_NOC_GRAY50);
    myView->TriedronDisplay (Aspect_TOTP_LEFT_LOWER, Quantity_NOC_WHITE, 0.1);
    myView->ChangeRenderingParams().RenderResolutionScale = 2.0f;
	 

    // interactive context and demo scene
    myContext = new AIS_InteractiveContext (aViewer);

	 // abre la ventana
    aWindow->Map();
	 // actualiza vista
    myView->Redraw();

  }

  //! Return context.
  const Handle(AIS_InteractiveContext)& Context() const { return myContext; }

  //! Return view.
  const Handle(V3d_View)& View() const { return myView; }
  
  //! Return viewer.
  const Handle(V3d_Viewer)& Viewer() const { return aViewer; }

private:
  // ! Handle expose event.
  virtual void ProcessExpose() override
  {
    if (!myView.IsNull())
    {
      FlushViewEvents (myContext, myView, true);
    }
  }

  // ! Handle window resize event.
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

  // ! Handle input.
  virtual void ProcessInput() override
  {
	// (OccWinViewer* )::MessageBeep(0); // prueba
    if (!myView.IsNull())
    {
      ProcessExpose();
    }
  }


  //! Window message handler.
  static LRESULT WINAPI windowProcWrapper (HWND theWnd, UINT theMsg, WPARAM theParamW, LPARAM theParamL)
  {
	  // (OccWinViewer* )::MessageBeep(0); // prueba
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
int OCCViewer_Init(  HWND FB_Window ,	 
							int* FB_Context,  
							int* FB_View
							)
// entrada del manejador de ventanas HWND desde FreeBasic
{
	FreeBasicWin=FB_Window; // asigna a global

   OSD::SetSignal (false);	
	OccWinViewer aViewer;

	// las devuelve a FreeBasic por si son necesarias
	*FB_Context=&aViewer.myContext;	
	*FB_View=&aViewer.myView; 

	// y las asigna a globales
   myContextGlobal=aViewer.myContext;
	myViewGlobal=aViewer.myView;
	
	// printf("context cpp %d\n",*FB_Context);
	// printf("view cpp %d\n",*FB_View);
  return 1; 
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


// eventos graficos: modo=0 solo movimientos, modo=1(defecto) refresca pantalla, modo=2 cambia medidas de pantalla
int OCCViewer_Update(int modo=1, int mx=0, int my=0, int v1=0, int v2=0, int mb=0)
{
	if(mb==1) // boton izquierdo, sin tecla control, saleccionar objeto
	{	
		// seleccionar un objeto en la posicion que hacemos pulsacion del raton
		myContextGlobal->Activate(0); // Activate shape selection mode (mode 0)
		myContextGlobal->MoveTo (mx, my, myViewGlobal, false);
		// myContextGlobal->Select(mx,my,mx+v1,my+v2,myViewGlobal,true); // Rectangle selection
		myContextGlobal->Select(true); // Click selection
	}

	//myViewGlobal->StartRotation(mx, my); // punto de rotacion
	// control de eventos de raton
	if(mb==2) // boton izquierdo, rotaciones
	{
		myViewGlobal->StartRotation(0, 0); // punto de rotacion en el centro de la ventana
		myViewGlobal->Rotation(v1,v2);
	}
	
	if(mb==3) // boton derecho translaciones
	{
		//myViewGlobal->Place (0, 0, 1); // desde el centro (por ahora)
		myViewGlobal->Translate(v1,v2,0); // x,y,z=0
	}
	
	if(mb==4) // boton medio lupas
	{
		// myViewGlobal->Scale(v1,v2,0); // x,y,z=0
		myViewGlobal->Zoom(mx,my,v1,v2); 
	}

// gp_Trsf translationTransform;
// translationTransform.SetTranslation(gp_Vec(dx, dy, dz));
// myContextGlobal->SetLocation(aisShape, TopLoc_Location(translationTransform));


	// en caso de evento RESIZE desde windows
	if (modo==2)
	{
		  myViewGlobal->Window()->DoResize();
		  myViewGlobal->MustBeResized();
		  myViewGlobal->InvalidateImmediate();
	}
	
	// actualiza pantalla solo si se indica
	if (modo==1) myViewGlobal->FitAll (0.01, false);
	
	// por defecto redibuja
   myViewGlobal->Redraw();
	  
	return 1; // correcto
}

/*
// Example within a mouse wheel event
void wheelEvent(QWheelEvent *event) {
    QPoint p = event->pos();
    // 1. Initialize zoom at current mouse position
    myView->StartZoomAtPoint(p.x(), p.y());
    
    // 2. Calculate zoom factor based on wheel delta
    double delta = (double)(event->delta()) / (15 * 8);
    int x = p.x();
    int y = p.y();
    // Formula to calculate new zoom point based on delta
    int x1 = (int)(p.x() + width() * delta / 100);
    int y1 = (int)(p.y() + height() * delta / 100);
    
    // 3. Apply zoom
    myView->ZoomAtPoint(x, y, x1, y1);
    myView->Invalidate(); // Refresh the view
}
*/