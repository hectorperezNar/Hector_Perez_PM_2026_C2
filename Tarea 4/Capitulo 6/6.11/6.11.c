#include <stdio.h>

void LecturaM(float [][12], int, int);
void LecturaV(float *, int);
void F1(float [][12], int, int, float *);
void F2(float [][12], int, int);
void F3(float *, int);

void main(void)
{
    float FON[5][12], PRE[5], REN[5];
    LecturaM(FON, 5, 12);
    LecturaV(PRE, 5);
    F1(FON, 5, 12, PRE, REN);
    F2(FON, 5, 12);
    F3(REN, 5);
}

void LecturaM(float A[][12], int F, int C)
{
    int I, J;
    for(I=0; I<F; I++)
        for(J=0; J<C; J++)
    {
        printf("Precio fondo %d\t mes %d: ", I+1, J+1);
        scanf("%f", &A[I][J]);
    }
}

