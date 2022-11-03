#include <stdio.h>
#include "Header.h"
#include <math.h>
void char_bit_division(unsigned char n, unsigned char bit[8])
{
    int j, i = 0;

    do{
        bit[i++] = n%2;
        n = n/2;
    }while(n > 0);

    for(j = i; j < 8; j++)
    {
        bit[j] = 0;
    }
}

void op_bitwise(unsigned char n, unsigned char bit[8])
{
    int i = 0;

    do{
        bit[i] = n & 1;
        n = n >> 1;
        i++;
    }while(n != 0 && i < 8);

    for(int j = i; j < 8; j++)
    {
        bit[j] = 0;
    }
}


void stampa_bit(unsigned char bit[8])
{
    int i;
    for(i = 7; i >= 0; i--)
    {
        printf("%d", bit[i]);
        if(i%4 == 0)
            printf(" ");
    }
}



short conversione_array(unsigned char bit[8], unsigned char array[])
{
    int decimale = 0;
    int i;
    int len = 0;
    for(i = 0; i < 8; i++)
        decimale += bit[i] * (pow(2,i));


    for(i = 0; i < 8, decimale > 0; i++)
    {
        array[i] = decimale%10;
        decimale = decimale/10;
        len++;
    }
return len;

}


int addizione_aritmetica(int op1, int op2)
{
    int rip = 1, somma = 0;

    do{
        somma = op1 ^ op2;
        rip = op1 & op2;
        rip = rip << 1;
        op1 = somma;
        op2 = rip;
    }while(rip > 0);

    return somma;
}

int sottr_aritmetica(int op1, int op2)
{
    int rip = 1, sottr = 0;

    do{
        sottr = op1 ^ op2;
        rip = ~op1 & op2;
        rip = rip << 1;
        op1 = sottr;
        op2 = rip;
    }while(rip > 0);

    return sottr;
}


int complemento_a2(int bit, int num)
{
    int range_max = pow(2, bit-1) -1;
    int range_min = -pow(2, bit-1);
    int modulo = pow(2, bit);
    if(num <= range_max && num >= range_min)
        return ((modulo+num) % modulo);
        else
            return 0;
}

int rapp_biased(int bit , int num)
{
    int range_max = pow(2, bit-1);
    int range_min = -(pow(2, bit-1)-1);

    if(num <= range_max && num >= range_min)
        return (pow(2,bit -1)-1) + num;
        else
            return 0;
}


int addizione_aritmetica2(int op1, int op2)
{
  int rip = 1, somma = 0;

    do{
        somma = op1 ^ op2;
        rip = op1 & op2;
        rip = rip << 1;
        op1 = somma;
        op2 = rip;
    }while(rip != 0);

    return somma;
}
