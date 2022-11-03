#include <stdio.h>
#include "Header.h"
#define Max_stack_size 5
void push_s(char elem, char temp[], int *head)
{
    if (*head < Max_stack_size-1)
        temp[++(*head)] = elem;
    else
        printf(" ***PILA PIENA*** ");
}

void pop_s(int *head)
{
    if (*head > -1)     //se c'è qualcosa
        (*head)--;      //decremento

}
