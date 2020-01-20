#include <stdio.h>

int main(){
    int aciertos = 0;

    printf("Colegio Hogwarts de Magia y Hechiceria\n");
    printf("Introduce el numero de aciertos (0-100): ");
    scanf("%d", &aciertos);

    if (aciertos <0 || aciertos >100){
        printf("El numero de aciertos debe estar entre 0 y 100. Muggle\n");
        return 0;
    }

    if (aciertos >=0 && aciertos < 50 ){
        printf("Calificacion: Troll\n");
        return 0;
    }

    if (aciertos >= 50 && aciertos < 60){
        printf("Calificacion: Desastroso\n");
        return 0;
    }

    if (aciertos >= 60 && aciertos < 80){
        printf("Calificacion: Satisfactorio\n");
        return 0;
    }

    if(aciertos >= 80 && aciertos < 90){
        printf("Calificacion: Supera las expectativas\n");
        return 0;
    }

    if(aciertos >= 90){
        printf("Calificacion: Extraordinario\n");
    }

    return 0;
}