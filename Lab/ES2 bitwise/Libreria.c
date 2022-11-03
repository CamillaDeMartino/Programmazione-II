#include <stdio.h>
#include "Header.h"
#define n_len 16

void bit_short(char n, unsigned char bit[n_len])
{
   short j;
   j = n_len-1;
   do
   {
       bit[j--] = n & 1;
       n = n >> 1;
   }while (n != 0 && j >= 0);

   if( j >= 0)
   {
       do{
        bit[j--] = 0;
       }while(j >= 0);
   }
}

void bit_short1(short n, unsigned char bit[n_len])
{
    short j;
    j = n_len - 1;

    do
    {
        bit[j--] = n & 1;
        n = n >> 1;
    }while (n != 0 && j >= 0);

    if(j >= 0)
    {
        do
        {
            bit[j--] = 0;
        }while(j >= 0);
    }
}


void bit_short2(int n, unsigned char bit[n_len])
{
    short j;
    j = n_len -1;

    do
    {
        bit[j--] = n & 1;
        n = n >> 1;
    }while(n != 0 && j >= 0);

    if(j >= 0)
    {
        do
        {
            bit[j--] = 0;
        }while(j >= 0);
    }
}
