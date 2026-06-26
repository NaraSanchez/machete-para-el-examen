#include <stdio.h>

double potencia(float a, int b) {
	if (b == 0) {
		return 1;
	}
	return a * potencia(a, b - 1);
}

int main() {
	float A;
	int B;
	
	printf("Ingrese un valor para A: \n");
	scanf("%f", &A);
	
	printf("Ingrese un valor para B: \n");
	scanf("%d", &B);
	
	double resultado;
	
	if (A == 0 && B != 0) {
		resultado = 0;
	}
	else if (B > 0) {
		resultado = potencia(A, B);
	}
	else if (B == 0) {
		resultado = 1;
	}
	else { // B < 0
		resultado = 1.0 / potencia(A, -B);
	}
	
	printf("Resultado: %.2f\n", resultado);
	
	return 0;
}
