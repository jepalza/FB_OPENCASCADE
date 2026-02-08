#include <occ_types.h>

#ifdef __cplusplus
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_Transform.hxx>
extern "C" {
#endif
    __declspec(dllexport) BRepBuilder __cdecl BRepBuilder_Init();
    __declspec(dllexport) void __cdecl BRepBuilder_MakeCompound(BRepBuilder builder, TopoDSCompound res);
    __declspec(dllexport) void __cdecl BRepBuilder_Add(BRepBuilder builder, TopoDSShape res, TopoDSShape shape);
    __declspec(dllexport) void __cdecl BRepBuilder_Free(BRepBuilder builder);

    __declspec(dllexport) void __cdecl BRepBuilderAPI_SetPrecision(double precision);
    __declspec(dllexport) BRepBuilderAPIMakeEdge __cdecl BRepBuilderAPIMakeEdge_InitWithGeomCurve(GeomCurve curve);
    __declspec(dllexport) TopoDSEdge __cdecl BRepBuilderAPIMakeEdge_ToTopoDSEdge(BRepBuilderAPIMakeEdge edge);
    __declspec(dllexport) void __cdecl BRepBuilderAPIMakeEdge_Free(BRepBuilderAPIMakeEdge edge);

    __declspec(dllexport) BRepBuilderAPIMakeWire __cdecl BRepBuilderAPIMakeWire_Init();
    __declspec(dllexport) BRepBuilderAPIMakeWire __cdecl BRepBuilderAPIMakeWire_InitWithTopoDSEdge(TopoDSEdge edge);
    __declspec(dllexport) void __cdecl BRepBuilderAPIMakeWire_AddEdge(BRepBuilderAPIMakeWire wire, TopoDSEdge edge);
    __declspec(dllexport) void __cdecl BRepBuilderAPIMakeWire_AddWire(BRepBuilderAPIMakeWire makeWire, TopoDSWire wire);
    __declspec(dllexport) TopoDSWire __cdecl BRepBuilderAPIMakeWire_ToTopoDSWire(BRepBuilderAPIMakeWire wire);
    __declspec(dllexport) void __cdecl BRepBuilderAPIMakeWire_Free(BRepBuilderAPIMakeWire wire);

    __declspec(dllexport) BRepBuilderAPIMakeFace __cdecl BRepBuilderAPIMakeFace_InitWithWire(TopoDSWire wire);
    __declspec(dllexport) TopoDSFace __cdecl BRepBuilderAPIMakeFace_ToTopoDSFace(BRepBuilderAPIMakeFace face);
    __declspec(dllexport) void __cdecl BRepBuilderAPIMakeFace_Free(BRepBuilderAPIMakeFace face);

    __declspec(dllexport) TopoDSShape __cdecl BRepBuilderAPIMakeShape_Shape(BRepBuilderAPIMakeShape makeShape);

    __declspec(dllexport) BRepBuilderAPITransform __cdecl BRepBuilderAPITransform_InitWithShapeTrsf(TopoDSShape shape, gpTrsf trsf);
    __declspec(dllexport) TopoDSShape __cdecl BRepBuilderAPITransform_Shape(BRepBuilderAPITransform breptrsf);
    __declspec(dllexport) void __cdecl BRepBuilderAPITransform_Free(BRepBuilderAPITransform breptrsf);
#ifdef __cplusplus
}
#endif
