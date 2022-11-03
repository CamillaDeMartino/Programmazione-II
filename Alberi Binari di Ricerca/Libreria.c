#include <stdio.h>
#include <stdlib.h>
#include "Header.h"


void costruisci_albero_binario(ALBERO albero[], int  n, int valori_input[])
{
    int i, radice;

    /* Inseriamo la radice */
    albero[1].valore = valori_input[i++];
    albero[1].esiste = 1;

    while(i<n) //Fin quando esistono nodi da inserire
    {
        radice = 1; //indice parte dalla radice

    /* CONTROLLO SE VA SOTTO ALBERO SINISTRO*/
    while(valori_input[i] <= albero[radice].valore && albero[2*radice].esiste )
        radice = 2*radice; //scendi al sottoalbero sinistro

    /* CONTROLLO SE VA SOTTO ALBERO DESTRO*/
    while(valori_input[i] >= albero[radice].valore && albero[(2*radice)+1].esiste )
        radice = (2*radice)+1; //scendi al sottoalbero destro

    /* TROVATO IL SOTTOALBERO, VEDO SE E' FIGLIO SINISTRO O DESTRO*/

        if(valori_input[i] < albero[radice].valore)
        {
            albero[2*radice].valore = valori_input[i];
            albero[2*radice].esiste = 1;
        }
        else
        {
            albero[(2*radice)+1].valore = valori_input[i];
            albero[(2*radice)+1].esiste = 1;
        }
        i++;

    }
}

int foglia(ALBERO albero[], int i, int n)
{
    if(i > n)           ///size superato
    return 1;

    if(!albero[i].esiste) /// Se il nodo puntato e' "vuoto", nella chiamata precedente avevamo una foglia
        return 1;

return 0;   /// Non e' una foglia
}
void visita_inorder(ALBERO albero[], int i, int n)
{
    if( foglia(albero,i,n))
        return;

    visita_inorder(albero, 2*i, n);

    printf("%hd ",albero[i].valore); /*stampa il nodo corrente dell'albero*/

    visita_inorder(albero, 2*i+1, n);


}
