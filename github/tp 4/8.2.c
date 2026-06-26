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
	
	// Buscamos un elemento
	int busnum;
	printf("que nuemro quiere buscar: \n");
	scanf("%d", &busnum);
	int numeroABuscar = busnum;
	struct Nodo* encontrado = buscar(raiz, numeroABuscar);
	if (encontrado != NULL) {
		printf("El numero %d fue encontrado en el arbol.\n", numeroABuscar);
	} else {
		printf("El numero %d no existe en el arbol.\n", numeroABuscar);
	}
}
