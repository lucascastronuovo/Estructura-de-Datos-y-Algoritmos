#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int num1;
	int num2;
	struct lista *sig;
 }nodo;

typedef struct lista2{
	int suma;
	struct lista2 *sig2;
 }nodo2;

void crear (nodo *pt);
void mostrar(nodo *pt);
nodo* eliminar1(nodo* );
void insertar2 (nodo* );
void eliminar2(nodo* );
void generar(nodo*,nodo2*);
void mostrar2(nodo2 *pt);

int main()
{
    int i=0;
    nodo *prin;
    nodo2 *p;
    prin=(nodo*)malloc(sizeof(nodo));
    p=(nodo2*)malloc(sizeof(nodo2));
    crear(prin);
    mostrar (prin);
    insertar2(prin);
    mostrar(prin);
    printf("la lista eliminada\n");
    prin=eliminar1(prin);
    eliminar2(prin);
    mostrar(prin);
    generar(prin,p);
    printf("la lista generada\n");
    mostrar2(p);
    return 0;
}

void crear (nodo *registro)
{
     printf("Ingrese numeros");
     scanf("%d",&registro->num1);
     scanf("%d",&registro->num2);

    if (registro->num1==-1&&registro->num2==-1)
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
        printf ("%d",registro->num1);
        printf ("%d",registro->num2);
        printf("\n");
        mostrar (registro->sig);
	}
	return;
}




void insertar2 (nodo *p)
{nodo *aux;
    while(p->sig!=NULL)
    {
        if(p->num1 + p->num2 >10) //condicion de insercion
        {
            aux=(nodo *)malloc(sizeof(nodo));
            aux->num1=p->num1+1;
            aux->num2=p->num2+1;//valor a insertar
            aux->sig=p->sig;
            p->sig=aux;
            p=p->sig->sig;

        }
        else
        p=p->sig;
    }
}

nodo* eliminar1(nodo* p)
{nodo *aux;
    while(p->num1%2==0 && p->num2%2==0)
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
        if(p->sig->num1%2==0 && p->sig->num2%2==0)
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
void generar(nodo* r,nodo2 *s)
{
    while(r->sig!=NULL)
    {
        s->suma=r->num1+r->num2;
        s->sig2=(nodo2*)malloc(sizeof(nodo2));
        s=s->sig2;
        r=r->sig;
    }
    s->sig2=NULL;
}
void mostrar2 (nodo2 *registro)
{
    if (registro->sig2 !=NULL)
	{
        printf ("%d",registro->suma);

        printf("\n");
        mostrar2 (registro->sig2);
	}
}
