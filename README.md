# FB_OPENCASCADE
Freebasic for OPENCASCADE “OCC” CAD integration
...

![opencascade1](https://github.com/jepalza/FB_OPENCASCADE/blob/main/visualizador/visualizador.png)

...

C-WRAPPER for OpenCascade libraries < https://dev.opencascade.org > version 7.7

using routines from < https://github.com/marcuswu/occwrapper > with slight modifications.

--

Still in the early stages, only three types of entities and two file output formats have been tested.

--

Integrating the complexity of the OPENCASCADE libraries into a C-WRAPPER is a monumental task.

Starting from those already converted by Marcus Wu ‘marcuswu’, I have added a few more things, such as a simple viewer

using the example from < https://github.com/gkv311/occt-hello > with slight modifications so that

it can be called from FreeBasic.

--

In order to compile the DLL and run it in FreeBasic, OPENCASCADE V7.7 must be installed.

--

In the simple FreeBasic example, three entities are automatically created: cube, rotated cube box, and sphere.

For STEP and IGES data output, a Boolean entity is created when the cube is cut with the sphere.

--

In addition, MINGW's own libraries may be necessary to execute the code compiled in FB:

libgcc_s_dw2-1.dll

libstdc++-6.dll

libwinpthread-1.dll

--

There is still a lot of work to be done, and I will gradually implement more features.

--
The reason for using version OCC7.7 from 2022 on WIN32 is for practical reasons, given that since versions 7.8 there is no longer a Windows installer, and furthermore, there is no longer a project for VC10 and support for X32 has been removed, and I, even in 2026, am still working on x32 and VC10, I can't avoid it....
--

Note: compiled for WIN32 for simplicity.


Translated with DeepL.com (free version)
--

--

--

--

Español

--

Freebasic para la integracion de OPENCASCADE "OCC" CAD

C-WRAPPER de las librerias OpenCascade < https://dev.opencascade.org > version 7.7

empleando las rutinas de < https://github.com/marcuswu/occwrapper > con ligeras modificaciones.

--

Aun esta poco avanzado, solo comprobados tres tipos de entidades y dos formas de salida de ficheros

--

Integrar en un C-WRAPPER la complejidad de las librerias OPENCASCADE es una tarea titanica.

Partiendo de las ya convertidas por Marcus Wu 'marcuswu' he añadido algunas cosas mas , como un visualizador 

simple usando el ejemplo de < https://github.com/gkv311/occt-hello > con ligeras modificaciones para

poderlo llamar desde FreeBasic.

--

Para poder compilar la DLL y ejecutar en FreeBasic, se necesita tener instalado OPENCASCADE V7.7

--

En el ejemplo sencillo de FreeBasic, se crean automaticamente 3 entidades: cubo, caja girada y esfera

y para la salida de datos STEP e IGES se crea una entidad Booleana al cortar el cubo con la esfera y la caja.

--

Ademas, puede que sean necesarias las librerias propias de MINGW para ejecutar el codigo compilado en FB:

libgcc_s_dw2-1.dll

libstdc++-6.dll

libwinpthread-1.dll

--
El motivo de emplear la version OCC7.7 de 2022 en WIN32 es por razones practicas, dado que desde las versiones 7.8 ya no existe instalador windows, y ademas, ya no hay proyecto para VC10 y el soporte para X32 se ha eliminado, y yo aun, en 2026, sigo trabajando en x32 y en VC10, no puedo evitarlo....
--

Queda mucho, mucho, trabajo por hacer, y poco a poco ire implementando mas cosas.

Nota: compilado para WIN32 por sencillez.
