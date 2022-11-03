#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

void costruisci_albero_binario(ALBERO **p_head, int  n, int valori_input[])
{
    ALBERO *ptr, *punt; /// ptr = puntatore a nodo nuovo
                        ///punt = puntatore che visita l'albero
    int i = 0;

    ///Creazione radice
    ptr = calloc(1, sizeof( ALBERO)); ///Facendo calloc, i puntatori dx e sx punteranno a NULL
    ptr ->valore = valori_input[i++];       ///si inserisce l'elemento alla radice e avanzato il puntatore
    *p_head = ptr;    ///la nuova testa sara' la radice


    while(i<n) //Fin quando esistono nodi da inserire
    {
        punt = *p_head; //indice parte dalla radice
        ptr = calloc(1, sizeof( ALBERO)); //Facendo calloc, i puntatori dx e sx punteranno a NULL

    /* CONTROLLO SE VA SOTTO ALBERO SINISTRO*/
    while(valori_input[i] <= punt->valore && punt->sx != NULL )
        punt = punt->sx;  //scendi al sottoalbero sinistro

    /* CONTROLLO SE VA SOTTO ALBERO DESTRO*/
    while(valori_input[i] >= punt ->valore && punt ->dx != NULL)
        punt = punt ->dx; //scendi al sottoalbero destro

    /* TROVATO IL SOTTOALBERO, VEDO SE E' FIGLIO SINISTRO O DESTRO*/

        if(valori_input[i] < punt ->valore)
        {
            punt ->sx = ptr; //Aggancia come figlio sinistro
            ptr ->valore = valori_input[i]; //inserisci valore nel nodo
        }
        else
        {
            punt ->dx = ptr; //Aggancia come figlio destro
            ptr ->valore = valori_input[i]; //inserisci valore nel nodo
        }
        i++;

    }
}

int foglia(ALBERO *p_punt)
{
   //Se non e' una foglia
   if(p_punt!=NULL)
    return 0;

   return 1;
}

void visita_inorder(ALBERO *p_punt)
{
    if( foglia(p_punt))
        return;

    visita_inorder(p_punt ->sx);

    printf("%hd ", p_punt ->valore); /*stampa il nodo corrente dell'albero*/

    visita_inorder(p_punt ->dx);


}
