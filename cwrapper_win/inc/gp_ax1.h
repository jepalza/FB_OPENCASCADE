#include <occ_types.h>

#ifdef __cplusplus
#include <gp_Ax1.hxx>
extern "C" {
#endif
    __declspec(dllexport) gpAx1 __cdecl gpAx1_Init(gpPnt origin, gpDir dir);
    __declspec(dllexport) gpDir __cdecl gpAx1_Direction(gpAx1 axis);
    __declspec(dllexport) void __cdecl gpAx1_Free(gpAx1 axis);
#ifdef __cplusplus
}
#endif
