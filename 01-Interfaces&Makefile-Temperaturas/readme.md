## 01-Interfaces&Makefile-Temperaturas

------------


### Objetivos
- Aplicar el uso de interfaces y módulos.
- Construir un programa formado por más de una unidad de traducción.
- Comprender el proceso de traducción o Build cuando intervienen varios archivos fuente.
- Aplicar el uso de Makefile.

### Temas
- Makefile.
- Archivos header (.h).
- Tipo de dato double.
- Funciones.
- Pruebas unitarias.
- assert

### Tareas
1. Escribir el Makefile.
2. Escribir Conversion.h
3. Escribir ConversionTest.c
4. Escribir Conversion.c
5. Escribir TablasDeConversion.c

### Restricciones
- Las dos funciones públicas deben llamarse Celsius y Farenheit.
- Utilizar assert.
- Utilizar const y no define.
- Utilizar for con declaración (C99).

### Resolución
- Para la compilación se utilizó el estandar C18 (Se indica en la creación de los objetos .o en makefile)
- Intenté realizar las funciones para el crédito extra, pero la función PrintFila no funciona de la manera esperada.
- EDIT: Se corrigió la funcion PrintFila. El problema estaba en el string que daba el formato, que se cambio por el siguiente "Celsius: %3.2f  Fahrenheit: %6.2f\n".
- Se agrega el resultado de la ejecución de TablasDeConversion en el archivo Output.txt