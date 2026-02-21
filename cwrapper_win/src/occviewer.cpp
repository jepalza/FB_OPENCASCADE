// Joseba Epalza , 2026
// simple visualizador de objetos creados en tiempo real dentro de FreeBasic

#include <windows.h>

#include "occviewer.h"

// jepalza
#include <AIS_InteractiveContext.hxx> // control de objetos agregados, mover, rotar, ampliar, etc
#include <AIS_Shape.hxx> // control de objetos que van al visualizador
#include <AIS_ViewController.hxx> // eventos y control del visualizador

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
HWND FreeBasicWin;
Handle(AIS_InteractiveContext) myContextGlobal;
Handle(V3d_View) myViewGlobal;
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
	int dummy=0;
// jepalza: por el momento, no empleo las llamadas internas, se hace todo desde FreeBasic
/*
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
  */
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

// eventos graficos: modo=0 solo movimientos, modo=0(defecto) refresca pantalla, modo=2 cambia medidas de pantalla
int OCCViewer_Update(int modo=0)
{
	// en caso de evento RESIZE desde windows
	if (modo==2)
	{
		  myViewGlobal->Window()->DoResize();
		  myViewGlobal->MustBeResized();
		  myViewGlobal->InvalidateImmediate();
	}
	
	// centra la pantalla solo si se indica
	if (modo==1) myViewGlobal->FitAll (0.01, false);

	// por defecto redibuja
   myViewGlobal->Redraw();
	  
	return 1; // correcto
}

// añade figuras al visualizador
AISShape OCCViewer_Add(TopoDS_Shape MyShape, int mode)
{
	Handle(AIS_Shape) ToShape = new AIS_Shape(MyShape); // objeto interactivo desde figura (toposhape to AISshape)

	myContextGlobal->Display (ToShape, mode, 0, true);
	myContextGlobal->SetDisplayMode(ToShape,AIS_Shaded, true);

	// actualiza visualizador en modo "fit all" (ver todo, o autoajuste)
   OCCViewer_Update(1);

	return (long &)ToShape;
}

// convierte coordenadas 2D del raton a 3D en el espacio OCC
int OCCViewer_Mouse3D(int mx, int my, double* xc, double* yc, double* zc)
{
	Standard_Real xp,yp,zp;
	myViewGlobal->Convert(mx, my, xp, yp, zp);
	*xc=xp;
	*yc=yp;
	*zc=zp;
	return 1;
}

AISShape OCCViewer_Transform(AISShape MyAISShape, gp_Pnt *orig, gp_Pnt *dest) //double xp,double yp, double zp)
{
/*
		// seleccionar un objeto en la posicion que hacemos pulsacion del raton
		myContextGlobal->Activate(0); // Activate shape selection mode (mode 0)
		myContextGlobal->MoveTo (mx, my, myViewGlobal, true);
		myContextGlobal->Select(true); // Click selection

		//Handle(AIS_InteractiveObject) AIS_Selected_Shape = new AIS_Shape(ActualShape);
		//myContextGlobal->Select(mx,my,mx+v1,my+v2,myViewGlobal,true); // Rectangle selection
		//ActualShape = myContextGlobal->SelectedShape();
		//const TopoDS_Shape ActualShape ;//= myContextGlobal->SelectedShape();
		// TopoDS_Shape* retVal = new TopoDS_Shape(ActualShape);
		Handle(AIS_InteractiveObject) selected = myContextGlobal->SelectedInteractive();
		//printf("%d %d\n",&ActualShape,retVal);
		// modo: completa (0), vertices (1), bordes (2), caras (4)
		myContextGlobal->Activate(selected, 0, true);
		
		gp_Pnt oldPnt = gp_Pnt(0,0,0); // Previous mouse 3D position
      gp_Pnt newPnt = gp_Pnt(mx, my, 0); // Current mouse 3D position
		gp_Trsf aTrsf;
		aTrsf.SetTranslation(oldPnt, newPnt); // Translation example
		myContextGlobal->SetLocation(selected, aTrsf); // Move the shape
		// myContextGlobal->Redisplay(selected, Standard_True); // Refresh the view
		//TopoDS_Shape shape = Handle(AIS_Shape)::DownCast(selected)->Shape();
myContextGlobal->InitSelected();
// if (myContextGlobal->MoreSelected()) 
{
Handle(AIS_Shape) aisShape = Handle(AIS_Shape)::DownCast(selected); //myContextGlobal->SelectedInteractive()); 
		// Handle(AIS_Shape) aisShape = Handle(AIS_Shape)::DownCast(selected );
		TopoDS_Shape shape = aisShape->Shape();
		///OCCViewer_Add(shape,0);
		//MyShape=&ActualShape;
		//return ActualShape;
		// pp=&shape;
*/
	
	Handle(AIS_InteractiveObject) selected = MyAISShape;//myContextGlobal->SelectedInteractive();
	
// for (myContextGlobal->InitSelected(); myContextGlobal->MoreSelected(); myContextGlobal->NextSelected()) {
// Handle(SelectMgr_EntityOwner) anOwner = myContextGlobal->SelectedOwner();
// }

	myContextGlobal->Display(selected,Standard_False);
	// myContextGlobal->ResetLocation(selected);
	myContextGlobal->Activate(selected, 0, true);
	// printf("ori:%f %f %f\n",orig->X(),orig->Y(),orig->Z());	
	// printf("dst:%f %f %f\n",dest->X(),dest->Y(),dest->Z());
	gp_Pnt oldPnt = *orig;//gp_Pnt(xp1,yp1,zp1); // Previous mouse 3D position
   gp_Pnt newPnt = *dest;//gp_Pnt(xp, yp, zp); // Current mouse 3D position
	gp_Trsf aTrsf;
	aTrsf.SetTranslation(oldPnt, newPnt); // Translation example
	myContextGlobal->SetLocation(selected, aTrsf); // Move the shape
	myContextGlobal->Redisplay(selected, Standard_True); // update



		// myContextGlobal->Activate(0); // Activate shape selection mode (mode 0)
		// myContextGlobal->MoveTo (mx, my, myViewGlobal, true);
		// if (!myContextGlobal->Select(true)) {printf("11\n"); return NULL;} // Click selection
		if (myContextGlobal->HasDetected()) {
			// Handle(AIS_InteractiveObject) 
			selected = myContextGlobal->DetectedInteractive();
			return (long &)selected;
		}

	// printf("%d %d\n",pp,&retVal);
	
// gp_Trsf translationTransform;
// translationTransform.SetTranslation(gp_Vec(dx, dy, dz));
// myContextGlobal->SetLocation(aisShape, TopLoc_Location(translationTransform));
	//return MyShape;
	
	return NULL;
}

// eventos raton, posicion y seleccion de figura 
AISShape OCCViewer_Mouse(int mx=0, int my=0, int v1=0, int v2=0, int mb=0)
{
	//myViewGlobal->StartRotation(mx, my); // punto de rotacion
	
	// control de eventos de raton
	if(mb==2) // boton izquierdo, rotaciones
	{
		myViewGlobal->StartRotation(0, 0); // punto de rotacion en el centro de la ventana
		myViewGlobal->Rotation(v1,v2);
	}
	
	else if(mb==3) // boton derecho translaciones
	{
		//myViewGlobal->Place (0, 0, 1); // desde el centro (por ahora)
		myViewGlobal->Translate(v1,v2,0); // x,y,z=0
	}
	
	else if(mb==4) // boton medio lupas
	{
		// myViewGlobal->Scale(v1,v2,0); // x,y,z=0
		myViewGlobal->Zoom(mx,my,v1,v2); 
	}
	
	//else // por defecto, seleccion de figura al pasar el raton sobre ella
	if(mb==1) // boton izquierdo, sin tecla control, saleccionar objeto
	{	
		// seleccionar un objeto en la posicion que hacemos pulsacion del raton
		myContextGlobal->Activate(0); // Activate shape selection mode (mode 0)
		myContextGlobal->MoveTo (mx, my, myViewGlobal, true);
		// if (!myContextGlobal->Select(true)) {printf("11\n"); return NULL;} // Click selection
		if (myContextGlobal->HasDetected()) {
			Handle(AIS_InteractiveObject) selected = myContextGlobal->DetectedInteractive();
			return (long &)selected;
		}
		//TopoDS_Shape selected = myContextGlobal->SelectedShape();
		//if(selected.IsNull()) {printf("44\n"); return NULL;}; // si nada es seleccionado
	}	

	return NULL; // nada seleccionado
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