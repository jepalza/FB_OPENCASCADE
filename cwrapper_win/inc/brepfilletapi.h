#include <occ_types.h>

#ifdef __cplusplus
#include <BRepFilletAPI_MakeFillet.hxx>
extern "C" {
#endif

    __declspec(dllexport) BRepFilletAPIMakeFillet __cdecl BRepFilletAPIMakeFillet_Init(TopoDSShape shape);
    __declspec(dllexport) void __cdecl BRepFilletAPIMakeFillet_Add(BRepFilletAPIMakeFillet fillet, TopoDSEdge edge, double radius);
    __declspec(dllexport) TopoDSShape __cdecl BRepFilletAPIMakeFillet_Shape(BRepFilletAPIMakeFillet fillet);
    __declspec(dllexport) void __cdecl BRepFilletAPIMakeFillet_Free(BRepFilletAPIMakeFillet fillet);
    __declspec(dllexport) BRepFilletAPIMakeChamfer __cdecl BRepFilletAPIMakeChamfer_Init(TopoDSShape shape);
    __declspec(dllexport) void __cdecl BRepFilletAPIMakeChamfer_Add(BRepFilletAPIMakeChamfer f, TopoDSEdge e, double radius);
    __declspec(dllexport) TopoDSShape __cdecl BRepFilletAPIMakeChamfer_Shape(BRepFilletAPIMakeChamfer f);
    __declspec(dllexport) void __cdecl BRepFilletAPIMakeChamfer_Free(BRepFilletAPIMakeChamfer f);

#ifdef __cplusplus
}
#endif
