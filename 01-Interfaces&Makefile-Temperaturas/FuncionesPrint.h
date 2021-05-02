/*
02/05/2021
Mosmann, Juan Ignacio
SSL K2051
FuncionesPrint header  
*/

void PrintFila(char *, double, double); //Recibe como parámetros el string de formato y los dos valores a mostrar, e imprime la fila

void PrintFilas(double (*funcion)(double), char[], int lower, int step, int upper); //Recibe como como parámetros el formato de los string a imprimir, los datos de los limites, el step y un puntero a la funcion que debe ejecutar, calcula los valores e imprime las filas 

void PrintTablaFahrenheit(int lower, int step, int upper); //Recibe como parámetros solo los límites y el step, que luego pasará a la función PrintFilas

void PrintTablaCelsius(int lower, int step, int upper); //Recibe como parámetros solo los límites y el step, que luego pasará a la función PrintFilas