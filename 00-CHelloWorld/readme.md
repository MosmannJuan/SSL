## 00-CHelloWorld

------------


### Objetivos
- Demostrar con, un programa simple, que se está en capacidad de editar,
compilar, y ejecutar un programa C.
- Contar con las herramientas necesarias para abordar la resolución de los
trabajos posteriores.

### Tareas
1. Si no posee una cuenta GitHub, crearla.
2. Crear un repositorio público llamado SSL.
3. Escribir el archivo readme.md que actúa como front page del repositorio personal.
4. Crear la carpeta 00-CHelloWorld.
5. Escribir el archivo readme.md que actúa como front page de la resolución.
6. Seleccionar, instalar, y configurar un compilador C11 ó C18.
7. Indicar en readme.md el compilador seleccionado.
8. Probar el compilador con un programa hello.c que envíe a stdout la línea Hello, World! o similar.
9. Ejecutar el programa, y capturar su salida en un archivo output.txt.
10. Publicar en el repositorio personal SSL la carpeta 00-CHelloWorld con readme.md, hello.c, y output.txt .
11. La última tarea es informar el usuario GitHub en la planilla indicada en el aula virtual.

### Resolución
- Se programó la función necesaria para imprimir el string "Hello, World!" en pantalla usando Visual Studio Code
- Se utilizó el compilador MinGW indicando que la compilación debía ser bajo el estándar C18
- Se corrió el programa desde la terminal usando el siguiente comando "./Hello.c > output.txt" para poder capturar la salida en un archivo de texto plano

------------

## Proceso de compilación
![Proceso de compilación](https://user-images.githubusercontent.com/63465251/115128763-85a55000-9fb6-11eb-9880-84a46648b7e7.jpeg)

## Comparación del código ensamblador producido por diferentes compiladores

#### Se utilizó la herramienta [Compiler Explorer](https://godbolt.org/) para comparar los códigos de ensamblador generados por el compilador gcc y clang. Para ambos se compararon 3 casos del código fuente usando como base [Hello.c](https://github.com/MosmannJuan/SSL/blob/main/00-CHelloWorld/Hello.c), archivo que se encuentra en este mismo repositorio. Los casos evaluedos son, código fuente tal cual está en el archivo, sin return y, finalmente, sin return ni include de la biblioteca stdio.h.

>> ### GCC
>> #### Se utilizó la versión 9.2.0 debido a que es la que tengo instalada en mi entorno local.
>> ![VersionGcc](https://user-images.githubusercontent.com/63465251/115166860-a5f30e80-a08b-11eb-9962-238b6d822bde.jpg)
>> ### Versión completa
>> ![gccCompleto](https://user-images.githubusercontent.com/63465251/115166886-be632900-a08b-11eb-8134-2384dd5a44be.jpg)
>> ### Sin return
>> ![gccSinReturn](https://user-images.githubusercontent.com/63465251/115166917-dfc41500-a08b-11eb-90bc-a0aa079a9450.jpg)
>> ### Sin return ni include
>> ![gccSinInclude](https://user-images.githubusercontent.com/63465251/115166937-f8ccc600-a08b-11eb-818b-c9e7030f9792.jpg)
>> ### Conclusiones
>> #### En el caso del compilador gcc podemos ver que el código ensamblador no varía en ninguno de estos casos, al no agregar el return podemos ver como el compilador lo agrega por nosotros, este es el caso de la instrucción de la línea 9. Si podemos resaltar el hecho de que, al sacar el include, el compilador nos envía un Warning indicandonos que estamos declarando de forma implicita una función perteneciente a una biblioteca, aún así el código puede compilarse de todas maneras.


>> ### Clang
>> #### Se eligió para trabajar la versión 10.0.0
>> ### Versión completa
>> ![ClangCompleto](https://user-images.githubusercontent.com/63465251/115167268-4dbd0c00-a08d-11eb-95eb-f8aac8dadb4d.jpg)
>> ### Sin return
>> ![ClangSinReturn](https://user-images.githubusercontent.com/63465251/115167284-5c0b2800-a08d-11eb-9712-7a2ca79e7209.jpg)
>> ### Sin return ni include
>> ![ClangSinInclude](https://user-images.githubusercontent.com/63465251/115167298-688f8080-a08d-11eb-9885-6a7988c2b737.jpg)
>> ### Conclusiones
>> #### Utilizando el compilador clang si podemos notar diferencias en el código ensamblador generado pero únicamente en el caso que quitamos el return, esto se ve en la desaparición de la instrucción de la linea 5. Al no agregar el include el código ensamblador generado es igual al caso anterior, pero de igual forma que lo hace gcc, envía un Warning indicandonos que estamos declarando de forma implicita una función ya perteneciente a una biblioteca.


## Conclusiones finales

#### Se pudo ver como distintos compiladores tienen distintas formas de traducir a código ensamblador un mismo código fuente. En el caso de Clang, daría la impresión de que resulta más reactivo a cambios en el código, mientras que gcc, no produjo cambio alguno en el código ensamblador al pasar por los diferentes casos.
#### Se puede apreciar como ambos códigos ensamblador solo se encargan de hacer el llamado a la función printf (Que en caso de no incluir la biblioteca que contiene la información sobre esta función, pareciera que puede buscarla igual solamente lanzando una advertencia). Para esto ambos compiladores utilizan registros similares. Algo que podemos resaltar es el hecho de que el codigo ensamblador generado por clang, utiliza el registro "rdi" de 64 bits para almacenar la dirección en la cual se encuentra el string, mientras que el compilador gcc la almacena en el registro "edi" de 32.

 
