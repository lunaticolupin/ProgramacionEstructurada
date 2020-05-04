#include <stdio.h>
int main()
{
    int cuenta; /* número de cuenta */
    char nombre[ 30 ]; /* nombre de cuenta */
    double saldo; /* saldo de la cuenta */

    FILE *ptrCf; /* ptrCf = apuntador al archivo clientes.dat */

    /* fopen abre el archivo; si no se puede abrir el archivo, abandona el programa */ 
    if ( ( ptrCf = fopen( "clientes.dat", "r" ) ) == NULL ) {
        printf( "El archivo no pudo abrirse\n" );
    } /* fin de if */
    else { /* lee la cuenta, el nombre y el saldo del archivo */
        printf( "%-10s%-13s%s\n", "Cuenta", "Nombre", "Saldo" );
        fscanf( ptrCf, "%d%s%lf", &cuenta, nombre, &saldo );

        /* mientras no sea fin de archivo */
        while ( !feof( ptrCf ) ) { 
            printf( "%-10d%-13s%7.2f\n", cuenta, nombre, saldo );
            fscanf( ptrCf, "%d%s%lf", &cuenta, nombre, &saldo );
        } /* fin de while */

        fclose( ptrCf ); /* fclose cierra el archivo */
    } /* fin de else */
    
    return 0; /* indica terminación exitosa */
}