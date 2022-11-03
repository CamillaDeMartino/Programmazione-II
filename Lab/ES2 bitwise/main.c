#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#define n_len 16

int main()
{
    //Mediante operatori bitwise, scrivere una funzione C per invertire (0 diventa 1 e 1 diventa 0) i 4 bit più
    //significativi, lasciando gli altri inalterati, di
    //• una variabile intera char.
    //• una variabile intera short.
    //• una variabile intera qualsiasi.
    //Visualizzare i bit degli operandi e del risultato.

    char x;
    unsigned char k, bit[n_len];

    x = 0XF4;

    bit_short(x,bit);
    printf("Operando: ");
    for(k = 0; k < n_len; k++)
        (k%4 == 0) ? printf( " %1u", bit[k] ) : printf ( "%1u", bit[k]);

    for(k = 0; k < n_len; k++)
    {
        if(k >= 0 && k < 4)
            bit[k] = bit[k] ^ 1;
    }

    printf("  Nuovo risultato: ");

    for(k = 0; k < n_len; k++)
        (k%4 == 0) ? printf( " %1u", bit[k] ) : printf ( "%1u", bit[k]);




    short y;
    unsigned char i, bit1[n_len];

    y = 13;

    bit_short1(y,bit1);
    printf( "\nOperando: " );

    for (i = 0; i < n_len; i++)
        (i%4 == 0)? printf( " %1u", bit1[i]) : printf ( "%1u", bit1[i]);

    for(i = 0; i < n_len; i++)
    {
        if(i >= 0 && i < 4)
            bit1[i] = bit1[i] ^ 1;
    }

    printf( "  Nuovo risultato: " );

     for (i = 0; i < n_len; i++)
        (i%4 == 0)? printf( " %1u", bit1[i]) : printf ( "%1u", bit1[i]);




   int z;
   unsigned char j, bit2[n_len];

   z = 22;
   bit_short2(z,bit2);

   printf("\nOperando: ");
   for(j = 0; j < n_len; j++)
            (j%4 == 0)? printf (" %1u", bit2[j]) : printf ("%1u", bit2[j]);

   for(j = 0 ; j < n_len; j++)
   {
       if(j >= 0 && j < 4)
            bit2[j] = bit2[j] ^ 1;;

   }

   printf( "  Nuovo risultato: " );
   for(j = 0; j < n_len; j++)
            (j%4 == 0)? printf (" %1u", bit2[j]) : printf ("%1u", bit2[j]);
            printf("\n");
    return 0;
}
