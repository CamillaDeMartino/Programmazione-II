#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#define MAX_GRADO 4
#define MAX_LEN 10 //Grandezza dei nodi

///si azzera il campo del grado
void azzera_grado (nodo_link link[])
{
   for(int i = 0; i < MAX_LEN; i++)
        link[i].grado = 0;
}

void costruisci_albero(nodo_link link[], nodo albero[],int *radice )
{
    int i, padre = 0;  ///in padre viene segnato l'indice del padre, salveremo infatti la relativa rabella

    for(i = 0;i < MAX_LEN;i++)
    {
        padre = albero[i].padre; // Dimmi l'indice padre
        strcpy(link[i].nome,albero[i].nome);    // Costruisci la tabella padre, inserendo il nome, link e aggiornando grado

        if(padre != -1)            // Se il padre del nodo corrente è diverso dalla radice
        {
           (link[padre].grado)++; //Aggiorna numero figli
           (link[padre].figlio[(link[padre].grado) - 1]) = i; //Si salva il link tra padre e figlio.
        }
        else            //Se e' il nodo radice, salva l'indice della radice
        *radice = i;
    }
}


void visita_livelli (nodo_link link[], int radice )
{
    int testa = 0,fondo = 0, i ,grado_padre=0;

    /* CODA in cui sono inseriti gli elementi per livelli*/

    nodo_link coda[MAX_LEN];
    nodo_link appoggio; //Nodo d'appoggio per cio' che estraggo

    /* Metti in coda l'indice della radice*/

    enqueue(link[radice],&fondo,coda);

    /* Cicla fin quando testa non raggiunge fondo (e quindi n nodi esauriti) */

    while(fondo != testa)
    { /* Estrai dalla coda nodo inserito */
        dequeue(&testa,coda,&appoggio,fondo);
        printf("PADRE: %-15s\tgrado=%hd\n",appoggio.nome,appoggio.grado);
        grado_padre = appoggio.grado; //ricava il grado per quel nodo padre

        /* Stampa e inserisci in coda i figli di quel nodo, che sono lunghi grado_padre. */
        if(grado_padre > 0)
            printf("FIGLI:\n");
        for(i = 0;i < grado_padre; i++) //Si mettono in coda i figli del nodo corrente
        {
            printf(" %s\n", link[appoggio.figlio[i]].nome);
            enqueue(link[appoggio.figlio[i]],&fondo,coda);/* Inserisci in coda i figli */
        }
        printf("\n-------------------------------\n");
    }
}


void enqueue(nodo_link elem, int *fondo, nodo_link coda[])
{
    if(*fondo < MAX_LEN)
        coda[(*fondo)++] = elem;
    else
        printf("Non è possibile effettuare altri inserimenti!\n");
}

void dequeue(int *testa, nodo_link coda[], nodo_link *appoggio, int fondo)
{
    if(*testa < fondo)
    {
        *appoggio = coda[(*testa)];
        (*testa)++;
    }
    else
        printf("\nNessun elemento presente nella pila!\n");
}
