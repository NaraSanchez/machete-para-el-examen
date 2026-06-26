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
	
	int cantidad;
	
	int totalAlumnos = 0;
	int aprobados = 0;
	int desaprobados = 0;
	
	float sumaNotas = 0;
	float sumaDesaprobados = 0;
	
	Alumno mayorNota, menorNota;
	
	
	// CREAR ARCHIVO Y CARGAR ALUMNOS
	
	archivo = fopen("alumnos.dat", "wb");
	
	if (archivo == NULL) {
		printf("No se pudo crear el archivo\n");
		return 1;
	}
	
	
	printf("Ingrese cantidad de alumnos: ");
	scanf("%d", &cantidad);
	
	
	for(int i = 0; i < cantidad; i++) {
		
		printf("\nAlumno %d\n", i+1);
		
		printf("Legajo: ");
		scanf("%d", &alumno.legajo);
		
		printf("Nombre: ");
		scanf("%s", alumno.nombre);
		
		printf("Nota: ");
		scanf("%f", &alumno.nota);
		
		
		fwrite(&alumno, sizeof(Alumno), 1, archivo);
	}
	
	
	fclose(archivo);
	
	
	
	// LEER ARCHIVO Y CALCULAR DATOS
	
	
	archivo = fopen("alumnos.dat", "rb");
	
	if (archivo == NULL) {
		printf("No se pudo abrir el archivo\n");
		return 1;
	}
	
	
	if(fread(&alumno, sizeof(Alumno), 1, archivo) == 1) {
		
		mayorNota = alumno;
		menorNota = alumno;
		
		
		do {
			
			totalAlumnos++;
			
			sumaNotas += alumno.nota;
			
			
			if(alumno.nota > mayorNota.nota) {
				mayorNota = alumno;
			}
			
			
			if(alumno.nota < menorNota.nota) {
				menorNota = alumno;
			}
			
			
			if(alumno.nota >= 6) {
				aprobados++;
			}
			else {
				desaprobados++;
				sumaDesaprobados += alumno.nota;
			}
			
			
		} while(fread(&alumno, sizeof(Alumno), 1, archivo) == 1);
		
	}
	
	
	fclose(archivo);
	
	
	
	// RESULTADOS
	
	
	printf("\n========== INFORME ==========\n");
	
	
	printf("Total de alumnos: %d\n", totalAlumnos);
	
	
	printf("\nAlumno con nota mas alta:\n");
	printf("Nombre: %s\n", mayorNota.nombre);
	printf("Legajo: %d\n", mayorNota.legajo);
	printf("Nota: %.2f\n", mayorNota.nota);
	
	
	
	printf("\nAlumno con nota mas baja:\n");
	printf("Nombre: %s\n", menorNota.nombre);
	printf("Legajo: %d\n", menorNota.legajo);
	printf("Nota: %.2f\n", menorNota.nota);
	
	
	
	printf("\nPromedio general: %.2f\n",
		   sumaNotas / totalAlumnos);
	
	
	
	printf("Cantidad de alumnos aprobados (>=6): %d\n",
		   aprobados);
	
	
	
	printf("Cantidad de alumnos desaprobados (<6): %d\n",
		   desaprobados);
	
	
	
	printf("Porcentaje aprobados: %.2f%%\n",
		   (float)aprobados * 100 / totalAlumnos);
	
	
	
	if(desaprobados > 0) {
		
		printf("Promedio desaprobados: %.2f\n",
			   sumaDesaprobados / desaprobados);
		
	}
	else {
		
		printf("No hay alumnos desaprobados\n");
		
	}
	
	
	return 0;
}
