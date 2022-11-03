#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#include <time.h>

int main()
{
    /**Data una matrice allocata una volta per righe ed un’altra per colonne
        • come VLA
        • dinamicamente
    visualizzarne gli elementi per righe e per colonne.**/
/*
    unsigned int M = 4, N = 6;
    unsigned int a[M*N];

    printf("\nMatrice allocata staticamente per righe:\n");
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
           {
            a[i*N+j] = 10*(i+1) + j+1;
            printf("%d ", a[i*N+j]);
           }
           printf("\n");
    }

    int *pa;
    pa = (int *)malloc(M*N*sizeof(int));

    printf("Matrice allocata dinamicamente(per righe):\n");
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            *(pa + i*N+ j) = a[i*N+j];
            printf( "%d ", *(pa + i* N+ j) );
        }

           printf("\n");
    }

     printf("\nMatrice allocata staticamente per colonne:\n");
    for(int j = 0; j < N; j++)
    {
        for(int i = 0; i < M; i++)
           {
            a[j*M+i] = 10*(i+1) + j+1;
            printf("%d ", a[j*M+i]);
           }
           printf("\n");
    }



   printf("Matrice allocata dinamicamente(per colonne):\n");
    for(int j = 0; j < N; j++)
    {
        for(int i = 0; i < M; i++)
        {
            *(pa + j*M+ i) = a[j*M + i];
            printf( "%d ", *(pa + j*M + i) );
        }

           printf("\n");
    }

*/


/**Scrivere la funzione C per il prodotto righe per colonne di due matrici C = A*B, allocando
dinamicamente le 3 matrici. Le matrici A e B devono essere costruite automaticamente**/
/*
    int *a, *b, *c, m, n, p;

    printf( "Inserire il numero di righe della matrice A: ");
    scanf("%d", &m);
    printf( "Inserire il numero di colonne di A e dunqe le righe di B: " );
    scanf("%d", &p);
    printf( "Inserire il numero di colonne di B: " );
    scanf("%d", &n);

    a = (int *)malloc(m*p *sizeof(int));
    b = (int *)malloc(n*p *sizeof(int));

    srand(time(NULL));

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < p; j++)
            *(a + i*p + j) = rand()%10;
    }

    for(int i = 0; i < p; i++)
    {
        for(int j = 0; j < n; j++)
            *(b + i*n + j) = rand()%10;
    }


    printf("\nMatrice A\n");
    Stampa_Matrice(a, m, p);
    printf("\nMatrice B\n");
    Stampa_Matrice(b, p, n);

    c = Stampa_C(a, b, m, n, p);
    printf("\nMatrice C\n");

    Stampa_Matrice(c, m, n);
*/


    /** Scrivere una funzione C per allocare dinamicamente una matrice triangolare inferiore
        come array frastagliato di numeri, senza memorizzare gli elementi nulli **/


     int M = 6, N = 6;
     //allocare in pt un array di punttaore ad array
     int **pt = (int **)malloc(M*sizeof(int *));

     //allocare ogni componente di pt un array di size decrescente
     for(int i = 0; i < M; i++ )
            pt[i] = (int *)malloc((i+1)*sizeof(int));


     assegna_valori(pt, M, N);
     stampa_triangolo(pt, M, N);

    return 0;
}
