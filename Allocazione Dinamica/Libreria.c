#include <stdio.h>
#include "Header.h"
#include <stdlib.h>

void stampa_matriceS(unsigned int A[6], unsigned int rows, unsigned int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
            printf("%d ", A[i*cols+j]);

        printf("\n");
    }
}

void stampa_matriceD(int *pa, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
            printf("%d ", *(pa + i*cols+j));

        printf("\n");
    }
}


int *Prodotto_rxc(int *a, int *b, int r, int c, int p)
{
    int *C, i, j, k;
    C = (int *)calloc (r*c, sizeof(int));

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            for(k = 0; k < p; k++)
                *(C + i*c +j) = *(C + i*c + j) + ((*(a + i*p +k)) * (*(b + k*c +j)));
        }
    }

    return C;
}


void assegna_valori(int **pt, int M, int N)
 {
     for(int i = 0; i < M; i++)
     {
         for(int j = 0; j < N; j++)
            *(pt[i] + j-1) = 10*(i+1) + (j+1);
     }

 }

 void stampa_triangolo(int **pt, int M, int N)
 {
     for(int i = 0; i < M; i++)
     {
         for(int j = 0; j < N; j++)
           (j>i) ? printf("   "): printf(" %d", *(pt[i] + j-1));

        printf("\n");
     }
 }

