#include <stdio.h>
int main() 
{
    //Definición de dos enteros y dos punteros a enteros respectivamente.
    int num1, num2;
    int *ptr1, *ptr2;

    //Asignacion de direcciones a las dos variables
    ptr1 = &num1;
    ptr2 = &num2;

    //Inicialización de variables
    num1 = 10;
    num2 = 20;

    //Asignación de un puntero a otra
    ptr1 = ptr2;

    //Puntero vacío o Nulo
    ptr2 = NULL;

    return 0;
}
