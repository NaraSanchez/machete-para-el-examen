#include <stdio.h>
#include <stdlib.h>
//Generar un archivo de texto con cinco nombres separados por punto y mostrarlos uno debajo del otro
int main()
{
	FILE *arch;
	char nombre[30];
	int i;
	char c;
	
	arch = fopen("nombres.txt", "w");
	
	if (arch == NULL)
	{
		printf("Error al crear el archivo");
		return 1;
	}
	
	printf("Ingrese 5 nombres:\n");
	
	for(i = 0; i < 5; i++)
	{
		scanf("%s", nombre);
		fprintf(arch, "%s.", nombre);
	}
	
	fclose(arch);
	
	/* Lectura del archivo */
	arch = fopen("nombres.txt", "r");
	
	if (arch == NULL)
	{
		printf("Error al abrir el archivo");
		return 1;
	}
	
	printf("\nContenido del archivo:\n");
	
	while((c = fgetc(arch)) != EOF)
	{
		if(c == '.')
			printf("\n");
		else
			printf("%c", c);
	}
	
	fclose(arch);
	
	return 0;
}

//Ejemplo: Archivo generado:Juan.Pedro.Ana.Lucia.Carlos.
//Salida:Juan
//	Pedro
//	Ana
//	Lucia
//	Carlos
