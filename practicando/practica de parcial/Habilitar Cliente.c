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

void habilitarCliente(struct Cliente clientes[], int cantidad, int dni);
struct Cliente buscarCliente(struct Cliente clientes[], int cantidad, int dni);

int main()
{
	struct Cliente clientes[100];
	int cantidad = 0;
	int opcion;
	
	int dni;
	printf("DNI del cliente a habilitar: ");
	scanf("%d", &dni);
	habilitarCliente(clientes, cantidad, dni);
	
	return 0;
}

// habilitar un cliente por DNI
void habilitarCliente(struct Cliente clientes[], int cantidad, int dni)
{
	for (int i = 0; i < cantidad; i++)
	{
		if (clientes[i].dni == dni)
		{
			clientes[i].habilitado = 1;
			printf("Cliente con DNI %d habilitado.\n", dni);
			return;
		}
	}
	printf("Cliente con DNI %d no encontrado.\n", dni);
}
