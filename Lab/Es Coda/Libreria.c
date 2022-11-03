#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#define Max_size 5

void enqueue(char elem, char temp[], int *coda)
{
    if(*coda < Max_size)
        temp[(*coda)++] = elem;
    else
        printf("\n***CODA PIENA***\n");
}

void dequeue(int *testa, int *coda)
{
    if(*testa != *coda)
        (*testa)++ ;
    else
        printf("\n***CODA VUOTA***\n");
}

void enqueue_cir(char elem, char temp[], int *fondo, int *numelem, int testa)
{
    if(*numelem < Max_size)
    {
        *fondo = testa + (*numelem);
        *fondo = (*fondo)%Max_size;
        temp[*fondo] = elem;
        (*numelem)++;
    }
    else
        printf("\n***ARRAY PIENO***\n");
}

void dequeue_cir(int *testa, int *numelem)
{
    if(*numelem > 0)
    {
        (*testa)++;
        *testa = (*testa)%Max_size;
        (*numelem)--;
    }
    else
        printf("\n***ARRAY VUOTO***\n");
}
