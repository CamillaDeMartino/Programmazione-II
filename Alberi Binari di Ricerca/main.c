#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int main()
{
    /** Scrivere function C iterativa per la costruzione di un albero binario di ricerca rappresentato mediante array**/


    ALBERO *albero;
    int i, *valori_input, n, nxn;

    printf("Inserisci il numero di nodi dell'albero: ");
    scanf(" %d", &n);

    nxn=pow(2,n);       ///n^2 per i link perche' le moltiplicazioni per 2 possono far uscire fuori dal range

    albero = (int *)malloc( nxn*(sizeof(ALBERO)) );  ///allochiamo un albero vuoto
    valori_input = (int *)malloc(n*(sizeof(int)));   ///allochiamo i valori da inserire

    for(i = 1;i <= nxn;i++) //puliamo l'albero
    {
        albero[i].valore = -1;
        albero[i].esiste=0;
    }

    for(i = 0; i < n; i++)
    {
        printf("\n");
        printf("Inserisci un valore: ");
        scanf(" %d", &valori_input[i]);
    }

    costruisci_albero_binario(albero, n, valori_input);

    printf("\nVALORI DELL'ALBERO NELL'ARRAY\n");
    i=1;
    while(i <= nxn)
    {
        if(albero[i].esiste)
        printf(" %d ", albero[i].valore);
        i++;
    }
    printf("\n");

    /* visita in order. Passo nxn per il caso di un albero non bilanciato */

    printf("\nVALORI DELL'ALBERO NELL'ARRAY CON VISITA IN ORDER (quindi ordinato)\n");
    visita_inorder(albero, 1, nxn);
    printf("\n");


    return 0;
}
