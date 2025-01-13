#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int num;
	struct lista *sig;
 }nodo;


void crear (nodo *pt);
void mostrar(nodo *pt);



int main()
{
    int i=0;
    nodo *prin;
    prin=(nodo*)malloc(sizeof(nodo));
    crear(prin);
    mostrar (prin);

    return 0;
}

void crear (nodo *registro)
{
    printf("Ingrese numero");
    scanf("%d",&registro->num)

    if (registro->num==0)
        registro->sig=NULL;
    else
	{

        registro->sig=(nodo*)malloc(sizeof(nodo));
        crear (registro->sig);

	}
	return;
}

void mostrar (nodo *registro)
{
    if (registro->sig !=NULL)
	{
        printf ("%d\n",registro->num);
        mostrar (registro->sig);
	}
	return;
}

