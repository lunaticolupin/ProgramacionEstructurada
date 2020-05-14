#include <stdio.h>

struct datosCliente { 
    int numCta; /* número de cuenta */
    char apellido[ 15 ]; /* apellido de la cuenta */
    char nombre[ 10 ]; /* nombre de la cuenta */
    double saldo; /* saldo de la cuenta */
}; 

int main() 
{ 
    FILE *ptrCf; 

    struct datosCliente cliente = { 0, "", "", 0.0 };

    if ( ( ptrCf = fopen( "credito.dat", "rb+" ) ) == NULL ) {
        printf( "El archivo no pudo abrirse.\n" );
    } else {
        printf( "Introduzca el numero de cuenta ( 1 a 100, 0 para terminar la entrada )\n? " );
        scanf( "%d", &cliente.numCta );

        while ( cliente.numCta != 0 ) { 
            printf( "Introduzca el apellido, el nombre, el saldo\n? " );
            fscanf( stdin, "%s%s%lf", cliente.apellido, cliente.nombre, &cliente.saldo );

            fseek( ptrCf, ( cliente.numCta - 1 ) * sizeof( struct datosCliente ), SEEK_SET );

            fwrite( &cliente, sizeof( struct datosCliente ), 1, ptrCf );

            printf( "Introduzca el numero de cuenta\n? " );
            scanf( "%d", &cliente.numCta );
        }

        fclose( ptrCf );
    }

    return 0; 
}