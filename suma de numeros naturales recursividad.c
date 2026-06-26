#include <stdio.h>
//hacer de forma recursiva la suma de los primers n numeros naturale
int suma (int n){
	if (n == 0) {
		return 0;
	}
	return n + suma(n - 1);
}
int main() {
	int n;
	printf("Ingrese la cantidad de numeros que quiere sumar: \n");
	scanf("%d", &n);
	
	if (n >= 0){
		printf("suma = %d \n", suma(n));	}
	else{
		printf("Ingrese un numero natural \n");
	}
	return 0;
}

