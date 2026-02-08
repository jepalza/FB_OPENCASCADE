#include <occ_types.h>

#ifdef __cplusplus
#include <gp_Ax2.hxx>
extern "C" {
#endif
    __declspec(dllexport) gpCirc __cdecl gpCirc_Init(gpAx2 center, double radius);
    __declspec(dllexport) double __cdecl gpCirc_Radius(gpCirc circle);
    __declspec(dllexport) gpPnt __cdecl gpCirc_Location(gpCirc circle);
    __declspec(dllexport) void __cdecl gpCirc_Free(gpCirc circle);
#ifdef __cplusplus
}
#endif
