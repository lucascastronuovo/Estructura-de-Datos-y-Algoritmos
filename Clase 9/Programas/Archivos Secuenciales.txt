#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	int legajo;
	char nombre[30];
	float promedio;
	FILE *p;
	p=fopen("alumnos.dat","w");
	if (p==NULL)
		printf("no se puede abrir el archivo");
	else{
		printf("ingrese legajo");
		scanf("%d",&legajo);
		while(legajo!=0){
			printf("ingrese nombre");
			scanf("%s",nombre);
			printf("ingrese promedio");
			scanf("%f",&promedio);
			fprintf(p,"%d   %s  %.3f\n",legajo,nombre,promedio);
			printf("ingrese legajo");
		    scanf("%d",&legajo);
		}
		
	}
	fclose(p);
	p=fopen("alumnos.dat","r");
	if (p==NULL)
		printf("no se puede abrir el archivo");
	else{
		while(!feof(p)){
			fscanf(p,"%d   %s  %f\n",&legajo,nombre,&promedio);
			printf("%d %s %.3f\n",legajo,nombre,promedio);
			
		}
		}
