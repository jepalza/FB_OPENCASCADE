# FB_OPENCASCADE
Freebasic para la integracion de OPENCASCADE "OCC" CAD

C-WRAPPER de las librerias OpenCascade < https://dev.opencascade.org > version 7.6

empleando las rutinas de < https://github.com/marcuswu/occwrapper > con ligeras modificaciones.

--


Aun esta poco avanzado, solo comprobados tres tipos de entidades y dos formas de salida de ficheros

La salida STEP esta bien lograda, la salida IGES aun le queda trabajo por hacer, dado que las entidades

construidas mediante otras o modificadas, no las reconoce y salen descompuestas.

--


Integrar en un C-WRAPPER la complejidad de las librerias OPENCASCADE es una tarea titanica.

Partiendo de las ya convertidas por Marcus Wu 'marcuswu' he añadido algunas cosas mas , como un visualizador 

simple usando el ejemplo de < https://github.com/gkv311/occt-hello > con ligeras modificaciones para

poderlo llamar desde FreeBasic.

--

Para poder compilar la DLL y ejecutar en FreeBasic, se necesita tener instalado OPENCASCADE V7.6

--

En el ejemplo sencillo de FreeBasic, se crean automaticamente 3 entidades: cubo, cuboide girado y esfera

y para la salida de datos STEP e IGES se crea una entidad Booleana al cortar el cubo con la esfera.

Para ver el resultado, pulsar las teclas 1, 2 o 3 en la ventana DOS y vemos la salida en la ventana grafica.

--

Ademas, puede que sean necesarias las librerias propias de MINGW para ejecutar el codigo compilado en FB:

libgcc_s_dw2-1.dll

libstdc++-6.dll

libwinpthread-1.dll

--

Queda mucho, mucho, trabajo por hacer, y poco a poco ire implementando mas cosas.

Nota: compilado para WIN32 por sencillez.
