#include<stdio.h> //primer error, faltaba el #
#include<conio.h>
#include<string.h>
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
	structregistro reg;//segundo error structregistro reg; debe ser struct registro reg;.
	char seguir;
	if ((arch=fopen(a,"wb"))==NULL)//tercer error Si no se abre el archivo, el programa debe terminar.
		printf("No se pudo abrir el archivo");//cuarto error no hay llaves en el if
	do
	{
		printf("\nIngrese numero de cliente: ");
		scanf("%d",&reg.cliente);
			
		printf("\nIngrese el nombre: ");
		scanf("%s",&reg.nombre);//scanf("%s",&reg.nombre); ? sobra el &
		printf("\nIngrese el saldo: ");
		scanf("%f",&reg.saldo);
		fwrite(&reg,sizeof(reg),1,arch);
		printf("desea terminar s/n: ");
		scanf("\n%c",&seguir);
	}
	while(seguir=='n'); 
	fclose(arch);
	getch();
}//quinto error, falta el return 0
