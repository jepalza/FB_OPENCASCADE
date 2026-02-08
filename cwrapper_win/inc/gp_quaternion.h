#include <occ_types.h>

#ifdef __cplusplus
#include <gp_Quaternion.hxx>
extern "C" {
#endif
    __declspec(dllexport) gpQuaternion __cdecl gpQuaternion_Inverted(gpQuaternion q);
    __declspec(dllexport) gpQuaternion __cdecl gpQuaternion_Multiplied(gpQuaternion q, gpQuaternion other);
    __declspec(dllexport) bool __cdecl gpQuaternion_IsEqual(gpQuaternion q, gpQuaternion other);
    __declspec(dllexport) double __cdecl gpQuaternion_GetRotationAngle(gpQuaternion q);

    __declspec(dllexport) void __cdecl gpQuaternion_Free(gpQuaternion q);
#ifdef __cplusplus
}
#endif
