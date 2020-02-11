#include <stdio.h>

int main (){
    int n=0;
    int sumatoria=0;
    printf("Tamaño del arreglo: ");
    scanf("%d",&n);

    int arreglo[n];

    printf("Introduce los elementos del arreglo\n");

    for(int i=0; i<n; i++){
        printf("Elemento [%d] ",i);
        scanf("%d", &arreglo[i]);
    }

    for (int i = 0; i < n; i++)
    {
        sumatoria += arreglo[i];
    }

    printf("Sumatoria = %d", sumatoria);
    
}