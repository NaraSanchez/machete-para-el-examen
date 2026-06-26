/*	Errores encontrados
1	Falta # en include<stdio.h>.
2	structregistro reg; debe ser struct registro reg;.
3	Si no se abre el archivo, el programa debe terminar.
4	scanf("%s",&reg.nombre); ? sobra el &.
5	no hay llaves en el if
6	falta return 0;.*/

#include <stdio.h>
#include <conio.h>
#include <string.h>

#define a "c:\\arch.dat"

struct registro
{
	int cliente;
	char nombre[20];
	float saldo;
};

int main()
{
	FILE *arch;
	struct registro reg;
	char seguir;
	
	if ((arch = fopen(a, "wb")) == NULL)
	{
		printf("No se pudo abrir el archivo");
		return 1;
	}
	
	do
	{
		printf("\nIngrese numero de cliente: ");
		scanf("%d", &reg.cliente);
		
		printf("Ingrese el nombre: ");
		scanf("%s", reg.nombre);
		
		printf("Ingrese el saldo: ");
		scanf("%f", &reg.saldo);
		
		fwrite(&reg, sizeof(reg), 1, arch);
		
		printf("Desea terminar s/n: ");
		scanf(" %c", &seguir);
		
	} while (seguir == 'n' || seguir == 'N');
	
	fclose(arch);
	
	getch();
	return 0;
}

//¿Qué hace este programa?
//	Crea un archivo binario llamado arch.dat.
//	Guarda registros con:
//	Número de cliente.
//	Nombre.
//	Saldo.
//	Continúa cargando datos mientras el usuario responda n.
//	Cada registro se guarda mediante fwrite().
