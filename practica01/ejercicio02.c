#include <stdio.h>

int main(){
    int numero = 0, factorial = 1, i;

    printf("Calcula el factorial de un numero entero N");

    while (numero >= 17 || numero <= 0)
    {
        printf("\nIntroduce el valor de N: ");
        scanf("%d", &numero);
    }
    
    for (i=1; i<=numero; i++){
        factorial = factorial * i;
        printf("El factorial de %d es %d \n", i, factorial);
    }
}