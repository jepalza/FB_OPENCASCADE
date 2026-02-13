#include <occ_types.h>

#ifdef __cplusplus
#include <BRepAlgoAPI_BooleanOperation.hxx>
extern "C" {
#endif

    __declspec(dllexport) BRepAlgoAPIFuse __cdecl BRepAlgoAPIFuse_Init();
    __declspec(dllexport) void __cdecl BRepAlgoAPIFuse_Free(BRepAlgoAPIFuse algo);
    __declspec(dllexport) BRepAlgoAPICut __cdecl BRepAlgoAPICut_Init();
    __declspec(dllexport) void __cdecl BRepAlgoAPICut_Free(BRepAlgoAPICut algo);
    __declspec(dllexport) BRepAlgoAPIBooleanOperation __cdecl BRepAlgoAPIFuse_ToBooleanOperation(BRepAlgoAPIFuse algo);
    __declspec(dllexport) BRepAlgoAPIBooleanOperation __cdecl BRepAlgoAPICut_ToBooleanOperation(BRepAlgoAPICut algo);
    
    __declspec(dllexport) TopoDSShape __cdecl BRepAlgoAPIBooleanOperation_Shape(BRepAlgoAPIBooleanOperation op);
    __declspec(dllexport) void __cdecl BRepAlgoAPIBooleanOperation_SetTools(BRepAlgoAPIBooleanOperation op, TopToolsListOfShape list);
    __declspec(dllexport) void __cdecl BRepAlgoAPIBooleanOperation_SetArguments(BRepAlgoAPIBooleanOperation op, TopToolsListOfShape list);
    __declspec(dllexport) void __cdecl BRepAlgoAPIBooleanOperation_Build(BRepAlgoAPIBooleanOperation op);
    __declspec(dllexport) void __cdecl BRepAlgoAPIBooleanOperation_Free(BRepAlgoAPIBooleanOperation op);

#ifdef __cplusplus
}
#endif
