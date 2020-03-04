/*
 *Alejandro Ramírez Cruz
 * ejemplo del uso de estructuras
 */

#include <stdio.h>

struct MATERIA{
	char nombre_alumno[20];
	char nombre_materia[20];
	int calificacion;
};

int main(){
	struct MATERIA materia;
	printf("Introduce los datos\n");
	printf("Alumno :");
	scanf("%s", materia.nombre_alumno);
	printf("Materia: ");
	scanf("%s", materia.nombre_materia);
	printf("Calificación: ");
	scanf("%d", &materia.calificacion);

	printf("%s %s %d",materia.nombre_alumno, materia.nombre_materia, 
	materia.calificacion);
}

