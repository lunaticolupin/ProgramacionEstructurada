#include <stdio.h>

void leer_archivo(char nombre[]);
void crear_archivo(char nombre[]);
void cerrar(FILE *archivo);
void menu();

int main()
{
    menu();
    
    return 0; /* indica terminación exitosa */
}

void leer_archivo(char nombre_archivo[]){
    int cuenta; /* número de cuenta */
    char nombre[ 30 ]; /* nombre de cuenta */
    double saldo; /* saldo de la cuenta */

    FILE *archivo;

    if ( ( archivo = fopen( nombre_archivo, "r" ) ) == NULL ) {
        printf( "El archivo \' %s \' no pudo abrirse\n", nombre_archivo );
    } else {
        printf("Contenido del archivo %s\n", nombre_archivo);
        for (int i=0; i<100; i++) printf("-");
        printf( "\n\n%-10s%-13s%s\n", "Cuenta", "Nombre", "Saldo" );
        fscanf( archivo, "%d%s%lf", &cuenta, nombre, &saldo );

        while ( !feof( archivo ) ) { 
            printf( "%-10d%-13s%7.2f\n", cuenta, nombre, saldo );
            fscanf( archivo, "%d%s%lf", &cuenta, nombre, &saldo );
        }

        cerrar(archivo);
    }
}

void crear_archivo(char nombre_archivo[]){
    int cuenta; /* número de cuenta */
    char nombre[ 30 ]; /* nombre de cuenta */
    double saldo; /* saldo de la cuenta */

    FILE *archivo; 

    if ( ( archivo = fopen( nombre_archivo, "w" ) ) == NULL ) {
        printf( "El archivo \' %s \' no pudo abrirse\n", nombre_archivo);
    } else { 
        printf( "\nIntroduzca la cuenta, el nombre, y el saldo.\n" );
        printf( "Introduzca EOF al final de la entrada.\n" );
        printf( "? " );
        scanf( "%d%s%lf", &cuenta, nombre, &saldo );

        while ( !feof( stdin ) ) { 
            fprintf( archivo, "%d %s %.2f\n", cuenta, nombre, saldo );
            printf( "? " );
            scanf( "%d%s%lf", &cuenta, nombre, &saldo );
        }

        cerrar( archivo );
    }
}

void cerrar(FILE *archivo){
    if (archivo != NULL){
        fclose( archivo ); /* fclose cierra el archivo */

        return;
    }

    printf("Error al cerrar el archivo");
}

void menu(){
    int op = -1;
    char nombre_archivo[100];
    
    while (op !=0)
    {
        printf("Opciones\n 1) Abrir archivo\n 2) Crear archivo\n 0) Salir\n");
        printf("? ");
        scanf("%d", &op);

        if (op==1 || op==2){
            printf("Nombre del archivo: ");
            scanf("%s",nombre_archivo);
        }

        switch (op)
        {
            case 0:
                printf("FIN");
                break;

            case 1:
                leer_archivo(nombre_archivo);
                break;
            
            case 2:
                crear_archivo(nombre_archivo);
                break;

            default:
                printf("La opción no es válida\n");
        }
    }
}