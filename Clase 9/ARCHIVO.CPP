#include<stdio.h>
#include<stdlib.h>

int main ()
{
int legajo;
char nom[15];
float sueldo;
FILE *cfptr;
if ((cfptr=fopen("e:\clientes.dat","w"))==NULL)
	printf("\n No se puede Abrir!!");
	else
	{
	printf("Ingrese Legajo (0 para terminar):");
	scanf("%d",&legajo);
	while(legajo != 0)
	{
		printf("Ingrese Nombre: \n");
		scanf("%s",nom);
		printf("Ingrese Sueldo: \n");
		scanf("%f",&sueldo);
		fprintf(cfptr,"%d  %s  %.2f\n",legajo,nom,sueldo);
		printf("Ingrese Legajo (ingrese 0 para Terminar):");
		scanf("%d",&legajo);

	}
        }
fclose(cfptr);
printf("\nLos Datos Ingresados son: \n\n");
if ((cfptr=fopen("e:\clientes.dat","r"))==NULL)
	printf("\n No Se puede Abrir!!!.");
	else
	{
	while(!feof(cfptr))
	{
	     fscanf(cfptr,"%d  %s  %f\n",&legajo, nom, &sueldo);
	     printf("Legajo: %d   Nombre: %s   Sueldo: %.2f\n",legajo,nom,sueldo);
	} 
	}
fclose(cfptr);
}

