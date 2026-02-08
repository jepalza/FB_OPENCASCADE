#include <occ_types.h>

#ifdef __cplusplus
#include <gp_Pnt.hxx>
extern "C" {
#endif
    __declspec(dllexport) gpPnt __cdecl gpPnt_Init(double x, double y, double z);
    __declspec(dllexport) void __cdecl gpPnt_Free(gpPnt pnt);
    __declspec(dllexport) void __cdecl gpPnt_SetCoord(gpPnt pnt, double x, double y, double z);
    __declspec(dllexport) void __cdecl gpPnt_SetX(gpPnt pnt, double x);
    __declspec(dllexport) void __cdecl gpPnt_SetY(gpPnt pnt, double y);
    __declspec(dllexport) void __cdecl gpPnt_SetZ(gpPnt pnt, double z);
    __declspec(dllexport) double __cdecl gpPnt_X(gpPnt pnt);
    __declspec(dllexport) double __cdecl gpPnt_Y(gpPnt pnt);
    __declspec(dllexport) double __cdecl gpPnt_Z(gpPnt pnt);
    __declspec(dllexport) bool __cdecl gpPnt_IsEqual(gpPnt pnt, gpPnt other, double tolerance);
    __declspec(dllexport) double __cdecl gpPnt_Distance(gpPnt pnt, gpPnt other);
    __declspec(dllexport) double __cdecl gpPnt_SquareDistance(gpPnt pnt, gpPnt other);
    __declspec(dllexport) void __cdecl gpPnt_MirrorCenterPoint(gpPnt pnt, gpPnt center);
    __declspec(dllexport) gpPnt __cdecl gpPnt_MirroredCenterPoint(gpPnt pnt, gpPnt center);
    __declspec(dllexport) void __cdecl gpPnt_MirrorAxis(gpPnt pnt, gpAx1 axis);
    __declspec(dllexport) gpPnt __cdecl gpPnt_MirroredAxis(gpPnt pnt, gpAx1 axis);
    __declspec(dllexport) void __cdecl gpPnt_Rotate(gpPnt pnt, gpAx1 axis, double angle);
    __declspec(dllexport) gpPnt __cdecl gpPnt_Rotated(gpPnt pnt, gpAx1 axis, double angle);
    __declspec(dllexport) void __cdecl gpPnt_Scale(gpPnt pnt, gpPnt other, double scale);
    __declspec(dllexport) gpPnt __cdecl gpPnt_Scaled(gpPnt pnt, gpPnt other, double scale);
    __declspec(dllexport) void __cdecl gpPnt_Transform(gpPnt pnt, gpTrsf transform);
    __declspec(dllexport) gpPnt __cdecl gpPnt_Transformed(gpPnt pnt, gpTrsf transform);
    __declspec(dllexport) void __cdecl gpPnt_Translate(gpPnt pnt, gpVec vector);
    __declspec(dllexport) gpPnt __cdecl gpPnt_Translated(gpPnt pnt, gpVec vector);
    __declspec(dllexport) void __cdecl gpPnt_TranslatePoints(gpPnt pnt, gpPnt pnt1, gpPnt pnt2);
    __declspec(dllexport) gpPnt __cdecl gpPnt_TranslatedPoints(gpPnt pnt, gpPnt pnt1, gpPnt pnt2);
#ifdef __cplusplus
}
#endif
