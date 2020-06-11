#include <stdio.h>
#include <math.h>

float promedio (float *, int);
void desviacion (float, float *, int, float *);

int main(){
    int n=0;
    float temp_promedio = 0, temp_desviacion = 0;

    printf("Elementos del arreglo: ");
    scanf("%d", &n);

    float arreglo[n];
    
    for(int i=0; i<n; i++){
        printf("Elemento [%d] ",i);
        scanf("%f", &arreglo[i]);
    }

    temp_promedio = promedio(arreglo, n);
    desviacion(temp_promedio, arreglo, n, &temp_desviacion);

    printf("\n\nPromedio = %.2f\nDesviacion = %.2f\n", temp_promedio, temp_desviacion);

    return 0;
}

float promedio (float *arreglo, int size){
    float sumatoria = 0;

    for (int i = 0; i<size ; i++){
        sumatoria += *(arreglo+i);
    }

    return (sumatoria/size);
}

void desviacion (float promedio, float *arreglo, int size, float *desviacion){
    float sumatoria = 0;

    for (int i = 0; i < size; i++)
    {
        float temp = 0;

        temp = pow(arreglo[i] - promedio,2);
        sumatoria += temp;
    }
        
    *desviacion = sqrt(sumatoria/(size-1));
}