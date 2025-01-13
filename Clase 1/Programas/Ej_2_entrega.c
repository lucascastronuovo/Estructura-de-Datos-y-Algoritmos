#include <stdio.h>

/*
2. Ingresar números hasta leer un cero. 
Se pide informar la cantidad de números malvados leídos.


Un Número malvado es todo número natural cuya
expresión en base 2 (binaria) contiene un número 
par de unos. Por ejemplo 12 , y 15 son números
malvados ya que 12=11002 y 15=11112.
*/


int main() {
    int num, cant_1 = 0, cant_0 = 0, cant_num_malvado = 0, i;

    printf("Número: ");
    scanf("%d", &num);

    while (num != 0) {
		
        for (i = num; i >= 2 || i == 1; i /= 2) {
            if (i % 2 == 1)
                cant_1 += 1;
            else
                cant_0 += 1;
        }

        if (cant_1 % 2 == 0)
            cant_num_malvado += 1;

        cant_1 = 0, cant_0 = 0;
		
        printf("Número: ");
        scanf("%d", &num);
        
    }

    printf("La cantdidad de números malvados es: %d", cant_num_malvado);
    
    return 0;
}