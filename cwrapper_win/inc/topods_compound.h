#include <occ_types.h>

#ifdef __cplusplus
#include <TopoDS_Compound.hxx>
extern "C" {
#endif
    __declspec(dllexport) TopoDSCompound __cdecl TopoDSCompound_Init();
    __declspec(dllexport) void __cdecl TopoDSCompound_Free(TopoDSCompound comp);
#ifdef __cplusplus
}
#endif
