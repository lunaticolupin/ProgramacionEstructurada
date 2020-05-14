#include <stdio.h>

struct datosCliente { 
    int numCta; /* número de cuenta */
    char apellido[ 15 ]; /* apellido de la cuenta */
    char nombre[ 10 ]; /* nombre de la cuenta */
    double saldo; /* saldo de la cuenta */
}; /* fin de la estructura datosCliente */

int main()
{ 
    int i; /* contador utilizado para contar de 1 a 100 */

    struct datosCliente clienteEnBlanco = { 0, "", "", 0.0 }; 
    FILE *ptrCf; /* apuntador al archivo credito.dat */

    if ( ( ptrCf = fopen( "credito.dat", "wb" ) ) == NULL ) {
        printf( "No pudo abrirse el archivo.\n" );  
    } else { 

        for ( i = 1; i <= 100; i++ ) {
            fwrite( &clienteEnBlanco, sizeof( struct datosCliente ), 1, ptrCf );
        }

        fclose ( ptrCf ); 
    } 
    
    return 0; 
}