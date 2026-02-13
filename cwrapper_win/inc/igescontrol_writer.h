// Joseba Epalza, 2026, guardar como archivos IGES solo entidades 3D basicas.

#include <occ_types.h>

typedef int IGESControlIgesModelType;

#ifdef __cplusplus
#include <IGESControl_Writer.hxx>

#include <IGESCAFControl.hxx>
#include <IGESCAFControl_Writer.hxx>

#include <TopoDS_Compound.hxx>
extern "C" {
#endif

    __declspec(dllexport) IGESControlWriter __cdecl IGESControlWriter_Init();
    __declspec(dllexport) void __cdecl IGESControlWriter_Add(IGESControlWriter writer, TopoDSShape shape, IGESControlIgesModelType mode);
    __declspec(dllexport) int  __cdecl IGESControlWriter_Write(IGESControlWriter writer, const char *filename);
    __declspec(dllexport) void __cdecl IGESControlWriter_Free(IGESControlWriter writer);
	
#ifdef __cplusplus
}
#endif
