#include <occ_types.h>

#ifdef __cplusplus
#include <gp_Dir.hxx>
extern "C" {
#endif
    __declspec(dllexport) gpDir __cdecl gpDir_Init(double x, double y, double z);
    __declspec(dllexport) gpDir __cdecl gpDir_InitVec(gpVec vector);
    __declspec(dllexport) void __cdecl gpDir_Free(gpDir dir);
    __declspec(dllexport) double __cdecl gpDir_X(gpDir dir);
    __declspec(dllexport) double __cdecl gpDir_Y(gpDir dir);
    __declspec(dllexport) double __cdecl gpDir_Z(gpDir dir);
    __declspec(dllexport) double __cdecl gpDir_Dot(gpDir dir, gpDir other);
    __declspec(dllexport) bool __cdecl gpDir_IsEqual(gpDir dir, gpDir other);
    __declspec(dllexport) bool __cdecl gpDir_IsParallel(gpDir dir, gpDir other);
#ifdef __cplusplus
}
#endif
