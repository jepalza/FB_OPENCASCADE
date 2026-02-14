# FB_OPENCASCADE


![opencascade1](https://github.com/jepalza/FB_OPENCASCADE/blob/main/imagen/visualizador.png)


Freebasic for OPENCASCADE “OCC” CAD integration
.

C-WRAPPER for OpenCascade libraries < https://dev.opencascade.org > version 7.7
.

Starting from those already prepared by Marcus Wu ‘marcuswu’ 

.

from < https://github.com/marcuswu/occwrapper > with several modifications.

.

Still in the early stages, only three types of entities and two file output formats have been tested.

.
In this initial version V0.3:
Top menus and graphic icons have been added. For now, only the “export” menus as IGES and STEP are functional.
The graphic icons have not yet been implemented.
The control of the graphic window has been improved, now allowing it to be managed from FreeBasic.
.

using the example from < https://github.com/gkv311/occt-hello > with a lot of modifications so that

it can be called from FreeBasic.

.

In order to compile the DLL and run it in FreeBasic, OPENCASCADE V7.7 must be installed.

.

In the simple FreeBasic example, three entities are automatically created: cube, rotated cube box, and sphere.

For STEP and IGES data output, a Boolean entity is created when the cube is cut with the sphere.

.

In addition, MINGW's own libraries may be necessary to execute the code compiled in FB:

libgcc_s_dw2-1.dll

libstdc++-6.dll

libwinpthread-1.dll



-
The reason for using version OCC7.7 from 2022 on WIN32 is for practical reasons, given that since versions 7.8 there is no longer a Windows installer, and furthermore, there is no longer a project for VC10 and support for X32 has been removed, and I, even in 2026, am still working on x32 and VC10, I can't avoid it....
-


-
Translated with DeepL.com (free version)
-

.

.

.

.

Español

.

Freebasic para la integracion de OPENCASCADE "OCC" CAD

.

C-WRAPPER de las librerias OpenCascade < https://dev.opencascade.org > version 7.7

.

Partiendo de las ya preparadas por Marcus Wu 'marcuswu'

.

de la pagina < https://github.com/marcuswu/occwrapper > con varias modificaciones.

.

En esta version incial V0.3:
Añadidos menus superiores e iconos graficos, por ahora solo funcionales los menus de "exportar" como IGES y STEP
los iconos graficos aun no estan implementados
se ha mejorado el control de la ventana grafica, permitiendo ahora su manejo desde FreeBasic

.

usando partes del visualizador de ejemplo < https://github.com/gkv311/occt-hello > con muchas modificaciones para

emplearlo desde FreeBasic.

.

Para poder compilar la DLL y ejecutar en FreeBasic, se necesita tener instalado OPENCASCADE V7.7

.

En el ejemplo sencillo de FreeBasic, se crean automaticamente 3 entidades: cubo, caja girada y esfera

y para la salida de datos STEP e IGES se crea una entidad Booleana al cortar el cubo con la esfera y la caja.

.

Pueden ser necesarias las librerias propias de MINGW para ejecutar el codigo compilado en FB:

libgcc_s_dw2-1.dll

libstdc++-6.dll

libwinpthread-1.dll

-
El motivo de emplear la version OCC7.7 de 2022 en WIN32 es por razones practicas, dado que desde las versiones 7.8 ya no existe instalador windows, y ademas, ya no hay proyecto para VC10 y el soporte para X32 se ha eliminado, y yo aun, en 2026, sigo trabajando en x32 y en VC10, no puedo evitarlo....
-