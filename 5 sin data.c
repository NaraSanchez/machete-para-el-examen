#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int legajo;
	char nombre[50];
	float nota;
} Alumno;

int main() {
	FILE *archivo;
	Alumno alumno;
	Alumno mayorNota, menorNota;
	
	int totalAlumnos = 0;
	int aprobados = 0;
	int desaprobados = 0;
	
	float sumaNotas = 0;
	float sumaDesaprobados = 0;
	
	archivo = fopen("alumnos.dat", "rb");
	
	if (archivo == NULL) {
		printf("Error al abrir el archivo.\n");
		return 1;
	}
	
	if (fread(&alumno, sizeof(Alumno), 1, archivo) == 1) {
		
		mayorNota = alumno;
		menorNota = alumno;
		
		do {
			totalAlumnos++;
			
			sumaNotas += alumno.nota;
			
			if (alumno.nota > mayorNota.nota)
				mayorNota = alumno;
			
			if (alumno.nota < menorNota.nota)
				menorNota = alumno;
			
			if (alumno.nota >= 6) {
				aprobados++;
			} else {
				desaprobados++;
				sumaDesaprobados += alumno.nota;
			}
			
		} while (fread(&alumno, sizeof(Alumno), 1, archivo) == 1);
		
	} else {
		printf("El archivo está vacío.\n");
		fclose(archivo);
		return 1;
	}
	
	fclose(archivo);
	
	float promedioGeneral = sumaNotas / totalAlumnos;
	float porcentajeAprobados = (float)aprobados * 100 / totalAlumnos;
	
	float promedioDesaprobados = 0;
	if (desaprobados > 0)
		promedioDesaprobados = sumaDesaprobados / desaprobados;
	
	printf("\n===== INFORME DE ALUMNOS =====\n");
	
	printf("Total de alumnos: %d\n", totalAlumnos);
	
	printf("\nAlumno con nota más alta:\n");
	printf("Legajo: %d\n", mayorNota.legajo);
	printf("Nombre: %s\n", mayorNota.nombre);
	printf("Nota: %.2f\n", mayorNota.nota);
	
	printf("\nAlumno con nota más baja:\n");
	printf("Legajo: %d\n", menorNota.legajo);
	printf("Nombre: %s\n", menorNota.nombre);
	printf("Nota: %.2f\n", menorNota.nota);
	
	printf("\nPromedio general: %.2f\n", promedioGeneral);
	
	printf("Cantidad de alumnos con nota >= 6: %d\n", aprobados);
	
	printf("Cantidad de alumnos con nota < 6: %d\n", desaprobados);
	
	printf("Porcentaje de alumnos con nota >= 6: %.2f%%\n",
		   porcentajeAprobados);
	
	printf("Promedio de alumnos con nota < 6: %.2f\n",
		   promedioDesaprobados);
	
	return 0;
}
