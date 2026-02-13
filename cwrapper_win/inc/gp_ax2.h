#include <occ_types.h>

#ifdef __cplusplus
#include <gp_Ax2.hxx>
extern "C" {
#endif
    __declspec(dllexport) gpAx2 __cdecl gpAx2_Init(gpPnt origin, gpDir normal, gpDir xAxis);
    __declspec(dllexport) void __cdecl gpAx2_Free(gpAx2 axis);
#ifdef __cplusplus
}
#endif
