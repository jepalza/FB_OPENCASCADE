// Joseba Epalza , 2026
// simple visualizador de objetos creados en tiempo real dentro de FreeBasic

#include <occ_types.h>

#include <windows.h>

#include <AIS_InteractiveContext.hxx>
#include <V3d_View.hxx>
#include <V3d_Viewer.hxx>
#include <WNT_WClass.hxx>
#include <WNT_Window.hxx>
#ifdef __cplusplus
extern "C" {
#endif

     __declspec(dllexport) int __cdecl OCCViewer_Init(
								HWND FB_Window ,
								int* FB_Context ,								
								int* FB_View );
     __declspec(dllexport) int __cdecl OCCViewer_Add( TopoDS_Shape aisShape, int mode );					
     __declspec(dllexport) int __cdecl OCCViewer_Update(int modo=1, int mx=0, int my=0, int v1=0, int v2=0, int mb=0);
	//__declspec(dllexport) int __cdecl OCCViewer_Close( HWND FBWindow );
						
#ifdef __cplusplus
}
#endif
