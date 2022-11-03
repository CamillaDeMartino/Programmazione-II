#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int main()
{
    /** Scrivere function C iterativa per la costruzione di un heap rappresentato mediante array**/

    int n, i;
    int *heap; //dichiaro un puntatore ad un albero heap

    printf("Inserisci il numero di elementi da inserire nella heap: ");
    scanf("%d", &n);

    heap = (int *)malloc(sizeof(int)*(n+1)); // alloco un albero heap di n+1, perche' ricavo figli partendo dall'indice 1 quindi v[1]
    heap[0] = -1; //primo valore array vuoto

    for(i = 1; i <= n; i++)             //si inseriscono i valori dei nodi
    {
        printf("Inserisci nodo: ");
        scanf("%d", &heap[i]);
    }

    costruisci_heap(heap, n);

    visualizza_heap(heap, n);
    return 0;
}
