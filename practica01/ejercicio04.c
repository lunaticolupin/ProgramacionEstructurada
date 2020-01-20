#include <stdio.h>

int main (){
    int num_articulos = 0, cantidad = 0, i;
    float precio = 0.0, iva = 0.0, subtotal_articulo = 0.0, subtotal = 0.0, total_iva = 0.0, total = 0.0;

    printf("Nota de venta");
    printf("\nNumero de articulos vendidos: ");
    scanf("%d", &num_articulos);

    for(i = 1; i<=num_articulos; i++){
        printf("\nArticulo %d\n", i);
        printf("\tCantidad de articulos: ");
        scanf("%d",&cantidad);
        printf("\tPrecio del articulo: ");
        scanf("%f",&precio);
        iva = (cantidad * precio) * 0.16;
        subtotal_articulo = (cantidad * precio);
        total_iva = total_iva + iva;
        subtotal= subtotal + subtotal_articulo;
        subtotal_articulo = subtotal_articulo + iva;
        printf("\tIVA: %.2f\n",iva);
        printf("\tTotal del articulo: %.2f\n", subtotal_articulo);
    }

    total = subtotal + total_iva;
    printf("Subtotal: %.2f\n",subtotal);
    printf("IVA: %.2f\n", total_iva);
    printf("Total de venta: %.2f\n", total);
}