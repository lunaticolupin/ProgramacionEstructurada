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
    int op = -1;

    FILE *ptrCf; /* ptrCf = apuntador al archivo clientes.dat */

    /* fopen abre el archivo. Si no es capaz de crear el archivo, sale delprograma */
    if ( ( ptrCf = fopen( "clientes.dat", "wb" ) ) == NULL ) {
        printf( "El archivo no pudo abrirse\n" );
    } else { 
        /* escribe la cuenta, el nombre y el saldo dentro del archivo */
        while ( op != 0 ) { 
            printf( "Introduzca la cuenta, el nombre, y el saldo.\n" );
            printf( "? " );
            
            scanf( "%d%s%lf", &cliente.cuenta, cliente.nombre, &cliente.saldo );
            
            fwrite( &cliente, sizeof(struct cuentaCliente), 1, ptrCf  );

            printf( "Continuar 1, Parar 0 ? " );
            scanf( "%d", &op );
        }

        fclose( ptrCf );
    }

    return 0; /* indica terminación exitosa */

 }