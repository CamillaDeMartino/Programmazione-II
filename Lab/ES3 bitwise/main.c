#include <stdio.h>
#include <stdlib.h>
#define n_len 16
#include "Header.h"

int main()
{
    //Scrivere una funzione C per scambiare il valore di due bit, fissati in input, di una variabile intera. Es.: bit 1 e 2
    //di 0000 1100 ⇒ 0000 1010; il bit 1 diventa uguale al bit 2 e il bit 2 diventa uguale al bit 1.

    short x;
    int n1,n2;
    unsigned char k, bit[n_len];

    printf( "Inserisci un numero: " );
    scanf(" %d", &x);

    bit_short(x,bit);
    printf( "Numero in binario: " );

    for(k = 0; k < n_len; k++)
        (k%4 == 0)? printf(" %1u", bit[k]) : printf ("%1u", bit[k]);

    printf( "\nQuali numeri vuoi invertire? " );
    scanf(" %d %d", &n1, &n2);

    scambiare(bit,n1,n2);
    printf( "Nuovo valore: " );
    for(k  = 0; k < n_len; k++)
         printf ("%1u", bit[k]);
    return 0;
}
