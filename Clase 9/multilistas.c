#include <stdio.h>
#include <stdlib.h>

typedef struct barrio {
	char nombarrio[30];
	struct inmuebles *bainm;
	struct barrio *sigbar;
} nodo;

typedef struct inmuebles {
	char dir[40];
	int sup;
	int cantamb;
	float precio;
	struct inmuebles *siginm;
} nodosec;

void ingresarbarrios(nodo *registro);
void ingresarinmuebles(nodosec *registro);
void mostrarbarrios(nodo *registro);
void mostrarinmuebles(nodosec *registro);
nodo *buscarbarrio(nodo *registro, char barrio[30]);
void ingresarinmueble(nodo *registro);
void eliminarinmueble(nodo *registro);

int main()
{
char barrio[30];
nodo *prim;
nodo *encontrado;
prim=(nodo *)malloc(sizeof(nodo));
ingresarbarrios(prim);
printf("Muestro los barrios: \n");
mostrarbarrios(prim);
printf("Ingrese el barrio donde desea agregar un inmueble: \n");
scanf("%s", barrio);
encontrado=buscarbarrio(prim, barrio);
if (encontrado != 0)
	{
	ingresarinmueble(encontrado);
	}

printf("Asi quedo ingresado: \n");
mostrarbarrios(prim);
printf("Ingrese el barrio donde desea se elimine un inmueble: \n");
scanf("%s", barrio);
encontrado=buscarbarrio(prim, barrio);
if (encontrado != 0)
	{
	eliminarinmueble(encontrado);
	}
printf("Asi quedo despues de borrar: \n");
mostrarbarrios(prim);


getch();
}

void ingresarbarrios(nodo *registro)
{
	char nombarrio[30];
	printf("Ingrese el nombre del barrio (X para finalizar): \n");
	scanf("%s", nombarrio);
	if (strcmpi(nombarrio, "X") == 0)
		{
		registro->sigbar=NULL;
		return;
		}
	else
		{
		strcpy(registro->nombarrio, nombarrio);
		registro->bainm=(nodosec *)malloc(sizeof(nodosec));

		ingresarinmuebles(registro->bainm);
		registro->sigbar=(nodo *)malloc(sizeof(nodo));
		ingresarbarrios(registro->sigbar);
		}
}


void ingresarinmuebles(nodosec *registro)
{
	char dir[40];
	int sup;
	int cantamb;
	float precio;
	nodosec *nuevo;

	printf("Ingrese la direccion del inmueble (X para finalizar):\n");
	scanf("%s", dir);
	if (strcmpi(dir, "X") == 0)
		{
		 registro->siginm=NULL;
		 return;
		}
	else
		{
		printf("Ingrese la superficie: \n");
		scanf("%d", &sup);
		printf("Ingrese la cantidad de ambientes: \n");
		scanf("%d", &cantamb);
		printf("Ingrese el precio: \n");
		scanf("%f", &precio);
		strcpy(registro->dir, dir);
		registro->sup=sup;
		registro->cantamb=cantamb;
		registro->precio=precio;
		registro->siginm=(nodosec *)malloc(sizeof(nodosec));
       
		ingresarinmuebles(registro->siginm);
		}
}

void mostrarbarrios(nodo *registro)
{
if (registro->sigbar != NULL)
	{
	printf("--------------------------------------------------------------\n");
	printf("Barrio : %s \n", registro->nombarrio);
	mostrarinmuebles(registro->bainm);
	mostrarbarrios(registro->sigbar);
	}
}


void mostrarinmuebles(nodosec *registro)
{


if (registro->siginm != NULL)

	{
	printf("\t- Direccion : %s  Superficie: %d Cantidad de Ambientes: %d Precion: %f \n",
		registro->dir, registro->sup, registro->cantamb, registro->precio);

	mostrarinmuebles(registro->siginm);
	}

return;
}

nodo *buscarbarrio(nodo *registro, char barrio[30])
	{
	// si el registro sigbar es NULL no encontro el barrio
	if (registro->sigbar == NULL)
		{
		printf("No se encontro el barrio \n");
		return 0;
		}
	else
		{
		if (strcmp(registro->nombarrio, barrio) == 0)
			{
			return registro;
			}
		else
			{
			return (buscarbarrio(registro->sigbar, barrio));
			}
		}
	}

void ingresarinmueble(nodo *registro)
	{
	// Busco el inmueble el primer inmueble que tenga menos de 4 ambientes
	nodosec *sig;
	nodosec *nuevo;
	char dir[40];
	int sup;
	int cantamb;
	float precio;

	sig=registro->bainm;
	while (sig->cantamb > 4 && sig->siginm != NULL)
		{
		sig=sig->siginm;
		}

	// Me quede en el primero
	nuevo=(nodosec *)malloc(sizeof(nodosec));
	printf("Ingrese la direccion del inmueble (X para finalizar):\n");
	scanf("%s", dir);
	printf("Ingrese la superficie: \n");
	scanf("%d", &sup);
	printf("Ingrese la cantidad de ambientes: \n");
	scanf("%d", &cantamb);
	printf("Ingrese el precio: \n");
	scanf("%f", &precio);
	strcpy(nuevo->dir, dir);
	nuevo->sup=sup;
	nuevo->cantamb=cantamb;
	nuevo->precio=precio;
	nuevo->siginm=sig->siginm;
	sig->siginm=nuevo;

	return;
	}

void eliminarinmueble(nodo *registro)
	{
	// Busco el inmueble el primer inmueble que tenga menos de 4 ambientes
	nodosec *sig;
	nodosec *anterior;
	float precio;

	sig=registro->bainm;
	precio=sig->precio;
	anterior=sig;

	while (precio > 50000 && sig->siginm != NULL)
		{
		anterior=sig;
		sig=sig->siginm;
		precio=sig->precio;
		}

	if (sig->siginm == NULL) // vuelvo a preguntar por si quedo en el ultimo
		{
		if (sig->precio < 50000)
			{
			anterior->siginm=NULL;
			free(sig);
			}
		}
	else
		{

		if (sig == registro->bainm) // es el primero
			{
			registro->bainm=sig->siginm;
			}
		else
			{
			anterior->siginm=sig->siginm;
			}
		free(sig);
		}

	return;
	}
