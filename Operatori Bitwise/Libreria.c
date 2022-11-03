#include <stdio.h>
#include <math.h>
#include "Header.h"
#define Max_Len 32
#define n_len 16

void bit_show(short len, char ch[] , short bit[Max_Len])
{
    short j, jc;
    char c;
    for(j = 0; j < Max_Len; j++)
        bit[j] = 0;
    for(jc = 0; jc < len; jc++)
    {
        c = ch[jc];
        for(j = 0; j < 8; j++)
        {
            bit[j+8*jc] = c & 1;
            c = c>>1;
        }
    }
}

void bit_show2(short n, unsigned char bit[n_len])
{
    short j = n_len - 1;

    do
    {
        bit[j--] = n&1;
        n = n >> 1;
    }while(n != 0 && j >= 0);

    if (j >= 0)
    {
        do{
            bit[j--] = 0;
        }while(j >= 0);
    }
}

short estrai_mask (short x, int scelta, int k)
{
   short mask = 0, i;

    for(i = 1; i <= k; i++)
            mask = mask << 1|1;
    if(scelta == 1)
            return x &( mask << sizeof(short)*8 - k);
    else
           return x & mask;

}


short estrai_shift(short x, int scelta, int k)
{
    if (scelta == 1)
    {
        x = x >> (sizeof(short)*8 - k);
        x = x << (sizeof(short)*8 - k);
    }
    else
    {
       x = x << (sizeof(short)*8 - k);
       x = x >> (sizeof(short)*8 - k);
    }
       return x;
}

short estrai_potenza(short x, int scelta, int k)
{
    if(scelta == 1)
    {
        x = x / pow (2, (sizeof(short)*8-k));
        x = x * pow (2, (sizeof(short)*8-k));
    }
    else
    {
        x = x * pow (2, (sizeof(short)*8-k));
        x = x / pow (2, (sizeof(short)*8-k));
    }
}


void char_bit_division(unsigned char n, unsigned char bit[8])
{
    char k = 0, j;
    do{
        bit[k++] = n%2;
        n = n/2;
    }while( n > 0 );

    for(j = k; j < 8; j++)
        bit[j] = 0;
}


void bitwise_division(unsigned char n, unsigned char bit[8])
{
    char k = 0, j;

    do{
        bit[k++] = n%2;
        n = n >> 1;
    }while(n > 0);

    for(j = k; j < 8; j++)
        bit[j] = 0;
}



short int decimale(unsigned char n, unsigned char bit[8])
{
    char i ;

    unsigned char decimale = 0;
    for(i = 0; i < 8; i++)
        decimale += bit[i]*(pow(2,i));

       return decimale;
}


short int crea_array(short int decimale, unsigned char array[])
{
    short int i, size = 0;
    for(i = 0; i < 8, decimale > 0; i++)
    {
        array[i] = decimale%10;
        decimale = decimale/10;
        size++;
    }
    return size;
}
