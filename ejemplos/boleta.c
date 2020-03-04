#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>

#define MAX 100
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

int valida_clave(char clave_materia[]){
	char clave[6]={""};

	strcpy(clave, clave_materia);
	for(int i=0; i<3; i++){
		if (!isalpha(clave[i])){
			printf("Formato no válido");
			return 0;
		}
	}

	for (int i=3; i<6; i++){
		if(!isdigit(clave[i])){
			printf("Formato no válido");
			return 0;
		}
	}

	return 1;
}

void captura_materias(struct MATERIA materias[], int num_materias){
    printf("Introduce los datos\n");

    for (int i=0; i<num_materias; i++){
		char temp[6]={""};
        
		while (!valida_clave(temp))
		{
			printf("Clave: ");
			scanf("%s", temp);
			fflush(stdin);
        	__fpurge(stdin);
		}
		
		strcpy(materias[i].clave, temp);

	    printf("Materia: ");
		fgets(materias[i].nombre, strlen(materias[i].nombre), stdin);
		fflush(stdin);
        __fpurge(stdin);

	    printf("Calificación: ");
	    materias[i].calificacion = lee_calificacion();
	
    }
	
}

float promedio (struct MATERIA materias[], int num_materias){
	float sumatoria=0;
	
	for (int i=0; i<num_materias; i++){
		sumatoria += materias[i].calificacion;
	}

	return sumatoria/num_materias;
}

int busca_calificacion (struct MATERIA materias[], char clave_materia[], int num_materias){

	for(int i=0; i<num_materias; i++){
		if(strcmp(clave_materia, materias[i].clave)==0){
			return materias[i].calificacion;
		}
	}

	return -1;
}

void muestra_boleta(char nombre_alumno[], struct MATERIA materias[], int num_materias){
	printf("Alumno: %s\n", nombre_alumno);

	for (int i=0; i<num_materias; i++){
		printf("%d \t %s \t %s \t %d \n", i, materias[i].clave, materias[i].nombre, materias[i].calificacion);
	}
}

int main(){
	struct MATERIA materias[MAX];
    char nombre_alumno[20];
	char clave_materia[10];
	int num_materias=0;

	printf("Nombre del alumno: ");
	fgets(nombre_alumno,strlen(nombre_alumno),stdin);
	fflush(stdin);
    __fpurge(stdin);

	printf("Numero de materias: ");
	scanf("%d", &num_materias);

    captura_materias(materias, num_materias);
	muestra_boleta(nombre_alumno, materias, num_materias);

	printf("Promedio: %f",promedio(materias, num_materias));
}

