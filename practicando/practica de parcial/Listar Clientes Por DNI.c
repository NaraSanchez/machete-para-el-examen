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

// Prototipos
void listarClientesPorDNI(struct Cliente clientes[], int cantidad);
struct Cliente buscarCliente(struct Cliente clientes[], int cantidad, int dni);
void ordenarClientes(struct Cliente clientes[], int cantidad);

int main()
{
	struct Cliente clientes[100];
	int cantidad = 0;
	int opcion;
	
	listarClientesPorDNI(clientes, cantidad);
	return 0;
}

// listar los clientes ordenados por DNI
void listarClientesPorDNI(struct Cliente clientes[], int cantidad)
{
	ordenarClientes(clientes, cantidad);
	
	printf("Clientes ordenados por DNI:\n");
	for (int i = 0; i < cantidad; i++)
	{
		printf("DNI: %d, Nombre: %s %s, Saldo: %.2f\n", clientes[i].dni, clientes[i].nombre, clientes[i].apellido, clientes[i].saldo);
	}
}

void ordenarClientes(struct Cliente clientes[], int cantidad)
{
	for (int i = 0; i < cantidad - 1; i++)
	{
		for (int j = 0; j < cantidad - i - 1; j++)
		{
			if (clientes[j].dni > clientes[j + 1].dni)
			{
				struct Cliente temp = clientes[j];
				clientes[j] = clientes[j + 1];
				clientes[j + 1] = temp;
			}
		}
	}
}
