/*una cadena es un ordenamiento de tipo char
al final se agrega un caracter nulo para poder hubicar el final 
de la cadena*/

/*Método de Selección (Selection Sort)
Este método es muy intuitivo: consiste en buscar el número más pequeño y “seleccionarlo” para ponerlo al principio.

¿Cómo funciona?
Busca el elemento más pequeño de todo el arreglo.
Lo intercambia con el elemento de la primera posición.
Luego busca el segundo más pequeño y lo pone en la segunda posición, y así sucesivamente.
void ordenarSeleccion(int arr[], int n) {
int i, j, min_idx, aux;
for (i = 0; i < n - 1; i++) {
min_idx = i; // Suponemos que el actual es el mínimo
for (j = i + 1; j < n; j++) {
if (arr[j] < arr[min_idx]) {
min_idx = j; // Encontramos uno más chico
}
}
// Intercambiamos el mínimo encontrado con el de la posición actual
aux = arr[min_idx];
arr[min_idx] = arr[i];
arr[i] = aux;
}
}*/
#include <stdio.h>
void imprimir(int A[], int tam);

int main(){
	int A[] = {4,2,3,5,1};
	int tam = sizeof(A)/sizeof(A[0]);
	
	//variables
	int i,j;
	int menor;
	int auxiliar;
	
	printf("arreglo desordeado: ");
	imprimir(A, tam);
	
	//inicio de seleccion
	for(i = 0; i < tam-1; i++){
		menor = i;
		for(j = i; j < tam; j++){
			if(A[j] < A[menor]){
				menor = j;
			}
		}
		auxiliar = A[i];
		A[i] = A[menor];
		A[menor] = auxiliar;
	}
	//fin de seleccion
	printf("arreglo ordeado: ");
	imprimir(A, tam);
	
	return 0;
}
	
	void imprimir(int A[], int tam){
		int i;
		for(i = 0; i < tam; i++){
			printf(" %d", A[i]);
		}
		printf("\n");
	}
