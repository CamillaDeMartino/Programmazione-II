#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#include <string.h>

struct Persona *crea_lista()
{
    struct Persona *head;
    head = NULL;
    return head;
}

void insl_testa(INFO_FIELD dato, struct Persona **p_head)
{
    struct Persona *ptr;

    ptr = calloc(1,sizeof(struct Persona));
    ptr->info = dato;
    ptr->p_next = *p_head;
    *p_head = ptr;
}


int vista(struct Persona **p_punt, char nodo[])
{
    while(*p_punt != NULL)
    {
        if(strcmp( (*p_punt)->info.nome, nodo) == 0)
            return 1;

        *p_punt = (*p_punt)->p_next;
    }
}

void insl_nodo(INFO_FIELD dato, struct Persona **p_punt)
{
    struct Persona *ptr;

    ptr = calloc(1,sizeof(struct Persona));

    ptr->info = dato;
    ptr->p_next = (*p_punt)->p_next;
    (*p_punt)->p_next = ptr;
    *p_punt = ptr;
}


void elim_testa(struct Persona **p_head)
{
    struct Persona *Libera;

    Libera = *p_head;
    *p_head = (*p_head)->p_next;

    free(Libera);
}

void elim_nodo(struct Persona **p_punt)
{
    struct Persona *Libera;

    Libera = (*p_punt)->p_next;
    (*p_punt)->p_next = ((*p_punt)->p_next)->p_next;

    free(Libera);
}


void visualizza_list(struct Persona *head)
{
    while( head != NULL)
    {
        printf(" Nome: %2s % \n Eta : %2hd\n\n", head->info.nome, head->info.eta);
        head=head->p_next;
    }
}


