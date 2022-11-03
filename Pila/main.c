#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#define Max_stack_size 10



int main()
{

    /** Simulare in C la gestione di una pila (stack) tramite array statico (può essere anche un array di struct)
        creando le funzioni di manipolazione push() [inserimento] e pop() [eliminazione]. Il programma deve
        prevedere un menù che consenta di scegliere l’operazione da eseguire.**/

        /*


        char temp[Max_stack_size], ch;
        int scelta, head = -1; //indica lo stack vuoto, punta sempre all'ultimo elemento inserito (stack pointer)


        do{
            printf("\nScegliere operazione\n[1]Inserisci\n[2]Eliminare\n[3]Esci\nInserire scelta: ");
            scanf(" %d", &scelta);

        switch(scelta){
        case 1:
            printf("Inserire elemento: ");
            scanf(" %c", &ch);
            push_s(ch,temp, &head);
            break;

        case 2:
            pop_s(&head);
            break;
        }
        }while(scelta != 3);

        if(head > -1 )
        {
            for(int i = head; i >= 0; i--)
                printf(" %c\n", temp[i]);
        }
        else
            printf("Pila vuota");



    */


/** Realizzare in C le funzioni per la gestione della struttura dati PILA mediante lista lineare dinamica e generica con nodo sentinella. **/

    struct PERSONA{

        INFO_FIELD info;
        struct PERSONA *p_next;
    };

    INFO_FIELD dato;
    struct PERSONA *head;
    int scelta, len_info;

    len_info = sizeof(INFO_FIELD);
    head = (struct PERSONA*)crea_lista();

    do{
            printf("\nScegliere operazione\n[1]Inserisci\n[2]Eliminare\n[3]Esci\nInserire scelta: ");
            fflush(stdin);
            scanf(" %d", &scelta);

        switch(scelta){
        case 1:
            printf("Inserire nome:  ");
            fflush(stdin);
            gets(dato.nome);
            insl_nodo(len_info, &dato, (void *)head);
            break;

        case 2:
            elim_nodo((void *)head);
            break;
        }

        visualizza( (void *)(head)->p_next);

        }while(scelta != 3);


    return 0;
}
