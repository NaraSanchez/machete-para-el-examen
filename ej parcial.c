#include <stdio.h>
#include <stdlib.h>

struct Nodo {
	int dato;
	struct Nodo* izquierdo;
	struct Nodo* derecho;
};

struct Nodo* crearNodo(int valor) {
	struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	nuevoNodo->dato = valor;
	nuevoNodo->izquierdo = NULL;
	nuevoNodo->derecho = NULL;
	return nuevoNodo;
}

struct Nodo* insertar(struct Nodo* raiz, int valor) {
	if (raiz == NULL) return crearNodo(valor);
	
	if (valor < raiz->dato) {
		raiz->izquierdo = insertar(raiz->izquierdo, valor);
	} else if (valor > raiz->dato) {
		raiz->derecho = insertar(raiz->derecho, valor);
	}
	return raiz;
}

void inorden(struct Nodo* raiz) {
	if (raiz != NULL) {
		inorden(raiz->izquierdo);
		printf("%d ", raiz->dato);
		inorden(raiz->derecho);
	}
}
void orden(struct Nodo* raiz) {
		if (raiz != NULL){
		orden(raiz->izquierdo);
		orden(raiz->derecho);
		printf("%d ", raiz->dato);
	}
}

struct Nodo* buscar(struct Nodo* raiz, int valor) {
	if (raiz == NULL || raiz->dato == valor) return raiz;
	if (valor < raiz->dato) return buscar(raiz->izquierdo, valor);
	return buscar(raiz->derecho, valor);
}
int main() {
	struct Nodo* raiz = NULL;
	
	// Insertamos elementos
	raiz = insertar(raiz, 2);
	insertar(raiz, 7);
	insertar(raiz, 5);
	insertar(raiz, 2);
	insertar(raiz, 6);
	insertar(raiz, 9);
	insertar(raiz, 5);
	insertar(raiz, 11);
	insertar(raiz, 4);
	
	// Imprimimos el recorrido inorden (debe salir ordenado de menor a mayor)
	printf("Elementos en el arbol (recorrido Inorden): ");
	inorden(raiz);
	printf("\n");
	// Imprimir el recorrido en orden (debe salir ordenado de mayor a menor)
	printf("Elementos en el arbol (recorrido Orden): ");
	inorden(raiz);
	printf("\n");
	printf("Elementos en el arbol: ");
	inorden(raiz);
	printf("\n");
}
/*}viod arbol(struct Nodo* raiz){
	if (raiz != NULL){
		
	}
}*/
