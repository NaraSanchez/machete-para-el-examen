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
void ordenarClientes(struct Cliente clientes[], int cantidad);
struct Cliente buscarCliente(struct Cliente clientes[], int cantidad, int dni);
void ordenarClientes(struct Cliente clientes[], int cantidad);

int main()
{
	struct Cliente clientes[100];
	int cantidad = 0;
	int opcion;
}

// buscar clientes con el metodo de Busqueda Binaria (Binary Search)
struct Cliente buscarCliente(struct Cliente clientes[], int cantidad, int dni)
{
	ordenarClientes(clientes, cantidad);
	
	int inicio = 0;
	int fin = cantidad - 1;
	
	while (inicio <= fin)
	{
		int medio = inicio + (fin - inicio) / 2;
		
		if (clientes[medio].dni == dni)
		{
			return clientes[medio];
		}
		else if (clientes[medio].dni < dni)
		{
			inicio = medio + 1;
		}
		else
		{
			fin = medio - 1;
		}
	}
	
	struct Cliente clienteNoEncontrado = {-1, "", "", 0.0, 0};
	return clienteNoEncontrado;
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
