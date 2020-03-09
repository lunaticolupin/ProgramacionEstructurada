#include <stdio.h>
     
      /* Definición de función "swap". Fíjate que las variables se reciben como puntero a esas variables. */
     void intercambio ( int *x, int *y )
      {
          /*Declaramos una variable temporal*/
          int tmp;
          tmp = *x;
          *x = *y;
          *y = tmp;
      }
      
      int main() 
      {
            int a, b;
            a = 1;
            b = 2;

            /*Llamamos a la función "swap" pasándole la dirección a las variables a y b.*/
            intercambio( &a, &b );
            /*Imprime los valores de a y b intercambiados*/
            printf(" a = %d b = %d\n", a, b );

      }