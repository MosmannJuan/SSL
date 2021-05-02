/*
02/05/2021
Mosmann, Juan Ignacio
SSL K2051
FuncionesPrint Definición de funciones  
*/

#include "FuncionesPrint.h"
#include "Conversion.h"
#include <stdio.h>

void PrintFila(char *formato, double valor1, double valor2){
    printf(formato, valor1, valor2);
}

void PrintFilas(double (*funcion)(double), char formato[], int lower, int step, int upper){
    int valorAConvertir;
    for (valorAConvertir = lower; valorAConvertir <= upper; valorAConvertir += step){
        PrintFila(formato, valorAConvertir, funcion(valorAConvertir));
    }
}

void PrintTablaFahrenheit(int lower, int step, int upper){
    printf("Tabla de celsius a fahrenheit \n");
    PrintFilas(Fahrenheit, "Celsius: %3.2f  Fahrenheit: %6.2f\n", lower, step, upper);
}

void PrintTablaCelsius(int lower, int step, int upper){
    printf("Tabla de fahrenheit a celsius \n");
    PrintFilas(Celsius, "Fahrenheit: %3.2f Celsius: %6.2f\n", lower, step, upper);
}