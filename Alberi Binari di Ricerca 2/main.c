#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int main()
{
    ALBERO *p_head;
    int i, *valori_input, n;

    printf("Inserisci il numero di nodi dell'albero: ");
    scanf(" %d", &n);

    valori_input = (int *)malloc(n*(sizeof(int)));   ///allochiamo i valori da inserire

    for(i = 0; i < n; i++)
    {
        printf("\n");
        printf("Inserisci un valore: ");
        scanf(" %d", &valori_input[i]);
    }

    p_head = NULL;         /// Assegno la testa dell'albero un indirizzo vuoto, dato che dobbiamo ancora comporlo.

    costruisci_albero_binario(&p_head, n, valori_input);


    printf("\nVISITA IN ORDER DELL'ALBERO BINARIO COSTRUITO (valori in ordine) \n");
    visita_inorder(p_head);

    return 0;
}
