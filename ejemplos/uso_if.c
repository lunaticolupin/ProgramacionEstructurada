/** 
 * Autor: Alejandro Ramírez Cruz
 * Fecha: 20/01/2020
 * version: 1.0
 **/
#include <stdio.h>

/** Lee dos numero y muestra que relaciones de comparación se cumplen **/
int main()
{
	int num1; /* primer número que lee el usuario */
	int num2; /* segundo número que lee el usuario */

	printf("Introduzca dos enteros, y le dire\n");
	printf("las relaciones que satisfacen: ");

	scanf("%d %d", &num1, &num2 ); /* lectura de los enteros */
	if ( num1 == num2 ) {
		printf( "%d es igual que %d\n", num1, num2 );
	} 

	if ( num1 != num2 ) {
		printf( "%d no es igual que %d\n", num1, num2 );
	} 

	if ( num1 < num2 ) {
		printf( "%d es menor que %d\n", num1, num2 );
	} 

	if ( num1 > num2 ) {
		printf( "%d es mayor que %d\n", num1, num2 );
	} 

	if ( num1 <= num2 ) {
		printf( "%d es menor o igual que %d\n", num1, num2 );
	} 

	if ( num1 >= num2 ) {
		printf( "%d es mayor o igual que %d\n", num1, num2 );
	} 

	return 0;
}
