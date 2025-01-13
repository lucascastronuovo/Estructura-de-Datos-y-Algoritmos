#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int num_cuenta;
	int saldo_ca;
	int saldo_cc;
	struct lista *sig;
 }nodo;

typedef struct lista_unif{
	int num_cuenta;
	int saldo_unif;
	struct lista_unif *sig;
 }nodo_unif;

void crear (nodo *p);
void mostrar(nodo *p);
void crear_lista_unif(nodo_unif *r, nodo *p);
void mostrar_unif(nodo_unif *r);
nodo* eliminar_neg(nodo* p);
void eliminar_neg2(nodo* p);
void ordenar(nodo *p);
nodo* insertar1 (nodo *p,int ,int ,int );
//void insertar2 (nodo *p,int ,int ,int );

int main()
{
    nodo *p=NULL;
    nodo_unif *r=NULL;
    int num_cuenta,saldo_ca,saldo_cc;

    p=(nodo*)malloc(sizeof(nodo));
    crear(p);
    mostrar(p);
    r=(nodo*)malloc(sizeof(nodo));
    crear_lista_unif(r,p);
    mostrar_unif(r);
    p=eliminar_neg(p);
    eliminar_neg2(p);
    printf("\nLista con negativos eliminados\n");
    mostrar(p);
    ordenar(p);
    printf("\nLista Ordenada\n");
    mostrar(p);
    printf("\nInsertar nuevo registro\n");
    printf("Ingrese numero de cuenta: ");
    scanf("%d",&num_cuenta);
    printf("Ingrese saldo de caja de ahorro: ");
    scanf("%d",&saldo_ca);
    printf("Ingrese saldo de cuenta corriente: ");
    scanf("%d",&saldo_cc);
    p=insertar1(p,num_cuenta,saldo_ca,saldo_cc);
    //insertar2(p,num_cuenta,saldo_ca,saldo_cc);
    printf("\nLista Ordenada con nuevo registro\n");
    mostrar(p);
    getch();
};

void crear (nodo *reg)
{
    printf("Ingrese numero de cuenta: ");
    scanf("%d",&reg->num_cuenta);
    printf("Ingrese saldo de caja de ahorro: ");
    scanf("%d",&reg->saldo_ca);
    printf("Ingrese saldo de cuenta corriente: ");
    scanf("%d",&reg->saldo_cc);
    if(reg->num_cuenta==0)
        reg->sig=NULL;
    else
        {
        reg->sig=(nodo*)malloc(sizeof(nodo));
        crear(reg->sig);
        }
};

void mostrar (nodo *reg)
{
    if (reg->sig !=NULL)
	{
        printf ("Numero de Cuenta:%d\n",reg->num_cuenta);
        printf ("Saldo de Caja de Ahorro:%d\n",reg->saldo_ca);
        printf ("Saldo de Cuenta Corriente:%d\n",reg->saldo_cc);
        printf("-----------------------------\n");
        mostrar (reg->sig);
	}
	return;
};


void crear_lista_unif(nodo_unif *reg_unif,nodo *reg)
{
    if(reg->num_cuenta==0)
        reg_unif->sig=NULL;
    else
        {
        reg_unif->num_cuenta = reg->num_cuenta;
        reg_unif->saldo_unif=reg->saldo_ca+reg->saldo_cc;
        reg_unif->sig=(nodo*)malloc(sizeof(nodo));
        crear_lista_unif(reg_unif->sig,reg->sig);
        }
};

void mostrar_unif(nodo_unif *reg)
{
    if (reg->sig !=NULL)
	{
        printf ("Numero de Cuenta:%d\n",reg->num_cuenta);
        printf ("Saldo Unificado:%d\n",reg->saldo_unif);
        printf("-----------------------------\n");
        mostrar_unif(reg->sig);
	}
	return;
};


nodo* eliminar_neg(nodo* p)
{nodo *aux;
    while(p->saldo_ca<0 || p->saldo_cc<0)
    {
        aux=p->sig;
        free(p);
        p=aux;

    }
    return p;
};

void eliminar_neg2(nodo* p)
{nodo *aux;
    while(p->sig!=NULL && p->sig->sig!=NULL)
    {
        if(p->sig->saldo_ca<0 || p->sig->saldo_cc<0)
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

};

void ordenar(nodo* actual)
{
     nodo *siguiente;
     nodo *aux=(nodo*)malloc(sizeof(nodo));

     while(actual->sig != NULL)
     {
          siguiente = actual->sig;

          while(siguiente->sig !=NULL)
          {
               if(actual->num_cuenta > siguiente->num_cuenta)
               {
                    aux->num_cuenta=siguiente->num_cuenta;
                    aux->saldo_ca=siguiente->saldo_ca;
                    aux->saldo_cc=siguiente->saldo_cc;

                    siguiente->num_cuenta=actual->num_cuenta;
                    siguiente->saldo_ca=actual->saldo_ca;
                    siguiente->saldo_cc=actual->saldo_cc;

                    actual->num_cuenta=aux->num_cuenta;
                    actual->saldo_ca=aux->saldo_ca;
                    actual->saldo_cc=aux->saldo_cc;
               }
               siguiente = siguiente->sig;
          }
          actual = actual->sig;

     }
};


nodo* insertar1(nodo *p,int num_cuenta,int salto_ca, int saldo_cc)
{
    nodo *aux;

    if(num_cuenta < p->num_cuenta)
    {
        aux=(nodo *)malloc(sizeof(nodo));
        aux->num_cuenta=num_cuenta;
        aux->saldo_ca=salto_ca;
        aux->saldo_cc=saldo_cc;
        aux->sig=p;
        p=aux;
    }
    return p;
};
