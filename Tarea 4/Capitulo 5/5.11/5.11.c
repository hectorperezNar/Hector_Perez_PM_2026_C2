#include <stdio.h>

/* Busqueda binaria. */

const int MAX=100;

void Lectura(int, int);              /* Prototipos de funciones. */
int Binaria(int *, int, int);

void main(void)
{
    int RES, ELE, TAM, VEC[MAX];
    do
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM>MAX || TAM<1); /* Se verifica que el tamaño del arreglo sea correcto. */

    Lectura(VEC, TAM);
    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);
    RES = Binaria(VEC, TAM, ELE); /* Se llama a la funcion que busca en el arreglo. */

    if (RES)
    /* Si RES tiene un valor verdadero -diferente de 0-, se escribe la posicion4
    en la que se encontro el elemento.*/
        printf("/nEl elemento no se encuentra en el arreglo");
}

void Lectura(int A[], int T)
{
    int I;
    for (I=0; I<T; I++)
    {
        printf("Ingrese el elemento %d: ", I+1);
        scanf("%d", &A[I]);
    }
}

int Binaria(int A[], int T, int E)
{
    int ELE, IZQ = 0, CEN, DER = T-1, BAN = 0:
    while ((IZQ <= DER) && (!BAN))
    {
        CEN = (IZQ + DER) / 2;
        if (E == A[CEN])
            BAN = CEN;
        else
            if (E > A[CEN])
                IZQ = CEN + 1;
            else
                DER = CEN - 1;
    }
    return (BAN);
}