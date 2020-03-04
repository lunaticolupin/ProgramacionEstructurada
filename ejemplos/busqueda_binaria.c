#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arreglo[1000];

void imprime(int arreglo[], int size){
    for(int i=0; i<size; i++){
        if (i==0){
            printf("\n[%d,",arreglo[i]);
            continue;
        }

        if (i==size-1){
            printf("%d]\n",arreglo[i]);
            continue;
        }

        printf("%d,", arreglo[i]);
    }
}

void generar_elementos(int size){
    srand((unsigned) time(NULL));

    for(int i=0; i<size; i++){
        arreglo[i]=rand()%1000;
    }

    imprime(arreglo,size);
}

int menor(int arreglo[], int size, int inicio){
    int menor = arreglo[inicio];
    int posicion = inicio;

    for (int i = inicio; i<size; i++){
        if (arreglo[i] < menor){
            menor = arreglo[i];
            posicion = i;
        }
    }

    return posicion;
}

void burbuja(int arreglo[], int size){
    for(int i = 0; i<size; i++){
        for (int j = 0; j<size-1; j++){
            if(arreglo[j] > arreglo[j+1]){
                int temp = arreglo[j];
                
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = temp;
            }
        }
    }

    imprime(arreglo,size);
}

void seleccion(int arreglo[], int size){
    for (int i=0; i<size-1;i++){
        int posicion_menor = menor(arreglo,size,i);
        int temp = arreglo[i];

        arreglo[i] = arreglo[posicion_menor];
        arreglo[posicion_menor] = temp;
    }

    imprime(arreglo, size);
}

void insercion(int arreglo[], int size){
    for (int i=1; i<size; i++){
        int temp = arreglo[i];
        int j = i-1;

        while((arreglo[j]>temp && (j>=0))){
            arreglo[j+1] = arreglo[j];
            j--;
        }

        arreglo[j+1] = temp;
    }
}

void rapido(int arreglo[], int inferior, int superior){
    int pivote = arreglo[superior];
    int temp;
    int i = inferior -1, j = superior;
    
    if(inferior > superior)
        return;
    
    while(1){
        while (arreglo[++i] < pivote);
        while (arreglo[--j] > pivote);

        if (i<j){
            temp = arreglo[i];
            arreglo[i]=arreglo[j];
            arreglo[j]=temp;
        }else{
            break;
        }       
    }

    temp = arreglo[i];
    arreglo[i] = arreglo[superior];
    arreglo[superior] = temp;

    rapido(arreglo, inferior, i-1);
    rapido(arreglo,i+1, superior);
}

void busqueda(int arreglo[], int size, int valor){
    int primero = 0, ultimo = size-1, medio = (primero+ultimo)/2;
    int encontrado = 0;

    while (primero <= ultimo){
        if (arreglo[medio] < valor){
            primero = medio + 1;
        }else if(arreglo[medio] == valor){
            printf("El valor esta en la posición %d\n", medio);
            encontrado++;
            break;
        }else{
            ultimo = medio - 1;
        }

        medio = (primero + ultimo)/2;
    }

    if (!encontrado){
        printf("No se encontró el valor\n");
    }
}

int main(){
    
    int n=0, valor=0;

    printf("Tamaño del arreglo: ");
    scanf("%d",&n);

    printf("Generar los elementos del arreglo");
    generar_elementos(n);

    printf("Ordenamiento Burbuja");
    burbuja(arreglo,n);

    imprime(arreglo,n);

    printf("Valor a buscar: ");
    scanf("%d", &valor);

    busqueda(arreglo, n, valor);
}