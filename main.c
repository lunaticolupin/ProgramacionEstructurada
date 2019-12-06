#include <stdio.h>
#include<stdlib.h>

struct nodoLista{
  char dato;
  struct nodoLista *ptrSiguiente;
};

typedef struct nodoLista NodoLista;
typedef NodoLista *ptrNodoLista;

void insertar( ptrNodoLista *ptrS, char valor );
char eliminar( ptrNodoLista *ptrS, char valor );
int estaVacia( ptrNodoLista ptrS );
void imprimeLista( ptrNodoLista ptrActual );
void instrucciones( void );

int main(void) {
  printf("Hello World\n");
  return 0;
}