#include <stdio.h>
#include <stdlib.h>
typedef struct listasR
{
    char nomplaylist[40];
    struct listaC *cab;
    struct listasR *sig;
}nodoR;

typedef struct listaC
{
    char nomcancion[40];
    char artista[40];
    struct listaC *sigC;
}nodoC;

//Declaracion de funciones

void mostrarlista(nodoR *);
void cargarPlayList(nodoR *);

int main()
{
    nodoR *p=NULL;
    p=(nodoR*)malloc(sizeof(nodoR));
    cargarPlayList(p);
    mostrarlista(p);
}

void mostrarlista(nodoR *p)
{
    if (p->sig!=NULL)
    {
        printf("\n\nPlay list %s \n",p->nomplaylist);
        mostrarcanciones(p->cab);
        mostrarlista(p->sig);
    }
}

void mostrarcanciones(nodoC *r)
{
    if (r->sigC!=NULL)
    {
        printf("Tema: %s\n",r->nomcancion);
        printf("Artista: %s \n",r->artista);
        mostrarcanciones(r->sigC);

    }
}


void cargarPlayList(nodoR *p)
{
    printf("\nIngrese nombre de la Nueva Play List - x para terminar: ");
    scanf("%s",p->nomplaylist);
    if (strcmpi(p->nomplaylist,"x")==0)

         {
            p->sig=NULL;
            return;
         }
    else
    {
        p->cab=(nodoC*)malloc(sizeof(nodoC));
        crearcanciones(p->cab);
        p->sig=(nodoR*)malloc(sizeof(nodoR));
        cargarPlayList(p->sig);


     }

}

void crearcanciones(nodoC *r)
{
    printf("\nIngrese nombre de la cancion - x para terminar: ");
    scanf("%s",r->nomcancion);
    if (strcmpi(r->nomcancion,"x")==0)
           {
               r->sigC=NULL;
               return;
           }
    else
    {
        printf("\nIngrese nombre del arista: ");
        scanf("%s",r->artista);
        r->sigC=(nodoC*)malloc(sizeof(nodoC));
        crearcanciones(r->sigC);
     }

}
