#include <stdio.h>
int main(){
    int x=5, y=10, temp;
    int *pi;

    printf("T1: el valor de x es %d\n", x);
    printf("T2: el valor de y es %d\n", y);

    pi = &x;
    temp = *pi;
    *pi = y;
    y=temp;

    printf("T3: el valor de x es %d\n", x);
    printf("T4: el valor de y es %d\n", y);
    printf("T5: la dirección de pi es %d\n", pi);
    printf("T3: el contenido de pi es %d\n", *pi);

    return 0;
}