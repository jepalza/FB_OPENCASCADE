#include <occ_types.h>

#ifdef __cplusplus
#include <TopLoc_Location.hxx>
extern "C" {
#endif
    __declspec(dllexport) void __cdecl TopLocLocation_Free(TopLocLocation loc);
    __declspec(dllexport) gpTrsf __cdecl TopLocLocation_Transformation(TopLocLocation loc);
#ifdef __cplusplus
}
#endif
