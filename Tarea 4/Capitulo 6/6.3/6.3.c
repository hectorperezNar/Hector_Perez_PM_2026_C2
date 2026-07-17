#include <stdio.h>

const int F = 8, C = 2, P = 5;

void Lectura(int [][C][P], int, int, int);
void Funcion1(int [][C][P], int, int, int);
void Funcion2(int [][C][P], int, int, int);
void Funcion3(int [][C][P], int, int, int);

void main(void)
{
    int UNI[F][C][P];
    Lectura(UNI, F, C, P);
    Funcion1(UNI, F, C, P);
    Funcion2(UNI, F, C, P);
    Funcion3(UNI, 6, C, P);
}

void Lectura(int A[][C][P], int FI, int C0, int PR)

{
    int, K, I, J;
    for (K=0; K<PR; K++)
    for (I=0; I<FI; I++)
    for (J=0; J<C0; J++)
    {
        printf("AñoÑ %d\tCarrera: %d\tSemestre: %d ", K+1, I+1, J+1);
        scanf("%d", &A[I][J][K]);
    }
}

