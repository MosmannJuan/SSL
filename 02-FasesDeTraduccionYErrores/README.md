##  02 - Fases de traducción y Errores


------------

### Objetivos

Este trabajo tiene como objetivo identificar las fases del proceso de traducción o
Build y los posibles errores asociados a cada fase.
Para lograr esa identificación se ejecutan las fases de traducción una a una, se
detectan y corrigen errores, y se registran las conclusiones en readme.md.
No es un trabajo de desarrollo; es más, el programa que usamos como ejemplo es
simple, similar a hello.c pero con errores que se deben corregir. La complejidad
está en la identificación y comprensión de las etapas y sus productos.

### Temas
- Fases de traducción.
- Preprocesamiento.
- Compilación.
- Ensamblado.
- Vinculación (Link).
- Errores en cada fase.
- Compilación separada.

### Tareas
1. La primera tarea es investigar las funcionalidades y opciones que su compilador presenta para limitar el inicio y fin de las fases de traducción.
2. La siguiente tarea es poner en uso lo que se encontró. Para eso se debe transcribir al readme.md cada comando ejecutado y su resultado o error correspondiente a la siguiente secuencia de pasos. También en readme.md se vuelcan las conclusiones y se resuelven los puntos solicitados. Para claridad, mantener en readme.md la misma numeración de la secuencia de pasos.

### Secuencia de pasos

Se parte de un archivo fuente que es corregido y refinado en sucesivos pasos.
Es importante no saltearse pasos para mantener la correlación, ya que el estado
dejado por el paso anterior es necesario para el siguiente.
1. Preprocesador
a. Escribir hello2.c, que es una variante de hello.c:
 `#include <stdio.h>
	int/*medio*/main(void){
	int i=42;
	 prontf("La respuesta es %d\n");`
b. Preprocesar hello2.c, no compilar, y generar hello2.i. Analizar su
contenido. ¿Qué conclusiones saca?
c. Escribir hello3.c, una nueva variante:
`int printf(const char * restrict s, ...);
	int main(void){
	int i=42;
 	prontf("La respuesta es %d\n");`
d. Investigar e indicar la semántica de la primera línea.
e. Preprocesar hello3.c, no compilar, y generar hello3.i. Buscar
diferencias entre hello3.c y hello3.i
1. Compilación
a. Compilar el resultado y generar hello3.s, no ensamblar.
b. Corregir solo los errores, no los warnings, en el nuevo archivo hello4.c y empezar de nuevo, generar hello4.s, no ensamblar.
c. Leer hello4.s, investigar sobre lenguaje ensamblador, e indicar de forma sintética cual es el objetivo de ese código.
d. Ensamblar hello4.s en hello4.o, no vincular.
3. Vinculación
a. Vincular hello4.o con la biblioteca estándar y generar el ejecutable.
b. Corregir en hello5.c y generar el ejecutable. Solo corregir lo necesario
para que vincule.
c. Ejecutar y analizar el resultado.
4. Corrección de Bug
a. Corregir en hello6.c y empezar de nuevo; verificar que funciona como
se espera.
5. Remoción de prototipo
a. Escribir hello7.c, una nueva variante:
`int main(void){
 	int i=42;
 	printf("La respuesta es %d\n", i);
	}`
b. Explicar porqué funciona.
6. Compilación Separada: Contratos y Módulos
a. Escribir studio1.c (sí, studio1, no stdio) y hello8.c.
La unidad de traducción studio1.c tiene una implementación de la función prontf, que es solo un wrapper de la función estándar printf:
`	void prontf(const char* s, int i){
	printf("La respuesta es %d\n", i);
	}`
La unidad de traducción hello8.c, muy similar a hello4.c, invoca a
prontf, pero no incluye ningún header.
int main(void){
int i=42;
 prontf("La respuesta es %d\n", i);
}
b. Investigar como en su entorno de desarrollo puede generar un programa
ejecutable que se base en las dos unidades de traducción (i.e., archivos
fuente, archivos con extensión .c).
Luego generar ese ejecutable y probarlo.
c. Responder ¿qué ocurre si eliminamos o agregamos argumentos a la
invocación de prontf? Justifique.
d. Revisitar el punto anterior, esta vez utilizando un contrato de interfaz en
un archivo header.
i. Escribir el contrato en studio.h.
\#ifndef _STUDIO_H_INCULDED_    
\#define _STUDIO_H_INCULDED_  
void prontf(const char*, int);  
\#endif  
ii. Escribir hello9.c, un cliente que sí incluye el contrato.
\#include "studio.h" // Interfaz que importa
int main(void){
int i=42;
 prontf("La respuesta es %d\n", i);
}
iii. Escribir studio2.c, el proveedor que sí incluye el contrato.
` #include "studio.h" // Interfaz que exporta
	\#include <stdio.h> // Interfaz que importa
	void prontf(const char* s, int i){
 	printf("La respuesta es %d\n", i);
	} `
iv. Responder: ¿Qué ventaja da incluir el contrato en los clientes y en el proveedor?

### Restricciones
- El programa ejemplo debe enviar por stdout la frase La respuesta es 42, el valor 42 debe surgir de una variable.


### Resolución

El compilador utilizado es gcc de MINGW, este compilador cuenta con las siguientes opciones de compilación que se pueden agregar al comando general: "gcc hola.c"
-
\- c:
realiza preprocesamiento y compilación, obteniento el archivo en código objeto; no realiza el enlazado.
-
\- E:
realiza solamente el preprocesamiento, enviando el resultado a la salida estándar.
-
\-o: 
archivo indica el nombre del archivo de salida, cualesquiera sean las etapas cumplidas.
-
\-Iruta
especifica la ruta hacia el directorio donde se encuentran los archivos marcados para incluir en el programa fuente. No lleva espacio entre la I y la ruta, así: -I/usr/include
-
\-L
especifica la ruta hacia el directorio donde se encuentran los archivos de biblioteca con el código objeto de las funciones referenciadas en el programa fuente.  No lleva espacio entre la L y la ruta, así: -L/usr/lib
-
\-Wall
muestra todos los mensajes de error y advertencia del compilador, incluso algunos cuestionables pero en definitiva fáciles de evitar escribiendo el código con cuidado.
-
\-g
incluye en el ejecutable generado la información necesaria para poder rastrear los errores usando un depurador, tal como GDB (GNU Debugger).
-
\-v
muestra los comandos ejecutados en cada etapa de compilación y la versión del compilador. Es un informe muy detallado.


### Hello2.i

Se obtuvo el archivo corriendo el siguiente comando desde consola "gcc -E hello2.c -o hello2.i"
En este archivo podemos apreciar como el preprocesamiento trae el contrato de las funciones que están declaradas en la biblioteca stdio.h, luego, deja en igual estado al final del archivo al código fuente escrito por nosotros.

### hello3.i
Se obtuvo el archivo corriendo el siguiente comando desde consola "gcc -E hello3.c -o hello3.i"
La primera línea del código hace referencia al contrato de una función que recibe de párametro un puntero a un char, la keyword restrict indica al compilador sobre optimizaciones para el uso de dicho puntero, los 3 puntos siguientes indican que puede recibir una cantidad variable de parámetros.
La gran diferencia que vemos entre hello2.i y hello3.i está en que, al no tener el include de la biblioteca "stdio.io", en hello3.i solamente tenemos las lineas que indican como fue creado dicho archivo y el código fuente a usar por el compilador.

### hello3.s
Se obtuvo el archivo corriendo el siguiente comando desde la consola "gcc -S hello3.c"
La corrección que se agregó fue la de agregar la llave } al final del archivo para indicar el fin de la función main.

### hello4.s
Se obtuvo el archivo corriendo el siguiente comando desde la consola "gcc -S hello4.c" 
A grandes rasgos, podríamos decir que el objetivo del código ensamblador es el de invocar a la función main, y luego invocar a la función prontf.

### hello4.o
Se obtuvo el archivo corriendo el siguiente comando desde la consola "as -o hello4.o hello4.s"

### hello4.exe
Se realizó la vinculación corriendo el siguiente comando desde la consola "gcc -o hello4 hello4.o"
Esto indica un error de compilación que indica que no está definida la referencia a la función prontf. Por lo tanto modificamos prontf por printf en hello5.c


### hello5.exe
Al compilar y ejecutar el archivo, se puede ver que el resultado no es el esperado, sino que imprime lo siguiente "La respuesta es 4200688"
Esto se debe a que no se le pasa a la función printf la variable que contiene al número a imprimir por pantalla.

### hello6.exe
Se corrigió el error antes mencionado agregando ", i" luego de "La respuesta es %d\n".
De esta manera el código compila y se ejecuta correctamente, mostrando por pantalla el mensaje:
"La respuesta es 42"

### hello7.exe
Esta variante del código funciona, por más que compile con advertencias, ya que lo único que se está removiendo es el contrato de la función, es decir, el preprocesador no podrá interpretar que los parámetros pasados a la función sean correctos, pero al momento de vincular, se puede obtener la declaración de printf de igual manera.

### hello8.exe con studio1.c
Para poder generar este archivo ejecutable se corrieron los siguientes comandos:
1. gcc -c hello8.c
2. gcc -c studio1.c
3. gcc -o hello8 hello8.o studio1.o

De esta forma se genera el ejecutable incluyendo a ambos archivos objeto, de todas maneras, el compilador envía una advertencia por no incluir los headers.

El resultado de ejecutar dicho archivo es el esperado "La respuesta es 42".

### hello9.exe
Para poder generar este archivo ejecutable se corrieron los siguientes comandos:
1. gcc -c hello9.c
2. gcc -c studio2.c
3. gcc -o hello9 hello9.o studio2.o

De esta forma, el compilador no envió las advertencias al compilar ambos archivos en un mismo ejecutable. 
El resultado de ejecutar dicho archivo es el esperado "La respuesta es 42".

La ventaja que posee incluir el contrato es que el preprocesador ya puede conocer sobre los argumentos que la función espera recibir, de esta forma, se pueden evitar errores en el uso de las funciones mucho antes.

