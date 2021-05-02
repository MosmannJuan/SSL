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

    PrintTablaCelsius(LOWER, STEP, UPPER);
    PrintTablaFahrenheit(LOWER, STEP, UPPER);

    system("pause");


    
    return 0;
}