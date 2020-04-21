#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 /* estructura auto_referenciada */
struct nodoLista {
    int dato; 
    struct nodoLista *ptrSiguiente; 
}; /* fin de la estructura nodoLista */

typedef struct nodoLista NodoLista; /* sinónimo para la estructura nodoLista */
typedef NodoLista *ptrNodoLista; /* sinónimo para de NodoLista* */

/* prototipos */
void insertar( ptrNodoLista *ptrS, int valor );
char eliminar( ptrNodoLista *ptrS, int valor );
int estaVacia( ptrNodoLista ptrS );
void imprimeLista( ptrNodoLista ptrActual );
void instrucciones( void );
void calcular(ptrNodoLista ptrActual);
int num_elementos = 0;
float sumatoria = 0, promedio = 0, desviacion = 0;

int main()
{ 
    ptrNodoLista ptrInicial = NULL; 
    int eleccion; 
    int elemento;

    instrucciones(); /* despliega el menú */
    printf( "? " );
    scanf( "%d", &eleccion );

    /* repite mientras el usuario no elija 3 */
    while ( eleccion != 4 ) { 

        switch ( eleccion ) { 

            case 1:
                printf( "Numero: " );
                scanf( "\n%d", &elemento );
                insertar( &ptrInicial, elemento ); /* inserta el elemento en la lista */
                imprimeLista( ptrInicial );
                break;

            case 2:

                /* si la lista no está vacía */
                if ( !estaVacia( ptrInicial ) ) { 
                    printf( "Introduzca un caracter para eliminar: " );
                    scanf( "\n%d", &elemento );

                    /* si encuentra el carácter, lo remueve */
                    if ( eliminar( &ptrInicial, elemento ) ) { /* elimina elemento */
                        printf( "numero %d eliminado.\n", elemento );
                        imprimeLista( ptrInicial );
                    } /* fin de if */
                    else {
                        printf( "no se encuentra el numero %d.\n\n", elemento );
                    } /* fin de else */

                } /* fin de if */
                else {
                    printf( "La lista esta vacia.\n\n" );
                } /* fin de else */

                break;
            
            case 3:
                calcular(ptrInicial );
                break;

             default:
                printf( "Opcion invalida.\n\n" );
                instrucciones();
                break;

        } /* fin de switch */

        printf( "? " );
        scanf( "%d", &eleccion );
    } /* fin de while */

    printf( "Fin de la ejecucion.\n" );

    return 0; /* indica terminación exitosa */

 } /* fin de main */

 /* despliega las instrucciones del programa para el usuario */
void instrucciones( void )
{ 
    printf( "Introduzca su eleccion:\n"
    " 1 para insertar un elemento en la lista.\n"
    " 2 para eliminar un elemento de la lista.\n"
    " 3 calcular promedio y media \n"
    " 4 para terminar.\n" );
} /* fin de la función instrucciones */

 /* Inserta un nuevo valor dentro de la lista en orden */
void insertar( ptrNodoLista *ptrS, int valor )
{ 
    ptrNodoLista ptrNuevo; /* apuntador a un nuevo nodo */
    ptrNodoLista ptrAnterior; /* apuntador a un nodo previo de la lista */
    ptrNodoLista ptrActual; /* apuntador al nodo actual de la lista */
    ptrNuevo = malloc( sizeof( NodoLista ) ); /* crea un nodo */

    if ( ptrNuevo != NULL ) { /* es espacio disponible */
        ptrNuevo->dato = valor; /* coloca el valor en el nodo */
        ptrNuevo->ptrSiguiente = NULL; /* el nodo no se liga a otro nodo */

        ptrAnterior = NULL;
        ptrActual = *ptrS;

        /* ciclo para localizar la ubicación correcta en la lista */
        while ( ptrActual != NULL && valor > ptrActual->dato ) { 
            ptrAnterior = ptrActual; /* entra al ... */
            ptrActual = ptrActual->ptrSiguiente; /* ... siguiente nodo */
        } /* fin de while */

        /* inserta un nuevo nodo al principio de la lista */
        if ( ptrAnterior == NULL ) { 
            ptrNuevo->ptrSiguiente = *ptrS;
            *ptrS = ptrNuevo;
        } /* fin de if */
        else { /* inserta un nuevo nodo entre ptrAnterior y ptrActual */
            ptrAnterior->ptrSiguiente = ptrNuevo;
            ptrNuevo->ptrSiguiente = ptrActual;
        } /* fin de else */

        num_elementos++;
        sumatoria += valor;

    } /* fin de if */
    else {
    printf( "No se inserto %c. No hay memoria disponible.\n", valor );
    } /* fin de else */

} /* fin de la función insertar */

/* Elimina un elemento de la lista */
char eliminar( ptrNodoLista *ptrS, int valor )
{ 
    ptrNodoLista ptrAnterior; /* apuntador a un nodo previo de la lista */
    ptrNodoLista ptrActual; /* apuntador al nodo actual de la lista */
    ptrNodoLista tempPtr; /* apuntador a un nodo temporal */

    /* elimina el primer nodo */
    if ( valor == ( *ptrS )->dato ) { 
        tempPtr = *ptrS; /* almacena el nodo a eliminar */
        *ptrS = ( *ptrS )->ptrSiguiente; /* desata el nodo */
        free( tempPtr ); /* libera el nodo desatado */
        num_elementos--;
        sumatoria -= valor;
        return valor;
    } /* fin de if */
    else { 
        ptrAnterior = *ptrS;
        ptrActual = ( *ptrS )->ptrSiguiente;

        /* ciclo para localizar la ubicación correcta en la lista */
        while ( ptrActual != NULL && ptrActual->dato != valor ) { 
            ptrAnterior = ptrActual; /* entra al ... */
            ptrActual = ptrActual->ptrSiguiente; /* ... siguiente nodo */
        } /* fin de while */

        /* elimina el nodo de ptrActual */
        if ( ptrActual != NULL ) { 
            tempPtr = ptrActual;
            ptrAnterior->ptrSiguiente = ptrActual->ptrSiguiente;
            free( tempPtr );

            num_elementos--;
            sumatoria -= valor;

            return valor;
        } /* fin de if */
    } /* fin de else */

    return '\0';

} /* fin de la función eliminar */

/* Devuelve 1 si la lista está vacía, de lo contrario, 0 */
int estaVacia( ptrNodoLista ptrS )
{ 
    return ptrS == NULL;

} /* fin de la función function estaVacia */

 /* Imprime la lista */
void imprimeLista( ptrNodoLista ptrActual )
{ 

    /* si la lista está vacía */
    if ( ptrActual == NULL ) {
        printf( "La lista esta vacia.\n\n" );
    } /* fin de if */
    else { 
        printf( "La lista es:\n" );

        /* mientras no sea el final de la lista */
        while ( ptrActual != NULL ) { 
            printf( "%d -> ", ptrActual->dato );
            ptrActual = ptrActual->ptrSiguiente; 
        } /* fin de while */

        printf( "NULL\n\n" );
    } /* fin de else */

} /* fin de la función imprimeLista */

void calcular(ptrNodoLista ptrActual)
{
    promedio = sumatoria / num_elementos;

    sumatoria = 0;

    if ( ptrActual == NULL ) {
        printf( "La lista esta vacia.\n\n" );
    } /* fin de if */
    else { 
        /* mientras no sea el final de la lista */
        while ( ptrActual != NULL ) { 
            float temp=0;
            int dato=0;
            //printf( "%c -> ", ptrActual->dato );

            dato = ptrActual->dato;
            temp = pow(dato - promedio,2);
            sumatoria += temp;
            
            ptrActual = ptrActual->ptrSiguiente; 
        } /* fin de while */
    } /* fin de else */

    desviacion = sqrt(sumatoria/(num_elementos-1));
    
    printf("\nPromedio = %.2f\nDesviacion = %.2f\n", promedio, desviacion);

}