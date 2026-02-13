#include <occ_types.h>

typedef int STEPControlStepModelType;

#ifdef __cplusplus
#include <STEPControl_Writer.hxx>
#include <STEPControl_StepModelType.hxx>
extern "C" {
#endif
    __declspec(dllexport) STEPControlWriter __cdecl STEPControlWriter_Init();
    __declspec(dllexport) int __cdecl STEPControlWriter_Transfer(STEPControlWriter writer, TopoDSShape shape, STEPControlStepModelType type);
    __declspec(dllexport) int __cdecl STEPControlWriter_Write(STEPControlWriter writer, char *filename);
    __declspec(dllexport) void __cdecl STEPControlWriter_Free(STEPControlWriter writer);
#ifdef __cplusplus
}
#endif
