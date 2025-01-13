#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c;
    printf("Ingrese la frase\n");
    c=getchar();
    while(c!='\n')
    {
       if (c=='m')
       {
         c=getchar();
           if(c=='p')
           {
               putchar('*');
               putchar('*');

           }
           else
           {
               putchar('m');
               putchar(c);
           }

       }
       else
       {
           putchar(c);
       }
        if (c!='\n')
            c=getchar();
    }
    return 0;
}
