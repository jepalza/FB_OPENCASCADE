


#include <AIS_InteractiveContext.hxx>
#include <AIS_Shape.hxx>
#include <V3d_Viewer.hxx>
#include <V3d_View.hxx>
#include <WNT_Window.hxx>
#include <Prs3d_Drawer.hxx>
#include <Standard_ErrorHandler.hxx>
#include <BRepPrimAPI_MakeWedge.hxx>
#include <gp_Vec.hxx>
#include <gp_Trsf.hxx>
#include <gp_Circ.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Pln.hxx>
#include <gp_Elips.hxx>
#include <gp_Sphere.hxx>
#include <AIS_Axis.hxx>
#include <BRepBuilderAPI_Transform.hxx>
#include <AIS_Point.hxx>
#include <AIS_Plane.hxx>
#include <AIS_Line.hxx>
#include <GProp_GProps.hxx>
#include <AIS_ConnectedInteractive.hxx>
#include <Geom_CartesianPoint.hxx>
#include <Geom_BSplineSurface.hxx>
#include <Geom_Axis1Placement.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_RectangularTrimmedSurface.hxx>
#include <Geom_Line.hxx>
#include <Geom_Circle.hxx>
#include <Geom_Transformation.hxx>
#include <Geom_CylindricalSurface.hxx>
#include <Graphic3d_ArrayOfSegments.hxx>
#include <Graphic3d_Group.hxx>
#include <BRepBuilderAPI_GTransform.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeCone.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include <BRepPrimAPI_MakePrism.hxx>
#include <BRepPrimAPI_MakeTorus.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakePolygon.hxx>
#include <BRepBuilderAPI_MakeShell.hxx>
#include <BRepPrimAPI_MakeRevol.hxx>
#include <BRepOffsetAPI_MakePipe.hxx>
#include <BRepOffsetAPI_ThruSections.hxx>
#include <BRepOffsetAPI_MakeEvolved.hxx>
#include <BRepOffsetAPI_DraftAngle.hxx>
#include <BRepOffsetAPI_Sewing.hxx>
#include <BRepGProp.hxx>
#include <BRepAlgo.hxx>
#include <BRepAlgoAPI_Cut.hxx>
#include <BRepAlgoAPI_Fuse.hxx>
#include <BRepAlgoAPI_Common.hxx>
#include <BRepAlgoAPI_Section.hxx>
#include <BRepFilletAPI_MakeFillet.hxx>
#include <BRepFilletAPI_MakeChamfer.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TopOpeBRepTool.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TopExp.hxx>
#include <GCE2d_MakeLine.hxx>
#include <BRepLib.hxx>
#include <BRepFeat_MakePrism.hxx>
#include <BRepFeat_MakeDPrism.hxx>
#include <BRepFeat_MakeRevol.hxx>
#include <BRepFeat_Gluer.hxx>
#include <BRepFeat_MakePipe.hxx>
#include <BRepFeat_MakeLinearForm.hxx>
#include <BRepFeat_SplitShape.hxx>
#include <BRepOffsetAPI_MakeThickSolid.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom2d_Circle.hxx>
#include <Geom2d_Line.hxx>
#include <GeomAPI_PointsToBSplineSurface.hxx>
#include <GeomAPI_PointsToBSpline.hxx>
#include <Geom_BSplineCurve.hxx>
#include <GeomFill_BSplineCurves.hxx>
#include <LocOpe_FindEdges.hxx>
#include <TopoDS_Compound.hxx>
#include <TopoDS_Solid.hxx>
#include <GeomPlate_HArray1OfHCurve.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <GeomAdaptor_Surface.hxx>
#include <BRepAdaptor_Curve2d.hxx>
#include <GeomPlate_BuildPlateSurface.hxx>
#include <GeomPlate_MakeApprox.hxx>
#include <TopTools_Array1OfShape.hxx>
#include <TColGeom2d_HArray1OfCurve.hxx>
#include <BRepTopAdaptor_FClass2d.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <GeomPlate_BuildAveragePlane.hxx>
#include <Plate_PinpointConstraint.hxx>
#include <Plate_D1.hxx>
#include <Plate_GtoCConstraint.hxx>
#include <Prs3d_Arrow.hxx>
#include <Prs3d_LineAspect.hxx>
#include <GeomPlate_Surface.hxx>
#include <GeomProjLib.hxx>
#include <GCE2d_MakeSegment.hxx>
#include <Geom2d_TrimmedCurve.hxx>


#include <UnitsAPI.hxx>


// extras
#include <Adaptor3d_CurveOnSurface.hxx>
#include <AIS_ColoredShape.hxx>
#include <AIS_ListOfInteractive.hxx>
#include <AIS_ListIteratorOfListOfInteractive.hxx>
#include <TColStd_Array2OfReal.hxx>

#include <BRepPrimAPI_MakeCylinder.hxx>
#include <TopExp_Explorer.hxx>
#include <Geom_Plane.hxx>
#include <BRepTools.hxx>









static Handle(AIS_Shape) AIS1;
static TopoDS_Face THE_F1, THE_F2;
static TopoDS_Edge THE_E1, THE_E2;



/////////////////////////////////////////////////////////////////////////////
void MyDemo_OnMirror() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}
	TopoDS_Shape S = BRepPrimAPI_MakeWedge (60.,100.,80.,20.).Shape();
	Handle(AIS_Shape) ais1 = new AIS_Shape(S);
	// myContextGlobal->SetDisplayMode(ais1,AIS_Shaded, Standard_True); // no necesario aqui, lo hago de manera global
	myContextGlobal->SetColor(ais1,Quantity_NOC_GREEN,Standard_False);
	myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);
	myContextGlobal->Display(ais1,Standard_False);
	gp_Trsf theTransformation;
	gp_Pnt PntCenterOfTheTransformation(110,60,60);
	Handle(AIS_Point) aispnt = new AIS_Point(new Geom_CartesianPoint(PntCenterOfTheTransformation));
	myContextGlobal->Display(aispnt,Standard_False);
	theTransformation.SetMirror(PntCenterOfTheTransformation);
	BRepBuilderAPI_Transform myBRepTransformation(S,theTransformation);
	TopoDS_Shape S2 = myBRepTransformation.Shape();
	Handle(AIS_Shape) ais2 = new AIS_Shape(S2);
	// myContextGlobal->SetDisplayMode(ais2,AIS_Shaded, Standard_True); // no necesario aqui, lo hago de manera global
	myContextGlobal->SetColor(ais2,Quantity_NOC_BLUE1,Standard_False); 
	myContextGlobal->SetMaterial(ais2,Graphic3d_NOM_PLASTIC,Standard_False);   
	myContextGlobal->Display(ais2,Standard_False);
	OCCViewer_Update(1);

}

void MyDemo_OnMirroraxis() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}
	TopoDS_Shape S = BRepPrimAPI_MakeWedge(60.,100.,80.,20.).Shape(); 
	Handle(AIS_Shape) ais1 = new AIS_Shape(S);
	myContextGlobal->SetColor(ais1,Quantity_NOC_GREEN,Standard_False); 
	myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);   
	myContextGlobal->Display(ais1,Standard_False);
	gp_Trsf theTransformation;
	gp_Ax1 axe = gp_Ax1(gp_Pnt(110,60,60),gp_Dir(0.,1.,0.));
	Handle(Geom_Axis1Placement) Gax1 = new Geom_Axis1Placement(axe);
	Handle (AIS_Axis) ax1 = new AIS_Axis(Gax1);
	myContextGlobal->Display(ax1,Standard_False);
	theTransformation.SetMirror(axe);
	BRepBuilderAPI_Transform myBRepTransformation(S,theTransformation);
	TopoDS_Shape S2 = myBRepTransformation.Shape();
	Handle(AIS_Shape) ais2 = new AIS_Shape(S2);
	myContextGlobal->SetColor(ais2,Quantity_NOC_BLUE1,Standard_False); 
	myContextGlobal->SetMaterial(ais2,Graphic3d_NOM_PLASTIC,Standard_False);   
	myContextGlobal->Display(ais2,Standard_False);
	OCCViewer_Update(1);

}


void MyDemo_OnRotate() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}
	TopoDS_Shape S = BRepPrimAPI_MakeWedge(60.,100.,80.,20.).Shape(); 
	Handle(AIS_Shape) ais1 = new AIS_Shape(S);
	myContextGlobal->SetColor(ais1,Quantity_NOC_GREEN,Standard_False); 
	myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);   
	myContextGlobal->Display(ais1,Standard_False);
	gp_Trsf theTransformation;
	gp_Ax1 axe = gp_Ax1(gp_Pnt(200,60,60),gp_Dir(0.,1.,0.));
	Handle(Geom_Axis1Placement) Gax1 = new Geom_Axis1Placement(axe);
	Handle (AIS_Axis) ax1 = new AIS_Axis(Gax1);
	myContextGlobal->Display(ax1,Standard_False);
	theTransformation.SetRotation(axe,30*M_PI/180);
	BRepBuilderAPI_Transform myBRepTransformation(S,theTransformation);
	TopoDS_Shape S2 = myBRepTransformation.Shape();
	Handle(AIS_Shape) ais2 = new AIS_Shape(S2);
	myContextGlobal->SetColor(ais2,Quantity_NOC_BLUE1,Standard_False); 
	myContextGlobal->SetMaterial(ais2,Graphic3d_NOM_PLASTIC,Standard_False);   
	myContextGlobal->Display(ais2,Standard_False);
	OCCViewer_Update(1);

}

void MyDemo_OnScale() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}
	TopoDS_Shape S = BRepPrimAPI_MakeWedge(60.,100.,80.,20.).Shape(); 
	Handle(AIS_Shape) ais1 = new AIS_Shape(S);
	myContextGlobal->SetColor(ais1,Quantity_NOC_GREEN,Standard_False); 
	myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);   
	myContextGlobal->Display(ais1,Standard_False);
	gp_Trsf theTransformation;
	gp_Pnt theCenterOfScale(200,60,60);
	Handle(AIS_Point) aispnt = new AIS_Point(new Geom_CartesianPoint(theCenterOfScale));

	myContextGlobal->Display(aispnt,Standard_False);
	theTransformation.SetScale(theCenterOfScale,0.5);
	BRepBuilderAPI_Transform myBRepTransformation(S,theTransformation);
	TopoDS_Shape S2 = myBRepTransformation.Shape();

	Handle(AIS_Shape) ais2 = new AIS_Shape(S2);
	myContextGlobal->SetColor(ais2,Quantity_NOC_BLUE1,Standard_False); 
	myContextGlobal->SetMaterial(ais2,Graphic3d_NOM_PLASTIC,Standard_False);   
	myContextGlobal->Display(ais2,Standard_False);
	OCCViewer_Update(1);

}



void MyDemo_OnTranslation() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}
	TopoDS_Shape S = BRepPrimAPI_MakeWedge(6.,10.,8.,2.).Shape(); 
	Handle(AIS_Shape) ais1 = new AIS_Shape(S);
	myContextGlobal->SetColor(ais1,Quantity_NOC_GREEN,Standard_False); 
	myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);
	myContextGlobal->Display(ais1,Standard_False);
	gp_Trsf theTransformation;
	gp_Vec theVectorOfTranslation(-6,-6,6);

	// Handle(ISession_Direction) aDirection1 = new ISession_Direction(gp_Pnt(0,0,0),theVectorOfTranslation);
	// myContextGlobal->Display(aDirection1,Standard_False);

	theTransformation.SetTranslation(theVectorOfTranslation);
	BRepBuilderAPI_Transform myBRepTransformation(S,theTransformation);
	TopoDS_Shape S2 = myBRepTransformation.Shape();

	Handle(AIS_Shape) ais2 = new AIS_Shape(S2);
	myContextGlobal->SetColor(ais2,Quantity_NOC_BLUE1,Standard_False); 
	myContextGlobal->SetMaterial(ais2,Graphic3d_NOM_PLASTIC,Standard_False);   
	myContextGlobal->Display(ais2,Standard_False);

	OCCViewer_Update(1);

}

void MyDemo_OnDisplacement() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}
  TopoDS_Shape S = BRepPrimAPI_MakeWedge(60., 100., 80., 20.).Shape();
	Handle(AIS_Shape) ais1 = new AIS_Shape(S);
	myContextGlobal->SetColor(ais1,Quantity_NOC_GREEN,Standard_False); 
	myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);   
	myContextGlobal->Display(ais1,Standard_False);
	gp_Trsf theTransformation;

	gp_Ax3 ax3_1(gp_Pnt(0,0,0),gp_Dir(0,0,1));
	gp_Ax3 ax3_2(gp_Pnt(60,60,60),gp_Dir(1,1,1));

	theTransformation.SetDisplacement(ax3_1,ax3_2);
	BRepBuilderAPI_Transform myBRepTransformation(S,theTransformation);
	TopoDS_Shape TransformedShape = myBRepTransformation.Shape();
	Handle(AIS_Shape) ais2 = new AIS_Shape(TransformedShape);
	myContextGlobal->SetColor(ais2,Quantity_NOC_BLUE1,Standard_False); 
	myContextGlobal->SetMaterial(ais2,Graphic3d_NOM_PLASTIC,Standard_False);   
	myContextGlobal->Display(ais2,Standard_False);
	OCCViewer_Update(1);

}


void MyDemo_OnDeform() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}
   TopoDS_Shape S = BRepPrimAPI_MakeWedge(60., 100., 80., 20.).Shape();
	Handle(AIS_Shape) ais1 = new AIS_Shape(S);
	myContextGlobal->SetColor(ais1,Quantity_NOC_GREEN,Standard_False); 
	myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);   

	gp_Mat rot(1., 0., 0.,    0., 0.5, 0.,   0., 0., 1.5);
	
	gp_GTrsf theTransformation;
	theTransformation.SetVectorialPart(rot);
	theTransformation.SetTranslationPart(gp_XYZ(5.,5.,5.));

	BRepBuilderAPI_GTransform myBRepTransformation(S,theTransformation);
	TopoDS_Shape S2 = myBRepTransformation.Shape();

	Handle(AIS_Shape) ais2 = new AIS_Shape(S2);
	myContextGlobal->SetColor(ais2,Quantity_NOC_BLUE1,Standard_False); 
	myContextGlobal->SetMaterial(ais2,Graphic3d_NOM_PLASTIC,Standard_False);   

	// figura original
	myContextGlobal->Display(ais1,Standard_False);
	OCCViewer_Update(1);
	Sleep(1000);
	// resultado del escalado
	myContextGlobal->Display(ais2,Standard_False);
	OCCViewer_Update(1);

}

/* =================================================================================
   ====================   P R I M I T I V E S   ====================================
   ================================================================================= */

void MyDemo_OnBox() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}
  TopoDS_Shape B1 = BRepPrimAPI_MakeBox(200., 150., 100.).Shape();
	Handle(AIS_Shape) aBox1 = new AIS_Shape(B1);
	myContextGlobal->SetMaterial(aBox1,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->SetColor(aBox1,Quantity_NOC_GREEN,Standard_False); 
	myContextGlobal->Display(aBox1,Standard_False);
	TopoDS_Shape B2 = BRepPrimAPI_MakeBox (gp_Ax2(gp_Pnt(-200.,-80.,-70.),
                                         gp_Dir(1.,2.,1.)),
                                         80., 90., 120.).Shape();
	Handle(AIS_Shape) aBox2 = new AIS_Shape(B2);
	myContextGlobal->SetMaterial(aBox2,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->SetColor(aBox2,Quantity_NOC_RED,Standard_False); 
	myContextGlobal->Display(aBox2,Standard_False);
	OCCViewer_Update(1);

}

void MyDemo_OnCylinder() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

  TopoDS_Shape C1 = BRepPrimAPI_MakeCylinder(50., 200.).Shape();
	Handle(AIS_Shape) aCyl1 = new AIS_Shape(C1);
	myContextGlobal->SetMaterial(aCyl1,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->SetColor(aCyl1,Quantity_NOC_RED,Standard_False); 
	myContextGlobal->Display(aCyl1,Standard_False);
	TopoDS_Shape C2 = BRepPrimAPI_MakeCylinder (gp_Ax2(gp_Pnt(200.,200.,0.),
												                      gp_Dir(0.,0.,1.)),
                                              40., 110., 210.*M_PI / 180).Shape();
	Handle(AIS_Shape) aCyl2 = new AIS_Shape(C2);
	myContextGlobal->SetMaterial(aCyl2,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->SetColor(aCyl2,Quantity_NOC_MATRABLUE,Standard_False); 	
	myContextGlobal->Display(aCyl2,Standard_False);
	OCCViewer_Update(1);

}


void MyDemo_OnCone() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}
  TopoDS_Shape C1 = BRepPrimAPI_MakeCone(50., 25., 200.).Shape();
	Handle(AIS_Shape) ais1 = new AIS_Shape(C1);
	myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->SetColor(ais1,Quantity_NOC_MATRABLUE,Standard_False); 		
	myContextGlobal->Display(ais1,Standard_False);
	TopoDS_Shape C2 = BRepPrimAPI_MakeCone(gp_Ax2(gp_Pnt(100.,100.,0.),
												                 gp_Dir(0.,0.,1.)),
                                         60., 0., 150., 210.*M_PI / 180).Shape();
	Handle(AIS_Shape) ais2 = new AIS_Shape(C2);
	myContextGlobal->SetMaterial(ais2,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->SetColor(ais2,Quantity_NOC_GREEN,Standard_False); 
	myContextGlobal->Display(ais2,Standard_False);
	OCCViewer_Update(1);

}

void MyDemo_OnSphere() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

  TopoDS_Shape S1 = BRepPrimAPI_MakeSphere(gp_Pnt(-200., -250., 0.), 80.).Shape();
	Handle(AIS_Shape) ais1 = new AIS_Shape(S1);
	myContextGlobal->SetColor(ais1,Quantity_NOC_AZURE,Standard_False); 
	myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->Display(ais1,Standard_False);
  TopoDS_Shape S2 = BRepPrimAPI_MakeSphere(100., 120.*M_PI / 180).Shape();
	Handle(AIS_Shape) ais2 = new AIS_Shape(S2);
	myContextGlobal->SetColor(ais2,Quantity_NOC_GREEN,Standard_False); 
	myContextGlobal->SetMaterial(ais2,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->Display(ais2,Standard_False);
	TopoDS_Shape S3 = BRepPrimAPI_MakeSphere(gp_Pnt(200.,250.,0.),100.,
                                           -60.*M_PI / 180, 60.*M_PI / 180).Shape();
	Handle(AIS_Shape) ais3 = new AIS_Shape(S3);
	myContextGlobal->SetColor(ais3,Quantity_NOC_RED,Standard_False); 
	myContextGlobal->SetMaterial(ais3,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->Display(ais3,Standard_False);
	TopoDS_Shape S4 = BRepPrimAPI_MakeSphere(gp_Pnt(0.,0.,-300.),150.,
                                           -45.*M_PI / 180, 45.*M_PI / 180, 45.*M_PI / 180).Shape();
	Handle(AIS_Shape) ais4 = new AIS_Shape(S4);
	myContextGlobal->SetColor(ais4,Quantity_NOC_MATRABLUE,Standard_False); 
	myContextGlobal->SetMaterial(ais4,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->Display(ais4,Standard_False);
	OCCViewer_Update(1);

}

void MyDemo_OnTorus() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

  TopoDS_Shape S1 = BRepPrimAPI_MakeTorus(60., 20.).Shape();
	Handle(AIS_Shape) ais1 = new AIS_Shape(S1);
	myContextGlobal->SetColor(ais1,Quantity_NOC_AZURE,Standard_False); 
	myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->Display(ais1,Standard_False);
	TopoDS_Shape S2 = BRepPrimAPI_MakeTorus(gp_Ax2(gp_Pnt(100.,100.,0.),gp_Dir(1.,1.,1.)),
                                          50., 20., 210.*M_PI / 180).Shape();
	Handle(AIS_Shape) ais2 = new AIS_Shape(S2);
	myContextGlobal->SetColor(ais2,Quantity_NOC_GREEN,Standard_False); 
	myContextGlobal->SetMaterial(ais2,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->Display(ais2,Standard_False);
	TopoDS_Shape S3 = BRepPrimAPI_MakeTorus(gp_Ax2(gp_Pnt(-200.,-150.,-100),gp_Dir(0.,1.,0.)),
                                          60., 20., -45.*M_PI / 180, 45.*M_PI / 180, 90.*M_PI / 180).Shape();
	Handle(AIS_Shape) ais3= new AIS_Shape(S3);
	myContextGlobal->SetColor(ais3,Quantity_NOC_CORAL,Standard_False); 
	myContextGlobal->SetMaterial(ais3,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->Display(ais3,Standard_False);
	OCCViewer_Update(1);

}

void MyDemo_OnWedge() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

  TopoDS_Shape S1 = BRepPrimAPI_MakeWedge(60., 100., 80., 20.).Shape();
	Handle(AIS_Shape) ais1 = new AIS_Shape(S1);
	myContextGlobal->SetColor(ais1,Quantity_NOC_AZURE,Standard_False); 
	myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->Display(ais1,Standard_False);
	TopoDS_Shape S2 = BRepPrimAPI_MakeWedge(gp_Ax2(gp_Pnt(100.,100.,0.),gp_Dir(0.,0.,1.)),
                                          60., 50., 80., 25., -10., 40., 70.).Shape();
	Handle(AIS_Shape) ais2 = new AIS_Shape(S2);
	myContextGlobal->SetColor(ais2,Quantity_NOC_CORAL2,Standard_False); 
	myContextGlobal->SetMaterial(ais2,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->Display(ais2,Standard_False);
	OCCViewer_Update(1);

}

void MyDemo_OnPrism() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

	TopoDS_Vertex V1 = BRepBuilderAPI_MakeVertex(gp_Pnt(-200.,-200.,0.));
	Handle(AIS_Shape) ais1 = new AIS_Shape(V1);
	myContextGlobal->Display(ais1,Standard_False);
	TopoDS_Shape S1 = BRepPrimAPI_MakePrism(V1,gp_Vec(0.,0.,100.));
	Handle(AIS_Shape) ais2 = new AIS_Shape(S1);
	myContextGlobal->Display(ais2,Standard_False);

	TopoDS_Edge E = BRepBuilderAPI_MakeEdge(gp_Pnt(-150.,-150,0.), gp_Pnt(-50.,-50,0.));
	Handle(AIS_Shape) ais3 = new AIS_Shape(E);
	myContextGlobal->Display(ais3,Standard_False);
	TopoDS_Shape S2 = BRepPrimAPI_MakePrism(E,gp_Vec(0.,0.,100.));
	Handle(AIS_Shape) ais4 = new AIS_Shape(S2);
	myContextGlobal->SetColor(ais4,Quantity_NOC_CORAL2,Standard_False); 
	myContextGlobal->SetMaterial(ais4,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->Display(ais4,Standard_False);

	TopoDS_Edge E1 = BRepBuilderAPI_MakeEdge(gp_Pnt(0.,0.,0.), gp_Pnt(50.,0.,0.));
	TopoDS_Edge E2 = BRepBuilderAPI_MakeEdge(gp_Pnt(50.,0.,0.), gp_Pnt(50.,50.,0.));
	TopoDS_Edge E3 = BRepBuilderAPI_MakeEdge(gp_Pnt(50.,50.,0.), gp_Pnt(0.,0.,0.));
	TopoDS_Wire W = BRepBuilderAPI_MakeWire(E1,E2,E3);
	TopoDS_Shape S3 = BRepPrimAPI_MakePrism(W,gp_Vec(0.,0.,100.));
	Handle(AIS_Shape) ais5 = new AIS_Shape(W);
	myContextGlobal->Display(ais5,Standard_False);
	Handle(AIS_Shape) ais6 = new AIS_Shape(S3);
	myContextGlobal->SetColor(ais6,Quantity_NOC_GREEN,Standard_False); 
	myContextGlobal->SetMaterial(ais6,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->Display(ais6,Standard_False);

	gp_Circ c = gp_Circ(gp_Ax2(gp_Pnt(200.,200.,0.),gp_Dir(0.,0.,1.)), 80.);
	TopoDS_Edge Ec = BRepBuilderAPI_MakeEdge(c);
	TopoDS_Wire Wc = BRepBuilderAPI_MakeWire(Ec);
	TopoDS_Face F = BRepBuilderAPI_MakeFace(gp_Pln(gp::XOY()),Wc);
	Handle(AIS_Shape) ais7 = new AIS_Shape(F);
	myContextGlobal->Display(ais7,Standard_False);
	TopoDS_Shape S4 = BRepPrimAPI_MakePrism(F,gp_Vec(0.,0.,100.));
	Handle(AIS_Shape) ais8 = new AIS_Shape(S4);
	myContextGlobal->SetColor(ais8,Quantity_NOC_MATRABLUE,Standard_False); 
	myContextGlobal->SetMaterial(ais8,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->Display(ais8,Standard_False);
	OCCViewer_Update(1);
}

void MyDemo_OnRevol() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

	TopoDS_Vertex V1 = BRepBuilderAPI_MakeVertex(gp_Pnt(-200.,-200.,0.));
	Handle(AIS_Shape) ais1 = new AIS_Shape(V1);
	myContextGlobal->Display(ais1,Standard_False);
	gp_Ax1 axe = gp_Ax1(gp_Pnt(-170.,-170.,0.),gp_Dir(0.,0.,1.));
	Handle(Geom_Axis1Placement) Gax1 = new Geom_Axis1Placement(axe);
	Handle (AIS_Axis) ax1 = new AIS_Axis(Gax1);
	myContextGlobal->Display(ax1,Standard_False);
	TopoDS_Shape S1 = BRepPrimAPI_MakeRevol(V1,axe);
	Handle(AIS_Shape) ais2 = new AIS_Shape(S1);
	myContextGlobal->Display(ais2,Standard_False);

	TopoDS_Edge E = BRepBuilderAPI_MakeEdge(gp_Pnt(-120.,-120,0.), gp_Pnt(-120.,-120,100.));
	Handle(AIS_Shape) ais3 = new AIS_Shape(E);
	myContextGlobal->Display(ais3,Standard_False);
	axe = gp_Ax1(gp_Pnt(-100.,-100.,0.),gp_Dir(0.,0.,1.));
	Handle(Geom_Axis1Placement) Gax2 = new Geom_Axis1Placement(axe);
	Handle (AIS_Axis) ax2 = new AIS_Axis(Gax2);
	myContextGlobal->Display(ax2,Standard_False);
	TopoDS_Shape S2 = BRepPrimAPI_MakeRevol(E,axe);
	Handle(AIS_Shape) ais4 = new AIS_Shape(S2);
	myContextGlobal->SetColor(ais4,Quantity_NOC_YELLOW,Standard_False); 
	myContextGlobal->SetMaterial(ais4,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->Display(ais4,Standard_False);

	TopoDS_Edge E1 = BRepBuilderAPI_MakeEdge(gp_Pnt(0.,0.,0.), gp_Pnt(50.,0.,0.));
	TopoDS_Edge E2 = BRepBuilderAPI_MakeEdge(gp_Pnt(50.,0.,0.), gp_Pnt(50.,50.,0.));
	TopoDS_Edge E3 = BRepBuilderAPI_MakeEdge(gp_Pnt(50.,50.,0.), gp_Pnt(0.,0.,0.));
	TopoDS_Wire W = BRepBuilderAPI_MakeWire(E1,E2,E3);
	axe = gp_Ax1(gp_Pnt(0.,0.,30.),gp_Dir(0.,1.,0.));
	Handle(Geom_Axis1Placement) Gax3 = new Geom_Axis1Placement(axe);
	Handle (AIS_Axis) ax3 = new AIS_Axis(Gax3);
	myContextGlobal->Display(ax3,Standard_False);
	TopoDS_Shape S3 = BRepPrimAPI_MakeRevol(W,axe, 210.*M_PI/180);
	Handle(AIS_Shape) ais5 = new AIS_Shape(W);
	myContextGlobal->Display(ais5,Standard_False);
	Handle(AIS_Shape) ais6 = new AIS_Shape(S3);
	myContextGlobal->SetColor(ais6,Quantity_NOC_GREEN,Standard_False); 
	myContextGlobal->SetMaterial(ais6,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->Display(ais6,Standard_False);

	gp_Circ c = gp_Circ(gp_Ax2(gp_Pnt(200.,200.,0.),gp_Dir(0.,0.,1.)), 80.);
	TopoDS_Edge Ec = BRepBuilderAPI_MakeEdge(c);
	TopoDS_Wire Wc = BRepBuilderAPI_MakeWire(Ec);
	TopoDS_Face F = BRepBuilderAPI_MakeFace(gp_Pln(gp::XOY()),Wc);
	axe = gp_Ax1(gp_Pnt(290,290.,0.),gp_Dir(0.,1,0.));
	Handle(Geom_Axis1Placement) Gax4 = new Geom_Axis1Placement(axe);
	Handle (AIS_Axis) ax4 = new AIS_Axis(Gax4);
	myContextGlobal->Display(ax4,Standard_False);
	TopoDS_Shape S4 = BRepPrimAPI_MakeRevol(F,axe, 90.*M_PI/180);
	Handle(AIS_Shape) ais8 = new AIS_Shape(S4);
	myContextGlobal->SetColor(ais8,Quantity_NOC_MATRABLUE,Standard_False); 
	myContextGlobal->SetMaterial(ais8,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->Display(ais8,Standard_False);
	OCCViewer_Update(1);
}

void MyDemo_OnPipe() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

	TColgp_Array1OfPnt CurvePoles(1,4);
	gp_Pnt pt = gp_Pnt(0.,0.,0.);
	CurvePoles(1) = pt;
	pt = gp_Pnt(20.,50.,0.);
	CurvePoles(2) = pt;
	pt = gp_Pnt(60.,100.,0.);
	CurvePoles(3) = pt;
	pt = gp_Pnt(150.,0.,0.);
	CurvePoles(4) = pt;
	Handle(Geom_BezierCurve) curve = new Geom_BezierCurve(CurvePoles);
	TopoDS_Edge E = BRepBuilderAPI_MakeEdge(curve);
	TopoDS_Wire W = BRepBuilderAPI_MakeWire(E);
	Handle(AIS_Shape) ais1 = new AIS_Shape(W);
	myContextGlobal->Display(ais1,Standard_False);
	OCCViewer_Update(1);
	Sleep(500);
	gp_Circ c = gp_Circ(gp_Ax2(gp_Pnt(0.,0.,0.),gp_Dir(0.,1.,0.)),10.);
	TopoDS_Edge Ec = BRepBuilderAPI_MakeEdge(c);
	TopoDS_Wire Wc = BRepBuilderAPI_MakeWire(Ec);
	Handle(AIS_Shape) ais3 = new AIS_Shape(Wc);
	myContextGlobal->Display(ais3,Standard_False);
	TopoDS_Face F = BRepBuilderAPI_MakeFace(gp_Pln(gp::ZOX()),Wc);
	TopoDS_Shape S = BRepOffsetAPI_MakePipe(W,F);
	Handle(AIS_Shape) ais2 = new AIS_Shape(S);
	myContextGlobal->SetColor(ais2,Quantity_NOC_MATRABLUE,Standard_False); 
	myContextGlobal->SetMaterial(ais2,Graphic3d_NOM_PLASTIC,Standard_False);   
	myContextGlobal->Display(ais2,Standard_False);
	OCCViewer_Update(1);


}

void MyDemo_OnThru() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

	gp_Circ c1 = gp_Circ(gp_Ax2(gp_Pnt(-100.,0.,-100.),gp_Dir(0.,0.,1.)),40.);
	TopoDS_Edge E1 = BRepBuilderAPI_MakeEdge(c1);
	TopoDS_Wire W1 = BRepBuilderAPI_MakeWire(E1);
	Handle(AIS_Shape) sec1 = new AIS_Shape(W1);
	myContextGlobal->Display(sec1,Standard_False);
	gp_Circ c2 = gp_Circ(gp_Ax2(gp_Pnt(-10.,0.,-0.),gp_Dir(0.,0.,1.)),40.);
	TopoDS_Edge E2 = BRepBuilderAPI_MakeEdge(c2);
	TopoDS_Wire W2 = BRepBuilderAPI_MakeWire(E2);
	Handle(AIS_Shape) sec2 = new AIS_Shape(W2);
	myContextGlobal->Display(sec2,Standard_False);	
	gp_Circ c3 = gp_Circ(gp_Ax2(gp_Pnt(-75.,0.,100.),gp_Dir(0.,0.,1.)),40.);
	TopoDS_Edge E3 = BRepBuilderAPI_MakeEdge(c3);
	TopoDS_Wire W3 = BRepBuilderAPI_MakeWire(E3);
	Handle(AIS_Shape) sec3 = new AIS_Shape(W3);
	myContextGlobal->Display(sec3,Standard_False);
	gp_Circ c4= gp_Circ(gp_Ax2(gp_Pnt(0.,0.,200.),gp_Dir(0.,0.,1.)),40.);
	TopoDS_Edge E4 = BRepBuilderAPI_MakeEdge(c4);
	TopoDS_Wire W4 = BRepBuilderAPI_MakeWire(E4);
	Handle(AIS_Shape) sec4 = new AIS_Shape(W4);
	myContextGlobal->Display(sec4,Standard_False);
	BRepOffsetAPI_ThruSections generator(Standard_False,Standard_True);
	generator.AddWire(W1);
	generator.AddWire(W2);
	generator.AddWire(W3);
	generator.AddWire(W4);
	generator.Build();
	TopoDS_Shape S1 = generator.Shape();
	Handle(AIS_Shape) ais1 = new AIS_Shape(S1);
	myContextGlobal->SetColor(ais1,Quantity_NOC_MATRABLUE,Standard_False); 
	myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);   
	myContextGlobal->Display(ais1,Standard_False);

	gp_Circ c1b = gp_Circ(gp_Ax2(gp_Pnt(100.,0.,-100.),gp_Dir(0.,0.,1.)),40.);
	TopoDS_Edge E1b = BRepBuilderAPI_MakeEdge(c1b);
	TopoDS_Wire W1b = BRepBuilderAPI_MakeWire(E1b);
	Handle(AIS_Shape) sec1b = new AIS_Shape(W1b);
	myContextGlobal->Display(sec1b,Standard_False);
	gp_Circ c2b = gp_Circ(gp_Ax2(gp_Pnt(210.,0.,-0.),gp_Dir(0.,0.,1.)),40.);
	TopoDS_Edge E2b = BRepBuilderAPI_MakeEdge(c2b);
	TopoDS_Wire W2b = BRepBuilderAPI_MakeWire(E2b);
	Handle(AIS_Shape) sec2b = new AIS_Shape(W2b);
	myContextGlobal->Display(sec2b,Standard_False);	
	gp_Circ c3b = gp_Circ(gp_Ax2(gp_Pnt(275.,0.,100.),gp_Dir(0.,0.,1.)),40.);
	TopoDS_Edge E3b = BRepBuilderAPI_MakeEdge(c3b);
	TopoDS_Wire W3b = BRepBuilderAPI_MakeWire(E3b);
	Handle(AIS_Shape) sec3b = new AIS_Shape(W3b);
	myContextGlobal->Display(sec3b,Standard_False);
	gp_Circ c4b= gp_Circ(gp_Ax2(gp_Pnt(200.,0.,200.),gp_Dir(0.,0.,1.)),40.);
	TopoDS_Edge E4b = BRepBuilderAPI_MakeEdge(c4b);
	TopoDS_Wire W4b = BRepBuilderAPI_MakeWire(E4b);
	Handle(AIS_Shape) sec4b = new AIS_Shape(W4b);
	myContextGlobal->Display(sec4b,Standard_False);
	BRepOffsetAPI_ThruSections generatorb(Standard_True,Standard_False);
	generatorb.AddWire(W1b);
	generatorb.AddWire(W2b);
	generatorb.AddWire(W3b);
	generatorb.AddWire(W4b);
	generatorb.Build();
	TopoDS_Shape S2 = generatorb.Shape();
	Handle(AIS_Shape) ais2 = new AIS_Shape(S2);
	myContextGlobal->SetColor(ais2,Quantity_NOC_ALICEBLUE,Standard_False); 
	myContextGlobal->SetMaterial(ais2,Graphic3d_NOM_PLASTIC,Standard_False);   
	myContextGlobal->Display(ais2,Standard_False);
	OCCViewer_Update(1);
}

void MyDemo_OnEvolved() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

	BRepBuilderAPI_MakePolygon P;
	P.Add(gp_Pnt(0.,0.,0.));
	P.Add(gp_Pnt(200.,0.,0.));
	P.Add(gp_Pnt(200.,200.,0.));
	P.Add(gp_Pnt(0.,200.,0.));
	P.Add(gp_Pnt(0.,0.,0.));
	TopoDS_Wire W = P.Wire();
	
	Handle(AIS_Shape) ais1 = new AIS_Shape(W);
	myContextGlobal->Display(ais1,Standard_False);
	
	TopoDS_Wire wprof = BRepBuilderAPI_MakePolygon(gp_Pnt(0.,0.,0.),gp_Pnt(-60.,-60.,-200.));
	
	Handle(AIS_Shape) ais3 = new AIS_Shape(wprof);
	myContextGlobal->Display(ais3,Standard_False);
	OCCViewer_Update(1);
	Sleep(500);
	TopoDS_Shape S = BRepOffsetAPI_MakeEvolved(W,wprof,GeomAbs_Arc,Standard_True,Standard_False,Standard_True,0.0001);
	
	Handle(AIS_Shape) ais2 = new AIS_Shape(S);
	myContextGlobal->SetColor(ais2,Quantity_NOC_MATRABLUE,Standard_False); 
	myContextGlobal->SetMaterial(ais2,Graphic3d_NOM_PLASTIC,Standard_False);   
	myContextGlobal->Display(ais2,Standard_False);
	OCCViewer_Update(1);

}

void MyDemo_OnDraft() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

  TopoDS_Shape S = BRepPrimAPI_MakeBox(200., 300., 150.).Shape();
	Handle(AIS_Shape) ais1 = new AIS_Shape(S);
	myContextGlobal->SetColor(ais1,Quantity_NOC_GREEN,Standard_False); 
	myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);   
	myContextGlobal->Display(ais1,Standard_False);
	OCCViewer_Update(1);
	Sleep(500);
	BRepOffsetAPI_DraftAngle adraft(S);
	TopExp_Explorer Ex;
	for (Ex.Init(S,TopAbs_FACE); Ex.More(); Ex.Next()) {
		TopoDS_Face F = TopoDS::Face(Ex.Current());
		Handle(Geom_Plane) surf = Handle(Geom_Plane)::DownCast(BRep_Tool::Surface(F));
		gp_Pln apln = surf->Pln();
		gp_Dir dirF = apln.Axis().Direction();
		if (dirF.IsNormal(gp_Dir(0.,0.,1.),Precision::Angular()))
			adraft.Add(F, gp_Dir(0.,0.,1.), 15.*M_PI/180, gp_Pln(gp::XOY()));
	}
	ais1->Set(adraft.Shape());
	myContextGlobal->Redisplay(ais1,Standard_False);
	OCCViewer_Update(1);

}

/* =================================================================================
   ====================   O P E R A T I O N S   ====================================
   ================================================================================= */

void MyDemo_OnCut() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

  TopoDS_Shape theBox = BRepPrimAPI_MakeBox(200, 60, 60).Shape();

Handle (AIS_Shape)	ais1 = new AIS_Shape(theBox);
myContextGlobal->SetDisplayMode(ais1,1,Standard_False);
myContextGlobal->SetColor(ais1,Quantity_NOC_GREEN,Standard_False);
myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);
myContextGlobal->Display(ais1,Standard_False);
const Handle(AIS_InteractiveObject)& anIO1 = ais1;
myContextGlobal->SetSelected (anIO1, Standard_False);
OCCViewer_Update(1);
Sleep(1000);


TopoDS_Shape theSphere = BRepPrimAPI_MakeSphere(gp_Pnt(100, 20, 20), 80).Shape();
Handle (AIS_Shape)	ais2 = new AIS_Shape(theSphere);
myContextGlobal->SetDisplayMode(ais2,1,Standard_False);
myContextGlobal->SetColor(ais2,Quantity_NOC_YELLOW,Standard_False);
myContextGlobal->SetMaterial(ais2,Graphic3d_NOM_PLASTIC,Standard_False);
myContextGlobal->Display(ais2,Standard_False);
const Handle(AIS_InteractiveObject)& anIO2 = ais2;
myContextGlobal->SetSelected (anIO2, Standard_False);
OCCViewer_Update(1);
Sleep(1000);

TopoDS_Shape ShapeCut = BRepAlgoAPI_Cut(theSphere,theBox);

myContextGlobal->Erase(ais1,Standard_False);
myContextGlobal->Erase(ais2,Standard_False);

Handle (AIS_Shape)	aSection = new AIS_Shape(ShapeCut);
myContextGlobal->SetDisplayMode(aSection,1,Standard_False);
myContextGlobal->SetColor(aSection,Quantity_NOC_RED,Standard_False);
myContextGlobal->SetMaterial(aSection,Graphic3d_NOM_PLASTIC,Standard_False);
myContextGlobal->Display(aSection,Standard_False);
const Handle(AIS_InteractiveObject)& anIOSection = aSection;
myContextGlobal->SetSelected (anIOSection, Standard_False);
OCCViewer_Update(1);

}










void MyDemo_OnFuse() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

gp_Pnt P(-5,5,-5);
TopoDS_Shape theBox1 = BRepPrimAPI_MakeBox(60, 200, 70).Shape();
Handle (AIS_Shape)	ais1 = new AIS_Shape(theBox1);
myContextGlobal->SetColor(ais1,Quantity_NOC_GREEN,Standard_False);
myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);
myContextGlobal->Display(ais1,Standard_False);
const Handle(AIS_InteractiveObject)& anIO1 = ais1;
myContextGlobal->SetSelected (anIO1, Standard_False);
OCCViewer_Update(1);
Sleep(1000);

TopoDS_Shape theBox2 = BRepPrimAPI_MakeBox(P, 20, 150, 110).Shape();
Handle (AIS_Shape)	ais2 = new AIS_Shape(theBox2);
myContextGlobal->SetColor(ais2,Quantity_NOC_YELLOW,Standard_False);
myContextGlobal->SetMaterial(ais2,Graphic3d_NOM_PLASTIC,Standard_False);
myContextGlobal->Display(ais2,Standard_False);
const Handle(AIS_InteractiveObject)& anIO2 = ais2;
myContextGlobal->SetSelected (anIO2, Standard_False);
OCCViewer_Update(1);
Sleep(1000);

TopoDS_Shape FusedShape = BRepAlgoAPI_Fuse(theBox1,theBox2);

myContextGlobal->Erase(ais1,false);
myContextGlobal->Erase(ais2,false);

Handle (AIS_Shape)	aFusion = new AIS_Shape(FusedShape);
myContextGlobal->SetDisplayMode(aFusion,1,Standard_False);
myContextGlobal->SetColor(aFusion,Quantity_NOC_RED,Standard_False);
myContextGlobal->SetMaterial(aFusion,Graphic3d_NOM_PLASTIC,Standard_False);
myContextGlobal->Display(aFusion,Standard_False);
const Handle(AIS_InteractiveObject)& anIOFusion = aFusion;
myContextGlobal->SetSelected (anIOFusion, Standard_False);
myContextGlobal->UpdateCurrentViewer();

}

void MyDemo_OnCommon() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

gp_Ax2 axe(gp_Pnt(10,10,10),gp_Dir(1,2,1));
TopoDS_Shape theBox = BRepPrimAPI_MakeBox(axe, 60, 80, 100).Shape();

Handle(AIS_Shape) aboxshape=new AIS_Shape(theBox);
myContextGlobal->SetColor(aboxshape,Quantity_NOC_YELLOW,Standard_False);
myContextGlobal->SetMaterial(aboxshape,Graphic3d_NOM_PLASTIC,Standard_False);    
myContextGlobal->SetTransparency(aboxshape,0.2,Standard_False);
myContextGlobal->Display(aboxshape, AIS_Shaded, 0, Standard_False);
const Handle(AIS_InteractiveObject)& anIOBoxShape = aboxshape;
myContextGlobal->SetSelected (anIOBoxShape, Standard_False);
OCCViewer_Update(1);
Sleep(500);

TopoDS_Shape theWedge = BRepPrimAPI_MakeWedge(60., 100., 80., 20.).Shape();

Handle(AIS_Shape) awedge = new AIS_Shape(theWedge);
myContextGlobal->SetColor(awedge,Quantity_NOC_RED,Standard_False);
myContextGlobal->SetMaterial(awedge,Graphic3d_NOM_PLASTIC,Standard_False);    
myContextGlobal->SetTransparency(awedge,0.0,Standard_False);
myContextGlobal->Display(awedge,Standard_False);
const Handle(AIS_InteractiveObject)& anIOWedge = awedge;
myContextGlobal->SetSelected (anIOWedge, Standard_False);
myContextGlobal->UpdateCurrentViewer();
Sleep(500);

TopoDS_Shape theCommonSurface = BRepAlgoAPI_Common(theBox,theWedge);

myContextGlobal->Erase(aboxshape, false);
myContextGlobal->Erase(awedge, false);

Handle(AIS_Shape) acommon = new AIS_Shape(theCommonSurface);
myContextGlobal->SetColor(acommon,Quantity_NOC_GREEN,Standard_False); 
myContextGlobal->SetMaterial(acommon,Graphic3d_NOM_PLASTIC,Standard_False);    
myContextGlobal->Display (acommon, AIS_Shaded, 0,Standard_False);
const Handle(AIS_InteractiveObject)& anIOCommon = acommon;
myContextGlobal->SetSelected (anIOCommon, Standard_False);
myContextGlobal->UpdateCurrentViewer();

}

void MyDemo_OnSection() 
{

	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

  TopoDS_Shape atorus = BRepPrimAPI_MakeTorus(120, 20).Shape();

    Handle(AIS_Shape) ashape=new AIS_Shape(atorus);
    myContextGlobal->SetColor(ashape,Quantity_NOC_RED,Standard_False);
    myContextGlobal->SetMaterial(ashape,Graphic3d_NOM_PLASTIC,Standard_False);    
    myContextGlobal->SetDisplayMode(ashape,1,Standard_False);
	myContextGlobal->SetTransparency(ashape,0.1,Standard_False);
    myContextGlobal->Display(ashape,Standard_False);

gp_Vec V1(1,1,1);
Standard_Real radius = 120;
Standard_Integer i=-3;

for(i;i<=3;i++) {
    TopoDS_Shape asphere = BRepPrimAPI_MakeSphere(gp_Pnt(26 * 3 * i, 0, 0), radius).Shape();

    Handle (AIS_Shape) theShape=new AIS_Shape (asphere);
    myContextGlobal->SetTransparency(theShape,0.1,Standard_False);
    myContextGlobal->SetColor(theShape,Quantity_NOC_WHITE,Standard_False);
    myContextGlobal->SetDisplayMode(theShape,1,Standard_False);
    myContextGlobal->Display(theShape,Standard_False);
	OCCViewer_Update(1);

    Standard_Boolean PerformNow=Standard_False; 

    BRepAlgoAPI_Section section(atorus,asphere,PerformNow);
    section.ComputePCurveOn1(Standard_True);
    section.Approximation(TopOpeBRepTool_APPROX);
    section.Build();

    Handle(AIS_Shape) asection=new AIS_Shape(section.Shape());
    myContextGlobal->SetDisplayMode (asection, 0, Standard_False);
    myContextGlobal->SetColor (asection, Quantity_NOC_WHITE, Standard_False);
    myContextGlobal->Display (asection, Standard_False);
    if(i<3) {
    myContextGlobal->Remove (theShape, Standard_False);
	}
}
  myContextGlobal->UpdateCurrentViewer();

}

void MyDemo_OnPsection() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

TopoDS_Shape theTorus = BRepPrimAPI_MakeTorus(35, 8).Shape();
Handle(AIS_Shape) atorus = new AIS_Shape(theTorus);
myContextGlobal->SetColor(atorus,Quantity_NOC_YELLOW,Standard_False); 
myContextGlobal->SetMaterial(atorus,Graphic3d_NOM_PLASTIC,Standard_False);
myContextGlobal->SetTransparency(atorus,0.1,Standard_False);
myContextGlobal->Display(atorus,Standard_False);
const Handle(AIS_InteractiveObject)& anIOTorus = atorus;
myContextGlobal->SetSelected (anIOTorus, Standard_False);
OCCViewer_Update(1);
Sleep(500);

gp_Pln aplane(1,0.25,3,4);
Handle (Geom_Plane) thePlane = new Geom_Plane(aplane);
Handle (AIS_Plane) ais1 = new AIS_Plane(thePlane);
myContextGlobal->Display(ais1,Standard_False);
const Handle(AIS_InteractiveObject)& anIO1 = ais1;
myContextGlobal->SetSelected (anIO1, Standard_False);
OCCViewer_Update(1);
Sleep(300);

BRepAlgoAPI_Section section(theTorus,thePlane,Standard_False);
section.ComputePCurveOn1(Standard_True);
section.Approximation(TopOpeBRepTool_APPROX);
section.Build();

Handle(AIS_Shape) asection=new AIS_Shape(section.Shape());
myContextGlobal->SetDisplayMode(asection ,0,Standard_False);
myContextGlobal->SetColor(asection,Quantity_NOC_WHITE,Standard_False); 
myContextGlobal->Display(asection,Standard_False);
OCCViewer_Update(1);

}

void MyDemo_OnBlend() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

TopoDS_Shape Box = BRepPrimAPI_MakeBox(gp_Pnt(-400,0,0),200,230,180).Shape();
Handle(AIS_Shape) ais1 = new AIS_Shape(Box);
myContextGlobal->SetColor(ais1,Quantity_NOC_YELLOW,Standard_False); 
myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False); 
myContextGlobal->Display(ais1,Standard_False);
const Handle(AIS_InteractiveObject)& anIO1 = ais1;
myContextGlobal->SetSelected (anIO1, Standard_False);
OCCViewer_Update(1);
Sleep(500);

BRepFilletAPI_MakeFillet fillet(Box);

for (TopExp_Explorer ex(Box,TopAbs_EDGE); ex.More(); ex.Next()) {
	TopoDS_Edge Edge =TopoDS::Edge(ex.Current());
	fillet.Add(20,Edge);
}

myContextGlobal->Remove(ais1,Standard_False);

TopoDS_Shape blendedBox = fillet.Shape();
Handle(AIS_Shape) aBlendbox = new AIS_Shape(blendedBox);
myContextGlobal->SetColor(aBlendbox,Quantity_NOC_YELLOW,Standard_False); 
myContextGlobal->SetMaterial(aBlendbox,Graphic3d_NOM_PLASTIC,Standard_False); 
myContextGlobal->Display(aBlendbox,Standard_False);
const Handle(AIS_InteractiveObject)& anIOBlendBox = aBlendbox;
myContextGlobal->SetSelected (anIOBlendBox, Standard_False);
OCCViewer_Update(1);
Sleep(500);


gp_Pnt P1(250,150,75);
TopoDS_Shape S1 = BRepPrimAPI_MakeBox(300, 200, 200).Shape();
TopoDS_Shape S2 = BRepPrimAPI_MakeBox(P1, 120, 180, 70).Shape();

TopoDS_Shape fusedShape = BRepAlgoAPI_Fuse(S1,S2);
Handle(AIS_Shape) ais2 = new AIS_Shape(fusedShape);
myContextGlobal->SetColor(ais2,Quantity_NOC_RED,Standard_False); 
myContextGlobal->SetMaterial(ais2,Graphic3d_NOM_PLASTIC,Standard_False);  
myContextGlobal->Display(ais2,Standard_False);
const Handle(AIS_InteractiveObject)& anIO2 = ais2;
myContextGlobal->SetSelected (anIO2, Standard_False);
OCCViewer_Update(1);

BRepFilletAPI_MakeFillet fill(fusedShape);

for (TopExp_Explorer ex1(fusedShape,TopAbs_EDGE); ex1.More(); ex1.Next()) {
	TopoDS_Edge E =TopoDS::Edge(ex1.Current());
	fill.Add(E);
}

for (Standard_Integer i = 1;i<=fill.NbContours();i++) {
	Standard_Real longueur(fill.Length(i));
	Standard_Real Rad(0.15*longueur);
	fill.SetRadius(Rad,i, 1);
}

TopoDS_Shape blendedFusedSolids = fill.Shape();

Handle(AIS_Shape) aBlend = new AIS_Shape(blendedFusedSolids);
myContextGlobal->SetColor(aBlend,Quantity_NOC_RED,Standard_False); 
myContextGlobal->SetMaterial(aBlend,Graphic3d_NOM_PLASTIC,Standard_False);  
myContextGlobal->Display(aBlend,Standard_False);

myContextGlobal->Remove(ais2,Standard_False);
OCCViewer_Update(1);

}

void MyDemo_OnEvolvedblend() 
{

	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

TopoDS_Shape theBox = BRepPrimAPI_MakeBox(200, 200, 200).Shape();
Handle(AIS_Shape) ais1 = new AIS_Shape(theBox);
myContextGlobal->SetColor(ais1,Quantity_NOC_BROWN,Standard_False); 
myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False); 
myContextGlobal->Display(ais1,Standard_False);
const Handle(AIS_InteractiveObject)& anIO1 = ais1;
myContextGlobal->SetSelected (anIO1, Standard_False);
OCCViewer_Update(1);
Sleep(500);

BRepFilletAPI_MakeFillet Rake(theBox);

TopExp_Explorer ex(theBox,TopAbs_EDGE);
ex.Next();
ex.Next();
ex.Next();
ex.Next();
Rake.Add(8,50,TopoDS::Edge(ex.Current()));
Rake.Build();
if (Rake.IsDone() ){
	TopoDS_Shape evolvedBox = Rake.Shape();
	ais1->Set(evolvedBox);
	myContextGlobal->Redisplay(ais1,Standard_False);
	myContextGlobal->SetSelected(anIO1, Standard_False);
	OCCViewer_Update(1);
	Sleep(500);

}

TopoDS_Shape theCylinder = BRepPrimAPI_MakeCylinder(gp_Ax2(gp_Pnt(-300, 0, 0), gp::DZ()), 100, 200).Shape();
Handle(AIS_Shape) ais3 = new AIS_Shape(theCylinder);
myContextGlobal->SetColor(ais3,Quantity_NOC_GREEN,Standard_False); 
myContextGlobal->SetMaterial(ais3,Graphic3d_NOM_PLASTIC,Standard_False);    
myContextGlobal->Display(ais3,Standard_False);
const Handle(AIS_InteractiveObject)& anIO3 = ais3;
myContextGlobal->SetSelected (anIO3, Standard_False);
OCCViewer_Update(1);
Sleep(500);

BRepFilletAPI_MakeFillet fillet(theCylinder);

TColgp_Array1OfPnt2d TabPoint2(1,20);

for (Standard_Integer i=0; i<=19; i++) {
	gp_Pnt2d Point2d(i*2*M_PI/19,60*cos(i*M_PI/19-M_PI/2)+10);
	TabPoint2.SetValue(i+1,Point2d);
}

TopExp_Explorer exp2(theCylinder,TopAbs_EDGE);
fillet.Add(TabPoint2,TopoDS::Edge(exp2.Current()));
fillet.Build();
if (fillet.IsDone() ){
	TopoDS_Shape LawEvolvedCylinder = fillet.Shape();
	ais3->Set(LawEvolvedCylinder);
	myContextGlobal->Redisplay(ais3,Standard_False);
	myContextGlobal->SetSelected(anIO3,Standard_False);
	OCCViewer_Update(1);
	Sleep(500);
}

gp_Pnt P(350,0,0);
TopoDS_Shape theBox2 = BRepPrimAPI_MakeBox(P, 200, 200, 200).Shape();
Handle(AIS_Shape) ais2 = new AIS_Shape(theBox2);
myContextGlobal->SetColor(ais2,Quantity_NOC_RED,Standard_False); 
myContextGlobal->SetMaterial(ais2,Graphic3d_NOM_PLASTIC,Standard_False);    
myContextGlobal->Display(ais2,Standard_False);
const Handle(AIS_InteractiveObject)& anIO2 = ais2;
myContextGlobal->SetSelected (anIO2, Standard_False);
OCCViewer_Update(1);
Sleep(500);


BRepFilletAPI_MakeFillet afillet(theBox2);

TColgp_Array1OfPnt2d TabPoint(1,6);

gp_Pnt2d P1(0.,8.);
gp_Pnt2d P2(0.2,16.);
gp_Pnt2d P3(0.4,25.);
gp_Pnt2d P4(0.6,55.);
gp_Pnt2d P5(0.8,28.);
gp_Pnt2d P6(1.,20.);
TabPoint.SetValue(1,P1);
TabPoint.SetValue(2,P2);
TabPoint.SetValue(3,P3);
TabPoint.SetValue(4,P4);
TabPoint.SetValue(5,P5);
TabPoint.SetValue(6,P6);

TopExp_Explorer exp(theBox2,TopAbs_EDGE);
exp.Next();
exp.Next();
exp.Next();
exp.Next();

afillet.Add(TabPoint, TopoDS::Edge(exp.Current()));

afillet.Build();
if (afillet.IsDone() ){
	TopoDS_Shape LawevolvedBox = afillet.Shape();
	ais2->Set(LawevolvedBox);
	myContextGlobal->Redisplay(ais2,Standard_False);
	myContextGlobal->SetSelected(anIO2,Standard_False);
	OCCViewer_Update(1);
	}

}

void MyDemo_OnChamf() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

TopoDS_Shape theBox = BRepPrimAPI_MakeBox(60,200,70).Shape();
Handle(AIS_Shape) ais1 = new AIS_Shape(theBox);
myContextGlobal->SetColor(ais1,Quantity_NOC_YELLOW,Standard_False); 
myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);    
myContextGlobal->Display(ais1,Standard_False);
const Handle(AIS_InteractiveObject)& anIO1 = ais1;
myContextGlobal->SetSelected (anIO1, Standard_False);
OCCViewer_Update(1);
Sleep(500);

BRepFilletAPI_MakeChamfer MC(theBox);
// add all the edges to chamfer
TopTools_IndexedDataMapOfShapeListOfShape M;
TopExp::MapShapesAndAncestors(theBox,TopAbs_EDGE,TopAbs_FACE,M);
for (Standard_Integer i = 1;i<=M.Extent();i++) {
	TopoDS_Edge E = TopoDS::Edge(M.FindKey(i));
	TopoDS_Face F = TopoDS::Face(M.FindFromIndex(i).First());
	MC.Add(5,5,E,F);
	}

TopoDS_Shape ChanfrenedBox = MC.Shape();
Handle(AIS_Shape) aBlendedBox = new AIS_Shape(ChanfrenedBox);
myContextGlobal->SetColor(aBlendedBox,Quantity_NOC_YELLOW,Standard_False); 
myContextGlobal->SetMaterial(aBlendedBox,Graphic3d_NOM_PLASTIC,Standard_False);    
myContextGlobal->Display(aBlendedBox,Standard_False);
const Handle(AIS_InteractiveObject)& anIOBlendedBox = aBlendedBox;
myContextGlobal->SetSelected (anIOBlendedBox, Standard_False);
OCCViewer_Update(1);
Sleep(500);

myContextGlobal->Erase(ais1,Standard_True);

}

/* =================================================================================
   ====================   L O C A L   O P E R A T I O N S   ========================
   ================================================================================= */

void MyDemo_OnPrismLocal() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}
  TopoDS_Shape S = BRepPrimAPI_MakeBox(400., 250., 300.).Shape();
	Handle(AIS_Shape) ais1 = new AIS_Shape(S);

	myContextGlobal->SetColor(ais1,Quantity_NOC_GREEN,Standard_False); 
	myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);   
	myContextGlobal->Display(ais1,Standard_False);
	const Handle(AIS_InteractiveObject)& anIO1 = ais1;
	myContextGlobal->SetSelected (anIO1, Standard_False);
	OCCViewer_Update(1);
	Sleep(500);

	TopExp_Explorer Ex;
	Ex.Init(S,TopAbs_FACE);
	Ex.Next();
	TopoDS_Face F = TopoDS::Face(Ex.Current());
	Handle(Geom_Surface) surf = BRep_Tool::Surface(F);
	Handle(Geom_Plane) Pl = Handle(Geom_Plane)::DownCast(surf);
	gp_Dir D = Pl->Pln().Axis().Direction();
// new in 2.0 ..use the trigonometric orientation to make the extrusion.
	D.Reverse();
	gp_Pnt2d p1,p2;
	Handle(Geom2d_Curve) aline;
	BRepBuilderAPI_MakeWire MW;
	p1 = gp_Pnt2d(200.,-100.);
	p2 = gp_Pnt2d(100.,-100.);
	aline = GCE2d_MakeLine(p1,p2).Value();
	MW.Add(BRepBuilderAPI_MakeEdge(aline,surf,0.,p1.Distance(p2)));
	p1 = p2;
	p2 = gp_Pnt2d(100.,-200.);
	aline = GCE2d_MakeLine(p1,p2).Value();
	MW.Add(BRepBuilderAPI_MakeEdge(aline,surf,0.,p1.Distance(p2)));
	p1 = p2;
	p2 = gp_Pnt2d(200.,-200.);
	aline = GCE2d_MakeLine(p1,p2).Value();
	MW.Add(BRepBuilderAPI_MakeEdge(aline,surf,0.,p1.Distance(p2)));
	p1 = p2;
	p2 = gp_Pnt2d(200.,-100.);
	aline = GCE2d_MakeLine(p1,p2).Value();
	MW.Add(BRepBuilderAPI_MakeEdge(aline,surf,0.,p1.Distance(p2)));
	BRepBuilderAPI_MakeFace MKF;
	MKF.Init(surf,Standard_False, Precision::Confusion());
	MKF.Add(MW.Wire());
	TopoDS_Shape FP = MKF.Face();
	BRepLib::BuildCurves3d(FP);
	BRepFeat_MakePrism MKP(S,FP,F,D,0,Standard_True);
	MKP.Perform(200.);
	TopoDS_Shape res1 = MKP.Shape();
	ais1->Set(res1);

	myContextGlobal->Redisplay(ais1,Standard_False);
	myContextGlobal->SetSelected(anIO1,Standard_False);
	OCCViewer_Update(1);
	Sleep(500);

	Ex.Next();
	TopoDS_Face F2 = TopoDS::Face(Ex.Current());
	surf = BRep_Tool::Surface(F2);
	Pl = Handle(Geom_Plane)::DownCast(surf);
	D = Pl->Pln().Axis().Direction();
	D.Reverse();
	BRepBuilderAPI_MakeWire MW2;
	p1 = gp_Pnt2d(100.,100.);
	p2 = gp_Pnt2d(200.,100.);
	aline = GCE2d_MakeLine(p1,p2).Value();
	MW2.Add(BRepBuilderAPI_MakeEdge(aline,surf,0.,p1.Distance(p2)));
	p1 = p2;
	p2 = gp_Pnt2d(150.,200.);
	aline = GCE2d_MakeLine(p1,p2).Value();
	MW2.Add(BRepBuilderAPI_MakeEdge(aline,surf,0.,p1.Distance(p2)));
	p1 = p2;
	p2 = gp_Pnt2d(100.,100.);
	aline = GCE2d_MakeLine(p1,p2).Value();
	MW2.Add(BRepBuilderAPI_MakeEdge(aline,surf,0.,p1.Distance(p2)));
	BRepBuilderAPI_MakeFace MKF2;
	MKF2.Init(surf,Standard_False, Precision::Confusion());
	MKF2.Add(MW2.Wire());
	FP = MKF2.Face();
	BRepLib::BuildCurves3d(FP);
	BRepFeat_MakePrism MKP2(res1,FP,F2,D,1,Standard_True);
	MKP2.Perform(100.);
	TopoDS_Shape res2 = MKP2.Shape();
	ais1->Set(res2);

	myContextGlobal->Redisplay (ais1, Standard_False);
	myContextGlobal->SetSelected (anIO1, Standard_False);
	OCCViewer_Update(1);

}

//
// BRepFeat_MakeDPrism
//
void MyDemo_OnDprismLocal() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

  TopoDS_Shape S = BRepPrimAPI_MakeBox(400., 250., 300.).Shape();
	Handle(AIS_Shape) ais1 = new AIS_Shape(S);

	myContextGlobal->SetColor(ais1,Quantity_NOC_RED,Standard_False); 
	myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);   
	
	TopExp_Explorer Ex;
	Ex.Init(S,TopAbs_FACE);
	Ex.Next();
	Ex.Next();
	Ex.Next();
	Ex.Next();
	Ex.Next();
	TopoDS_Face F = TopoDS::Face(Ex.Current());
	Handle(Geom_Surface) surf = BRep_Tool::Surface(F);
	gp_Circ2d c(gp_Ax2d(gp_Pnt2d(200.,130.),gp_Dir2d(1.,0.)),50.);
	BRepBuilderAPI_MakeWire MW;
	Handle(Geom2d_Curve) aline = new Geom2d_Circle(c);
	MW.Add(BRepBuilderAPI_MakeEdge(aline,surf,0.,M_PI));
	MW.Add(BRepBuilderAPI_MakeEdge(aline,surf,M_PI,2.*M_PI));
	BRepBuilderAPI_MakeFace MKF;
	MKF.Init(surf,Standard_False, Precision::Confusion());
	MKF.Add(MW.Wire());
	TopoDS_Face FP = MKF.Face();
	BRepLib::BuildCurves3d(FP);
	BRepFeat_MakeDPrism MKDP(S,FP,F,10*M_PI/180,1,Standard_True);
	MKDP.Perform(200);
	TopoDS_Shape res1 = MKDP.Shape();

	myContextGlobal->Display(ais1,Standard_False);
	const Handle(AIS_InteractiveObject)& anIO1 = ais1;
	myContextGlobal->SetSelected (anIO1, Standard_False);
	OCCViewer_Update(1);
	Sleep(500);

	ais1->Set(res1);
	
	myContextGlobal->Redisplay(ais1,Standard_False);
	myContextGlobal->SetSelected(anIO1,Standard_False);

	OCCViewer_Update(1);

}

void MyDemo_OnRevolLocal() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}
  TopoDS_Shape S = BRepPrimAPI_MakeBox(400., 250., 300.).Shape();

	Handle(AIS_Shape) ais1 = new AIS_Shape(S);
	
	myContextGlobal->SetColor(ais1,Quantity_NOC_CORAL,Standard_False); 
	myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);   
	myContextGlobal->Display(ais1,Standard_False);
	const Handle(AIS_InteractiveObject)& anIO1 = ais1;
	myContextGlobal->SetSelected (anIO1, Standard_False);
	OCCViewer_Update(1);
	Sleep(500);

	TopExp_Explorer Ex;
	Ex.Init(S,TopAbs_FACE);
	Ex.Next();
	Ex.Next();
	TopoDS_Face F1 = TopoDS::Face(Ex.Current());
	Handle(Geom_Surface) surf = BRep_Tool::Surface(F1);
	Handle (Geom_Plane) Pl = Handle(Geom_Plane)::DownCast(surf);
	gp_Ax1 D = gp::OX();
	BRepBuilderAPI_MakeWire MW1;
	gp_Pnt2d p1,p2;
	p1 = gp_Pnt2d(100.,100.);
	p2 = gp_Pnt2d(200.,100.);
	Handle(Geom2d_Line) aline = GCE2d_MakeLine(p1,p2).Value();
	MW1.Add(BRepBuilderAPI_MakeEdge(aline,surf,0.,p1.Distance(p2)));
	p1 = p2;
	p2 = gp_Pnt2d(150.,200.);
	aline = GCE2d_MakeLine(p1,p2).Value();
	MW1.Add(BRepBuilderAPI_MakeEdge(aline,surf,0.,p1.Distance(p2)));
	p1 = p2;
	p2 = gp_Pnt2d(100.,100.);
	aline = GCE2d_MakeLine(p1,p2).Value();
	MW1.Add(BRepBuilderAPI_MakeEdge(aline,surf,0.,p1.Distance(p2)));
	BRepBuilderAPI_MakeFace MKF1;
	MKF1.Init(surf,Standard_False, Precision::Confusion());
	MKF1.Add(MW1.Wire());
	TopoDS_Face FP = MKF1.Face();
	BRepLib::BuildCurves3d(FP);
	BRepFeat_MakeRevol MKrev(S,FP,F1,D,1,Standard_True);
	Ex.Next();
	Ex.Next();
	TopoDS_Face F2 = TopoDS::Face(Ex.Current());
	MKrev.Perform(F2);
	TopoDS_Shape res1 = MKrev.Shape();


	myContextGlobal->Remove (ais1, Standard_False);
	Handle(AIS_Shape) ais2 = new AIS_Shape(res1);
	myContextGlobal->Display(ais2,Standard_False);
	const Handle(AIS_InteractiveObject)& anIO2 = ais2;
	myContextGlobal->SetSelected (anIO2, Standard_False);
	OCCViewer_Update(1);

}

void MyDemo_OnGlueLocal() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}
  TopoDS_Shape S1 = BRepPrimAPI_MakeBox(gp_Pnt(-500., -500., 0.), gp_Pnt(-100., -250., 300.)).Shape();

	Handle(AIS_Shape) ais1 = new AIS_Shape(S1);
	myContextGlobal->SetColor(ais1,Quantity_NOC_ORANGE,Standard_False); 
	myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);   
	myContextGlobal->Display(ais1,Standard_False);
	const Handle(AIS_InteractiveObject)& anIO1 = ais1;
	myContextGlobal->SetSelected (anIO1, Standard_False);
	OCCViewer_Update(1);
	Sleep(1000);
	
	TopExp_Explorer Ex1;
	Ex1.Init(S1,TopAbs_FACE);
	Ex1.Next();
	Ex1.Next();
	Ex1.Next();
	Ex1.Next();
	Ex1.Next();
	TopoDS_Face F1 = TopoDS::Face(Ex1.Current());
  TopoDS_Shape S2 = BRepPrimAPI_MakeBox(gp_Pnt(-400., -400., 300.), gp_Pnt(-200., -300., 500.)).Shape();
	Handle(AIS_Shape) ais2 = new AIS_Shape(S2);

	myContextGlobal->SetColor(ais2,Quantity_NOC_AZURE,Standard_False); 
	myContextGlobal->SetMaterial(ais2,Graphic3d_NOM_PLASTIC,Standard_False);   
	myContextGlobal->Display(ais2,Standard_False);
	const Handle(AIS_InteractiveObject)& anIO2 = ais2;
	myContextGlobal->SetSelected (anIO2, Standard_False);
	OCCViewer_Update(1);
	Sleep(1000);

	TopExp_Explorer Ex2;
	Ex2.Init(S2,TopAbs_FACE);
	Ex2.Next();
	Ex2.Next();
	Ex2.Next();
	Ex2.Next();
	TopoDS_Face F2 = TopoDS::Face(Ex2.Current());
	BRepFeat_Gluer glue(S2,S1);
	glue.Bind(F2,F1);
	TopoDS_Shape res1 = glue.Shape();
	myContextGlobal->Erase(ais2,Standard_False);
	
	ais1->Set(res1);

	myContextGlobal->Redisplay (ais1, Standard_False);
	myContextGlobal->SetSelected(anIO1,Standard_False);
	OCCViewer_Update(1);
	Sleep(1000);

  TopoDS_Shape S3 = BRepPrimAPI_MakeBox(500., 400., 300.).Shape();

	Handle(AIS_Shape) ais3 = new AIS_Shape(S3);
	myContextGlobal->SetColor(ais3,Quantity_NOC_ORANGE,Standard_False); 
	myContextGlobal->SetMaterial(ais3,Graphic3d_NOM_PLASTIC,Standard_False);   
	myContextGlobal->Display(ais3,Standard_False);
	const Handle(AIS_InteractiveObject)& anIO3 = ais3;
	myContextGlobal->SetSelected (anIO3, Standard_False);
	OCCViewer_Update(1);
	Sleep(1000);

	TopExp_Explorer Ex3;
	Ex3.Init(S3,TopAbs_FACE);
	Ex3.Next();
	Ex3.Next();
	Ex3.Next();
	Ex3.Next();
	Ex3.Next();
	TopoDS_Face F3 = TopoDS::Face(Ex3.Current());
  TopoDS_Shape S4 = BRepPrimAPI_MakeBox(gp_Pnt(0., 0., 300.), gp_Pnt(200., 200., 500.)).Shape();

	Handle(AIS_Shape) ais4 = new AIS_Shape(S4);
	myContextGlobal->SetColor(ais4,Quantity_NOC_AZURE,Standard_False); 
	myContextGlobal->SetMaterial(ais4,Graphic3d_NOM_PLASTIC,Standard_False);   
	myContextGlobal->Display(ais4,Standard_False);
	const Handle(AIS_InteractiveObject)& anIO4 = ais4;
	myContextGlobal->SetSelected (anIO4, Standard_False);
	OCCViewer_Update(1);
	Sleep(1000);

	TopExp_Explorer Ex4;
	Ex4.Init(S4,TopAbs_FACE);
	Ex4.Next();
	Ex4.Next();
	Ex4.Next();
	Ex4.Next();
	TopoDS_Face F4 = TopoDS::Face(Ex4.Current());
	BRepFeat_Gluer glue2(S4,S3);
	glue2.Bind(F4,F3);
	LocOpe_FindEdges CommonEdges(F4,F3);
	for (CommonEdges.InitIterator(); CommonEdges.More(); CommonEdges.Next()) 
		glue2.Bind(CommonEdges.EdgeFrom(),CommonEdges.EdgeTo());
	TopoDS_Shape res2 = glue2.Shape();
	myContextGlobal->Erase(ais3,Standard_False);
	
	ais4->Set(res2);

	myContextGlobal->Redisplay(ais4,Standard_False);
	myContextGlobal->SetSelected(anIO4,Standard_False);
	OCCViewer_Update(1);
	Sleep(1000);

}


void MyDemo_OnPipeLocal() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}
  TopoDS_Shape S = BRepPrimAPI_MakeBox(400., 250., 300.).Shape();
	Handle(AIS_Shape) ais1 = new AIS_Shape(S);

	myContextGlobal->SetColor(ais1,Quantity_NOC_CORAL,Standard_False); 
	myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);   
	myContextGlobal->Display(ais1,Standard_False);
	const Handle(AIS_InteractiveObject)& anIO1 = ais1;
	myContextGlobal->SetSelected (anIO1, Standard_False);
	OCCViewer_Update(1);
	Sleep(500);

	TopExp_Explorer Ex;
	Ex.Init(S,TopAbs_FACE);
	Ex.Next();
	Ex.Next();
	TopoDS_Face F1 = TopoDS::Face(Ex.Current());
	Handle(Geom_Surface) surf = BRep_Tool::Surface(F1);
	BRepBuilderAPI_MakeWire MW1;
	gp_Pnt2d p1,p2;
	p1 = gp_Pnt2d(100.,100.);
	p2 = gp_Pnt2d(200.,100.);
	Handle(Geom2d_Line) aline = GCE2d_MakeLine(p1,p2).Value();
	MW1.Add(BRepBuilderAPI_MakeEdge(aline,surf,0.,p1.Distance(p2)));
	p1 = p2;
	p2 = gp_Pnt2d(150.,200.);
	aline = GCE2d_MakeLine(p1,p2).Value();
	MW1.Add(BRepBuilderAPI_MakeEdge(aline,surf,0.,p1.Distance(p2)));
	p1 = p2;
	p2 = gp_Pnt2d(100.,100.);
	aline = GCE2d_MakeLine(p1,p2).Value();
	MW1.Add(BRepBuilderAPI_MakeEdge(aline,surf,0.,p1.Distance(p2)));
	BRepBuilderAPI_MakeFace MKF1;
	MKF1.Init(surf,Standard_False, Precision::Confusion());
	MKF1.Add(MW1.Wire());
	TopoDS_Face FP = MKF1.Face();
	BRepLib::BuildCurves3d(FP);
	TColgp_Array1OfPnt CurvePoles(1,3);
	gp_Pnt pt = gp_Pnt(150.,0.,150.);
	CurvePoles(1) = pt;
	pt = gp_Pnt(200.,-100.,150.);
	CurvePoles(2) = pt;
	pt = gp_Pnt(150.,-200.,150.);
	CurvePoles(3) = pt;
	Handle(Geom_BezierCurve) curve = new Geom_BezierCurve(CurvePoles);
	TopoDS_Edge E = BRepBuilderAPI_MakeEdge(curve);
	TopoDS_Wire W = BRepBuilderAPI_MakeWire(E);
	BRepFeat_MakePipe MKPipe(S,FP,F1,W,1,Standard_True);
	MKPipe.Perform();
	TopoDS_Shape res1 = MKPipe.Shape();
	ais1->Set(res1);

	myContextGlobal->Redisplay(ais1,Standard_False); 
	myContextGlobal->SetSelected(anIO1,Standard_False);
	OCCViewer_Update(1);
	
}


void MyDemo_OnLinearLocal() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}
	BRepBuilderAPI_MakeWire mkw;
	gp_Pnt p1 = gp_Pnt(0.,0.,0.);
	gp_Pnt p2 = gp_Pnt(200.,0.,0.);
	mkw.Add(BRepBuilderAPI_MakeEdge(p1,p2));
	p1 = p2;
	p2 = gp_Pnt(200.,0.,50.);
	mkw.Add(BRepBuilderAPI_MakeEdge(p1,p2));
	p1 = p2;
	p2 = gp_Pnt(50.,0.,50.);
	mkw.Add(BRepBuilderAPI_MakeEdge(p1,p2));
	p1 = p2;
	p2 = gp_Pnt(50.,0.,200.);
	mkw.Add(BRepBuilderAPI_MakeEdge(p1,p2));
	p1 = p2;
	p2 = gp_Pnt(0.,0.,200.);
	mkw.Add(BRepBuilderAPI_MakeEdge(p1,p2));
	p1 = p2;
	mkw.Add(BRepBuilderAPI_MakeEdge(p2,gp_Pnt(0.,0.,0.)));
	
	TopoDS_Shape S = BRepPrimAPI_MakePrism(BRepBuilderAPI_MakeFace(mkw.Wire()), 
									   gp_Vec(gp_Pnt(0.,0.,0.),gp_Pnt(0.,100.,0.)));

	Handle(AIS_Shape) ais1 = new AIS_Shape(S);
	myContextGlobal->SetColor(ais1,Quantity_NOC_CYAN2,Standard_False); 
	myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);   
	myContextGlobal->Display(ais1,Standard_False);
	const Handle(AIS_InteractiveObject)& anIO1 = ais1;
	myContextGlobal->SetSelected (anIO1, Standard_False);
	OCCViewer_Update(1);
	Sleep(500);

	TopoDS_Wire W = BRepBuilderAPI_MakeWire(BRepBuilderAPI_MakeEdge(gp_Pnt(50.,45.,100.),
													  gp_Pnt(100.,45.,50.)));	
	Handle(Geom_Plane) aplane = new Geom_Plane(0.,1.,0.,-45.);
	BRepFeat_MakeLinearForm aform(S, W, aplane, gp_Vec(0.,10.,0.), gp_Vec(0.,0.,0.),
								  1, Standard_True);
	aform.Perform(/*10.*/); // new in 2.0

	TopoDS_Shape res = aform.Shape();
	ais1->Set(res);
	myContextGlobal->Redisplay(ais1,Standard_False);
	myContextGlobal->SetSelected (anIO1, Standard_False);
	OCCViewer_Update(1);

}


void MyDemo_OnSplitLocal() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

  TopoDS_Shape S = BRepPrimAPI_MakeBox(gp_Pnt(-100, -60, -80), 150, 200, 170).Shape();
	
	Handle(AIS_Shape) ais1 = new AIS_Shape(S);
	myContextGlobal->SetColor(ais1,Quantity_NOC_RED,Standard_False);
	myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);
	myContextGlobal->Display(ais1,Standard_False);
	const Handle(AIS_InteractiveObject)& anIO1 = ais1;
	myContextGlobal->SetSelected (anIO1, Standard_False);
	OCCViewer_Update(1);
	Sleep(500);

	BRepAlgoAPI_Section asect(S, gp_Pln(1,2,1,-15),Standard_False);
	asect.ComputePCurveOn1(Standard_True);
	asect.Approximation(Standard_True);
	asect.Build();
	TopoDS_Shape R = asect.Shape();

	BRepFeat_SplitShape asplit(S);
	
	for (TopExp_Explorer Ex(R,TopAbs_EDGE); Ex.More(); Ex.Next()) {
		TopoDS_Shape anEdge = Ex.Current();
		TopoDS_Shape aFace;
		if (asect.HasAncestorFaceOn1(anEdge,aFace)) {
			TopoDS_Face F = TopoDS::Face(aFace);
			TopoDS_Edge E = TopoDS::Edge(anEdge);
			asplit.Add(E,F);
		}
	}

	asplit.Build();

	//Sleep(1000);
	myContextGlobal->Erase(ais1,Standard_False);
	//OCCViewer_Update(1);

	TopoDS_Shape Result = asplit.Shape();
	
	Handle(AIS_Shape) ais2 = new AIS_Shape(Result);

	myContextGlobal->SetColor(ais2,Quantity_NOC_RED,Standard_False);
	myContextGlobal->SetMaterial(ais2,Graphic3d_NOM_PLASTIC,Standard_False);
	myContextGlobal->SetDisplayMode(ais2,1,Standard_False);
	myContextGlobal->Display(ais2,Standard_False);
	const Handle(AIS_InteractiveObject)& anIO2 = ais2;
	myContextGlobal->SetSelected (anIO2, Standard_False);
	OCCViewer_Update(1);

}



void MyDemo_OnThickLocal() 
{
	AIS_ListOfInteractive L;
	myContextGlobal->DisplayedObjects(L);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(L);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

  TopoDS_Shape S1 = BRepPrimAPI_MakeBox(150, 200, 110).Shape();
	
	Handle(AIS_Shape) abox1 = new AIS_Shape(S1);
	myContextGlobal->SetColor (abox1, Quantity_NOC_WHITE, Standard_False);
	myContextGlobal->SetMaterial(abox1,Graphic3d_NOM_PLASTIC,Standard_False);
	myContextGlobal->Display(abox1,Standard_False);
	const Handle(AIS_InteractiveObject)& anIOBox1 = abox1;
	myContextGlobal->SetSelected (anIOBox1, Standard_False);
	OCCViewer_Update(1);
	Sleep(1000);

	TopTools_ListOfShape aList;
	TopExp_Explorer Ex(S1,TopAbs_FACE);
	Ex.Next();	//this is the front face
	TopoDS_Shape aFace = Ex.Current();
	aList.Append(aFace);
	
    BRepOffsetAPI_MakeThickSolid aSolidMaker;
    aSolidMaker.MakeThickSolidByJoin(S1,aList,10,0.01);
	TopoDS_Shape aThickSolid = aSolidMaker.Shape();

	Handle(AIS_Shape) ais1 = new AIS_Shape(aThickSolid);
	myContextGlobal->SetColor(ais1,Quantity_NOC_RED,Standard_False);
	myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_PLASTIC,Standard_False);
	myContextGlobal->Display(ais1,Standard_False);
	const Handle(AIS_InteractiveObject)& anIO1 = ais1;
	myContextGlobal->SetSelected (anIO1, Standard_False);
	OCCViewer_Update(1);
	Sleep(1000);
	
	myContextGlobal->Erase(abox1,Standard_True);
	OCCViewer_Update(1);


}

void MyDemo_OnOffsetLocal() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

  TopoDS_Shape S1 = BRepPrimAPI_MakeBox(150, 200, 110).Shape();

	Handle(AIS_Shape) aisBox1 = new AIS_Shape(S1);
	myContextGlobal->SetColor(aisBox1,Quantity_NOC_BROWN,Standard_False);
	myContextGlobal->SetMaterial(aisBox1,Graphic3d_NOM_GOLD,Standard_False);
	myContextGlobal->Display(aisBox1,Standard_False);
	OCCViewer_Update(1);
	Sleep(500);

    BRepOffsetAPI_MakeOffsetShape aShapeMaker1;
    aShapeMaker1.PerformByJoin(S1,60,0.01);
	TopoDS_Shape anOffsetShape1 = aShapeMaker1.Shape();

	Handle(AIS_Shape) ais1 = new AIS_Shape(anOffsetShape1);
	myContextGlobal->SetColor(ais1,Quantity_NOC_MATRABLUE,Standard_False);
	myContextGlobal->SetMaterial(ais1,Graphic3d_NOM_GOLD,Standard_False);
	myContextGlobal->SetTransparency(ais1,0.5,Standard_False);
	myContextGlobal->Display(ais1,Standard_False);
	OCCViewer_Update(1);
	Sleep(500);

  TopoDS_Shape S2 = BRepPrimAPI_MakeBox(gp_Pnt(500, 0, 0), 220, 140, 180).Shape();
	
	Handle(AIS_Shape) aisBox2 = new AIS_Shape(S2);
	myContextGlobal->SetColor(aisBox2,Quantity_NOC_WHITE,Standard_False);
	myContextGlobal->SetMaterial(aisBox2,Graphic3d_NOM_GOLD,Standard_False);
	myContextGlobal->SetTransparency(aisBox2,0.5,Standard_False);
	myContextGlobal->Display(aisBox2,Standard_False);
	OCCViewer_Update(1);
	Sleep(500);

    BRepOffsetAPI_MakeOffsetShape aShapeMaker2;
    aShapeMaker2.PerformByJoin(S2,-40,0.01,
      BRepOffset_Skin,Standard_False,Standard_False,GeomAbs_Arc);
	TopoDS_Shape anOffsetShape2 = aShapeMaker2.Shape();

	Handle(AIS_Shape) ais2 = new AIS_Shape(anOffsetShape2);
	myContextGlobal->SetColor (ais2, Quantity_NOC_MATRABLUE, Standard_False);
	myContextGlobal->SetMaterial(ais2,Graphic3d_NOM_GOLD,Standard_False);
	myContextGlobal->Display (ais2, Standard_False);
	OCCViewer_Update(1);
	
}

/* =================================================================================
   ====================   B U I L D I N G   ========================================
   ================================================================================= */


void MyDemo_OnVertex() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

	TopoDS_Vertex V1,V2,V3;
	
	V1 = BRepBuilderAPI_MakeVertex(gp_Pnt(0,0,0));
	V2 = BRepBuilderAPI_MakeVertex(gp_Pnt(10,7,25));
	
	gp_Pnt P(-12,8,-4);
	BRepBuilderAPI_MakeVertex MV(P);
	V3 = MV.Vertex();

	Handle(AIS_Shape) Point1 = new AIS_Shape(V1);
	myContextGlobal->Display(Point1,Standard_False);
	Handle(AIS_Shape) Point2 = new AIS_Shape(V2);
	myContextGlobal->Display(Point2,Standard_False);
	Handle(AIS_Shape) Point3 = new AIS_Shape(V3);
	myContextGlobal->Display(Point3,Standard_False);

	OCCViewer_Update(1);

}

void MyDemo_OnEdge() 
{
	
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}
	
	
	TopoDS_Edge BlueEdge,YellowEdge,WhiteEdge,RedEdge,GreenEdge;
	TopoDS_Vertex V1,V2,V3,V4;
	
/////////////The blue edge

	BlueEdge = BRepBuilderAPI_MakeEdge(gp_Pnt(-80,-50,-20),gp_Pnt(-30,-60,-60));

/////////////The yellow edge
	
	V1 = BRepBuilderAPI_MakeVertex(gp_Pnt(-20,10,-30));
	V2 = BRepBuilderAPI_MakeVertex(gp_Pnt(10,7,-25));
	YellowEdge = BRepBuilderAPI_MakeEdge(V1,V2);

/////////////The white edge
	
	gp_Lin line(gp_Ax1(gp_Pnt(10,10,10),gp_Dir(1,0,0)));
	WhiteEdge = BRepBuilderAPI_MakeEdge(line,-20,10);

//////////////The red edge

	gp_Elips Elips(gp_Ax2(gp_Pnt(10,0,0),gp_Dir(1,1,1)),60,30);
	RedEdge = BRepBuilderAPI_MakeEdge(Elips,0,M_PI/2);

/////////////The green edge and the both extreme vertex

	gp_Pnt P1(-15,200,10);
	gp_Pnt P2(5,204,0);
	gp_Pnt P3(15,200,0);
	gp_Pnt P4(-15,20,15);
	gp_Pnt P5(-5,20,0);
	gp_Pnt P6(15,20,0);
	gp_Pnt P7(24,120,0);
	gp_Pnt P8(-24,120,12.5);
	TColgp_Array1OfPnt array(1,8);
	array.SetValue(1,P1);
	array.SetValue(2,P2);
	array.SetValue(3,P3); 
	array.SetValue(4,P4); 
	array.SetValue(5,P5); 
	array.SetValue(6,P6); 
	array.SetValue(7,P7); 
	array.SetValue(8,P8); 
	Handle (Geom_BezierCurve) curve = new Geom_BezierCurve(array);
	
	BRepBuilderAPI_MakeEdge ME (curve);
	GreenEdge = ME;
	V3 = ME.Vertex1();
	V4 = ME.Vertex2();

//////////////Display
Handle(AIS_Shape) blue = new AIS_Shape(BlueEdge);
myContextGlobal->SetColor(blue,Quantity_NOC_MATRABLUE,Standard_False); 
myContextGlobal->Display(blue,Standard_False);

Handle(AIS_Shape) yellow = new AIS_Shape(YellowEdge);
myContextGlobal->SetColor(yellow,Quantity_NOC_YELLOW,Standard_False); 
myContextGlobal->Display(yellow,Standard_False);

Handle(AIS_Shape) white = new AIS_Shape(WhiteEdge);
myContextGlobal->SetColor(white,Quantity_NOC_WHITE,Standard_False); 
myContextGlobal->Display(white,Standard_False);

Handle(AIS_Shape) red = new AIS_Shape(RedEdge);
myContextGlobal->SetColor(red,Quantity_NOC_RED,Standard_False); 
myContextGlobal->Display(red,Standard_False);

Handle(AIS_Shape) green = new AIS_Shape(GreenEdge);
myContextGlobal->SetColor(green,Quantity_NOC_GREEN,Standard_False); 
myContextGlobal->Display(green,Standard_False);

Handle(AIS_Shape) Point1 = new AIS_Shape(V3);
myContextGlobal->Display(Point1,Standard_False);
Handle(AIS_Shape) Point2 = new AIS_Shape(V4);
myContextGlobal->Display(Point2,Standard_False);

OCCViewer_Update(1);

}

void MyDemo_OnWire() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

	TopoDS_Wire RedWire,YellowWire,WhiteWire,
		ExistingWire, ExistingWire2;

	TopoDS_Edge Edge1,Edge2,Edge3,Edge4,Edge5,Edge6,Edge7,LastEdge;
	TopoDS_Vertex LastVertex;

////////////The red wire is build from a single edge

	gp_Elips Elips(gp_Ax2(gp_Pnt(250,0,0),gp_Dir(1,1,1)),160,90);
	Edge1 = BRepBuilderAPI_MakeEdge(Elips,0,M_PI/2);

	RedWire = BRepBuilderAPI_MakeWire(Edge1);

///////////the yellow wire is build from an existing wire and an edge
	
	gp_Circ circle(gp_Ax2(gp_Pnt(-300,0,0),gp_Dir(1,0,0)),80);
	Edge2 = BRepBuilderAPI_MakeEdge(circle,0,M_PI);

	ExistingWire = BRepBuilderAPI_MakeWire(Edge2);

	Edge3 = BRepBuilderAPI_MakeEdge(gp_Pnt(-300,0,-80),gp_Pnt(-90,20,-30));

	BRepBuilderAPI_MakeWire MW1(ExistingWire,Edge3);
	if (MW1.IsDone()) {
			YellowWire = MW1;
	}


//////////the white wire is built with an existing wire and 3 edges.
//////////we use the methods Add, Edge and Vertex from BRepBuilderAPI_MakeWire.

	gp_Circ circle2(gp_Ax2(gp_Pnt(0,0,0),gp_Dir(0,1,0)),200);
	Edge4 = BRepBuilderAPI_MakeEdge(circle2,0,M_PI);

	ExistingWire2 = BRepBuilderAPI_MakeWire(Edge4);

	gp_Pnt P1(0,0,-200);
	gp_Pnt P2(5,204,0);
	Edge5 = BRepBuilderAPI_MakeEdge(P1,P2);

	gp_Pnt P3(-15,20,15);
	Edge6 = BRepBuilderAPI_MakeEdge(P2,P3);
	gp_Pnt P4(15,20,0);	
	Edge7 = BRepBuilderAPI_MakeEdge(P3,P4);

	BRepBuilderAPI_MakeWire MW;
	MW.Add(ExistingWire2);
	MW.Add(Edge5);
	MW.Add(Edge6);
	MW.Add(Edge7);

	if (MW.IsDone()) {
		WhiteWire = MW.Wire();
		LastEdge = MW.Edge();
		LastVertex = MW.Vertex();
	}


Handle(AIS_Shape) red = new AIS_Shape(RedWire);
myContextGlobal->SetColor(red,Quantity_NOC_RED,Standard_False); 
myContextGlobal->Display(red,Standard_False);

Handle(AIS_Shape) yellow = new AIS_Shape(YellowWire);
myContextGlobal->SetColor(yellow,Quantity_NOC_YELLOW,Standard_False); 
myContextGlobal->Display(yellow,Standard_False);

Handle(AIS_Shape) white = new AIS_Shape(WhiteWire);
myContextGlobal->SetColor(white,Quantity_NOC_WHITE,Standard_False); 
myContextGlobal->Display(white,Standard_False);

Handle(AIS_Shape) lastE = new AIS_Shape(LastEdge);
myContextGlobal->SetWidth(lastE,3,Standard_False);
myContextGlobal->SetColor(lastE,Quantity_NOC_RED,Standard_False); 
myContextGlobal->Display(lastE,Standard_False);

Handle(AIS_Shape) lastV = new AIS_Shape(LastVertex);
myContextGlobal->Display(lastV,Standard_False);

OCCViewer_Update(1);

}

void MyDemo_OnFace() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}



	TopoDS_Face WhiteFace, BrownFace, RedFace, PinkFace;
	TopoDS_Edge Edge1, Edge2, Edge3, Edge4, Edge5, Edge6, Edge7;
	TopoDS_Wire Wire1;
	gp_Pnt P1, P2, P3, P4, P5, P6, P7;

	gp_Sphere sphere (gp_Ax3(gp_Pnt(0,0,0),gp_Dir(1,0,0)),150);

	WhiteFace = BRepBuilderAPI_MakeFace(sphere,0.1,0.7,0.2,0.9);

//////////////////////////////////

	P1.SetCoord(-15,200,10);
	P2.SetCoord(5,204,0);
	P3.SetCoord(15,200,0);
	P4.SetCoord(-15,20,15);
	P5.SetCoord(-5,20,0);
	P6.SetCoord(15,20,35);
	TColgp_Array2OfPnt array(1,3,1,2);
	array.SetValue(1,1,P1);
	array.SetValue(2,1,P2);
	array.SetValue(3,1,P3); 
	array.SetValue(1,2,P4); 
	array.SetValue(2,2,P5); 
	array.SetValue(3,2,P6);
	Handle (Geom_BSplineSurface) curve = GeomAPI_PointsToBSplineSurface(array,3,8,GeomAbs_C2,0.001);

	RedFace = BRepBuilderAPI_MakeFace(curve, Precision::Confusion());

////////////////////

	gp_Circ circle(gp_Ax2(gp_Pnt(0,0,0),gp_Dir(1,0,0)),80);
	Edge1 = BRepBuilderAPI_MakeEdge(circle,0,M_PI);

	Edge2 = BRepBuilderAPI_MakeEdge(gp_Pnt(0,0,-80),gp_Pnt(0,-10,40));
	Edge3 = BRepBuilderAPI_MakeEdge(gp_Pnt(0,-10,40),gp_Pnt(0,0,80));

	TopoDS_Wire YellowWire;
	BRepBuilderAPI_MakeWire MW1(Edge1,Edge2,Edge3);
	if (MW1.IsDone()) {
			YellowWire = MW1;
	}

	BrownFace = BRepBuilderAPI_MakeFace(YellowWire);


/////////////

	P1.SetCoord(35,-200,40);
	P2.SetCoord(50,-204,30);
	P3.SetCoord(65,-200,30);
	P4.SetCoord(35,-20,45);
	P5.SetCoord(45,-20,30);
	P6.SetCoord(65,-20,65);
	TColgp_Array2OfPnt array2(1,3,1,2);
	array2.SetValue(1,1,P1);
	array2.SetValue(2,1,P2);
	array2.SetValue(3,1,P3); 
	array2.SetValue(1,2,P4); 
	array2.SetValue(2,2,P5); 
	array2.SetValue(3,2,P6);
	
	Handle (Geom_BSplineSurface) BSplineSurf = GeomAPI_PointsToBSplineSurface(array2,3,8,GeomAbs_C2,0.001);
	
	TopoDS_Face aFace = BRepBuilderAPI_MakeFace(BSplineSurf, Precision::Confusion());

	//2d lines
	gp_Pnt2d P12d(0.9,0.1);
	gp_Pnt2d P22d(0.2,0.7);
	gp_Pnt2d P32d(0.02,0.1);

	Handle (Geom2d_Line) line1 = new Geom2d_Line(P12d,gp_Dir2d((0.2-0.9),(0.7-0.1)));
	Handle (Geom2d_Line) line2 = new Geom2d_Line(P22d,gp_Dir2d((0.02-0.2),(0.1-0.7)));
	Handle (Geom2d_Line) line3 = new Geom2d_Line(P32d,gp_Dir2d((0.9-0.02),(0.1-0.1)));


	//Edges are on the BSpline surface
	Edge1 = BRepBuilderAPI_MakeEdge(line1,BSplineSurf,0,P12d.Distance(P22d));
	Edge2 = BRepBuilderAPI_MakeEdge(line2,BSplineSurf,0,P22d.Distance(P32d));
	Edge3 = BRepBuilderAPI_MakeEdge(line3,BSplineSurf,0,P32d.Distance(P12d));

	Wire1 = BRepBuilderAPI_MakeWire(Edge1,Edge2,Edge3);
	Wire1.Reverse();
	PinkFace = BRepBuilderAPI_MakeFace(aFace,Wire1);
	BRepLib::BuildCurves3d(PinkFace);

/////////////Display
	Handle(AIS_Shape) white = new AIS_Shape(WhiteFace);
	myContextGlobal->SetColor(white,Quantity_NOC_WHITE,Standard_False);
	myContextGlobal->SetMaterial(white,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->Display(white,Standard_False);
	
	Handle(AIS_Shape) red = new AIS_Shape(RedFace);
	myContextGlobal->SetColor(red,Quantity_NOC_RED,Standard_False);
	myContextGlobal->SetMaterial(red,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->Display(red,Standard_False);
	
	Handle(AIS_Shape) brown = new AIS_Shape(BrownFace);
	myContextGlobal->SetColor(brown,Quantity_NOC_BROWN,Standard_False);
	myContextGlobal->SetMaterial(brown,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->Display(brown,Standard_False);
	
	Handle(AIS_Shape) pink = new AIS_Shape(PinkFace);
	myContextGlobal->SetColor(pink,Quantity_NOC_HOTPINK,Standard_False);
	myContextGlobal->SetMaterial(pink,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->Display(pink,Standard_False);

	OCCViewer_Update(1);

}

void MyDemo_OnShell() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

	TColgp_Array2OfPnt Poles(1,2,1,4);
	Poles.SetValue(1,1,gp_Pnt(0,0,0));
	Poles.SetValue(1,2,gp_Pnt(0,10,2));
	Poles.SetValue(1,3,gp_Pnt(0,20,10)); 
	Poles.SetValue(1,4,gp_Pnt(0,30,0)); 
	Poles.SetValue(2,1,gp_Pnt(10,0,5));
	Poles.SetValue(2,2,gp_Pnt(10,10,3));
	Poles.SetValue(2,3,gp_Pnt(10,20,20));
	Poles.SetValue(2,4,gp_Pnt(10,30,0));

	TColStd_Array1OfReal UKnots(1,2);
	UKnots.SetValue(1,0);
	UKnots.SetValue(2,1);

	TColStd_Array1OfInteger UMults(1,2);
	UMults.SetValue(1,2);
	UMults.SetValue(2,2);

	TColStd_Array1OfReal VKnots(1,3);
	VKnots.SetValue(1,0);
	VKnots.SetValue(2,1);
	VKnots.SetValue(3,2);

	TColStd_Array1OfInteger VMults(1,3);
	VMults.SetValue(1,3);
	VMults.SetValue(2,1);
	VMults.SetValue(3,3);

	Standard_Integer UDegree(1);
	Standard_Integer VDegree(2);
	
	Handle (Geom_BSplineSurface) BSpline = new Geom_BSplineSurface(Poles,UKnots,VKnots,UMults,VMults,UDegree,VDegree);
	
	TopoDS_Face WhiteFace = BRepBuilderAPI_MakeFace(BSpline, Precision::Confusion());

	
	Handle(AIS_Shape) white = new AIS_Shape(WhiteFace);
	myContextGlobal->SetColor (white, Quantity_NOC_WHITE, Standard_False);
	myContextGlobal->SetMaterial(white,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->SetTransparency (white, 0.7, Standard_False);
	myContextGlobal->Display(white,Standard_False);
	

	TopoDS_Shell aShell = BRepBuilderAPI_MakeShell(BSpline);
	Handle(AIS_Shape) anAISShell = new AIS_Shape(aShell);
	myContextGlobal->SetDisplayMode (anAISShell, 0, Standard_False);
	myContextGlobal->Display(anAISShell,Standard_False);
	//myContextGlobal->SetSelected(anAISShell);

	OCCViewer_Update(1);

	
}

void MyDemo_OnCompound() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

	BRep_Builder builder;
	TopoDS_Compound Comp;
	builder.MakeCompound(Comp);

	TopoDS_Vertex aVertex = BRepBuilderAPI_MakeVertex(gp_Pnt(-20,10,-30));
	builder.Add(Comp,aVertex);
	
	gp_Lin line(gp_Ax1(gp_Pnt(10,10,10),gp_Dir(1,0,0)));
	TopoDS_Edge anEdge = BRepBuilderAPI_MakeEdge(line,-20,10);
	builder.Add(Comp,anEdge);

	gp_Sphere sphere (gp_Ax3(gp_Pnt(-80,0,0),gp_Dir(1,0,0)),150);
	TopoDS_Face aFace = BRepBuilderAPI_MakeFace(sphere,0.1,0.7,0.2,0.9);
	builder.Add(Comp,aFace);

  TopoDS_Shape aBox = BRepPrimAPI_MakeBox(gp_Pnt(-60, 0, 0), 30, 60, 40).Shape();
	builder.Add(Comp,aBox);

	Handle(AIS_Shape) white = new AIS_Shape(Comp);
	myContextGlobal->SetDisplayMode (white, 0, Standard_False);
	myContextGlobal->Display(white,Standard_False);

	OCCViewer_Update(1);


}





void MyDemo_OnSewing() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

	gp_Pnt P(0,0,0);
	gp_Vec V(0,0,1);
	Handle(Geom_Plane) Pi=new Geom_Plane(P,V);
	Handle(Geom_RectangularTrimmedSurface) GeometricSurface=new Geom_RectangularTrimmedSurface(Pi,0.,100.,0.,100.);
	TopoDS_Shape FirstShape = BRepBuilderAPI_MakeFace(GeometricSurface, Precision::Confusion());
	
	Handle(AIS_Shape) white1 = new AIS_Shape(FirstShape);
	
	myContextGlobal->SetColor(white1,Quantity_NOC_RED,Standard_False);
	myContextGlobal->SetMaterial(white1,Graphic3d_NOM_PLASTIC,Standard_False); 
	myContextGlobal->SetTransparency(white1,0.4,Standard_False);
	myContextGlobal->Display(white1,Standard_False);
	//Sleep(1000);
	
	gp_Pnt P1(0,0,0);
	gp_Pnt P2(50,0,0);
	gp_Pnt P3(100,0,0);
	gp_Pnt P4(25,12,85);
	gp_Pnt P5(100,0,80);
	gp_Pnt P6(135,-12,85);

	TColgp_Array2OfPnt Array(1,3,1,2);
	Array.SetValue(1,1,P1);
	Array.SetValue(2,1,P2);
	Array.SetValue(3,1,P3);
	Array.SetValue(1,2,P4);
	Array.SetValue(2,2,P5);
	Array.SetValue(3,2,P6);

	Handle (Geom_BSplineSurface) aSurf = GeomAPI_PointsToBSplineSurface(Array,3,8,GeomAbs_C2,0.00001);
	TopoDS_Shape SecondShape = BRepBuilderAPI_MakeFace(aSurf, Precision::Confusion());
	
	Handle(AIS_Shape) white2 = new AIS_Shape(SecondShape);
	
	myContextGlobal->SetColor(white2,Quantity_NOC_YELLOW,Standard_False);
	myContextGlobal->SetMaterial(white2,Graphic3d_NOM_PLASTIC,Standard_False);  
	myContextGlobal->SetTransparency(white2,0.4,Standard_False);
	myContextGlobal->Display(white2,Standard_False);

	//Sleep(1000);
	
	BRepOffsetAPI_Sewing aMethod;
	aMethod.Add(FirstShape);	
	aMethod.Add(SecondShape);

	aMethod.Perform();

	TopoDS_Shape sewedShape = aMethod.SewedShape();

	Handle(AIS_Shape) result = new AIS_Shape(sewedShape);
	myContextGlobal->SetDisplayMode(result,0,Standard_False);
	myContextGlobal->Display(result,Standard_False);

	OCCViewer_Update(1);

}







void MyDemo_OnBuilder() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

	//The tolerance is the tolerance of confusion
	Standard_Real precision = Precision::Confusion();

	//The builder
	BRep_Builder B;

	//Build the vertices
	TopoDS_Vertex V000, V001, V010, V011, V100, V101, V110, V111;
	B.MakeVertex(V000,gp_Pnt(0,0,0),precision);
	B.MakeVertex(V001,gp_Pnt(0,0,100),precision);
	B.MakeVertex(V010,gp_Pnt(0,150,0),precision);
	B.MakeVertex(V011,gp_Pnt(0,150,100),precision);
	B.MakeVertex(V100,gp_Pnt(200,0,0),precision);
	B.MakeVertex(V101,gp_Pnt(200,0,100),precision);
	B.MakeVertex(V110,gp_Pnt(200,150,0),precision);
	B.MakeVertex(V111,gp_Pnt(200,150,100),precision);

	//Build the edges
	//the edges are oriented as the axis X,Y,Z
	TopoDS_Edge EX00, EX01, EX10, EX11;
	TopoDS_Edge EY00, EY01, EY10, EY11;
	TopoDS_Edge EZ00, EZ01, EZ10, EZ11;
	Handle (Geom_Line) L;

	//Edge X00
	L = new Geom_Line(gp_Pnt(0,0,0),gp_Dir(1,0,0));
	B.MakeEdge(EX00,L,precision);
	V000.Orientation(TopAbs_FORWARD);
	V100.Orientation(TopAbs_REVERSED);
	B.Add(EX00,V000);
	B.Add(EX00,V100);
	//Parameters
	B.UpdateVertex(V000,0,EX00,precision);
	B.UpdateVertex(V100,200,EX00,precision);

	//Edge X10
	L = new Geom_Line(gp_Pnt(0,150,0),gp_Dir(1,0,0));
	B.MakeEdge(EX10,L,precision);
	V010.Orientation(TopAbs_FORWARD);
	V110.Orientation(TopAbs_REVERSED);
	B.Add(EX10,V010);
	B.Add(EX10,V110);
	//Parameters
	B.UpdateVertex(V010,0,EX10,precision);
	B.UpdateVertex(V110,200,EX10,precision);

	//Edge Y00
	L = new Geom_Line(gp_Pnt(0,0,0),gp_Dir(0,1,0));
	B.MakeEdge(EY00,L,precision);
	V000.Orientation(TopAbs_FORWARD);
	V010.Orientation(TopAbs_REVERSED);
	B.Add(EY00,V000);
	B.Add(EY00,V010);
	//Parameters
	B.UpdateVertex(V000,0,EY00,precision);
	B.UpdateVertex(V010,150,EY00,precision);

	//Edge Y10
	L = new Geom_Line(gp_Pnt(200,0,0),gp_Dir(0,1,0));
	B.MakeEdge(EY10,L,precision);
	V100.Orientation(TopAbs_FORWARD);
	V110.Orientation(TopAbs_REVERSED);
	B.Add(EY10,V100);
	B.Add(EY10,V110);
	//Parameters
	B.UpdateVertex(V100,0,EY10,precision);
	B.UpdateVertex(V110,150,EY10,precision);

	//Edge Y01
	L = new Geom_Line(gp_Pnt(0,0,100),gp_Dir(0,1,0));
	B.MakeEdge(EY01,L,precision);
	V001.Orientation(TopAbs_FORWARD);
	V011.Orientation(TopAbs_REVERSED);
	B.Add(EY01,V001);
	B.Add(EY01,V011);
	//Parameters
	B.UpdateVertex(V001,0,EY01,precision);
	B.UpdateVertex(V011,150,EY01,precision);

	//Edge Y11
	L = new Geom_Line(gp_Pnt(200,0,100),gp_Dir(0,1,0));
	B.MakeEdge(EY11,L,precision);
	V101.Orientation(TopAbs_FORWARD);
	V111.Orientation(TopAbs_REVERSED);
	B.Add(EY11,V101);
	B.Add(EY11,V111);
	//Parameters
	B.UpdateVertex(V101,0,EY11,precision);
	B.UpdateVertex(V111,150,EY11,precision);

	//Edge Z00
	L = new Geom_Line(gp_Pnt(0,0,0),gp_Dir(0,0,1));
	B.MakeEdge(EZ00,L,precision);
	V000.Orientation(TopAbs_FORWARD);
	V001.Orientation(TopAbs_REVERSED);
	B.Add(EZ00,V000);
	B.Add(EZ00,V001);
	//Parameters
	B.UpdateVertex(V000,0,EZ00,precision);
	B.UpdateVertex(V001,100,EZ00,precision);

	//Edge Z01
	L = new Geom_Line(gp_Pnt(0,150,0),gp_Dir(0,0,1));
	B.MakeEdge(EZ01,L,precision);
	V010.Orientation(TopAbs_FORWARD);
	V011.Orientation(TopAbs_REVERSED);
	B.Add(EZ01,V010);
	B.Add(EZ01,V011);
	//Parameters
	B.UpdateVertex(V010,0,EZ01,precision);
	B.UpdateVertex(V011,100,EZ01,precision);

	//Edge Z10
	L = new Geom_Line(gp_Pnt(200,0,0),gp_Dir(0,0,1));
	B.MakeEdge(EZ10,L,precision);
	V100.Orientation(TopAbs_FORWARD);
	V101.Orientation(TopAbs_REVERSED);
	B.Add(EZ10,V100);
	B.Add(EZ10,V101);
	//Parameters
	B.UpdateVertex(V100,0,EZ10,precision);
	B.UpdateVertex(V101,100,EZ10,precision);

	//Edge Z11
	L = new Geom_Line(gp_Pnt(200,150,0),gp_Dir(0,0,1));
	B.MakeEdge(EZ11,L,precision);
	V110.Orientation(TopAbs_FORWARD);
	V111.Orientation(TopAbs_REVERSED);
	B.Add(EZ11,V110);
	B.Add(EZ11,V111);
	//Parameters
	B.UpdateVertex(V110,0,EZ11,precision);
	B.UpdateVertex(V111,100,EZ11,precision);


	//Circular Edges
	Handle (Geom_Circle) C;
	//Standard_Real R = 100;

	//Edge EX01
	C = new Geom_Circle(gp_Ax2(gp_Pnt(100,0,100),gp_Dir(0,1,0),gp_Dir(-1,0,0)),100);
	B.MakeEdge(EX01,C,precision);
	V001.Orientation(TopAbs_FORWARD);
	V101.Orientation(TopAbs_REVERSED);
	B.Add(EX01,V001);
	B.Add(EX01,V101);
	//Parameters
	B.UpdateVertex(V001,0,EX01,precision);
	B.UpdateVertex(V101,M_PI,EX01,precision);

	//Edge EX11
	C = new Geom_Circle(gp_Ax2(gp_Pnt(100,150,100),gp_Dir(0,1,0),gp_Dir(-1,0,0)),100);
	B.MakeEdge(EX11,C,precision);
	V011.Orientation(TopAbs_FORWARD);
	V111.Orientation(TopAbs_REVERSED);
	B.Add(EX11,V011);
	B.Add(EX11,V111);
	//Parameters
	B.UpdateVertex(V011,0,EX11,precision);
	B.UpdateVertex(V111,M_PI,EX11,precision);

	//Build wire and faces
	//Faces normals are along the axis X,Y,Z
	TopoDS_Face FXMIN, FXMAX, FYMIN, FYMAX, FZMIN, FZMAX;
	TopoDS_Wire W;
	Handle (Geom_Plane) P;
	Handle (Geom2d_Line) L2d;
	Handle (Geom2d_Circle) C2d;
	Handle (Geom_CylindricalSurface) S;

	//Face FXMAX
	P = new Geom_Plane(gp_Ax2(gp_Pnt(200,0,0),gp_Dir(1,0,0),gp_Dir(0,1,0)));
	B.MakeFace(FXMAX,P,precision);
	//the wire and the edges
	B.MakeWire (W);

	EY10.Orientation(TopAbs_FORWARD);
	B.Add(W,EY10);
	//pcurve
	L2d = new Geom2d_Line(gp_Pnt2d(0,0),gp_Dir2d(1,0));
	B.UpdateEdge(EY10,L2d,FXMAX,precision);

	EZ11.Orientation(TopAbs_FORWARD);
	B.Add(W,EZ11);
	//pcurve
	L2d = new Geom2d_Line(gp_Pnt2d(150,0),gp_Dir2d(0,1));
	B.UpdateEdge(EZ11,L2d,FXMAX,precision);

	EY11.Orientation(TopAbs_REVERSED);
	B.Add(W,EY11);
	//pcurve
	L2d = new Geom2d_Line(gp_Pnt2d(0,100),gp_Dir2d(1,0));
	B.UpdateEdge(EY11,L2d,FXMAX,precision);

	EZ10.Orientation(TopAbs_REVERSED);
	B.Add(W,EZ10);
	//pcurve
	L2d = new Geom2d_Line(gp_Pnt2d(0,0),gp_Dir2d(0,1));
	B.UpdateEdge(EZ10,L2d,FXMAX,precision);

	B.Add(FXMAX,W);

	//Face FXMIN
	P = new Geom_Plane(gp_Ax2(gp_Pnt(0,0,0),gp_Dir(-1,0,0),gp_Dir(0,0,1)));
	B.MakeFace(FXMIN,P,precision);
	//the wire and the edges
	B.MakeWire (W);

	EZ00.Orientation(TopAbs_FORWARD);
	B.Add(W,EZ00);
	//pcurve
	L2d = new Geom2d_Line(gp_Pnt2d(0,0),gp_Dir2d(1,0));
	B.UpdateEdge(EZ00,L2d,FXMIN,precision);

	EY01.Orientation(TopAbs_FORWARD);
	B.Add(W,EY01);
	//pcurve
	L2d = new Geom2d_Line(gp_Pnt2d(100,0),gp_Dir2d(0,1));
	B.UpdateEdge(EY01,L2d,FXMIN,precision);

	EZ01.Orientation(TopAbs_REVERSED);
	B.Add(W,EZ01);
	//pcurve
	L2d = new Geom2d_Line(gp_Pnt2d(0,150),gp_Dir2d(1,0));
	B.UpdateEdge(EZ01,L2d,FXMIN,precision);

	EY00.Orientation(TopAbs_REVERSED);
	B.Add(W,EY00);
	//pcurve
	L2d = new Geom2d_Line(gp_Pnt2d(0,0),gp_Dir2d(0,1));
	B.UpdateEdge(EY00,L2d,FXMIN,precision);


	B.Add(FXMIN,W);
	
	//Face FYMAX

	P = new Geom_Plane(gp_Ax2(gp_Pnt(0,0,0),gp_Dir(0,1,0),gp_Dir(0,0,1)));
	B.MakeFace(FYMAX,P,precision);
	//the wire and the edges
	B.MakeWire (W);

	EZ00.Orientation(TopAbs_FORWARD);
	B.Add(W,EZ00);
	//pcurve
	L2d = new Geom2d_Line(gp_Pnt2d(0,0),gp_Dir2d(1,0));
	B.UpdateEdge(EZ00,L2d,FYMAX,precision);

	EX01.Orientation(TopAbs_FORWARD);
	B.Add(W,EX01);
	//pcurve
	C2d = new Geom2d_Circle(gp_Ax2d(gp_Pnt2d(100,100),gp_Dir2d(0,-1)),100);
	B.UpdateEdge(EX01,C2d,FYMAX,precision);
	B.UpdateVertex(V001,0,EX01,FYMAX,precision);
	B.UpdateVertex(V101,M_PI,EX01,FYMAX,precision);

	EZ10.Orientation(TopAbs_REVERSED);
	B.Add(W,EZ10);
	//pcurve
	L2d = new Geom2d_Line(gp_Pnt2d(0,200),gp_Dir2d(1,0));
	B.UpdateEdge(EZ10,L2d,FYMAX,precision);

	EX00.Orientation(TopAbs_REVERSED);
	B.Add(W,EX00);
	//pcurve
	L2d = new Geom2d_Line(gp_Pnt2d(0,0),gp_Dir2d(0,1));
	B.UpdateEdge(EX00,L2d,FYMAX,precision);


	B.Add(FYMAX,W);



	//Face FYMIN
	P = new Geom_Plane(gp_Ax2(gp_Pnt(0,150,0),gp_Dir(0,1,0),gp_Dir(0,0,1)));
	B.MakeFace(FYMIN,P,precision);
	//the wire and the edges
	B.MakeWire (W);

	EZ01.Orientation(TopAbs_FORWARD);
	B.Add(W,EZ01);
	//pcurve
	L2d = new Geom2d_Line(gp_Pnt2d(0,0),gp_Dir2d(1,0));
	B.UpdateEdge(EZ01,L2d,FYMIN,precision);

	EX11.Orientation(TopAbs_FORWARD);
	B.Add(W,EX11);
	//pcurve
	C2d = new Geom2d_Circle(gp_Ax2d(gp_Pnt2d(100,100),gp_Dir2d(0,-1)),100);
	B.UpdateEdge(EX11,C2d,FYMIN,precision);
	B.UpdateVertex(V011,0,EX11,FYMIN,precision);
	B.UpdateVertex(V111,M_PI,EX11,FYMIN,precision);

	EZ11.Orientation(TopAbs_REVERSED);
	B.Add(W,EZ11);
	//pcurve
	L2d = new Geom2d_Line(gp_Pnt2d(0,200),gp_Dir2d(1,0));
	B.UpdateEdge(EZ11,L2d,FYMIN,precision);

	EX10.Orientation(TopAbs_REVERSED);
	B.Add(W,EX10);
	//pcurve
	L2d = new Geom2d_Line(gp_Pnt2d(0,0),gp_Dir2d(0,1));
	B.UpdateEdge(EX10,L2d,FYMIN,precision);

	B.Add(FYMIN,W);

	//Face FZMAX
	P = new Geom_Plane(gp_Ax2(gp_Pnt(0,0,0),gp_Dir(0,0,-1),gp_Dir(0,1,0)));
	B.MakeFace(FZMAX,P,precision);
	//the wire and the edges
	B.MakeWire (W);

	EY00.Orientation(TopAbs_FORWARD);
	B.Add(W,EY00);
	//pcurve
	L2d = new Geom2d_Line(gp_Pnt2d(0,0),gp_Dir2d(1,0));
	B.UpdateEdge(EY00,L2d,FZMAX,precision);

	EX10.Orientation(TopAbs_FORWARD);
	B.Add(W,EX10);
	//pcurve
	L2d = new Geom2d_Line(gp_Pnt2d(150,0),gp_Dir2d(0,1));
	B.UpdateEdge(EX10,L2d,FZMAX,precision);

	EY10.Orientation(TopAbs_REVERSED);
	B.Add(W,EY10);
	//pcurve
	L2d = new Geom2d_Line(gp_Pnt2d(0,200),gp_Dir2d(1,0));
	B.UpdateEdge(EY10,L2d,FZMAX,precision);

	EX00.Orientation(TopAbs_REVERSED);
	B.Add(W,EX00);
	//pcurve
	L2d = new Geom2d_Line(gp_Pnt2d(0,0),gp_Dir2d(0,1));
	B.UpdateEdge(EX00,L2d,FZMAX,precision);


	B.Add(FZMAX,W);
		
	//Face FZMIN
	S = new Geom_CylindricalSurface(gp_Ax3(gp_Pnt(100,0,100),gp_Dir(0,1,0),gp_Dir(-1,0,0)),100);
	B.MakeFace(FZMIN,S,precision);

	//the wire and the edges
	B.MakeWire (W);

	EX01.Orientation(TopAbs_FORWARD);
	B.Add(W,EX01);
	//pcurve
	L2d = new Geom2d_Line(gp_Ax2d(gp_Pnt2d(0,0),gp_Dir2d(1,0)));
	B.UpdateEdge(EX01,L2d,FZMIN,precision);
	B.UpdateVertex(V001,0,EX01,FZMIN,precision);
	B.UpdateVertex(V101,M_PI,EX01,FZMIN,precision);

	EY11.Orientation(TopAbs_FORWARD);
	B.Add(W,EY11);
	//pcurve
	L2d = new Geom2d_Line(gp_Pnt2d(M_PI,0),gp_Dir2d(0,1));
	B.UpdateEdge(EY11,L2d,FZMIN,precision);

	EX11.Orientation(TopAbs_REVERSED);
	B.Add(W,EX11);
	//pcurve
	L2d = new Geom2d_Line(gp_Ax2d(gp_Pnt2d(0,150),gp_Dir2d(1,0)));
	B.UpdateEdge(EX11,L2d,FZMIN,precision);
	B.UpdateVertex(V111,M_PI,EX11,FZMIN,precision);
	B.UpdateVertex(V011,0,EX11,FZMIN,precision);

	EY01.Orientation(TopAbs_REVERSED);
	B.Add(W,EY01);
	//pcurve
	L2d = new Geom2d_Line(gp_Pnt2d(0,0),gp_Dir2d(0,1));
	B.UpdateEdge(EY01,L2d,FZMIN,precision);

	B.Add(FZMIN,W);

	FYMAX.Orientation(TopAbs_REVERSED);

	//Shell
	TopoDS_Shell Sh;
	B.MakeShell(Sh);
	B.Add(Sh,FXMAX);
	B.Add(Sh,FXMIN);
	B.Add(Sh,FYMAX);
	B.Add(Sh,FYMIN);
	B.Add(Sh,FZMAX);
	B.Add(Sh,FZMIN);

	// Solid
	TopoDS_Solid Sol;
	B.MakeSolid(Sol);
	B.Add(Sol,Sh);

	Handle(AIS_Shape) borne = new AIS_Shape(Sol);
	myContextGlobal->SetDisplayMode (borne, 1, Standard_False);
	myContextGlobal->SetColor (borne, Quantity_NOC_RED, Standard_False);
	myContextGlobal->SetMaterial(borne,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->Display(borne,Standard_False);


	OCCViewer_Update(1);
 
}

void MyDemo_OnGeometrie() 
{
	AIS_ListOfInteractive aList;
	myContextGlobal->DisplayedObjects(aList);
	AIS_ListIteratorOfListOfInteractive aListIterator;
	for(aListIterator.Initialize(aList);aListIterator.More();aListIterator.Next()){
		myContextGlobal->Remove (aListIterator.Value(), Standard_False);
	}

	//geometry of a vertex
	TopoDS_Vertex aVertex = BRepBuilderAPI_MakeVertex(gp_Pnt(0,120,70));
	gp_Pnt GeometricPoint = BRep_Tool::Pnt(aVertex);

	Handle(AIS_Shape) vert = new AIS_Shape(aVertex);
	myContextGlobal->Display(vert,Standard_False);
	OCCViewer_Update(1);
	Sleep (500);

	//geometry of an edge
	TopoDS_Edge anEdge = BRepBuilderAPI_MakeEdge(gp_Pnt(100,50,250),gp_Pnt(-30,-100,-50));
	Handle(AIS_Shape) yellow = new AIS_Shape(anEdge);
	myContextGlobal->SetWidth(yellow,2,Standard_False);
	myContextGlobal->Display(yellow,Standard_False);
	OCCViewer_Update(1);
	Sleep (500);

	TopLoc_Location location;
	Standard_Real first, last;
	Handle (Geom_Curve) aCurve = BRep_Tool::Curve(anEdge,location,first,last);
	TopoDS_Edge anEdgeDS = BRepBuilderAPI_MakeEdge(aCurve);

	Handle (Geom_Line) aLine = Handle (Geom_Line)::DownCast(aCurve);
	if (!aLine.IsNull()) {
		Handle (AIS_Line) DispLine = new AIS_Line(aLine);
		myContextGlobal->Display(DispLine,Standard_False);
		OCCViewer_Update(1);
		Sleep (500);
	}
		
	//geometry of a face
	gp_Pnt P(-20,-20,-20);
	gp_Vec V(0,0,1);
	Handle(Geom_Plane) Pi=new Geom_Plane(P,V);
	Handle(Geom_RectangularTrimmedSurface) Surface=new Geom_RectangularTrimmedSurface(Pi,0.,100.,0.,100.);
	TopoDS_Face RedFace = BRepBuilderAPI_MakeFace(Surface, Precision::Confusion());

	Handle(AIS_Shape) red = new AIS_Shape(RedFace);
	myContextGlobal->SetColor(red,Quantity_NOC_RED,Standard_False);
	myContextGlobal->SetMaterial(red,Graphic3d_NOM_PLASTIC,Standard_False);    
	myContextGlobal->Display(red,Standard_False);
	OCCViewer_Update(1);
	Sleep (500);

	TopLoc_Location location2;
	Handle (Geom_Surface) aGeometricSurface = BRep_Tool::Surface(RedFace,location2);

	Handle (Geom_Plane) aPlane = Handle (Geom_Plane)::DownCast(aGeometricSurface);
	if (!aPlane.IsNull()) {
		Handle (AIS_Plane) DispPlane = new AIS_Plane(aPlane);
		myContextGlobal->Display(DispPlane,Standard_False);

	}


	OCCViewer_Update(1);
	Sleep (500);

}

void MyDemo_OnExplorer() 
{
	myContextGlobal->RemoveAll (false);
	
	TopoDS_Shape aBox = BRepPrimAPI_MakeBox(100, 100, 100).Shape();
	Standard_Integer j(8);
	Handle(AIS_ColoredShape) theBox = new AIS_ColoredShape(aBox);
	myContextGlobal->SetColor(theBox,Quantity_NOC_RED,Standard_False);
	myContextGlobal->SetMaterial(theBox,Graphic3d_NOM_PLASTIC,Standard_False);  
	myContextGlobal->Display(theBox, AIS_Shaded, 0,Standard_False);
	OCCViewer_Update(1);
	Sleep(500);

	for (TopExp_Explorer exp (aBox,TopAbs_FACE);exp.More();exp.Next())
	{
		TopoDS_Face aCurrentFace = TopoDS::Face(exp.Current());
		{
			Handle(AIS_ColoredDrawer) aSubFaceAspects = theBox->CustomAspects (aCurrentFace);
			aSubFaceAspects->SetShadingAspect (new Prs3d_ShadingAspect());
			*aSubFaceAspects->ShadingAspect()->Aspect() = *theBox->Attributes()->ShadingAspect()->Aspect();
			aSubFaceAspects->ShadingAspect()->Aspect()->ChangeFrontMaterial().SetTransparency (0.8f);
			myContextGlobal->Redisplay (theBox, false);
		}

		//test the orientation of the current face
		TopAbs_Orientation orient = aCurrentFace.Orientation();

		//Recover the geometric plane
		TopLoc_Location location;
		Handle (Geom_Surface) aGeometricSurface = BRep_Tool::Surface(aCurrentFace,location);

		Handle (Geom_Plane) aPlane = Handle (Geom_Plane)::DownCast(aGeometricSurface);

		//Build an AIS_Shape with a new color
		Handle(AIS_Shape) theMovingFace = new AIS_Shape(aCurrentFace);
		Quantity_NameOfColor aCurrentColor = (Quantity_NameOfColor)j;
		myContextGlobal->SetColor(theMovingFace,aCurrentColor,Standard_False);
		myContextGlobal->SetMaterial(theMovingFace,Graphic3d_NOM_PLASTIC,Standard_False);  
		//Find the normal vector of each face
		gp_Pln agpPlane = aPlane->Pln();
		gp_Ax1 norm = agpPlane.Axis();
		gp_Dir dir = norm.Direction();
		gp_Vec move(dir);

		TopLoc_Location aLocation;
		Handle (AIS_ConnectedInteractive) theTransformedDisplay = new AIS_ConnectedInteractive();
		theTransformedDisplay->Connect(theMovingFace, aLocation);

		Handle (Geom_Transformation) theMove = new Geom_Transformation(aLocation.Transformation());
        myContextGlobal->Display(theTransformedDisplay,Standard_False);
		myContextGlobal->UpdateCurrentViewer();
		Sleep (500);

		for (Standard_Integer i=1;i<=30;i++)
		{
			theMove->SetTranslation(move*i);
			if (orient==TopAbs_FORWARD) myContextGlobal->SetLocation(theTransformedDisplay,TopLoc_Location(theMove->Trsf()));
			else myContextGlobal->SetLocation(theTransformedDisplay,TopLoc_Location(theMove->Inverted()->Trsf()));

			myContextGlobal->Redisplay(theTransformedDisplay,true);
		}
		j+=15;
	}

	myContextGlobal->UpdateCurrentViewer();
	Sleep (500);

}


// llamadas desde FreeBasic
void OCCViewer_Demo(int MyDemo)
{
	// contexto global para cada figura creada, en modo solido
	myContextGlobal->SetDisplayMode(AIS_Shaded,Standard_False);
	
        if(MyDemo==  0) MyDemo_OnMirror();
        if(MyDemo==  1) MyDemo_OnMirroraxis();
        if(MyDemo==  2) MyDemo_OnRotate();
        if(MyDemo==  3) MyDemo_OnScale();
        if(MyDemo==  4) MyDemo_OnTranslation();
        if(MyDemo==  5) MyDemo_OnDisplacement();
        if(MyDemo==  6) MyDemo_OnDeform();
        if(MyDemo==  7) MyDemo_OnBox();
        if(MyDemo==  8) MyDemo_OnCylinder();
        if(MyDemo==  9) MyDemo_OnCone();
        if(MyDemo== 10) MyDemo_OnSphere();
        if(MyDemo== 11) MyDemo_OnTorus();
        if(MyDemo== 12) MyDemo_OnWedge();
        if(MyDemo== 13) MyDemo_OnPrism();
        if(MyDemo== 14) MyDemo_OnRevol();
        if(MyDemo== 15) MyDemo_OnPipe();
        if(MyDemo== 16) MyDemo_OnThru();
        if(MyDemo== 17) MyDemo_OnEvolved();
        if(MyDemo== 18) MyDemo_OnDraft();
        if(MyDemo== 19) MyDemo_OnCut();
        if(MyDemo== 20) MyDemo_OnFuse();
        if(MyDemo== 21) MyDemo_OnCommon();
        if(MyDemo== 22) MyDemo_OnSection();
        if(MyDemo== 23) MyDemo_OnPsection();
        if(MyDemo== 24) MyDemo_OnBlend();
        if(MyDemo== 25) MyDemo_OnEvolvedblend();
        if(MyDemo== 26) MyDemo_OnChamf();
        if(MyDemo== 27) MyDemo_OnPrismLocal();
		  if(MyDemo== 28) MyDemo_OnDprismLocal();
        if(MyDemo== 29) MyDemo_OnRevolLocal();
        if(MyDemo== 30) MyDemo_OnPipeLocal();
        if(MyDemo== 31) MyDemo_OnLinearLocal();
        if(MyDemo== 32) MyDemo_OnGlueLocal();
        if(MyDemo== 33) MyDemo_OnSplitLocal();
        if(MyDemo== 34) MyDemo_OnThickLocal();
        if(MyDemo== 35) MyDemo_OnOffsetLocal();
        if(MyDemo== 36) MyDemo_OnVertex();
        if(MyDemo== 37) MyDemo_OnEdge();
        if(MyDemo== 38) MyDemo_OnWire();
        if(MyDemo== 39) MyDemo_OnFace();
        if(MyDemo== 40) MyDemo_OnShell();
        if(MyDemo== 41) MyDemo_OnCompound();
        if(MyDemo== 42) MyDemo_OnSewing();
        if(MyDemo== 43) MyDemo_OnBuilder();
        if(MyDemo== 44) MyDemo_OnGeometrie();
        if(MyDemo== 45) MyDemo_OnExplorer();
}