#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int main()
{

    /**Scrivere una function C che, fissato il numero n di bit, calcoli la rappresentazione di un intero:
        -per complemento a 2;
        -per eccesso B (B-biased)**/

    /*
     int n_bit, n_numero, bit[32];
     int complemento2, biased;

     printf( "Inserisci un numero: " );
     scanf(" %d", &n_numero);
     printf( "Inserisci il numero di bit su cui rappresentarlo: " );
     scanf(" %d", &n_bit);

     complemento2 = rapp_complemento(n_numero, n_bit);
     char_bit_division(complemento2,bit);

     printf( "Rappresentazione complemento a 2: %d\n", complemento2 );
     printf( "Rappresentazione complemento a 2 in binario: " );

     for(int i = n_bit-1 ; i >= 0; i--)
        printf("%d", bit[i]);

    biased = rapp_biased(n_numero, n_bit);

    printf( "\nRappresentazione biased %d\n", biased );
    printf( "Rappresentazione biased in binario: " );

     for(int i = n_bit-1 ; i >= 0; i--)
        printf("%d", bit[i]);

        printf("\n");

    */



    /**Scrivere una function C per eseguire l’addizione aritmetica(Versione1)in base 2 mediante gli operatori bitwise.**/

    int op1, op2;

    printf( "Inserisci il primo operando: " );
    scanf(" %d", &op1);
    printf( "\nInserisci il secondo operando: " );
    scanf(" %d", &op2);

    printf( "\nAddizione binaria: %d\n", addizione_binaria(op1, op2));

    return 0;
}
