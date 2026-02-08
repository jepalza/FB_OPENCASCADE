#include <occ_types.h>

#ifdef __cplusplus
#include <gp_Pln.hxx>
extern "C" {
#endif
    __declspec(dllexport) gpPln __cdecl gpPln_Init();
    __declspec(dllexport) gpPln __cdecl gpPln_InitAx3(gpAx3 coord);
    __declspec(dllexport) gpPln __cdecl gpPln_InitPntDir(gpPnt origin, gpDir dir);
    __declspec(dllexport) gpAx1 __cdecl gpPln_Axis(gpPln plane);
    __declspec(dllexport) gpAx3 __cdecl gpPln_Position(gpPln plane);
    __declspec(dllexport) bool __cdecl gpPln_ContainsPoint(gpPln plane, gpPnt point);
    __declspec(dllexport) void __cdecl gpPln_Free(gpPln plane);
#ifdef __cplusplus
}
#endif
