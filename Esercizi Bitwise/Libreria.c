#include <stdio.h>
#include <math.h>
#include "Header.h"

char low_up(char ch)
{
    int ASCII = ch;

    if(ASCII <= 90 && ASCII >= 65)
	{
	   printf("Carattere inserito maiuscolo\n");
           return ch^32;
	}
       else
        {
	  printf("Carattere inserito minuscolo\n");
	  return ch^32;
	}
}

char ruota ( char ch, char n_bit)
{
    char mask = ch;

    if(n_bit < 0)
    {
        mask = mask << (n_bit * (-1));
        ch = ch >> n_bit;

        return mask|ch;
    }
    else
    {
        mask = mask >> n_bit;
        ch = ch << n_bit;

        return mask|ch;
    }
}

void show(char ch)
{
    unsigned char bit[16][5] = {"0000","0001","0010","0011",
                                "0100","0101","0110","0111",
                                "1000","1001","1010","1011",
                                "1100","1101","1110","1111"
                                };


   unsigned char sx, dx;

   sx = ch >> 4;
   dx = (ch << 4); dx = dx >> 4;

   printf("char = %c, decimale = %d\n", ch,ch);
   printf("bin =  %s %s", bit[sx], bit[dx]);

}



char estrarre_mask(char numero, int scelta, int bit)
{
    char mask = 0;

    for(int i = 0; i < bit; i++)
        mask = mask << 1 | 1;

    if(scelta == 1)
       return numero & mask << (sizeof(char)*8 - bit);
    else
       return numero & mask;

}

char estrarre_shift(char ch, int scelta, int bit)
{
    if(scelta == 1)
    {
        ch >> (sizeof(char)*8 - bit);
        return ch << (sizeof(char)*8 - bit);
    }
    else
    {
        ch << (sizeof(char)*8 - bit);
        return ch >> (sizeof(char)*8 - bit);
    }
}

char estrarre_potenza(char ch, int scelta, int bit)
{
    if (scelta == 1)
    {
        ch = ch/pow(2,sizeof(char)*8 - bit);
        return ch*pow(2,sizeof(char)*8 - bit);
    }
    else
    {
        ch = ch*pow(2,sizeof(char)*8 - bit);
        return ch/pow(2,sizeof(char)*8 - bit);
    }
}

void bit_show(char ch)
{
    char j = 7, bit[8];

    do
    {
        bit[j--] = ch & 1;
        ch = ch >> 1;
    }while(ch != 0 && j >= 0);

    if(j >= 0)
    {
        do{
            bit[j--] = 0;
        }while(j >= 0);
    }

    for(int k = 0; k < 8; k++)
        (k%4 == 0) ? printf(" %1d", bit[k]) : printf ("%1d", bit[k]);
}
void bit_show2(char x, unsigned char bit[8])
{
    short j;
    j =  7;
    do
    {
        bit[j--] = x & 1;
        x = x >> 1;
    }while(x != 0 && j >= 0);

    if(j >= 0)
    {
        do{
            bit[j--] = 0;
        }while(j >= 0);
    }
}

void scambiare(unsigned char bit[8], int n1, int n2)
{
    short j, k;

    for(j = 7 ; j >= 0; j--)
    {
        for(k = 7 ; k >= 0; k--)
        {
            if(j == 8-n1 && k == 8-n2)
                {
                    bit[j] = bit[j] ^ bit[k];
                    bit[k] = bit[j] ^ bit[k];
                    bit[j] = bit[j] ^ bit[k];
                }

        }
    }
}



int addizione_binaria(int op1, int op2)
{
    int somma = 0, riporto;

 while(riporto > 0)
    {
        somma = op1 ^ op2;

        riporto = op1 & op2;
        riporto = riporto << 1;

        op1 =  somma;
        op2 = riporto;
    }
    return somma;
}

int sottrazione_binaria(int op1, int op2)
{
    int sott, riporto = 1;

 while(riporto > 0)
    {
    sott = op1 ^ op2;
    riporto = ~op1 & op2;
    riporto = riporto << 1;

    op2 =  riporto;
    op1 = sott;
   }

    return sott;
}
