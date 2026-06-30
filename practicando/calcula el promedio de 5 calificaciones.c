#include <stdio.h>
/*un arreglo es una coleccion de elementos
todos los elementos son del mismo tipo
tienen un tamaño definido que no cambia despues de haber sido establecido
para acceder a cada elemento del arreglo se utiliza sub indice*/

/*1)Realizar un programa que pida 5 calificaciones por teclado y calcule 
el promedio de ellas*/
int main() {
	//inicializacion
	float calificaciones[5];
	float promedio = 0;
	//pantalla
	printf("PROGRAMA QUE CALCULA EL PROMEDIO DE 5 ESTUDIANTES  \n");
	//programa
	for (int i = 0; i < 5; i++){
		printf("Inserte calificacion %d: ", i + 1);
		scanf("%f", &calificaciones[i]);
		promedio = promedio + calificaciones[i];
	}
	printf("El promedio de las ccalificaciones es: %2.f", promedio/5);
	return 0;
}
