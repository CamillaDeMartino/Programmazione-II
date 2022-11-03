#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    char nome[20];

} INFO_FIELD;

struct LISTA{

    INFO_FIELD info;
    struct LISTA *next;        //punta al prossimo nodo
    struct LISTA *before;      //punta al nodo precedente

};

struct LISTA *crealista_sentinella();
struct LISTA *cerca_nodo(struct LISTA *p_head1, struct LISTA *p_head2, char *nodo);
void inserisci_nodo (struct LISTA *prima, struct LISTA *dopo, INFO_FIELD Dati);
void elimina_nodo(struct LISTA *prima,struct LISTA *dopo);
void stampaLISTA (struct LISTA *head1, struct LISTA *head2); void stampaLISTA2 (struct LISTA *head1, struct LISTA *head2);
int main()
{
    /** Realizzare in C le funzioni per la gestione, mediante menù, della  lista
    bidirezionale mediante lista lineare dinamica e generica con [rispettivamente senza] nodo sentinella.
    **/


    int scelta, esito;
    INFO_FIELD dato;
    struct LISTA *head1, *head2, *punt;

    head1 = (struct LISTA*)crealista_sentinella();
    head2 = (struct LISTA*)crealista_sentinella();

    head1->next = head2;
    head2->before = head1;
    do{

        printf("*----------- ESEMPIO DI GESTIONE DI UNA LISTA LIENARE ------------*\n");
        printf("*[1] - Inserisci in testa alla lista                              *\n");
        printf("*[2] - Inserisci un elemento nel mezzo                            *\n");
        printf("*[3] - Elimina un elemento dalla testa                            *\n");
        printf("*[4] - Elimina un elemento dal nodo sucessivo                     *\n");
        printf("*[5] - Visualizza la lista dalla testa                            *\n");
        printf("*[6] - Visualizza la lista dalla coda                             *\n");
        printf("*[7] - Esci dal programma                                         *\n");
        printf("*-----------------------------------------------------------------*\n");
        printf("\nScelta: ");
        scanf(" %d", &scelta);
        fflush(stdin);

        switch(scelta){

        case 1:     printf("Inserisci il nome: ");
                    fflush(stdin);
                    gets(dato.nome);
                    inserisci_nodo(head1, head1->next,dato);
                    break;

        case 2:
                    printf("Inserie nome nodo precedente a quello da inserire: ");
                    fflush(stdin);
                    gets(dato.nome);
                    punt = cerca_nodo(head1->next,head2,dato.nome);  //Cerca nodo a partire dal successivo di sentinella1 fino a sentinella2


                    printf("Inserisci il nome:");
                    gets(dato.nome);
                    fflush(stdin);
                    inserisci_nodo(punt, punt->next,dato);
                    break;

        case 3:
                    if(head1->next != head2 && head2->before != head1)
                    elimina_nodo(head1, (head1->next)->next);  //[Sentinella]->[Nodo in testa da elim]->[Nodo succ] quindi
                    else
                    printf("Lista vuota");
                    break;

        case 4:
                    if(head1->next != head2 && head2->before != head1)
                    {

                    printf("Inserie nome nodo precedente a quello da eliminare: ");
                    gets(dato.nome);
                    fflush(stdin);

                    punt = cerca_nodo(head1->next,head2,dato.nome);

                    elimina_nodo(punt->before, punt->next);
                    }

                    else
                    printf("Lista vuota");
                    break;

        case 5:
                    printf("*--- VISUALIZZAZIONE LISTA DALLA TESTA ---*\n\n");
                    /* Controllo se la LISTA è vuota. Bastava una delle 2 espressioni, se vale una per forza vale l'altra */
                    if(head1->next==head2 && head2->before==head1)
                        puts("LISTA vuota");
                    else stampaLISTA(head1->next,head2);//visualizzare dalla testa
                    break;
        case 6:
                    printf("*--- VISUALIZZAZIONE LISTA DAL FONDO ---*\n\n");
                    /* Controllo se la LISTA è vuota.Bastava una delle 2 espressioni, se vale una per forza vale l'altra */
                    if(head1->next==head2 && head2->before==head1)
                        puts("LISTA vuota");
                    else stampaLISTA2(head1,head2->before);//visualizzare dal fondo
                    break;

        }

    }while(scelta != 7);

    return 0;
}


struct LISTA *crealista_sentinella()
{
    struct LISTA *head;

    head = (struct LISTA *)calloc(1,sizeof(struct LISTA));
    return head;
};


/*  inserisci_nodo: Questa function adatta per le liste bidirezionali, ha il compito di inserire
    un nuovo nodo tra 2 nodi individuati da 2 puntatori: prima e dopo.
    Agganciato il nuovo nodo tra prima e dopo, i nodi prima e dopo dovranno essere agganciati a loro
    Volta al nuovo nodo creato. */

void inserisci_nodo (struct LISTA *prima, struct LISTA *dopo, INFO_FIELD Dati)
{
    struct LISTA *ptr;

    ptr = (struct LISTA*)calloc(1,sizeof(struct LISTA));

    ptr->info = Dati;
    ptr->next = dopo;
    ptr->before = prima;

    prima->next = ptr;
    dopo->before=ptr;
}


struct LISTA *cerca_nodo(struct LISTA *p_head1, struct LISTA *p_head2, char *nodo)
{
    struct LISTA *p_punt;

    p_punt = p_head1;

    while(p_head1->next != p_head2)
    {
        if(strcmp((*p_punt).info.nome, nodo) == 0)
            return p_punt;

        p_punt = p_punt->next;
    }
}

void elimina_nodo(struct LISTA *prima,struct LISTA *dopo)
{
    struct LISTA *libera;

    libera = prima->next;
    prima->next = dopo;     //aggangia il nodo predecessore a quello dopo il nodo corrente
    dopo ->before = prima;

    free(libera);
}

void stampaLISTA (struct LISTA *head1, struct LISTA *head2)
{
    struct LISTA *punt;
    int i=1;
    punt=head1; /* Se punt punta alla sentinella2, la visita e' finita*/

    while(punt!=head2)
    {
        printf("\n%d NOME = %s\t \n",i, punt->info.nome);
        i++;
        punt=punt->next;
    }
}
 void stampaLISTA2 (struct LISTA *head1, struct LISTA *head2)
 {
     struct LISTA *punt;
     int i=1;
     punt=head2; /* Se punt punta alla sentinella1, la visita e' finita*/

     while(punt!=head1)
    {
        printf("\n%d NOME = %s\t \n",i,punt->info.nome);
        i++;
        punt=punt->before; /* precedente */
    }
 }
