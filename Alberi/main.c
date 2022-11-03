#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#define MAX_GRADO 4
#define MAX_LEN 10 //Grandezza dei nodi

int main()
{
/** Scrivere function C per la costruzione e visita per livelli di un albero qualsiasi rappresentato mediante
    array. [Suggerimento: la struct che definisce il generico nodo dell’albero, come nella figura sotto, deve
    contenere i seguenti campi: l'informazione, il grado del nodo ed un array di puntatori (ai nodi figli) di
    dimensione pari al massimo grado dei nodi, che si suppone noto] **/

    ///Definiamo la struttura iniziale dell'albero, dove i numeri indicano l'indice del padre nel vettore

    nodo albero[MAX_LEN] = {{"Gabriele",6},{"Giuseppe",4},{"Pasquale",8},{"Giulia",8},{"Angela",8},
                            {"Maria",9},{"Giovanni",-1},{"Antonio",9},{"Gennaro",6},{"Anna",6}};   ///-1 indica la radice

    ///Tabella inizialmente sporca; costruiremo l'albero, definendo i gradi(nuemro dei figli) e gli indici in cui si trovano tali figli nel vettore

    nodo_link link[MAX_LEN]; ///array di puntatore ai nodi figli
    int radice;              ///indice che individua la radice

    azzera_grado(link);      ///viene inzializzato l'albero ponendo il grado a 0

    costruisci_albero(link,albero,&radice); ///chiamata alla function per costruire l'albero

    printf("\t*--- Costruzione e visita per livelli di un albero qualsiasi ---*\n\n");
    printf("\tRADICE\n");
    visita_livelli(link,radice);    ///Chiamata alla function per la visita dell'abero
    printf("\n");
    return 0;
}
