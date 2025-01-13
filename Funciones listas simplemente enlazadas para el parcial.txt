#include <stdio.h>
#include <stdlib.h>


typedef struct lista{
	int num;
	struct lista *sig;
 }nodo;






void crear (nodo *registro)
{

    scanf("%d",&registro->num);

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

nodo* insertar1(nodo *p)
{
    nodo *aux;
    if()//condicion de insercion
    {
        aux=(nodo *)malloc(sizeof(nodo));
        aux->num=0;//valor a insertar
        aux->sig=p;
        p=aux;
    }
    return p;
}

void insertar2 (nodo *p)
{nodo *aux;
    while(p->sig!=NULL)
    {
        if() //condicion de insercion
        {
            aux=(nodo *)malloc(sizeof(nodo));
            aux->num=0;//valor a insertar
            aux->sig=p->sig;
            p->sig=aux;

        }
        p=p->sig;
    }
}

nodo* eliminar1(nodo* p)
{nodo *aux;
    while()//condicion de eliminacion
    {
        aux=p->sig;
        free(p);
        p=aux;

    }
    return p;
}
void eliminar2(nodo* p)
{nodo *aux;
    while(p->sig!=NULL&& p->sig->sig!=NULL)
    {
        if()//condicion de eliminacion
        {
            aux=p->sig->sig;
            free(p->sig);
            p->sig=aux;
        }
        else
        {
            p=p->sig;
        }
    }

}
int main()
{

    nodo *prin=NULL;
    prin=(nodo*)malloc(sizeof(nodo));
    crear(prin);
    mostrar (prin);
    prin=insertar1(prin);
    insertar2(prin);
    prin=eliminar1(prin);
    eliminar2(prin);
    mostrar(prin);

    return 0;
}