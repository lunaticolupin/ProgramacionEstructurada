#include<stdio.h>

int main(){
    int a=9999, b=9999, c=9999;

    printf("Introduce tres numeros enteros entre -1000 y 1000\n");

    while (a > 1000 || a < -1000){
        printf("\nPrimer valor: ");
        scanf("%d", &a);
    }

    while (b < -1000 || b > 1000){
        printf("Segundo valor: ");
        scanf("%d", &b);
    }

    while (c < -1000 || c > 1000){
        printf("Tercer valor: ");
        scanf("%d", &c);
    }

    printf("El orden de menor a mayor es: ");

    if(a<b){
        if(a<c){
            if(b<c){
                printf("%d, %d, %d", a, b, c);
            }else{
                printf("%d,%d, %d", a, c, b);            
            }
        }else{
            printf("%d, %d, %d", c, a, b);
        }
    }else{
        if (b<c){
            if (a<c){
                printf("%d, %d, %d", b, a, c);
            }
            else{
                printf("%d, %d, %d", b, c, a);
            }
        }else{
            if (b<a){
                printf("%d, %d, %d", c, b, a);
            }else{
                printf("%d, %d, %d", c, a, b);
            }
        }
    }

    printf("\n");
}