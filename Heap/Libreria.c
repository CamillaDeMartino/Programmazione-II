#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

/*costruisci heap: semplicemente scorre 'i' che punta al nodo corrente e mediante
  heapify posizioniamo i figli nella giusta posizione tale che
  padre(x)> x*/

void costruisci_heap(int heap[], int n)
{
    for(int i = 1; i <= n; i++)
        heapify(heap, i);
}


/* heapify: Ha il compito di controllare se quel nodo e' piu' grande del padre.
    se lo e' scambiamo e passiamo all'eventuale padre successore dividendo i/2.
    Se il nodo e' piu' piccolo del padre, ci fermiamo perche' vale la proprieta'.*/

void heapify(int heap[], int i)
{
    int temp;

    while(i != 1 && heap[i] > heap[i/2])         //il padre è indicato con i/2 (formule prefissat per gli array)
    {                                           //si resta nel ciclo finchè viene rispettata la proprietà di heap
        //scambia
        temp = heap[i];
        heap[i] = heap[i/2];
        heap[i/2] = temp;

        i = i/2; /* Passa al padre superiore */
    }

}

void visualizza_heap(int heap[], int n)
{
    int i;
    for(i = 1; i <= n ; i++)
    {
        printf("Nodo: %3d  Padre: %3d  ", heap[i], heap[i/2]);
    /* Controllo se sono presenti dei figli */
        if(i*2 <= n)
            printf("Figlio sinistro: %3d  ", heap[i*2]);
        if((i*2)+1 <= n)
            printf("Figlio destro: %3d", heap[(i*2)+1]);
        printf("\n\n");
    }
}
