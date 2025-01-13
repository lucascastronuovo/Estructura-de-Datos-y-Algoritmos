#include <stdio.h>

/*
Desarrollar un programa en C que permita leer un texto carácter a carácter terminado en punto. Por fin de proceso

a) Mostrar el texto con tres blancos de
separación después de cada palabra que finaliza
en s y tiene al menos 2 vocales.

b) Contar cuantas palabras de
mas de 4 caracteres empiezan y terminan
con la misma letra.

*/

int main() {
    int c, i, cont_vocal = 0, c_ant, prim_c, ult_c, cont_c = 0, cont_palabras = 0;

	c = getchar();

while (c != '.'){
	
	prim_c = c;
	
	while (c != '.' && c != ' ') {

		if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U' )
			cont_vocal++;
		
		putchar(c);
		c_ant = c;
		cont_c++;
		c = getchar();

		
	}
	
	ult_c = c_ant;

	if (cont_c > 4 && prim_c == ult_c) {
		cont_palabras++;
		cont_c = 0;

	}
		
	if (c_ant == 's' && cont_vocal >= 2) {
		for (i = 0; i < 3; i++)
			putchar(' ');

	
	}

	else
		putchar(c);

	cont_vocal = 0;

	while (c != '.' && c == ' ')
		c = getchar();

}

	printf("\n La cantidad de palabras: %d", cont_palabras);
	
	return 0;
}
   