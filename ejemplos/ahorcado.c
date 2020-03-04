/**
 * Autor: Alejandro Ramírez Cruz
 * Fecha: 12/02/2020
 * Descripción: Juego del Ahorcado
 **/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdio_ext.h>

char palabras[10][20] = {"GRYFFINDOR","SLYTERIN","HUFFLEPUFF","RAVENCLAW","HOGWARTS","QUIDDITCH","LUNATICO","CANUTO","CORNAMENTA","COLAGUSANO"};
char adivina[10][20];
int intentos = 1;
int indice = 0;
int puntuacion = 0;

int main(){
    char letra;

    /** Sustituye cada letra impar por un guion bajo '_' en el arreglo adivina**/
    for(int i = 0; i<10; i++){
        char temp[20];
        
        strcpy(temp, palabras[i]);

        for (int j = 0; j<strlen(temp); j++){
            if (j%2){
                temp[j] = '_';
            }
        }

        strcpy(adivina[i], temp);
        printf("%s\n",adivina[i]);
    }

    for (indice=0; indice<10; indice++){

    printf("Completa la palabra %s\n", adivina[indice]);

    /** Pide una letra y la busca en la palabra original, si la encuentra sustituye el guion bajo por la letra **/
    while(intentos <=3){
        char palabra[20]; 
        char temp[20];

        strcpy(palabra,palabras[indice]);
        strcpy(temp,adivina[indice]);

        /** Ejecuta el ciclo hasta que ingrese una letra **/
        while (1){
            printf("Letra: ");
            letra = getchar();
            fflush(stdin);
            __fpurge(stdin);

            if (isalpha(letra)){
                letra = toupper(letra);
                break;
            }

            printf("Debe ingresar una letra: ");
        }

        for (int i = 0; i < strlen(palabra); i++){
            if (letra == palabra[i]){
                temp[i] = letra;
            }
        }

        strcpy(adivina[indice],temp);
        printf("%s\n", adivina[indice]);
        intentos++;
    }

    intentos=1;

    /** Pide completar la palabra, tiene 3 intentos **/
    while(intentos <=3){
        char palabra[20];

        if(strcmp(adivina[indice],palabras[indice])==0){
            puntuacion++;
            printf("Acertaste");
            break;
        }

        printf("Completa la palabra: ");
        scanf("%s",palabra);

        if(strcmp(palabra, palabras[indice]) == 0){
            puntuacion++;
            printf("Acertaste");
            break;
        }

        intentos++;
    }

    if(intentos>3){
        printf("Ahorcado");
    }

    }
}