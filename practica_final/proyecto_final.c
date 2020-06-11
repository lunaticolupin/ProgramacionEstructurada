#include<stdio.h>
#include <stdlib.h>
#include <math.h>

struct nodoLista {
    float dato; 
    struct nodoLista *ptrSiguiente; 
};

typedef struct nodoLista NodoLista; /* sinónimo para la estructura nodoLista */
typedef NodoLista *ptrNodoLista; /* sinónimo para de NodoLista* */

void leer_archivo(char *ruta, ptrNodoLista nodo);
void leer_datos(ptrNodoLista nodo);
void agregar_nodo(ptrNodoLista *nodo, float valor);
void mostrar_lista(ptrNodoLista nodo);
float promedio(ptrNodoLista nodo);
float desviacion(float promedio, ptrNodoLista nodo);

int main(){

    ptrNodoLista nodoInicial;
    int op = 0;
    char nombre_archivo[100];
    
    printf("CALCULO DE PROMEDIO Y DESVIACION ESTANDARD");
    

    printf("\n1) Leer datos desde archivo \n2) Leer datos desde teclado \n3) Salir\n");
    printf("Op? ");
    scanf("%d",&op);
    fflush(stdin);

    switch (op)
    {
    case 1:
        nodoInicial = NULL;
        printf("Ruta del archivo: ");
        scanf("%s",nombre_archivo);
        leer_archivo(nombre_archivo, nodoInicial);
        break;
    
    case 2:
        nodoInicial = NULL;
        printf("Introduce los numeros\n");
        leer_datos(nodoInicial);
        break;

    case 3:
        printf("Fin");
        return 0;

    default:
        printf("La opcion no es valida");
        break;
    }

    return 0;
}

void leer_archivo(char *ruta, ptrNodoLista nodoRaiz){
    FILE *archivo; 
    float temp = 0, temp_promedio = 0, temp_desviacion = 0;
 
    if ( ( archivo = fopen( ruta, "r" ) ) == NULL ) {
        printf( "El archivo no pudo abrirse\n" );
    } else { 
        while ( !feof( archivo ) ) { 
            fscanf( archivo, "%f", &temp);
            printf( "Elemento: %.2f\n", temp);
            agregar_nodo(&nodoRaiz, temp);
        }
        fclose( archivo ); 
    } 

    mostrar_lista(nodoRaiz);
    temp_promedio = promedio(nodoRaiz);
    temp_desviacion = desviacion(temp_promedio, nodoRaiz);
    printf ("\n Promedio: %.2f \n Desviacion : %.2f \n", temp_promedio, temp_desviacion);
}

void leer_datos(ptrNodoLista nodoRaiz){
    float temp = 0, temp_promedio = 0, temp_desviacion = 0;
    int num_elementos = 0;

    printf("Numero de elementos de la lista: ");
    scanf("%d",&num_elementos);

    for (int i = 0; i<num_elementos; i++){
        printf("Elemento [%d]: ",i);
        scanf("%f",&temp);
        agregar_nodo(&nodoRaiz, temp);
    }

    mostrar_lista(nodoRaiz);
    temp_promedio = promedio(nodoRaiz);
    temp_desviacion = desviacion(temp_promedio, nodoRaiz);
    printf ("\n Promedio: %.2f \n Desviacion : %.2f \n", temp_promedio, temp_desviacion);
}

void agregar_nodo(ptrNodoLista *nodoRaiz, float valor){
    ptrNodoLista ptrNuevo; 
    ptrNodoLista ptrAnterior;
    ptrNodoLista ptrActual;
    ptrNuevo = malloc( sizeof( NodoLista ) );

    if ( ptrNuevo != NULL ) { 
        ptrNuevo->dato = valor; 
        ptrNuevo->ptrSiguiente = NULL;

        ptrAnterior = NULL;
        ptrActual = *nodoRaiz;

        ptrNuevo->ptrSiguiente = *nodoRaiz;
        *nodoRaiz = ptrNuevo;
    } else {
        printf( "No se inserto %f. No hay memoria disponible.\n", valor );
    } 
}

void mostrar_lista( ptrNodoLista ptrActual )
{ 

    if ( ptrActual == NULL ) {
        printf( "La lista esta vacia.\n\n" );
    } else { 
        printf("\n");
        while ( ptrActual != NULL ) { 
            printf( "%.2f -> ", ptrActual->dato );
            ptrActual = ptrActual->ptrSiguiente; 
        } 

        printf( "NULL\n\n" );
    } 
}

float promedio (ptrNodoLista nodoActual){
    int num_elementos = 0;
    float sumatoria = 0;

    if (nodoActual == NULL){
        printf("Lista vacia\n\n");
        return 0;
    }

    while (nodoActual != NULL)
    {
        float temp = 0;

        temp = nodoActual->dato;
        sumatoria +=temp;
        nodoActual = nodoActual->ptrSiguiente;
        num_elementos++;
    }
    
    return (sumatoria/num_elementos);

}

float desviacion(float promedio, ptrNodoLista nodoActual){
    int num_elementos = 0;
    float sumatoria = 0;

    if ( nodoActual == NULL ) {
        printf( "La lista esta vacia.\n\n" );
        return 0;
    } 

    while ( nodoActual != NULL ) { 
        float temp=0;
        int dato=0;

        dato = nodoActual->dato;
        temp = pow(dato - promedio,2);
        sumatoria += temp;
        
        nodoActual = nodoActual->ptrSiguiente; 
        num_elementos++;
    } 

    return (sqrt(sumatoria/(num_elementos-1)));
}