#include <stdio.h>

struct cuentaCliente
{
    int cuenta; /* número de cuenta */
    char nombre[ 30 ]; /* nombre de cuenta */
    double saldo; /* saldo de la cuenta */
};

int main()
{
    struct cuentaCliente cliente;
    FILE *ptrCf; /* ptrCf = apuntador al archivo clientes.dat */

    /* fopen abre el archivo; si no se puede abrir el archivo, abandona el programa */ 
    if ( ( ptrCf = fopen( "clientes.dat", "rb" ) ) == NULL ) {
        printf( "El archivo no pudo abrirse\n" );
    }else { /* lee la cuenta, el nombre y el saldo del archivo */
        printf( "%-10s%-13s%s\n", "Cuenta", "Nombre", "Saldo" );
        
        /* mientras no sea fin de archivo */
        while ( !feof( ptrCf ) ) {
            fread( &cliente, sizeof( struct cuentaCliente ), 1, ptrCf ); 
            printf( "%-10d%-13s%7.2f\n", cliente.cuenta, cliente.nombre, cliente.saldo );
        } /* fin de while */

        fclose( ptrCf ); /* fclose cierra el archivo */
    } /* fin de else */
    
    return 0; /* indica terminación exitosa */
}