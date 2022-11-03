#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#include <time.h>

int main()
{
    /** A partire da una matrice A(m×n), del tipo sotto indicato
        allocata una volta per righe ed un’altra per colonne
            • come VLA (Variable Length Array)
            • dinamicamente
        visualizzarne gli elementi sia per righe che per colonne.**/

/*
        unsigned int rows = 4, cols = 6;
        unsigned int A[rows*cols];

        //allocata staticamente per righe
        for (int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                A[i*cols + j] = 10*(i+1) + j+1;
            }
        }

        stampa_matriceS(A,rows,cols);
        printf("\n");

        //allocata staticamente per colonne

        for (int i = 0; i < rows; i++)                      //se non volessi usare la function stampa_matrice e invece stampare nel main,
        {                                                   //avrei dovuto invertire i for
            for(int j = 0; j < cols; j++)
            {
                A[j*rows + i] = 10*(i+1) + j+1;
            }
        }

        stampa_matriceS(A,cols,rows);
        printf("\n");

        //Allocata dinamicamente per righe

        int *pa;

        pa = (int *)malloc(rows*cols*sizeof(int));

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
                *(pa + i*cols + j) = 10*(i+1) + j+1;
        }

        stampa_matriceD(pa, rows, cols);
        printf("\n");

        //allocata dinamicamente per colonne

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
                *(pa + j*rows + i) = 10*(i+1) + j+1;
        }

        stampa_matriceD(pa, cols, rows);

        */



        /** Scrivere una funzione C per il prodotto righe per colonne di due matrici C = A*B, allocando
            dinamicamente in modo opportuno le 3 matrici. Le matrici A e B devono essere costruite
            automaticamente come nell’esercizio 1.**/

            /*

            int *a, *b, *C, r,c,p;

            printf( "Inserire il numero di righe della matrice A: ");
            scanf("%d", &r);
            printf( "Inserire il numero di colonne di A e dunqe le righe di B: " );
            scanf("%d", &p);
            printf( "Inserire il numero di colonne di B: " );
            scanf("%d", &c);

            a = (int *)malloc(r * p * sizeof(int));
            if(a == NULL)
                printf("Errore di allocazione!");

            b = (int *)malloc(p * c * sizeof(int));
            if(b == NULL)
                printf("Errore di allocazione!");

            srand(time(NULL));

            for(int i = 0; i < r; i++)
            {
                for(int j = 0; j < p; j++)
                    *(a + i*p + j) = rand()%10;
            }

            stampa_matriceD(a,r,p);
            printf("\n");

            for(int i = 0; i < p; i++)
            {
                for(int j = 0; j < c; j++)
                    *(b + i*c + j) = rand()%10;
            }

            stampa_matriceD(b,p,c);
            printf("\n");

            C = Prodotto_rxc(a, b, r, c, p);
            stampa_matriceD(C,r,c);


            */



    /** Scrivere una funzione C per allocare dinamicamente una matrice triangolare inferiore come
                array frastagliato di numeri, senza memorizzare gli elementi nulli.**/

     /*
     int M = 6, N = 6;
     //allocare in pt un array di punttaore ad array
     int **pt = (int **)malloc(M*sizeof(int *));

     //allocare ogni componente di pt un array di size decrescente
     for(int i = 0; i < M; i++ )
            pt[i] = (int *)malloc((i+1)*sizeof(int));


     assegna_valori(pt, M, N);
     stampa_triangolo(pt, M, N);
    */




    return 0;
}
