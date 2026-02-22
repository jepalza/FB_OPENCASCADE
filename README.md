# FB_OPENCASCADE


![opencascade1](https://github.com/jepalza/FB_OPENCASCADE/blob/main/imagen/visualizador.png)

![opencascade2](https://github.com/jepalza/FB_OPENCASCADE/blob/main/imagen/visualizador2.png)


Freebasic for OPENCASCADE “OCCT” CAD integration
C-WRAPPER for OpenCascade libraries < https://dev.opencascade.org > version 7.7

Starting from those already prepared by **Marcus Wu** *(marcuswu)*
from < https://github.com/marcuswu/occwrapper > with several modifications.

In order to compile the DLL, **OPENCASCADE V7.7** must be installed.
(the DLL is already compiled in the latest "release")


## Initial version V0.3
-Simple viewer using the example from < https://github.com/gkv311/occt-hello > with a lot of modifications so that
it can be called from FreeBasic.  
-Top menus and graphic icons have been added. For now, only the “export” menus as IGES and STEP are functional.  
-The graphic icons have not yet been implemented.  
-The control of the graphic window has been improved, now allowing it to be managed from FreeBasic.  
-For control viewer, use CONTROL Key and mouse buttons.  

## Update 21-feb.-2026 to V0.31
-repaired FREETYPE libraries error.  
-working on more features on viewer, like transforms.  

## Update 22-feb.2026 to 0.32
-new 46 examples added from the Opencascade 7.7 “modeling” demo.  
-Additionally, you can see an example in native FreeBasic at "ayudas/demo booleanas".  

In addition
---
MINGW's own libraries may be necessary to execute the code compiled in FB:  
`libgcc_s_dw2-1.dll`  
`libstdc++-6.dll`  
`libwinpthread-1.dll`  

***The reason for using version OCCT V7.7 from 2022 on WIN32 is for practical reasons, given that since versions 7.8 there is no longer a Windows installer, and furthermore, there is no longer a project for VC10 and support for X32 has been removed, and I, even in 2026, am still working on x32 and VC10, I can't avoid it....***  


**Translated with DeepL.com (free version)**  
---  
# Español
---

Freebasic para la integración de OPENCASCADE "OCCT" CAD  
C-WRAPPER de las librerías OpenCascade < https://dev.opencascade.org > versión 7.7  

Partiendo de las ya preparadas por **Marcus Wu** *(marcuswu)*  
de la pagina < https://github.com/marcuswu/occwrapper > con varias modificaciones.  

## Versión inicial V0.3
-Añadidos menus superiores e iconos gráficos, por ahora solo funcionales los menus de "exportar" como IGES y STEP
los iconos gráficos aun no están implementados.  
-Se ha mejorado el control de la ventana gráfica, permitiendo ahora su manejo desde FreeBasic.  
-Para controlar el visualizador, emplear la tecla CONTROL y el Ratón.  

## Actualización 21-feb-2026 a V0.31
-Reparado un error en librerías FREETYPE.  
-Trabajando en mejorar el visualizador, como añadir transformaciones.  

## Actualización 22-feb.2026 a V0.32
-Añadidos 46 nuevos ejemplos desde Opencascade 7.7 demo “modeling” usando partes del visualizador de ejemplo < https://github.com/gkv311/occt-hello > con muchas modificaciones para emplearlo desde FreeBasic.  
-Además se puede ver un ejemplo en FreeBasic nativo en "ayudas/demo booleanas"

Para poder compilar la DLL , se necesita tener instalado **OPENCASCADE V7.7**  
(en la versión publicada viene ya compilada)

Además
---
Pueden ser necesarias las librerías propias de MINGW para ejecutar el código compilado en FB:  
`libgcc_s_dw2-1.dll`  
`libstdc++-6.dll`  
`libwinpthread-1.dll`  

***El motivo de emplear la versión OCCT V7.7 de 2022 en WIN32 es por razones practicas, dado que desde las versiones 7.8 ya no existe instalador windows, y además, ya no hay proyecto para VC10 y el soporte para X32 se ha eliminado, y yo aun, en 2026, sigo trabajando en x32 y en VC10, no puedo evitarlo....***
