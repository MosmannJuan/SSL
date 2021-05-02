/*
02/05/2021
Mosmann, Juan Ignacio
SSL K2051
Conversion definición de funciones
*/

#include "Conversion.h"


double Fahrenheit (double cels){
    return (cels * 9/5) + 32;
}

double Celsius (double fahr){
    return (fahr - 32) * 5/9;
}

