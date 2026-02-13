#include <occ_types.h>

#ifdef __cplusplus
#include <gp_Vec.hxx>
extern "C" {
#endif
    __declspec(dllexport) double __cdecl gpResolution();
    __declspec(dllexport) gpVec __cdecl gpVec_Init(double x, double y, double z);
    __declspec(dllexport) gpVec __cdecl gpVec_InitDir(gpDir dir);
    __declspec(dllexport) gpVec __cdecl gpVec_InitPoints(gpPnt start, gpPnt end);
    __declspec(dllexport) void __cdecl gpVec_Free(gpVec vector);
    __declspec(dllexport) double __cdecl gpVec_X(gpVec vec);
    __declspec(dllexport) double __cdecl gpVec_Y(gpVec vec);
    __declspec(dllexport) double __cdecl gpVec_Z(gpVec vec);
    __declspec(dllexport) bool __cdecl gpVec_IsEqual(gpVec vec, gpVec other);
    __declspec(dllexport) double __cdecl gpVec_Dot(gpVec v, gpVec other);
    __declspec(dllexport) gpVec __cdecl gpVec_Multiplied(gpVec v, double dist);
    __declspec(dllexport) gpVec __cdecl gpVec_Crossed(gpVec v, gpVec other);
    __declspec(dllexport) gpVec __cdecl gpVec_Normalized(gpVec v);
    __declspec(dllexport) double __cdecl gpVec_Magnitude(gpVec v);
#ifdef __cplusplus
}
#endif
