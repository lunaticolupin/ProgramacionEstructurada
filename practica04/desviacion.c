#include <stdio.h>
#include <math.h>

float calcula_promedio (float *arreglo, int num);
void calcula_desviacion (float promedio, float *arreglo, int num, float *desviacion);

int main(){
    int n=0;
    float promedio = 0, desviacion = 0;

    printf("Elementos del arreglo: ");
    scanf("%d", &n);

    float arreglo[n];

    for(int i=0; i<n; i++){
        printf("Elemento [%d] ",i);
        scanf("%f", &arreglo[i]);
    }

    promedio = calcula_promedio(arreglo, n);
    calcula_desviacion(promedio, arreglo, n, &desviacion);

    printf("\n\nPromedio = %.2f\nDesviacion = %.2f\n", promedio, desviacion);

    return 0;
    
}

float calcula_promedio (float *arreglo, int num){
    float sumatoria = 0;

    for (int i=0; i<num; i++){
        sumatoria += *(arreglo+i);
    }

    return (sumatoria/num);
}

void calcula_desviacion (float promedio, float *arreglo, int num, float *desviacion){
    float sumatoria = 0;

    for (int i = 0; i < num; i++)
    {
        float temp = 0;

        temp = pow(arreglo[i] - promedio,2);
        sumatoria += temp;
    }
        
    *desviacion = sqrt(sumatoria/(num-1));
}