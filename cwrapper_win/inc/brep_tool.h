#include <occ_types.h>

#ifdef __cplusplus
#include <BRep_Tool.hxx>
extern "C" {
#endif

    __declspec(dllexport) gcSurface __cdecl BRepTool_Surface(TopoDSFace face);
    __declspec(dllexport) void __cdecl GCSurface_Free(gcSurface surface);
    __declspec(dllexport) gpPnt __cdecl BRepTool_Pnt(TopoDSVertex vertex);

#ifdef __cplusplus
}
#endif
