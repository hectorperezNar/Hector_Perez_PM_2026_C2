#include <stdio.h>
#include <math.h>

/* Par, impar o nulo.
NUM: Variable de tipo entero. */

int Principal(void)
{
    int NUM;
    printf("Ingrese el numero:");
    scanf("%d", &NUM);
    if (NUM == 0)
         printf("n\nulo");
    else
            if(pow (-1, NUM) > 0)
                printf("\nPar");
            else
                printf("\nImpar");
    return 0;
}