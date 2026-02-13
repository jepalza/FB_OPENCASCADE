#include <occ_types.h>

#ifdef __cplusplus
#include <BRepPrimAPI_MakePrism.hxx>
#include <BRepPrimAPI_MakeRevol.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
extern "C" {
#endif

    __declspec(dllexport) BRepPrimAPIMakeRevol __cdecl BRepPrimAPIMakeRevol_Init(TopoDSFace face, gpAx1 axis, double degrees);
    __declspec(dllexport) TopoDSShape __cdecl BRepPrimAPIMakeRevol_Shape(BRepPrimAPIMakeRevol makeRevol);
    __declspec(dllexport) void __cdecl BRepPrimAPIMakeRevol_Free(BRepPrimAPIMakeRevol makeRevol);
    
    __declspec(dllexport) BRepPrimAPIMakePrism __cdecl BRepPrimAPIMakePrism_Init(TopoDSFace face, gpVec vec);
    __declspec(dllexport) TopoDSShape __cdecl BRepPrimAPIMakePrism_Shape(BRepPrimAPIMakePrism makePrism);
    __declspec(dllexport) void __cdecl BRepPrimAPIMakePrism_Free(BRepPrimAPIMakePrism makePrism);
    
    __declspec(dllexport) BRepPrimAPIMakeCylinder __cdecl BRepPrimAPIMakeCylinder_Init(gpAx2 position, double radius, double height);
    __declspec(dllexport) TopoDSShape __cdecl BRepPrimAPIMakeCylinder_Shape(BRepPrimAPIMakeCylinder makeCylinder);
    __declspec(dllexport) void __cdecl BRepPrimAPIMakeCylinder_Free(BRepPrimAPIMakeCylinder makeCylinder);
    
    __declspec(dllexport) BRepPrimAPIMakeBox __cdecl BRepPrimAPIMakeBox_Init(gpAx2 position, double dx, double dy, double dz);
    __declspec(dllexport) TopoDSShape __cdecl BRepPrimAPIMakeBox_Shape(BRepPrimAPIMakeBox makeBox);
    __declspec(dllexport) void __cdecl BRepPrimAPIMakeBox_Free(BRepPrimAPIMakeBox makeBox);

	// Joseba Epalza, 2026, incluido la creacion de esferas
    __declspec(dllexport) BRepPrimAPIMakeSphere __cdecl BRepPrimAPIMakeSphere_Init(gpAx2 position, double rad);
    __declspec(dllexport) TopoDSShape __cdecl BRepPrimAPIMakeSphere_Shape(BRepPrimAPIMakeSphere makeSphere);
    __declspec(dllexport) void __cdecl BRepPrimAPIMakeSphere_Free(BRepPrimAPIMakeSphere makeSphere);
	
#ifdef __cplusplus
}
#endif
