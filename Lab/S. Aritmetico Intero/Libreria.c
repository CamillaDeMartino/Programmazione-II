#include <stdio.h>
#include "Header.h"
#include <math.h>
int rapp_complemento(int n_numero, int n_bit)
{
    int potenza = pow(2,n_bit);
    return (potenza + n_numero) % potenza;
}

void char_bit_division(int numero, int bit[32])
{
    int k = 0, j;

    do
    {
        bit[k++] = numero%2;
        numero = numero/2;
    }while(numero > 0);

    for(j = k; j < 32; j++)
    {
        bit[j] = 0;
    }
}

int rapp_biased(int n_numero, int n_bit)
{
    int biased = pow(2,n_bit-1)-1;
    return n_numero + biased;
}


int addizione_binaria( int op1,int op2)
{
    int somma = 0, riporto = 0;
   do
   {
        somma = op1 ^ op2;
        riporto = op1 & op2;
        riporto = riporto << 1;
        op1 = somma;
        op2 = riporto;
   }while(riporto != 0);

   return somma;
}
