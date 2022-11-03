#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#define MAX 16
/**L'algoritmo di visita deve essere gestito direttamente dal programmatore nell'algoritmo iterativo,
mentre viene gestito dal linguaggio di programmazione quando l'algoritmo e' descritto in maniera ricorsiva.**/


int foglia(int albero[], int i)
{
   if(i >= MAX)         ///se hai superato il massimo
    return 1;
   if(albero[i] == -1)
    return 1;          ///se abbiamo una foglia

   return 0;           ///non è una foglia
}

///Nella visita PREORDER, lo stack conserva i nodi di cui non si è ancora visitato il sottoalbero DX

void visita_preorder(int albero[], int i)
{
    if (foglia(albero, i))     ///soluzione banale: indice > dimensione albero (se il nodo è una foglia)
        return;                ///indica il ritorno al precedente processo lasciato in sospeso

    printf("%d ",albero[i]);   ///stampa il nodo corrente dell'albero

    visita_preorder(albero, 2*i);       /// richiama la function sul sotto-albero di sinistra avente come radice il figlio sinistro
    visita_preorder(albero, 2*i+1);     /// richiama la function sul sotto-albero di destra avente come radice il figlio destra

}

///Nella visita INORDER, lo stack conserva i nodi di cui non si è ancora visitato il sottoalbero DX

void visita_inorder(int albero[], int i)
{
    if(foglia(albero, i))
        return;

    visita_inorder(albero, 2*i);

    printf("%d ",albero[i]);

    visita_inorder(albero, 2*i+1);
}

///Nella visita POSTORDER, lo stack conserva i nodi di cui non si è ancora visitata la radice
void visita_postorder(int albero[], int i)
{
    if(foglia(albero,i))
        return;

    visita_postorder(albero, 2*i);
    visita_postorder(albero, 2*i+1);

    printf("%d ",albero[i]);
}
