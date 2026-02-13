#include <occ_types.h>

#ifdef __cplusplus
#include <BRepMesh_IncrementalMesh.hxx>
extern "C" {
#endif

    __declspec(dllexport) BRepMeshIncrementalMesh __cdecl BRepMeshIncrementalMesh_Init(TopoDSShape shape, double linearDefl, bool isRelative, double angularDefl, bool isParallel);
    __declspec(dllexport) void __cdecl BRepMeshIncrementalMesh_Free(BRepMeshIncrementalMesh mesh);

#ifdef __cplusplus
}
#endif
