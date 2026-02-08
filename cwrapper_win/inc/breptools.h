#include <occ_types.h>

#ifdef __cplusplus
#include <BRepTools.hxx>
extern "C" {
#endif

    __declspec(dllexport) void __cdecl BRepTools_UVBounds(TopoDSFace face, double *umin, double *umax, double *vmin, double *vmax);

#ifdef __cplusplus
}
#endif
