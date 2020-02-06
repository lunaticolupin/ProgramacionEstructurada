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
int puntuacion = 0;

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

void strtoup(char palabra[]){
    for (int i = 0; i < strlen(palabra); i++){
        palabra[i] = toupper(palabra[i]);
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

        printf("Debe ingresar una letra: ");
    }
    
}

int main (){
    char letra;

    ocultarLetras();
    
    while (indice < 10){

        printf("\nPalabra %d: %s\n",indice+1,adivinanzas[indice]);

        for (int i = 1;i <= 3; i++){
            printf("Letra: ");
            letra = leerLetra();

            if (!buscarLetra(letra)){
                printf("(ー_ー)!! La letra %c no existe en la palabra\n", letra);
            }
        }

        while (intentos <= 3){
            char palabra[20];

            printf("Intento %d\n\tCompleta la palabra: ",intentos);
            scanf("%s",palabra);
            fflush(stdin);
            __fpurge(stdin);

            if (adivinaPalabra(palabra)){
                printf("\n(^_^)/ ACERTASTE! +1p \n");
                puntuacion++;
                break;
            }

            printf("\n (－‸ლ) Siguiente intento \n");
            intentos++;
        }

        if (intentos > 3)
            printf("\n((+_+)) AHORCADO! 0p \n");

        printf("\nContinuar? (S/N) ");
        letra = leerLetra();

        if (letra != 'S'){
            break;
        }

        intentos = 1;
        indice++;
    }  

    printf("\n(^_^)/ Puntaje final %d puntos \n",puntuacion);

    return 0;
}