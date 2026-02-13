#include <occ_types.h>

#ifdef __cplusplus
#include <BRepGProp.hxx>
#include <GProp_GProps.hxx>
extern "C" {
#endif

    __declspec(dllexport) void __cdecl BRepGProp_SurfaceProperties(TopoDSShape shape, GPropGProps sprops, bool skipShared, bool useTriangulation);
    __declspec(dllexport) void __cdecl BRepGProp_LinearProperties(TopoDSShape shape, GPropGProps sprops, bool skipShared, bool useTriangulation);

#ifdef __cplusplus
}
#endif
