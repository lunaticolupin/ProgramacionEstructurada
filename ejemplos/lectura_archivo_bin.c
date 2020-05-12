#include <stdio.h>

struct datosCliente { 
    int numCta; /* número de cuenta */
    char apellido[ 15 ]; /* apellido */
    char nombre[ 10 ]; /* nombre */
    double saldo; /* saldo */
}; /* fin de la estructura datosCliente */

int main()
{ 
    FILE *ptrCf; /* apuntador de archivo credito.dat */

    /* crea datosCliente con información predeterminada */
    struct datosCliente cliente = { 0, "", "", 0.0 };

    /* fopen abre el archivo; si no se puede abrir, sale del archivo */
    if ( ( ptrCf = fopen( "credito.dat", "rb" ) ) == NULL ) {
        printf( "No pudo abrirse el archivo.\n" );
    } else { 
        printf( "%-6s%-16s%-11s%10s\n", "Cta", "Apellido", "Nombre", "Saldo" );
        
        /* lee todos los registro del archivo (hasta eof) */
        while ( !feof( ptrCf ) ) { 
            fread( &cliente, sizeof( struct datosCliente ), 1, ptrCf );
            
            //if ( cliente.numCta != 0 ) {
                printf( "%-6d%-16s%-11s%10.2f\n", cliente.numCta, cliente.apellido, cliente.nombre, cliente.saldo );
            //} 
        } 

        fclose( ptrCf );
    }
    return 0;  
}