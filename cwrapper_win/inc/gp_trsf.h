#include <occ_types.h>

#ifdef __cplusplus
#include <gp_Trsf.hxx>
extern "C" {
#endif
    __declspec(dllexport) gpTrsf __cdecl gpTrsf_Init();
    __declspec(dllexport) void __cdecl gpTrsf_SetMirror(gpTrsf trsf, gpAx1 axis);
    __declspec(dllexport) void __cdecl gpTrsf_SetMirrorAx1(gpTrsf transform, gpAx1 axis);
    __declspec(dllexport) void __cdecl gpTrsf_SetMirrorAx2(gpTrsf transform, gpAx2 axis);
    __declspec(dllexport) void __cdecl gpTrsf_SetTransformation(gpTrsf transform, gpAx3 from, gpAx3 to);
    __declspec(dllexport) void __cdecl gpTrsf_SetRotation(gpTrsf transform, gpAx1 axis, double rads);
    __declspec(dllexport) void __cdecl gpTrsf_SetTranslation(gpTrsf transform, gpVec vec);
    __declspec(dllexport) gpQuaternion __cdecl gpTrsf_GetRotation(gpTrsf transform);
    __declspec(dllexport) void __cdecl gpTrsf_Free(gpTrsf transform);
#ifdef __cplusplus
}
#endif
