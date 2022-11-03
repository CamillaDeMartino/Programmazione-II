#include <stdio.h>
#include <stdlib.h>
#include "Header.h"



/*typedef struct Persona{

    char nome[20];
    struct Persona *p_next;

}PERSONA;*/


int main()
{
    /** Simulare in C l’algoritmo di visita di una lista lineare già memorizzata mediante un array statico di
        struct (come nella tabella in basso) in cui il primo campo contiene l’informazione ed il secondo contiene il
        link al nodo successivo (in questo caso il link è l’indice di una componente dell’array). Memorizzando
        nell’array i dati come mostrato nella figura che segue, l’output del programma consiste nell’elenco di nomi
        ordinato alfabeticamente**/
  /*
    PERSONA vettore[]= {{"Anna",5},{"Mario", 8},{"Giuseppe", 6},
                        {"Angela", 0},{"Valeria", -1},{"Fabrizio", 7},
                        {"Marianna", 1},{"Giovanni", 2}, {"Patrizia", 10},
                        {"Valentina",4},{"Sara",9}};

    int p_testa = 3;

    while(p_testa != -1)
    {
      printf("%s\n", vettore[p_testa].nome);
      p_testa = vettore[p_testa].p_next;
    }
*/



/** Realizzare la gestione di una lista lineare mediante menù:
        visualizzazione mediante visita,
        inserimento in testa,
        inserimento in mezzo,
        e eliminazione in testa, eliminazione in mezzo.
        Implementare la lista lineare con una struttura autoriferente dinamica. **/

/*
     struct Persona *head, *punt;
     int scelta, esito;
     char nodo[20];
     INFO_FIELD dato;


     head = crea_lista();


     do{

        printf("*----------- ESEMPIO DI GESTIONE DI UNA LISTA LIENARE ------------*\n");
        printf("*[1] - Inserisci in testa alla lista                              *\n");
        printf("*[2] - Inserisci un elemento nel mezzo                            *\n");
        printf("*[3] - Elimina un elemento dalla testa                            *\n");
        printf("*[4] - Elimina un elemento dal nodo sucessivo                     *\n");
        printf("*[5] - Visualizza la lista                                        *\n");
        printf("*[6] - Esci dal programma                                         *\n");
        printf("*-----------------------------------------------------------------*\n");
        printf("\nScelta: ");
        scanf(" %d", &scelta);
        fflush(stdin);

        switch(scelta){

        case 1:
                printf("Inserisci il nome:");
                gets(dato.nome);
                fflush(stdin);
                printf("Inserisci l'eta");
                scanf(" %d", &dato.eta);
                insl_testa(dato,&head);
                break;

        case 2:
                if(head != NULL) //se non è vuota
                {
                   printf("Inserie nome nodo precedente a quello da inserire: ");
                   gets(nodo);
                   fflush(stdin);

                   punt = head;
                   esito = vista(&punt, nodo);

                   if(esito == 1)
                   {
                     printf("Inserisci il nome:");
                     gets(dato.nome);
                     fflush(stdin);
                     printf("Inserisci l'eta");
                     scanf(" %d", &dato.eta);
                     insl_nodo(dato, &punt);
                   }
                   else
                    printf("Nodo non trovato!");

                }
                else
                    printf("Lista vuota!");

                break;

        case 3:
                if(head != NULL)
                   elim_testa(&head);
                else
                    printf("Lista vuota");
                break;

        case 4:
                if(head != NULL)
                {
                    printf("Inserie nome nodo precedente a quello da eliminare: ");
                    gets(nodo);
                    fflush(stdin);

                    punt = head;
                    esito = vista(&punt, nodo);

                    if(esito == 1 && punt ->p_next) //cioè se l'esito è positivo ed esist dopo un altro nodo
                        elim_nodo(&punt);
                    else
                        printf("Non trovato!");
                }
                else
                    printf("Vuota!");
                break;

        case 5:

                if(head!=NULL) //Ho almeno un elemento nella lista
                {
                    printf("*--- VISUALIZZA LISTA ---*\n\n");
                    visualizza_list(head);
                }
                else printf("Lista vuota!!\n");

                break;

        }


     }while(scelta != 6);
*/







    return 0;
}
