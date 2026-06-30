/*una cadena es un ordenamiento de tipo char
al final se agrega un caracter nulo para poder hubicar el final 
de la cadena*/

/*Método de Inserción (Insertion Sort)
Es la forma en la que la mayoría de las personas ordenan una mano de cartas.

¿Cómo funciona?
Vas tomando un elemento a la vez y lo “insertás” en su posición correcta comparándolo con los que ya tenés a su izquierda (que ya están ordenados).

void ordenarInsercion(int arr[], int n) {
int i, j, actual;
for (i = 1; i < n; i++) {
actual = arr[i];
j = i - 1;

// Desplazamos los elementos que son mayores que el actual
while (j >= 0 && arr[j] > actual) {
arr[j + 1] = arr[j];
j = j - 1;
}
arr[j + 1] = actual; // Insertamos el elemento en su lugar
}
}
Resumen: ¿Cuál usar?
Burbuja: Muy fácil de entender, pero el más lento de todos.
Selección: Realiza menos intercambios de datos que la burbuja, lo que lo hace un poquito más eficiente en ciertos casos.
Inserción: Es muy rápido si el arreglo ya está “casi” ordenado.
¡Dominar estos métodos te da el control total sobre cómo organizar la información en tus programas!*/
#include <stdio.h>

void insercion(int[], int);

int main() {
	//variables
	int i;
	int tam;
	
	//proceso
	int A[] = {6,3,87,2,7,9,3,10};
	tam = sizeof(A)/sizeof(A[0]);
	
	printf("el arreglo desordenado: ");
	
	for(i = 0; i < tam; i++){
		printf(" %d", A[i]);
	}
	
	insercion(A, tam);
	printf("\n");
	printf("el arreglo ordenado: ");
	
	for(i = 0; i < tam; i++){
		printf(" %d", A[i]);
	}
}

void insercion(int A [], int tam){
	int i,j,num;
	for(i = 1; i < tam; i++){
		num = A[i];
		j = i-1;
		while(j >= 0 && A[j] > num){
			A[j+1]  = A[j];
			j--;
		}
		A[j+1] = num;
	}
}
