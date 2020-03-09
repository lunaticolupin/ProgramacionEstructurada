/**
 * Los punteros tienen dos cometidos. 
 * El primero es almacenar una dirección de memoria.
 * El segundo es utilizar la dirección de memoria almacenada para acceder al dato al que apunta mediante una indirección 
 **/

#include <stdio.h>
int main(int argc, char** argv) 
{
    int num1, num2;
    
    //Declaración de punteros
    int *ptr1, *ptr2;

    ptr1 = &num1;
    ptr2 = &num2;

    num1 = 10;
    num2 = 20;

    //Indirección
    //Asigna el valor 30 a la dirección de memoria almacenada en ptr1 mediante una indirección.
    *ptr1 = 30;

    //Asigna el valor 40 a la dirección a la que apunta ptr2
    *ptr2 = 40;

    /** dos indirecciones. 
     * La expresión a la derecha del signo igual obtiene el dato en la posición indicada por la dirección almacenada en ptr1 (la dirección de num1)
     *  y este dato se almacena en la posición indicada por el puntero ptr2 (la dirección de num2)**/

    *ptr2 = *ptr1;

    return 0;
}
