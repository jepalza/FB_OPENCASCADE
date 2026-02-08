// Joseba Epalza , 2026
// simple visualizador de objetos creados en tiempo real dentro de FreeBasic

#include <occ_types.h>

#include <windows.h>

#include <AIS_InteractiveContext.hxx>
#include <V3d_View.hxx>
#include <V3d_Viewer.hxx>

#ifdef __cplusplus
extern "C" {
#endif

     __declspec(dllexport) int __cdecl OCCViewer_Init(
						Handle(V3d_View) FBView,
						Handle(AIS_InteractiveContext) FBContext );

     __declspec(dllexport) int __cdecl OCCViewer_Add(
						TopoDS_Shape aisShape,
						int mode );
		
#ifdef __cplusplus
}
#endif
