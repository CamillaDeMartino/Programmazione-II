#include <stdio.h>
#include "Header.h"
#include <string.h>
#define Max_queue_size 10

void enqueue(char elem, char p_enqueue[], int *bottom)
{
    if(*bottom < Max_queue_size)
    {
       p_enqueue[(*bottom)++] = elem;
    }
    else
        printf("CODA PIENA");
}

void dequeue(int *top, int *bottom)
{
    if(*top != *bottom)
        (*top)++;
    else
        printf("CODA VUOTA");
}

void enqueue_circ(char elem, char queue[], int *Numelem, int *bottom, int top)
{
    if(*Numelem < Max_queue_size)
    {
        *bottom = top + (*Numelem);
        *bottom = (*bottom)%Max_queue_size;
         queue[*bottom] = elem;
         (*Numelem)++;
    }
    else
        printf("CODA PIENA");
}

void dequeue_circ(int *top, int *Numelem)
{
    if(*Numelem > 0)
    {
        (*top)++;
        *top = (*top)%Max_queue_size;
        (*Numelem)--;
    }
    else
        printf("CODA VUOTA");
}

void *creaLista_sentinella()
{ struct lista
    {
      INFO_FIELD info;
      struct lista *p_next;
    };

    struct lista *testa;

    testa = (struct lista *) calloc(1,sizeof(struct lista)); //testa->p_next=NULL; con calloc posso evitare tale istruzione

    return testa;
}


void insl_nodo(int len_info, INFO_FIELD *p_dato, void **bottom)
{
    /* definisce una struttura generica che condivide con il main solo il tipo infofield e
        dichiara un puntatore alla struttura (nuovo dato da aggiungere) */
    struct lista{

        INFO_FIELD info;
        struct lista *p_next;
    }*ptr;


    ptr = calloc(1,sizeof(struct lista));
    memcpy(ptr, p_dato, len_info);          //copia len_info byte da *p_dato a *ptr, senza interessarsi della struttura
    ptr->p_next = ((struct lista*)*bottom)->p_next; // colleghiamo il nuovo nodo con la vecchia testa
    ((struct lista*)*bottom)->p_next = ptr;         // nodo bottm e' agganciato a ptr
    *bottom = ptr;
}

void elim_nodo(void *p_head)
{
    struct lista{

        INFO_FIELD info;
        struct lista *p_next;
    }*ptr;


    ptr = ((struct lista*)p_head)->p_next;      /* prendi nodo successivo al nodo sentinella (o puntato da p_punt) */
    ((struct lista *) p_head)->p_next = ptr->p_next;  /* Aggancia nodo p_punt al successivo del successivo (guarda ptr chi e') */

    free(ptr);
}

void visualizza(void *head)
{
    struct lista{

        INFO_FIELD info;
        struct lista *p_next;
    }*ptr;

    while (ptr != NULL)
    {
        printf(" %s\n",ptr->info.nome);
        ptr = ptr->p_next;

    };

}
