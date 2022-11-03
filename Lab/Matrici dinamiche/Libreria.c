#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

void Stampa_Matrice(int *matrice, int r, int c)
{
    int i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
            printf( "%d ", *(matrice+i*c+j));

        printf( "\n" );
    }
}

int *Stampa_C(int *a, int *b, int m, int n , int p)
{
    int *c, i, j, k;
    c = (int *)calloc(m*n, sizeof(int));

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            for(k = 0; k < p; k++)
                *(c+ i*n+ j) = *(c + i*n + j) + ( (*(a + i*p + k)) * (*(b + k*n + j)) );
        }
    }

    return c;
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
