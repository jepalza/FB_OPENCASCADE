#include <occ_types.h>

#ifdef __cplusplus
#include <TopTools_ListOfShape.hxx>
extern "C" {
#endif
    __declspec(dllexport) TopToolsListOfShape __cdecl TopToolsListOfShape_Init();
    __declspec(dllexport) void __cdecl TopToolsListOfShape_Free(TopToolsListOfShape list);
    __declspec(dllexport) TopoDSShape __cdecl TopToolsListOfShape_Append(TopToolsListOfShape list, TopoDSShape shape);
    __declspec(dllexport) void __cdecl TopToolsListOfShape_AppendList(TopToolsListOfShape list, TopToolsListOfShape other);
    __declspec(dllexport) int __cdecl TopToolsListOfShape_Extent(TopToolsListOfShape list);
    __declspec(dllexport) ShapeIterator __cdecl TopToolsListOfShape_Begin(TopToolsListOfShape list);
    __declspec(dllexport) ShapeIterator __cdecl ShapeIterator_Next(ShapeIterator iter);
    __declspec(dllexport) TopoDSShape __cdecl ShapeIterator_Shape(ShapeIterator iter);
#ifdef __cplusplus
}
#endif
