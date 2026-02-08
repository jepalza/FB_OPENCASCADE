#include <occ_types.h>

#ifdef __cplusplus
#include <GeomAdaptor_Surface.hxx>
extern "C" {
#endif
    __declspec(dllexport) GeomAdapterSurface __cdecl GeomAdapterSurface_Init(gcSurface surface);
    __declspec(dllexport) void __cdecl GeomAdapterSurface_Free(GeomAdapterSurface surface);
    __declspec(dllexport) bool __cdecl GeomAdapterSurface_IsConical(GeomAdapterSurface surface);
    __declspec(dllexport) bool __cdecl GeomAdapterSurface_IsCylindrical(GeomAdapterSurface surface);
    __declspec(dllexport) bool __cdecl GeomAdapterSurface_IsPlanar(GeomAdapterSurface surface);
#ifdef __cplusplus
}
#endif
