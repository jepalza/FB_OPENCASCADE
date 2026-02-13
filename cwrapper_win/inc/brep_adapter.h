#include <occ_types.h>

#ifdef __cplusplus
#include <BRepAdaptor_Curve.hxx>
extern "C" {
#endif

#ifndef _GeomAbs_SurfaceType_HeaderFile
typedef int GeomAbs_SurfaceType;
#endif

    __declspec(dllexport) BRepAdapterCurve __cdecl BRepAdapterCurve_Init(TopoDSEdge edge);
    __declspec(dllexport) bool __cdecl BRepAdapterCurve_IsLine(BRepAdapterCurve curve);
    __declspec(dllexport) bool __cdecl BRepAdapterCurve_IsCircle(BRepAdapterCurve curve);
    __declspec(dllexport) bool __cdecl BRepAdapterCurve_IsEllipse(BRepAdapterCurve curve);
    __declspec(dllexport) gpCirc __cdecl BRepAdapterCurve_ToCircle(BRepAdapterCurve curve);
    
    __declspec(dllexport) BRepAdapterSurface __cdecl BRepAdapterSurface_Init(TopoDSFace face);
    __declspec(dllexport) BRepAdapterSurface __cdecl BRepAdapterSurface_InitRestriction(TopoDSFace face, bool restriction);
    __declspec(dllexport) gpPln __cdecl BRepAdapterSurface_Plane(BRepAdapterSurface surface);
    __declspec(dllexport) gpDir __cdecl BRepAdapterSurface_Direction(BRepAdapterSurface surface);
    __declspec(dllexport) GeomAbs_SurfaceType __cdecl BRepAdapterSurface_Type(BRepAdapterSurface surface);
    __declspec(dllexport) void __cdecl BRepAdapterSurface_Free(BRepAdapterSurface surface);

#ifdef __cplusplus
}
#endif
