#include <stdio.h>
/*2) Inicializar un arreglo de 10 elementos y con un ciclo for verificar 
cual de los elementos es mayor*/
int main() {
	//inicializar
	int arreglo[10] = {10,1,2,-3,-100,1000,-200,7,1,0};
	int mayor = 0;
	//programa 
	for (int i = 0; i < 10; i++){
		if(arreglo[i] > arreglo[mayor]){
			mayor = i;
		}
	}
	printf("El elemento de mayor valor es: %d", arreglo[mayor]);
	printf("\nSu posicion es: %d", mayor);
	return 0;
}

/*tipo nombre_arreglo[ tamaño] = {lista-valores};
Ejemplo:
	int x[7] = {3,5,7,-2,0,1,4};*/
