#include <stdio.h>
#include <stdlib.h>

struct Cliente
{
	int dni;
	char nombre[30];
	char apellido[30];
	float saldo;
	int habilitado; // 1 para habilitado, 0 para inhabilitado
};

void modificarCliente(struct Cliente clientes[], int cantidad, int dni);
struct Cliente buscarCliente(struct Cliente clientes[], int cantidad, int dni);

int main()
{
	struct Cliente clientes[100];
	int cantidad = 0;
	int opcion;
	
	int dni;
	printf("DNI del cliente a modificar: ");
	scanf("%d", &dni);
	modificarCliente(clientes, cantidad, dni);
	
	return 0;
}

// modificar nombre, apellido o saldo de un cliente por DNI
void modificarCliente(struct Cliente clientes[], int cantidad, int dni)
{
	for (int i = 0; i < cantidad; i++)
	{
		if (clientes[i].dni == dni)
		{
			printf("Cliente encontrado: %s %s\n", clientes[i].nombre, clientes[i].apellido);
			printf("Nuevo nombre: ");
			scanf("%s", clientes[i].nombre);
			printf("Nuevo apellido: ");
			scanf("%s", clientes[i].apellido);
			printf("Nuevo saldo: ");
			scanf("%f", &clientes[i].saldo);
			printf("Cliente modificado.\n");
			return;
		}
	}
	printf("Cliente con DNI %d no encontrado.\n", dni);
}
