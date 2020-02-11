#include <stdio.h>
#include <math.h>

int main(){
    int n=0;
    float promedio = 0, sumatoria = 0, desviacion = 0;

    scanf("%d", &n);

    int arreglo[n];

    for(int i=0; i<n; i++){
        printf("Elemento [%d] ",i);
        scanf("%d", &arreglo[i]);
        sumatoria += arreglo[i];
    }

    promedio = sumatoria/n;
    sumatoria = 0;

    for (int i = 0; i < n; i++)
    {
        float temp = 0;

        temp = pow(arreglo[i] - promedio,2);
        sumatoria += temp;
    }
    printf("%f",sumatoria);
    
    desviacion = sqrt(sumatoria/(n-1));
    
    printf("\nPromedio = %f\nDesviacion = %f", promedio, desviacion);
}