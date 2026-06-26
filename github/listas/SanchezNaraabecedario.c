#include <stdio.h>
#include <stdlib.h>

struct NodoSimple {
    char dato;
    struct NodoSimple* siguiente;
};

void agregarAlFinal(struct NodoSimple** cabeza, char valor) {

    struct NodoSimple* nuevo = (struct NodoSimple*) malloc(sizeof(struct NodoSimple));
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (*cabeza == NULL) {
        *cabeza = nuevo;
    } else {
        struct NodoSimple* actual = *cabeza;
        while (actual -> siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}

void eliminarMultiplosDeTres(struct NodoSimple** cabeza) {
    if (*cabeza == NULL) return; 

    struct NodoSimple* actual = *cabeza;
    struct NodoSimple* anterior = NULL;
    int posicion = 1; 

    while (actual != NULL) {
        if (posicion % 3 == 0) {
            struct NodoSimple* aBorrar = actual;
            
            anterior->siguiente = actual->siguiente; 
            actual = actual->siguiente; 
            
            free(aBorrar); 
        } else {
            anterior = actual;
            actual = actual->siguiente;
        }
        posicion++;
    }
}

void imprimirLista(struct NodoSimple* cabeza) {
    while (cabeza != NULL) {
        printf("%c -> ", cabeza->dato);
        cabeza = cabeza->siguiente;
    }
    printf("NULL\n");
}

void liberarLista(struct NodoSimple* cabeza) {
    struct NodoSimple* temp;
    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
}

int main() {
    struct NodoSimple* listaAbecedario = NULL;

    for (char letra = 'A'; letra <= 'Z'; letra++) {
        agregarAlFinal(&listaAbecedario, letra);
    }

    printf("Lista Original (Abecedario):\n");
    imprimirLista(listaAbecedario);

    eliminarMultiplosDeTres(&listaAbecedario);

    printf("\nLista Resultante (Sin multiplos de 3):\n");
    imprimirLista(listaAbecedario);

    liberarLista(listaAbecedario);

    return 0;
}
