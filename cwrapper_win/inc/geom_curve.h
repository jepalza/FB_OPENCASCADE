#include <occ_types.h>

#ifdef __cplusplus
#include <GC_MakeCircle.hxx>
#include <GC_MakeSegment.hxx>
#include <GC_MakeArcOfCircle.hxx>
extern "C" {
#endif
    __declspec(dllexport) gcTrimmedCurve __cdecl gcMakeCircle(gpAx2 center, double radius);
    __declspec(dllexport) gcTrimmedCurve __cdecl gcMakeArcOfCircle(gpCirc circle, gpPnt pt1, gpPnt pt2, bool sense);
    __declspec(dllexport) gcTrimmedCurve __cdecl gcMakeArcOfCirclePts(gpPnt pt1, gpPnt pt2, gpPnt pt3);
    __declspec(dllexport) gcTrimmedCurve __cdecl gcMakeSegment(gpPnt start, gpPnt end);
    __declspec(dllexport) void __cdecl gcTrimmedCurve_Free(gcTrimmedCurve arc);
    __declspec(dllexport) GeomCurve __cdecl gcTrimmedCurve_ToGeomCurve(gcTrimmedCurve curve);
#ifdef __cplusplus
}
#endif
