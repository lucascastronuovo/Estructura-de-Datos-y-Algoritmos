#include <stdio.h>


/*

Con los conocimientos adquiridos hasta el momento se pide desarrollar un programa en C con funciones que permita:



Ingresar números enteros y cargar un vector con los primero 10 números positivos o hasta que se lea un cero.

Si el vector no tiene elementos, mostrar una leyenda, caso contrario mostrarlo y realizar las siguientes operaciones;



a) Insertar el opuesto antes de aquellos números pares menores al promedio.

b) Ordenar el vector de mayor a menor y mostrarlo.



*/

int ingresar_num() {

    int n;

    printf("Ingrese un número: ");
    scanf("%d", &n);


    return n;


}


void cargar_vec(int v[], int dim) {

    int pos = 0, num;

    do {

    num = ingresar_num();

    if (num > 0)    {
        v[pos] = num;
        pos ++;

    }

    if (num == 0)
        v[pos] = "No se ha ingresado ningún valor";

    }

    while (num != 0); {

       num = ingresar_num();

        if (num > 0)    {
            v[pos] = num;
            pos ++;

        } 


    }
}


int main() {

    int vec[10], dim = 10;

    cargar_vec(vec, dim);

    printf(vec);
    
    return 0;
}