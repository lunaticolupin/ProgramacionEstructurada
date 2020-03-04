#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>

struct MATERIA{
	char clave[6];
	char nombre[20];
	int calificacion;
};



int lee_calificacion(){
	int temp = -1;
	
	while(temp < 0 || temp > 11){
		scanf("%d", &temp);
	}

	return temp;
}

void lee_clave(char clave[]){
	char temp[6];
	int valido = 0;

	while(valido<6){
		scanf("%s", temp);
		fflush(stdin);
        __fpurge(stdin);

		for(int i=0; i<3; i++){
			if (!isalpha(temp[i])){
				break;
			}

			valido++;
		}

		for (int i=3; i<6; i++){
			if(!isdigit(temp[i])){
				break;
			}

			valido++;
		}

		if(valido!=6){
			printf("Formato no válido\nClave:");
			valido = 0;
		}
	}
	
	strcpy(clave,temp);
}

void captura_materias(struct MATERIA materias[]){
    printf("Introduce los datos\n");

    for (int i=0; i<1; i++){
        printf("Clave: ");
		lee_clave(materias[i].clave);
		//scanf("%s",materias[i].clave);
		fflush(stdin);
        __fpurge(stdin);
	    printf("Materia: ");
		scanf("%20[^\n]",materias[i].nombre);
		printf("%s %s",materias[i].clave,materias[i].nombre);

	    printf("Calificación: ");
	    materias[i].calificacion = lee_calificacion();
		
		printf("%s %s",materias[i].clave,materias[i].nombre);
    }
	
}

float promedio (struct MATERIA materias[]){
	float sumatoria=0;
	for (int i=0; i<1; i++){
		sumatoria += materias[i].calificacion;
	}

	return sumatoria/5;
}

int busca_calificacion (struct MATERIA materias[], char clave_materia[]){
	for(int i=0; i<5; i++){
		if(strcmp(clave_materia, materias[i].clave)==0){
			return materias[i].calificacion;
		}
	}

	return -1;
}

void muestra_boleta(char nombre_alumno[], struct MATERIA materias[]){
	printf("Alumno: %s\n", nombre_alumno);
	for (int i=0; i<5; i++){
		//printf("%d\t%s\t%s\t%d\n",i, materias[i].clave, materias[i].nombre, materias[i].calificacion);
		printf("%s",materias[i].clave);
	}
}

int main(){
	struct MATERIA materias[5];
    char nombre_alumno[10];
	char clave_materia[10];

	printf("Nombre del alumno: ");
	fgets(nombre_alumno,10,stdin);
	fflush(stdin);
        __fpurge(stdin);

    captura_materias(materias);
	muestra_boleta(nombre_alumno, materias);

	printf("Promedio: %f",promedio(materias));

	/*printf("\nClave de materia: ");
	scanf("%s", clave_materia);

	int calificacion = busca_calificacion(materias, clave_materia);

	if(calificacion>=0){
		printf("Calificación: %d\n",calificacion);
	}else{
		printf("No se encontro la materia");
	}*/
}

