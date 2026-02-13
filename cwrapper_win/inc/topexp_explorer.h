
#include <occ_types.h>

typedef int TopAbsShapeEnum;

#ifdef __cplusplus
#include <TopAbs_ShapeEnum.hxx>
#include <TopExp_Explorer.hxx>
extern "C" {
#endif
    __declspec(dllexport) TopExpExplorer __cdecl TopExpExplorer_Init(TopoDSShape shape, TopAbsShapeEnum toFind);
    __declspec(dllexport) void __cdecl TopExpExplorer_Free(TopExpExplorer exp);
    __declspec(dllexport) bool __cdecl TopExpExplorer_More(TopExpExplorer exp);
    __declspec(dllexport) void __cdecl TopExpExplorer_Next(TopExpExplorer exp);
    __declspec(dllexport) TopoDSShape __cdecl TopExpExplorer_Current(TopExpExplorer exp);
    __declspec(dllexport) int __cdecl TopExpExplorer_Depth(TopExpExplorer exp);
    __declspec(dllexport) TopoDSVertex __cdecl TopExp_FirstVertex(TopoDSEdge edge);
    __declspec(dllexport) TopoDSVertex __cdecl TopExp_LastVertex(TopoDSEdge edge);
#ifdef __cplusplus
}
#endif
