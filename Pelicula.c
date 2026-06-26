#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pelicula
	{
	char nombre [100];
	int anio;
	struct Pelicula *siguiente;
};

void insertarAlInicio(struct Pelicula **cabeza, const char *nombre, int anio)
{
	struct Pelicula *nuevoNodo = (struct Pelicula *)malloc(sizeof(struct Pelicula));
	strcpy(nuevoNodo->nombre, nombre);
	nuevoNodo->anio = anio;
	nuevoNodo->siguiente = *cabeza;
	*cabeza = nuevoNodo;
}
void insertarAlFinal(struct Pelicula **cabeza, const char *nombre, const int anio)
{
	struct Pelicula *nuevoNodo = (struct Pelicula *)malloc(sizeof(struct Pelicula));
	strcpy(nuevoNodo->nombre, nombre);
	nuevoNodo->anio = anio;
	nuevoNodo->siguiente = NULL;
	
	if (*cabeza == NULL)
	{
		*cabeza = nuevoNodo;
		return;
	}
	
	struct Pelicula *temp = *cabeza;
	while (temp->siguiente != NULL)
	{
		temp = temp->siguiente;
	}
	temp->siguiente = nuevoNodo;
}

void eliminarPelicula(struct Pelicula **cabeza)
{
	struct Pelicula *temp = *cabeza;
	struct Pelicula *anterior = NULL;
	
	if (temp == NULL)
		return;
	
	if (anterior == NULL)
	{
		*cabeza = temp->siguiente;
	}
	else
	{
		anterior->siguiente = temp->siguiente;
	}
	
	free(temp);
}
void mostrarLista(struct Pelicula *nodo)
{
	while (nodo != NULL)
	{
		printf("%s (año: %d) -> ", nodo->nombre, nodo->anio);
		nodo = nodo->siguiente;
	}
	printf("NULL\n");
}
void buscarNodo(struct Pelicula *cabeza, const char *nombre)
{
	struct Pelicula *temp = cabeza;
	
	while (temp != NULL)
	{
		if (strcmp(temp->nombre, nombre) == 0)
		{
			printf("Pelicula encontrada: %s (%d)\n",
				   temp->nombre,
				   temp->anio);
			return;
		}
		
		temp = temp->siguiente;
	}
	
	printf("Pelicula no encontrada: %s\n", nombre);
}

int main()
{
	struct Pelicula *lista = NULL;
	int opcion;
	char nombre[100];
	int anio;
	
	do
	{
		printf("\n==================== MENU ====================\n");
		printf("1. Agregar pelicula al inicio\n");
		printf("2. Agregar pelicula al final\n");
		printf("3. Buscar pelicula\n");
		printf("4. Mostrar lista\n");
		printf("5. Salir\n");
		printf("Seleccione una opcion: ");
		scanf("%d", &opcion);
		getchar(); // consume el salto de línea
		
		switch(opcion)
		{
		case 1:
			printf("Nombre de la pelicula: ");
			fgets(nombre, sizeof(nombre), stdin);
			nombre[strcspn(nombre, "\n")] = '\0';
			
			printf("Anio: ");
			scanf("%d", &anio);
			getchar();
			
			insertarAlInicio(&lista, nombre, anio);
			printf("Pelicula agregada al inicio.\n");
			break;
			
		case 2:
			printf("Nombre de la pelicula: ");
			fgets(nombre, sizeof(nombre), stdin);
			nombre[strcspn(nombre, "\n")] = '\0';
			
			printf("Anio: ");
			scanf("%d", &anio);
			getchar();
			
			insertarAlFinal(&lista, nombre, anio);
			printf("Pelicula agregada al final.\n");
			break;
			
		case 3:
			printf("Ingrese el nombre de la pelicula a buscar: ");
			fgets(nombre, sizeof(nombre), stdin);
			nombre[strcspn(nombre, "\n")] = '\0';
			
			buscarNodo(lista, nombre);
			break;
			
		case 4:
			printf("\nLista de peliculas:\n");
			mostrarLista(lista);
			break;
			
		case 5:
			printf("Saliendo del programa...\n");
			break;
			
		default:
			printf("Opcion invalida.\n");
		}
		
	} while(opcion != 5);
	
	return 0;
}
