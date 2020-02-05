/**
 * Autor: Alejandro Ramírez Cruz
 * Fecha: 04/02/2020
 * Descripción: Juego del Ahorcado
 **/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdio_ext.h>

char palabras[][20] = {"GRYFFINDOR","SLYTERIN","HUFFLEPUFF","RAVENCLAW","HOGWARTS","QUIDDITCH","LUNATICO","CANUTO","CORNAMENTA","COLAGUSANO"};
char adivinanzas[10][20];
int intentos = 1;
int indice = 0;

void ocultarLetras(){
    for(int i = 0; i<10; i++){
        char temp[20];
        
        strcpy(temp, palabras[i]);

        for (int j = 0; j<strlen(temp); j++){
            if (j%2){
                temp[j] = '_';
            }
        }

        strcpy(adivinanzas[i], temp);
        printf("%s\n",adivinanzas[i]);
    }
}

int adivinaPalabra(char palabra[]){

    strtoup(palabra);

    if(strcmp(palabra, palabras[indice]) == 0){
        return 1;
    }

    return 0;
}

int buscarLetra(char letra){
    int aciertos = 0;
    char *palabra = palabras[indice];
    char *temp = adivinanzas[indice];

    for (int i = 0; i < strlen(palabra); i++){
        if (letra == palabra[i]){
            temp[i] = letra;
            aciertos++;
        }
    }

    if (aciertos){
        printf("%s\n", adivinanzas[indice]);
    }

    return aciertos;
}

char leerLetra(){
    char temp;

    while (1){
        temp = getchar();
        fflush(stdin);
        __fpurge(stdin);

        if (isalpha(temp)){
            temp = toupper(temp);
            return temp;
        }

        printf("Debe ingresar una letra");
    }
    
}

void strtoup(char palabra[]){
    for (int i = 0; i < strlen(palabra); i++){
        palabra[i] = toupper(palabra[i]);
    }
}

int main (){
    char letra;

    ocultarLetras();
    
    while (indice < 10){
        int acierto = 0;

        printf("\nCompleta la palabra: %s",adivinanzas[indice]);

        for (int i = 1;i <= 3; i++){
            printf("Letra: ");
            letra = leerLetra();

            if (!buscarLetra(letra)){
                printf("La letra %c no existe en la palabra\n", letra);
            }
        }

        for (;intentos <= 3; intentos++){
            char palabra[20];

            printf("Intento %d\nLa palabra es: ",intentos);
            scanf("%s",palabra);

            if (adivinaPalabra(palabra)){
                acierto = 1;
                printf("Acertaste!!! (　＾∇＾) \n");
                break;
            }

            printf("Siguiente intento (ง •̀_•́)ง\n");

        }

        if (!acierto)
            printf("Ahorcado!!! o(╥﹏╥)o");

        printf("Continuar? (S/N) ");
        letra = leerLetra();

        if (letra != 'S'){
            break;
        }

        indice++;
    }  

    return 0;
}