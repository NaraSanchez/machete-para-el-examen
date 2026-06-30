/*una cadena es un ordenamiento de tipo char
al final se agrega un caracter nulo para poder hubicar el final 
de la cadena*/

/*Método de la Burbuja (Bubble Sort)
Es el más famoso para aprender. Se llama así porque los números más grandes “flotan” hacia el final del arreglo como burbujas.

¿Cómo funciona?
Compara parejas de números vecinos. Si el de la izquierda es mayor que el de la derecha, los intercambia. Repite este proceso recorriendo todo el arreglo varias veces hasta que no queden intercambios por hacer.

void ordenarBurbuja(int arr[], int n) {
int i, j, aux;
for (i = 0; i < n - 1; i++) {
for (j = 0; j < n - 1 - i; j++) {
if (arr[j] > arr[j + 1]) {
// Intercambio
aux = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = aux;
}
}
}
}*/

#include <stdio.h>
void imprimir(int A[], int tam);

int main(){
	int A[] = {10,26,5,1,7};
	
	int tam = sizeof(A)/sizeof(A[0]);
	int i,j,tem;
	
	printf("arreglo desordeado: ");
	imprimir(A, tam);
	
	//burbuja 
	for(i = 0; i < tam; i++){
		for(j = 0; j < tam-1; j++){
			if(A[j]>A[j+1]){
				tem = A[j];
				A[j] = A[j+1];
				A[j+1] = tem;
			}
		}
	}
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
