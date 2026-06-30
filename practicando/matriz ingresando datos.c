#include <stdio.h>

int main() {
	//inicializar
	int matriz[3][4] = {{0,3,4,10},{3,1,-10,10},{10,100,3,1}};
	
	//programa
	printf("ingrese valores para la matriz de 3x4: \n");
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 4; j++){
			printf("elemento [%d,%d]: ", i, j);	
			scanf("%d", &matriz[i][j]);
		}
		printf("\n");
	}
	
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 4; j++){
			printf("%d   ", matriz[i][j]);	
		}
		printf("\n");
	}
	
	return 0;
}

