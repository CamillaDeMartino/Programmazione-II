#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#define Max_queue_size 10
int main()
{
   /**  Simulare in C la gestione di una coda (queue) tramite array statico (può essere anche un array di struct)
        creando le funzioni di manipolazione enqueue() [inserimento] e dequeue() [eliminazione]. Il programma
        deve prevedere un menù che consenta di scegliere l’operazione da eseguire. Le informazioni NON vanno
        spostate! **/

        /* NB non e' il miglior modo, dato che non posso sfruttare le eliminazioni lasciate da TESTA
                (SOLUZIONE?ARRAY CIRCOLARE!) */
/*
         char temp[Max_queue_size], ch;
         int scelta, top = 0; //idividua l'indice del primo elemento da estrarre[TESTA della coda]
         int bottom = 0;      //idividua l'indice dell'ultimo elemento dove inserire in coda[FONDO]


         do{

            printf("Scegliere un operazione:\n[1]Inserimento\n[2]Eliminazione\n[3]Esci\n");
            scanf(" %d", &scelta);

            switch(scelta){
            case 1:
                printf("Inserisci elemento: ");
                scanf(" %c", &ch);

                enqueue(ch,temp,&bottom);
                break;

            case 2:
                 dequeue(&top, &bottom);
                 break;

            }
         }while(scelta != 3);

         for(int i = top; i < bottom; i++)
            printf(" %c\n", temp[i]);
*/


    /** Simulare in C la gestione di una coda (queue) tramite array statico circolare (può essere anche un array
        di struct) creando le funzioni di manipolazione enqueue() [inserimento] e dequeue() [eliminazione]. Il
        programma deve prevedere un menù che consenta di scegliere l’operazione da eseguire**/

        /*
        int scelta, Numelem = 0, top = 0, bottom = 0;
        char temp[Max_queue_size], ch;

        do{

            printf("Scegliere un operazione:\n[1]Inserimento\n[2]Eliminazione\n[3]Esci\n");
            scanf(" %d", &scelta);

            switch(scelta){
            case 1:
                printf("Inserisci elemento: ");
                scanf(" %c", &ch);

                enqueue_circ(ch,temp,&Numelem,&bottom,top);
                break;

            case 2:
                 dequeue_circ(&top, &Numelem);
                 break;

            }
         }while(scelta != 3);


        for(int i = Numelem; i >= 0; i--)           //puoi mettere anche il for nel do-while e ti esce una cosa più sistemata
            printf(" %c\n", temp[i]);
*/




/**Realizzare in C le funzioni per la gestione della struttura dati CODA mediante lista lineare dinamica e generica con nodo sentinella.**/


    struct PERSONA{

        INFO_FIELD info;
        struct PERSONA *p_next;
    };

    INFO_FIELD dato;
    struct PERSONA *head, *bottom;
    int scelta, len_info;

    len_info = sizeof(INFO_FIELD);
    head = (struct PERSONA*)creaLista_sentinella();
    bottom = head;

    do{
            visualizza( (void *)(head)->p_next);
            printf("\nScegliere operazione\n[1]Inserisci\n[2]Eliminare\n[3]Esci\nInserire scelta: ");
            fflush(stdin);
            scanf(" %d", &scelta);

        switch(scelta){
        case 1:
            printf("Inserire nome:  ");
            fflush(stdin);
            gets(dato.nome);
            insl_nodo(len_info, &dato, (void **)&bottom);
            break;

        case 2:
            elim_nodo((void *)head);
            break;
        }



        }while(scelta != 3);


        return 0;
}
