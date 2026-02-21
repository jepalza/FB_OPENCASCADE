#include <occ_types.h>

#ifdef __cplusplus
#include <TopoDS_Shape.hxx>
extern "C" {
#endif
    __declspec(dllexport) bool __cdecl TopoDSShape_IsEqual(TopoDSShape shape, TopoDSShape other);
    __declspec(dllexport) void __cdecl TopoDSShape_Free(TopoDSShape shape);
    __declspec(dllexport) TopLocLocation __cdecl TopoDSShape_Location(TopoDSShape shape);
    __declspec(dllexport) int __cdecl TopoDSShape_Orientation(TopoDSShape shape);
#ifdef __cplusplus
}
#endif
