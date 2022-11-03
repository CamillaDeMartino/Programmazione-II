#include <stdio.h>
#include "Header.h"
#include <string.h>
#define Max_stack_size 10

void push_s(char ch, char p_stack[], int *head)
{
  if(*head < Max_stack_size-1)
        p_stack[++(*head)] = ch;
  else
    printf("PILA PIENA");
}

void pop_s(int *head)
{
    if(*head > -1)
        (*head)--;

}


char *crea_lista()
{
    struct lista { 
	INFO_FIELD info; 
	struct lista *p_next;     
}; 

struct lista *testa; 

testa = (struct lista *) calloc(1,sizeof(struct lista)); //testa->p_next=NULL; con calloc posso evitare tale istruzione return testa; }

return testa;

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


void insl_nodo(int len_info, INFO_FIELD *p_dato, void *p_head)
{
    /* definisce una struttura generica che condivide con il main solo il tipo infofield e
        dichiara un puntatore alla struttura (nuovo dato da aggiungere) */
    struct lista{

        INFO_FIELD info;
        struct lista *p_next;
    }*ptr;


    ptr = calloc(1,sizeof(struct lista));
    memcpy(ptr, p_dato, len_info);          //copia len_info byte da *p_dato a *ptr, senza interessarsi della struttura
    ptr->p_next = ((struct lista*)p_head)->p_next; // colleghiamo il nuovo nodo con la vecchia testa
    ((struct lista*)p_head)->p_next = ptr;         // nodo p_head e' agganciato a ptr
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
