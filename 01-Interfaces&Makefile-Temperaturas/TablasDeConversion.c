/*
02/05/2021
Mosmann, Juan Ignacio
SSL K2051
Conversion Tablas de conversión
*/

#include "Conversion.h"
#include "FuncionesPrint.h"
#include <stdio.h>
#include <stdlib.h>

int main (void){
    
    const int LOWER = 0;
    const int UPPER = 300;
    const int STEP = 20;
    char formato[] = "%3d %6.lf\n";

    printf("Tabla de fahrenheit a celsius \n");
    printf("Fahrenheit Celsius \n");

    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
    {
        printf(formato, fahr, Celsius(fahr));
    }

    printf ("Tabla de celsius a fahrenheit \n");
    printf("Celsius Fahrenheit\n");
    int cels;
    for (cels = LOWER; cels <= UPPER; cels += STEP)
    {
        printf(formato, cels, Fahrenheit(cels));
    }
    //PrintFila(formato, 0, Fahrenheit(0));
    // PrintTablaCelsius(LOWER, STEP, UPPER);
    // PrintTablaFahrenheit(LOWER, STEP, UPPER);

    system("pause");


    
    return 0;
}