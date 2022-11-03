#include <stdio.h>
#include <math.h>
#include "Header.h"
#define bias 127        //(2^8-1  -1)

float estrarre_sem(int n, char bit[32])
{
    int exp, sign, mantissa, mask = 0;

    mask = 0x80000000; //1000000

    sign = mask & n;
    sign = sign >> 31;

    mask = 0x7f800000; //11111111000000

    exp = mask & n;
    exp = exp >> 23;
    exp = exp - bias;


    mask = 0x007fffff; //11111111111

    mantissa = mask & n;

    for(int i = 32; i >= 0; i--)
    {
        bit[i] = (char)n&1;
        n = n >> 1;
    }


    /*_____ Ricostruzione del Float iniziale _____*/
    // NB: Per avere il floating point, dobbiamo effettuare
    // x = (-1)^s*[l.m]*b^(e-bias)
    //La nostra base e' 2 e il bias 127. Dato che abbiamo un bit implicito,
    //lo ripristiniamo aggiungendo 1 alla mantissa

    float verifica_float, bit_implicito;

    bit_implicito=(((float)mantissa)/(1<<23))+1;   /* Divido la mantissa per 2^23, in tal modo da
                                                      spostarmi la virgola e aggiungere il bit implicito */

    verifica_float = pow(-1,sign) * (bit_implicito)* pow(2, exp);


    printf("\nSegno: %d \n", sign);
    printf("Mantissa: %.5f \n", bit_implicito-1); //Mantissa senza hidden bit
    printf("Esponente: %d \n", exp);

    return verifica_float;
}
