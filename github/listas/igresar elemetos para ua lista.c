#include <stdio.h>
#include <stdlib.h>
#define cant  5

// Estructura de un nodo
struct Nodo {
	int dato;
	struct Nodo* siguiente;
};


int main()
{
	
	int j,valor;
	struct Nodo* nuevo= NULL;
	struct Nodo* cabeza;
	nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
	j=0;
	if (nuevo == NULL) 
	            {
					printf("Error al asignar memoria.\n");
					
				}
	    else 
	       {
					printf("Crear primer elemento \n");
					printf("Ingrese un valor\n");
					scanf ("%d",&valor);
					nuevo->dato = valor;
					nuevo->siguiente = NULL;
					cabeza=nuevo;
					printf("%d\n ", cabeza->dato);
					j++;
					printf("Primer valor:\n");
					
					printf("%d\n ", nuevo->dato);
					
				}	
				   nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
				   while (nuevo != NULL && j<cant)
					{
				       printf("Ingrese un valor\n");
				       scanf ("%d",&valor);
			    	   nuevo->dato = valor;
				       nuevo->siguiente = NULL;
					   if (cabeza == NULL)
					   {
						   cabeza = nuevo;
					   }
					   else
					   {
						   struct Nodo* actual = cabeza;
						   while (actual->siguiente != NULL)
						   {
							   actual = actual->siguiente;
						   }
						   actual->siguiente = nuevo;
					   }
					   j++;
				       printf("Valor % d:\n",j);
					   printf("%d\n ", nuevo->dato);
					   nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
				    }
				   printf("Mostrar los elementos de la lista\n");
				   while (cabeza != NULL) {
					   printf("%d -> ", cabeza->dato);
					   cabeza = cabeza->siguiente;
				   }
	                  			
		
				
				return 0;
			}
			
			
		
		
		
		
		
		
		
		
		
	
	
	
	
		
