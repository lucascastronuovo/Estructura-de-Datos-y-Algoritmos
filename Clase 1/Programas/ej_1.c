#include <stdio.h>

int main() {

int num,cont=0,acum=0,primero,cont1=0,i,contdivi=0,contprimos=0;
	printf("Ingrese un numero entero");
	scanf("%d",&num);
	primero=num;
	while(num!=0){
		if(num%6==0 && num>0){
			cont=cont+1;
			acum=acum+num;
		}
		if(num%primero==0 && num!=primero){
			cont1++;
		}
        for(i=2;i<num;i++){
			if(num%i==0){
				contdivi++;
			}
		}
			if (contdivi==0 && num!=1 && num>0){
			contprimos++;
			//printf("el numero primo es %d",num);
		    }
		contdivi=0;
	    printf("Ingrese un numero entero");
	    scanf("%d",&num);
	}
	if(cont!=0){
		printf("\nel promedio es %d",acum/cont);
	}
	else {
		printf("no se ingresaron valores para calcular el promedio");
	}
	printf("\nla cantidad de multiplos es %d %d",primero,cont1);
	printf("\nla cantidad de numeros primos es %d",contprimos);

    return 0;
}
