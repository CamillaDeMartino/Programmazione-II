#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#define Max_stack_size 5

int main()
{
    /**Simulare in C la gestione di una pila (stack) tramite array statico creando le funzioni di manipolazione
        push()[inserimento] e pop() [eliminazione].
        Il programma deve prevedere un menù che consenta di scegliere l’operazione da eseguire. **/


    char ch, temp[Max_stack_size];
    int scelta, head = -1;

    do
    {
        printf("\nScegliere operazione\n[1]Inserisci\n[2]Eliminare\n[3]Esci\nInserire scelta: ");
        scanf( "%d", &scelta);

        switch(scelta)
        {
        case 1:
            printf("\nInserire carattere: ");
            scanf(" %c", &ch);
            push_s(ch, temp, &head);
            break;

        case 2:
            pop_s(&head);
            break;
        }

        printf("\n***PILA****\n");

        if(head > -1)
        {
            for(int i = head; i >= 0; i--)
            printf("[%c]\n", temp[i]);
        }
        else
            printf("\n***PILA VUOTA***\n");

    }while(scelta != 3);

    return 0;
}
