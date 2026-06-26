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

void preorden(struct Nodo* raiz) {
	if (raiz != NULL) {
		printf("%d ", raiz->dato);
		preorden(raiz->izquierdo);
		preorden(raiz->derecho);
	}
}

void postorden(struct Nodo* raiz) {
	if (raiz != NULL) {
		postorden(raiz->izquierdo);
		postorden(raiz->derecho);
		printf("%d ", raiz->dato);
	}
}

struct Nodo* buscar(struct Nodo* raiz, int valor) {
	if (raiz == NULL || raiz->dato == valor) return raiz;
	if (valor < raiz->dato) return buscar(raiz->izquierdo, valor);
	return buscar(raiz->derecho, valor);
}
int main() {
	int busnum;
	int opcion;
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
	
	//menu
	printf("Seleccione una opcion:\n");
	printf("1. Buscar un numero ingresado por teclado\n");
	printf("2. Mostrar los elementos Inorden\n");
	printf("3. Mostrar los elementos Preorden\n");
	printf("4. Mostrar los elementos Postorden\n");
	
	scanf("%d", &opcion);
	
	switch (opcion) {
		
	case 1: {
		int busnum;
		
		printf("¿Que numero quiere buscar?: ");
		scanf("%d", &busnum);
		
		struct Nodo* encontrado = buscar(raiz, busnum);
		
		if (encontrado != NULL) {
			printf("El numero %d fue encontrado en el arbol \n", busnum);
		} else {
			printf("El numero %d no existe en el arbol \n", busnum);
		}
		
		break;
	}
	
	case 2:
		printf("Elementos en el arbol (Inorden): ");
		inorden(raiz);
		printf("\n");
		break;
		
	case 3:
		printf("Elementos en el arbol (Preorden): ");
		preorden(raiz);
		printf("\n");
		break;
		
	case 4:
		printf("Elementos en el arbol (Postorden): ");
		postorden(raiz);
		printf("\n");
		break;
		
	default:
		printf("Opcion no valida \n");
	}
	
	return 0;
}

