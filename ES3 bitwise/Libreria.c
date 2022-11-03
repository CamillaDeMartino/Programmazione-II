#include <stdio.h>
#define n_len 16

void bit_short(short x, unsigned char bit[n_len])
{
    short j;
    j = n_len - 1;
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

void scambiare(unsigned char bit[n_len], int n1, int n2)
{
    short j, k;

    for(j = n_len - 1 ; j >= 0; j--)
    {
        for(k = n_len - 1 ; k >= 0; k--)
        {
            if(j == 16 - n1 && k == 16 - n2)
                {
                    bit[j] = bit[j] ^ bit[k];
                    bit[k] = bit[j] ^ bit[k];
                    bit[j] = bit[j] ^ bit[k];
                }

        }
    }
}
