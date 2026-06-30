#include <stdio.h>

int main() {
	//inicializar
	int matriz[3][4] = {{0,3,4,10},{3,1,-10,10},{10,100,3,1}};
	
	//programa
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 4; j++){
			printf("%d   ", matriz[i][j]);	
		}
		printf("\n");
	}

	return 0;
}

