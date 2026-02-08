#include <occ_types.h>

#ifdef __cplusplus
#include <GeomLProp_SLProps.hxx>
extern "C" {
#endif
    __declspec(dllexport) GeomLPropSLProps __cdecl GeomLPropSLProps_Init(gcSurface surface, double umin, double vmin, double n, double res);
    __declspec(dllexport) gpDir __cdecl GeomLPropsSLProps_Normal(GeomLPropSLProps props);
    __declspec(dllexport) void __cdecl GeomLPropSLProps_Free(GeomLPropSLProps props);
#ifdef __cplusplus
}
#endif
