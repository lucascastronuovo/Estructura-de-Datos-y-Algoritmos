#include <stdio.h>
#include <stdlib.h>


typedef struct lista{
	int num1;
	int num2;
	int num3;
	struct lista *sig;
 }nodo;

typedef struct lista1{
	int num;
	struct lista *sig;
 }nodo1;


void crear (nodo *pt);
nodo* insertar1(nodo* );
nodo* eliminar1(nodo* );
void insertar2 (nodo* );
void eliminar2(nodo* );


int main()
{
    nodo *prin;
    nodo1 *p;

    prin=(nodo*)malloc(sizeof(nodo));
    p=(nodo1*)malloc(sizeof(nodo1));
    crear(prin);
    mostrar(prin);
    generar(prin,p);
    printf("la lista nueva es");
    mostrar1(p);

    insertar2(prin);
    prin=insertar1(prin);
    printf("la lista nueva es");

    mostrar(prin);
    prin=eliminar1(prin);
    eliminar2(prin);
    printf("la lista nueva es");
    mostrar(prin);

    return 0;
}

void crear (nodo *r)
{

    printf("Ingrese un numero");
    scanf("%d",&r->num1);

    if (r->num1==0)
        r->sig=NULL;
    else
	{
    printf("Ingrese un numero");
    scanf("%d",&r->num2);
    printf("Ingrese un numero");
    scanf("%d",&r->num3);
    r->sig=(nodo*)malloc(sizeof(nodo));
    crear (r->sig);

	}
	return;
}

void mostrar (nodo *registro)
{
    if (registro->sig !=NULL)
	{
        printf ("%d\n",registro->num1);
        printf ("%d\n",registro->num2);
        printf ("%d\n",registro->num3);
        mostrar (registro->sig);
	}
	return;
}
void generar(nodo *h, nodo1 *f)
{
  while(h->sig!=NULL)
  {
      if(h->num1+h->num2+h->num3 > 10)
      {
          f->num=h->num1+h->num2+h->num3;
          f->sig=(nodo1*)malloc(sizeof(nodo1));
          f=f->sig;
      }
      h=h->sig;
  }
  f->sig=NULL;
}

void mostrar1 (nodo1 *registro)
{
    if (registro->sig !=NULL)
	{
        printf ("%d\n",registro->num);

        mostrar1 (registro->sig);
	}
	return;
}
nodo* insertar1(nodo *p)
{
    nodo *aux;

        aux=(nodo *)malloc(sizeof(nodo));
        aux->num1=(p->num1/2);
        aux->num2=(p->num2/2);
        aux->num3=(p->num3/2);
        aux->sig=p;
        p=aux;

    return p;
}

void insertar2 (nodo *p)
{nodo *aux;
    while(p->sig!=NULL && p->sig->sig!=NULL)
    {

            aux=(nodo *)malloc(sizeof(nodo));
            aux->num1=(p->sig->num1/2);
            aux->num2=(p->sig->num2/2);
            aux->num3=(p->sig->num3/2);
            aux->sig=p->sig;
            p->sig=aux;


        p=p->sig->sig;
    }
}
nodo* eliminar1(nodo* p)
{nodo *aux;
    while(p->num1*p->num2*p->num3 < 30)
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
        if(p->sig->num1*p->sig->num2*p->sig->num3 < 30)
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


