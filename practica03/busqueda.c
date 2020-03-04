/**
 * Autor: Alejandro Ramírez Cru<
 * Fecha: 25/02/2020
 * Descripción: Programa que busca un valor dentro de un arreglo
 **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000 //Tamaño maximo del arreflo

int arreglo[MAX];

/** Imprime los elementos del arreglo **/
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

/** Genera los de manera aleatoria los elementos de un arreglo **/
void generar_elementos(int size){
    srand((unsigned) time(NULL));

    for(int i=0; i<size; i++){
        arreglo[i]=rand() % MAX;
    }

    imprime(arreglo, size);
}

/** Método Quicksort para ordenar los elementos de un arreglo **/
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

/** Busqueda binaria de elementos en un arreglo **/
void buscar(int arreglo[], int valor, int size){
    int primero = 0;
    int ultimo = size-1;
    int medio = (primero+ultimo)/2;
    int encontrado = 0;

    while(primero<=ultimo){

        if(arreglo[medio] == valor){
            printf("El valor %d esta en la posicion %d\n", valor, medio);
            encontrado++;

            while (arreglo[medio]==arreglo[medio+1])//Busca valores repetidos
            {
                medio++;
                printf("El valor %d esta en la posicion %d\n", valor, medio);
                encontrado++;
            }
            break;
        }

        if(arreglo[medio] < valor){
            primero = medio + 1;
        }else{
            ultimo = medio - 1;
        }

        medio = (primero+ultimo)/2;
    }

    if(!encontrado){
        printf("No se encontró el valor %d", valor);
    }

}

int main(){
    
    int size=0;
    int valor=0;

    while (size<1 || size>MAX){
        printf("Tamaño del arreglo: ");
        scanf("%d",&size);
    }

    printf("Generar los elementos del arreglo");
    generar_elementos(size);

    printf("Ordenamiento Burbuja");
    rapido(arreglo, 0, size-1);

    imprime(arreglo, size);

    printf("Valor a buscar: ");
    scanf("%d",&valor);

    buscar(arreglo,valor,size);
}