#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {

    char nome[20];
    short eta;
}INFO_FIELD;

struct PERSONA{
    INFO_FIELD info;
    struct PERSONA *p_next;

};


struct PERSONA *crea_lista();
void insl_testa (INFO_FIELD Dati, struct PERSONA **head);
void insl_nodo (INFO_FIELD Dati, struct PERSONA **punt);
 void visualizza (struct PERSONA *head);
 void elim_nodo (struct PERSONA **punt);
 void elim_testa (struct PERSONA **head);
 int cerca_nodo (struct PERSONA **punt, char nodo[]);

int main()
{

    /** Realizzare la gestione di una lista lineare mediante menù:
        visualizzazione mediante visita,
        inserimento in testa,
        inserimento in mezzo,
        e eliminazione in testa, eliminazione in mezzo.
        Implementare la lista lineare con una struttura autoriferente dinamica. **/

        struct PERSONA *head, *punt;
        INFO_FIELD nuovodato;
        char scelta, nodo[20];
        int esito;

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
            scanf(" %c", &scelta);
            fflush(stdin);

            switch(scelta){
            case '1':
                        printf("Inserire Nome: ");
                        gets(nuovodato.nome);
                        fflush(stdin);
                        printf("Inserisci Eta: ");
                        scanf(" %d", &nuovodato.eta);
                        insl_testa(nuovodato, &head);
                        break;

            case '2':
                        if(head != NULL)
                        {
                          printf("Inserie nome nodo precedente a quello da inserire: ");
                          gets(nodo);
                          fflush(stdin);

                          punt = head; //serve per non perdere la testa
                          esito = cerca_nodo(&punt, nodo);

                          if(esito == 1)
                          {
                            printf("Inserire Nome: ");
                            gets(nuovodato.nome);
                            printf("Inserisci Eta: ");
                            scanf(" %d", &nuovodato.eta);
                            insl_nodo(nuovodato, &punt);
                          }
                          else
                            printf("Nodo non trovato!\n");
                        }
                        else
                            printf("Lista vuota!\n");

                        break;

            case '3':
                        if( head != NULL)
                            elim_testa(&head);
                        else
                            printf("Lista vuota!\n");

                        break;

            case '4':
                        if( head != NULL)
                        {
                          printf("Inserie nome nodo precedente a quello da eliminare: ");
                          gets(nodo);
                          fflush(stdin);

                          punt = head; //serve per non perdere la testa
                          esito = cerca_nodo(&punt, nodo);

                          if(esito == 1 && punt -> p_next)   //se nodo e' stato trovato e non e' l'ultimo
                          {                                  //l'ultimo nodo punta a null: Quindi non posso eliminare l'elemento successivo puntato dall'ultimo nodo (sarebbe NULL)
                            elim_nodo(&punt);
                          }
                          else
                            printf("Nodo non trovato!\n");
                        }
                        else
                            printf("Lista vuota!\n");

                        break;

            case '5':
                        if(head!=NULL) //Ho almeno un elemento nella lista
                        {
                            printf("*--- VISUALIZZA LISTA ---*\n\n");
                            visualizza(head);
                        }
                        else printf("Lista vuota!!\n");

                        break;


            }

        }while(scelta != '6');

    return 0;
}


struct PERSONA *crea_lista()
{
    struct PERSONA *testa;
    testa = NULL;
    return testa;
}


void insl_testa(INFO_FIELD dato, struct PERSONA **p_head)
{
    struct PERSONA *ptr;  //puntatore al nuovo nodo

    ptr = calloc(1,sizeof(struct PERSONA)); //Richiediamo di allocare un nuovo nodo di grandezza persona
    ptr -> info = dato;                     //Inserisci dati; (*ptr).info
    ptr -> p_next = *p_head;                //Head contiene l'indirizzo del nodo in testa
    *p_head = ptr;                          //aggangia testa al nuovo nodo
}

int cerca_nodo(struct PERSONA **punt, char nodo[])
{
    while( *punt != NULL)
    {
        if(strcmp( (*punt)->info.nome, nodo) == 0)
        return 1;
        *punt=(*punt)->p_next; //punt punterà al nodo trovato
    }
    return 0;

}

void insl_nodo(INFO_FIELD dato, struct PERSONA **p_punt)
{
    struct PERSONA *ptr;

    ptr = (struct PERSONA *)calloc(1, sizeof(struct PERSONA));    //Richiediamo di allocare un nodo di grandezza persona
    ptr -> info = dato;                         //Inserisci dati; (*ptr).info
    ptr -> p_next = (*p_punt) -> p_next;        // Aggancia il nuovo nodo al successivo di punt
    (*p_punt)->p_next = ptr;                    //* Aggancia il nodo considerato a punt al nuovo nodo */
    *p_punt = ptr;                              //aggiorna punt al nodo corrente
}

void elim_testa( struct PERSONA **head)
{
    struct PERSONA *libera;
    libera = *head;
    *head = (*head)->p_next;

    free(libera);  //libero la memoria dove prima c'era l'elemento da eliminare
}

void elim_nodo(struct PERSONA **punt)
{
    struct PERSONA *libera;
    libera = (*punt) -> p_next;                  //libera il nodo successivo a quello puntato
    (*punt) -> p_next= ((*punt) -> p_next)->p_next;   //salta al nodo successivo a quello eliminato

    free(libera);
}


void visualizza(struct PERSONA *head)
{
    //visita
    do
        {
            printf(" Nome: %2s % \n Eta : %2hd\n\n", head->info.nome, head->info.eta);
            head=head->p_next;

        }while(head!=NULL);
}
