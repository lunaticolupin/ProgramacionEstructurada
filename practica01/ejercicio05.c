#include <stdio.h>

int main(){
    int opcion=1;
    float pi=3.1416, area=-0.1, base=0.0, altura = 0.0, radio=0.0;

    printf("Calculo de areas\n");

    while (opcion >0 && opcion <5)
    {
        printf("\n Elige una figura\n");
        printf("1. Circulo\n");
        printf("2. Triangulo\n");
        printf("3. Cuadrado\n");
        printf("4. Rectangulo\n");
        printf("Opcion: ");
        scanf("%d",&opcion);

        switch (opcion)
        {
        case 1:
            printf("Valor del radio: ");
            scanf("%f", &radio);
            area = pi * radio * radio;
            break;
        
        case 2:
            printf("Valor de la base: ");
            scanf("%f", &base);

            printf("Valor de la altura: ");
            scanf("%f",&altura);

            area = (base * altura)/2;
            break;
        
        case 3:
            printf("Valor del lado: ");
            scanf("%f", &base);

            area = base * base;
            break;

        case 4:
            printf("Valor de la base: ");
            scanf("%f", &base);

            printf("Valor de la altura: ");
            scanf("%f",&altura);

            area = base * altura;
            break;
        
        default:
            printf("Fin\n");
            area = -0.1;
            break;
        }

        if (area != -0.1)
            printf("Area: %.2f\n",area);
    }
    
}