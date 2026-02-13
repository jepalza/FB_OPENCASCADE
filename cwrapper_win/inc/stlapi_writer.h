#include <occ_types.h>

#ifdef __cplusplus
#include <StlAPI_Writer.hxx>
extern "C" {
#endif
    __declspec(dllexport) StlAPIWriter __cdecl StlAPIWriter_Init();
    __declspec(dllexport) bool __cdecl StlAPIWriter_Write(StlAPIWriter writer, TopoDSCompound res, const char *filename);
    __declspec(dllexport) void __cdecl StlAPIWriter_Free(StlAPIWriter writer);
#ifdef __cplusplus
}
#endif
