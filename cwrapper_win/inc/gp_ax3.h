#include <occ_types.h>

#ifdef __cplusplus
#include <gp_Ax3.hxx>
extern "C" {
#endif
    __declspec(dllexport) gpAx3 __cdecl gpAx3_Init(gpPnt origin, gpDir normal, gpDir xDir);
    __declspec(dllexport) gpDir __cdecl gpAx3_XDirection(gpAx3 coord);
    __declspec(dllexport) gpDir __cdecl gpAx3_YDirection(gpAx3 coord);
    __declspec(dllexport) gpDir __cdecl gpAx3_Direction(gpAx3 coord);
    __declspec(dllexport) gpPnt __cdecl gpAx3_Location(gpAx3 coord);
    __declspec(dllexport) void __cdecl gpAx3_Rotate(gpAx3 coord, gpAx1 axis, double angle);
    __declspec(dllexport) gpAx3 __cdecl gpAx3_Translated(gpAx3 coord, gpVec vec);
    __declspec(dllexport) void __cdecl gpAx3_Free(gpAx3 coord);
#ifdef __cplusplus
}
#endif
