#Bastián Contreras Wasilkowski - bastian.contrerasw@alumnos.uv.cl En este documento se explicará el diseño de solución y las funciones utilizadas para resolver la problemática planteada en la Tarea 3 de la asignatura de Sistemas Operativos.

Teniendo en cuenta el código creado, en el archivo 'tarea03.cpp' dentro de la carpeta '/src' del presente GitHub, primero se realiza un include para las librerias requeridas, seguido a ello se puede encontrar una función llamada "signalController", la cual realiza una administración de las señales de detención de procesos, indicando a cada una una acción determinada, en este caso, denegandolas, a excepción de SIGUSR1 y SIGUSR2 las cuales son capaces de detener los procesos padre e hijo mediante sus respectivos PID.

En el "main" del código se puede encontrar en primera instancia el registro de las señales y la función la cual administra cada una de ellas. Posteriormente se encuentra un fork el cual crea el hijo del proceso actual, además de la definición de variables requeridas para el resto del código.

Luego se posee un for el cual llega hasta 50 iteraciones, marcando el límite de funcionamiento del programa. Seguido a esto se pueden encontrar tres 'if', los cuales diferencian los procesos padre, hijo, y el error del fork.
El primer if, perteneciente al padre, calcula fibonacci de forma secuencial, imprimiendo en pantalla cada una de las iteraciones, junto al PID del proceso, y una linea de sleep, la cual duerme el proceso en cuestión un segundo.
El segundo if pertenece al hijo, aquí se puede apreciar un sleep de 1200 milisegundos y posteriormente el cálculo de los valores impares y la forma de mostrar en pantalla cada uno de ellos, junto al PID del proceso.
Por último, se encuentra un if en caso de fallo en la realización del fork, reportando el error mediante un EXIT_FAILURE. 
