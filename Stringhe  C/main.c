#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#include <string.h>

int main()
{
    /** Confrontando i risultati con quelli delle relative funzioni del C ed utilizzando per le stringhe
            o l’allocazione statica
            o l’allocazione dinamica
        scrivere una function C che accetti in input il numero n e legga da tastiera n caratteri (uno alla volta)
        costruendo la stringa che li contiene (parametro di output), senza usare strcat(...).**/

        /*
        int scelta, n;
        char stringa[30], *stringaD;

        printf ("Scegliere il tipo di allocazione\n1.Statica\n2.Dinamica\n");
        scanf(" %d", &scelta);

        switch(scelta)
        {
            case 1:
                     printf("Inserire il numero di carattere da immettere: ");
                     scanf(" %d", &n);
                     allocazione_statica(n+1,stringa);
                     printf("Caratteri inseriti: %s", stringa);
                     break;

            case 2:
                    printf("Inserire il numero di carattere da immettere: ");
                    scanf(" %d", &n);
                    allocazione_dinamica(n+1, &stringaD);
                    printf("Caratteri inseriti: %s", stringaD);
                    break;
        }


        */


        /** Confrontando i risultati con quelli delle relative funzioni del C ed utilizzando per le stringhe
                o l’allocazione statica
                o l’allocazione dinamica
            scrivere una function C che restituisca la concatenazione di due stringhe (parametri di input) senza usare
            strcat(...). È a scelta restituire la concatenazione delle due stringhe in una terza variabile (parametro di
            output o function stessa) oppure nella prima delle due variabili di input. **/

    /*

        char str1[32], str2[32], concS[64];
        char *str1D, *str2D, *concD;
        int scelta, n,m;


        fflush(stdin);
        printf("Inserisci la prima stringa\n");
        gets(str1);

        printf("Inserisci la seconda stringa\n");
        gets(str2);
        n = strlen(str1);
        m = strlen(str2);


        printf ("Scegliere il tipo di allocazione\n1.Statica\n2.Dinamica\n");
        scanf(" %d", &scelta);


        switch(scelta)
        {
            case 1:

                     concatenazione(n,m,str1,str2,concS);

                     printf("Concatenazione: %s", concS);
                     break;

            case 2:

                    str1D = (char*)malloc(n+1);
                    str2D = (char*)malloc(m+1);

                    strcpy(str1D, str1);
                    strcpy(str2D, str2);

                    concD = (char*)malloc(n+m+1);

                    concatenazione(n,m,str1D,str2D,concD);

                    printf("Caratteri inseriti: %s", concD);
                    break;
        }


        */




    /** Confrontando i risultati con quelli delle relative funzioni del C, scrivere una function C che restituisca la
        prima occorrenza di una sottostringa in una stringa senza usare strstr(...).**/

/*
        char stringa1[16], stringa2[16];
        int n,m, indice;

        printf( "Inserire la prima stringa " );
        gets(stringa1);

        printf( "Inserire la seconda stringa " );
        gets(stringa2);

        n = strlen(stringa1);
        m = strlen(stringa2);

        indice = occorrenze(n,m,stringa1,stringa2);

        if(indice < 0 )
        {
            printf("\nnon trovato\n");
        }
        else
            printf("\nchiave %s trovata nella stringa %s all'indice %d", stringa2, stringa1, indice);




        */



    /** Usando l’allocazione dinamica e le funzioni C per manipolare le stringhe, scrivere una function C che
        restituisca il numero totale delle occorrenze di una sottostringa in una stringa e
            o [liv.1] ne visualizzi la posizione di tutte le occorrenze trovate.
            o [liv.2] restituisca in un array la posizione di tutte le occorrenze trovate. **/

/*
        char stringa1[16], stringa2[16];
        int array_i[32];
        int n,m, indici;

        printf( "Inserire la prima stringa " );
        gets(stringa1);

        printf( "Inserire la seconda stringa " );
        gets(stringa2);

        n = strlen(stringa1);
        m = strlen(stringa2);

        indici = occorrenze2(n,m,stringa1,stringa2,array_i);

        printf("\nNumero di occorrenze: %d", indici);

        for(int i = 0; i< indici; i++)
            printf("\nOccorrenza n. %d all'indice %d", i+1, array_i[i]);


        */



        /**] Utilizzando per le stringhe
o l’allocazione statica
o l’allocazione dinamica
scrivere una function C che elimini tutte le occorrenze di una data sottostringa in una stringa col minimo
numero di spostamenti di blocchi di memoria.**/
    return 0;
}
