#include <stdio.h>
#include <stdlib.h>
//Prototipos
void cargar(int []);
void mostrar(int [], int);
int eliminar(int []);
void mostrar(int [], int);
void promedio(int [], int);

//Programa Principal
int main(){
    //Declaracion de variables
    int vec[15], dim = 12;

    cargar(vec);
    mostrar(vec, dim);
    dim = eliminar(vec);
    mostrar(vec, dim);
    ordenar(vec, dim);
    mostrar(vec, dim);
    if (dim != 0){
    promedio(vec, dim);
    mostrar(vec, dim + 1);
    } else {
        printf("No se puede calcular el promedio.\n");
    }
}

//Funciones
void cargar(int vec[]){
    int num, contPar = 0, contImp = 6;

    while(contPar < 6 || contImp < 12){
        printf("Ingrese un numero: ");
        scanf("%d", &num);
        if(num%2 == 0 && contPar < 6){
            vec[contPar] = num;
            contPar++;
        } else if(num%2 != 0 && contImp < 12) {
            vec[contImp] = num;
            contImp++;
        }
        //Contador de prueba
        //printf("%d %d\n", contPar, contImp);
    }
}

void mostrar(int vec[], int dim){
    int i;

    for(i = 0; i < dim; i++){
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int eliminar(int vec[]){
    int dim = 12, i = 0;
    //Metodo FOR
    /*
    for(i = 0; i < dim; i++){
        if(vec[i]%7 == 0){
            desplazar(vec, i, dim);
            dim--;
            i--;
        }
    }
    */
    //Metodo WHILE
    while(i < dim){
        if(vec[i]%7 == 0){
            desplazar(vec, i, dim);
            dim--;
        } else {
            i++;
        }
    }
    return dim;
}

void desplazar(int vec[], int i, int dim){
    int j;

    for(j = i; j < dim; j++){
        vec[j] = vec[j + 1];
    }
}

void promedio(int vec[], int dim){
    int i, acum = 0, prom;

    for(i = 0; i < dim; i++){
        acum += vec[i];
    }
    prom = acum / dim;
    vec[dim] = prom;
}

void ordenar(int vec[], int dim){
    int i, j, aux;

    for(i = 0; i < dim; i++){
        for(j = i + 1; j < dim; j++){
            //Menor a mayor
            if(vec[i] > vec[j]){
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
}
