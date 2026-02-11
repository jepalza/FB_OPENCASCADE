
del /s *.o

del ..\FBOCC_WIN\FBOCCWrapper.dll
del _resultado.txt

set OPTS= -std=c++11 -O3 -w  -D_WIN32 -fpermissive

set DIRINC=-I./inc -I../OpenCascade/inc
set DIRLIB=-L../OpenCascade/lib/

set LIBS= -lTKBin -lTKBinL -lTKBinTObj -lTKBinXCAF -lTKBO -lTKBool -lTKBRep -lTKCAF -lTKCDF  -lTKernel -lTKFeat -lTKFillet -lTKG2d -lTKG3d -lTKGeomAlgo -lTKGeomBase -lTKHLR -lTKIGES -lTKLCAF -lTKMath -lTKMesh -lTKMeshVS -lTKOffset -lTKOpenGl -lTKPrim -lTKRWMesh -lTKService -lTKShHealing -lTKStd -lTKStdL -lTKSTEP -lTKSTEP209 -lTKSTEPAttr -lTKSTEPBase -lTKSTL -lTKTObj -lTKTopAlgo -lTKV3d -lTKVCAF -lTKVRML -lTKXCAF -lTKXDEIGES -lTKXDESTEP -lTKXMesh -lTKXml -lTKXmlL -lTKXmlTObj -lTKXmlXCAF -lTKXSBase

G++ %OPTS% %DIRINC% -c src\occviewer.cpp              -o .\obj\occviewer.o             2>>_resultado.txt

G++ %OPTS% %DIRINC% -c src\brepalgoapi.cpp            -o .\obj\brepalgoapi.o           2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\brepfilletapi.cpp          -o .\obj\brepfilletapi.o         2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\brepgprop.cpp              -o .\obj\brepgprop.o             2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\brepmesh.cpp               -o .\obj\brepmesh.o              2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\brepprimapi.cpp            -o .\obj\brepprimapi.o           2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\breptools.cpp              -o .\obj\breptools.o             2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\brep_adapter.cpp           -o .\obj\brep_adapter.o          2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\brep_builder.cpp           -o .\obj\brep_builder.o          2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\brep_tool.cpp              -o .\obj\brep_tool.o             2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\gcpnts.cpp                 -o .\obj\gcpnts.o                2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\geomlprop_slprops.cpp      -o .\obj\geomlprop_slprops.o     2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\geom_adapter.cpp           -o .\obj\geom_adapter.o          2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\geom_curve.cpp             -o .\obj\geom_curve.o            2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\gprop.cpp                  -o .\obj\gprop.o                 2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\gp_ax1.cpp                 -o .\obj\gp_ax1.o                2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\gp_ax2.cpp                 -o .\obj\gp_ax2.o                2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\gp_ax3.cpp                 -o .\obj\gp_ax3.o                2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\gp_circ.cpp                -o .\obj\gp_circ.o               2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\gp_dir.cpp                 -o .\obj\gp_dir.o                2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\gp_pln.cpp                 -o .\obj\gp_pln.o                2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\gp_pnt.cpp                 -o .\obj\gp_pnt.o                2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\gp_quaternion.cpp          -o .\obj\gp_quaternion.o         2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\gp_trsf.cpp                -o .\obj\gp_trsf.o               2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\gp_vec.cpp                 -o .\obj\gp_vec.o                2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\occutils.cpp               -o .\obj\occutils.o              2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\stepcontrol_writer.cpp     -o .\obj\stepcontrol_writer.o    2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\stlapi_writer.cpp          -o .\obj\stlapi_writer.o         2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\igescontrol_writer.cpp     -o .\obj\igescontrol_writer.o    2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\topexp_explorer.cpp        -o .\obj\topexp_explorer.o       2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\toploc_location.cpp        -o .\obj\toploc_location.o       2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\topods_compound.cpp        -o .\obj\topods_compound.o       2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\topods_shape.cpp           -o .\obj\topods_shape.o          2>>_resultado.txt
G++ %OPTS% %DIRINC% -c src\toptools_listofshape.cpp   -o .\obj\toptools_listofshape.o  2>>_resultado.txt


G++ ^
  .\obj\occviewer.o ^
  .\obj\brepalgoapi.o ^
  .\obj\brepfilletapi.o ^
  .\obj\brepgprop.o ^
  .\obj\brepmesh.o ^
  .\obj\brepprimapi.o ^
  .\obj\breptools.o ^
  .\obj\brep_adapter.o ^
  .\obj\brep_builder.o ^
  .\obj\brep_tool.o ^
  .\obj\gcpnts.o ^
  .\obj\geomlprop_slprops.o ^
  .\obj\geom_adapter.o ^
  .\obj\geom_curve.o ^
  .\obj\gprop.o ^
  .\obj\gp_ax1.o ^
  .\obj\gp_ax2.o ^
  .\obj\gp_ax3.o ^
  .\obj\gp_circ.o ^
  .\obj\gp_dir.o ^
  .\obj\gp_pln.o ^
  .\obj\gp_pnt.o ^
  .\obj\gp_quaternion.o ^
  .\obj\gp_trsf.o ^
  .\obj\gp_vec.o ^
  .\obj\occutils.o ^
  .\obj\stepcontrol_writer.o ^
  .\obj\stlapi_writer.o ^
  .\obj\igescontrol_writer.o ^
  .\obj\topexp_explorer.o ^
  .\obj\toploc_location.o ^
  .\obj\topods_compound.o ^
  .\obj\topods_shape.o ^
  .\obj\toptools_listofshape.o ^
  %DIRLIB% ^
  %LIBS% ^
  -o ..\FBOCC_WIN\FBOCCWrapper.dll -shared ^
     2>>_resultado.txt
