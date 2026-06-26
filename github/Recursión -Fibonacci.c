#include <stdio.h>

// Funci?n recursiva para calcular el en?simo t?rmino de Fibonacci
int fibonacci(int n) {
	// Caso base: los dos primeros n?meros de la secuencia
	if (n == 0) {
		return 0;
	} else if (n == 1) {
		return 1;
	} else {
		// Llamada recursiva
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main() {
	int n, i;
	
	printf("Ingresa el n?mero de t?rminos a mostrar: ");
	scanf("%d", &n);
	
	if (n<0) printf("Error");
	else
	{
		printf("Serie de Fibonacci para los primeros %d t?rminos:\n", n);
		for (i = 0; i < n; i++) 
		{
			printf("%d ", fibonacci(i));
		}
	}
	return 0;
}
