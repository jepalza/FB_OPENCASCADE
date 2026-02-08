#include <occ_types.h>

#ifdef __cplusplus
#include <GProp_GProps.hxx>
extern "C" {
#endif
    __declspec(dllexport) GPropGProps __cdecl GPropGProps_Init();
    __declspec(dllexport) void __cdecl GPropGProps_Free(GPropGProps props);
    __declspec(dllexport) double __cdecl GPropGProps_Mass(GPropGProps props);
    __declspec(dllexport) gpPnt __cdecl GPropGProps_CentreOfMass(GPropGProps props);
#ifdef __cplusplus
}
#endif
