#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
 {
      char nome[20];

 }INFO_FIELD;

 /* PROTOTIPI */
void *crealista_sentinella();
void *cerca_lista(void *p_head, char *buffer);
void *cerca_lista_p(void *head, char *buffer);
int is_testa(void *p_head, char *buffer);
void elim_nodo(void *p_punt);
void visita(void *punt, void *head);
void insl_nodo(short len_info, INFO_FIELD *p_dato, void *p_punt);


int main()
{
    /**Realizzare in C le funzioni per la gestione, mediante menù, delle strutture dati LISTA CIRCOLARE
     mediante LISTA lineare dinamica e generica con nodo sentinella.**/

     /* dichiarazione della LISTA */

    struct LISTA {
        INFO_FIELD info;
        struct LISTA *next;
        struct LISTA *before;
        };

    char buffer[20];
    int scelta, esito;
    struct LISTA *head,*punt, *old_punt;
    INFO_FIELD dato;

    head = (struct LISTA *)crealista_sentinella(); //Creazione nodo sentinella di testa
    head->next = head; // agganciamo la sentinella 1a se stessa

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

                insl_nodo(sizeof(dato), &dato, (void *)head); /* Dato che vuole inserire in testa, gli passo heado cosÃ¬ inserisce dopo il nodo  sentinella */
                break;

        case 2:
                if(head != NULL) //se non è vuota
                {
                   printf("Inserie nome nodo precedente a quello da inserire: ");
                   gets(buffer);
                   fflush(stdin);

                   punt = cerca_lista((void *)head, buffer);

                   if(punt != NULL)
                   {
                     printf("Inserisci il nome:");
                     gets(dato.nome);
                     fflush(stdin);
                     insl_nodo(sizeof(dato), &dato, (void *)punt);
                   }
                   else
                    printf("Nodo non trovato!");

                }
                else
                    printf("Lista vuota!");

                break;

        case 3:
                if(head != NULL)
                   elim_nodo((void *)head);
                else
                    printf("Lista vuota");
                break;

        case 4:
                if(head != NULL)
                {
                    printf("Inserie nome nodo precedente a quello da eliminare: ");
                    gets(buffer);
                    fflush(stdin);

                    /* Controlla se l'elemento da eliminare e' in testa. In tal caso attiviamo l'altra function.
                    PS head punta al nodo sentinella, head->next al primo nodo info */

                    esito = is_testa((void *)head->next, buffer);

                    if(esito == 1 ) //cioè il nodo è il primo della lista
                        printf("Utilizzare l'opzione 3");
                    else
                        printf("Non trovato!");
                }
                else
                    /* Se non e' in testa, ricavati il precedente. Da lui ti elimini il  successivo, ossia il nodo interessato */

                    old_punt = cerca_lista_p((void *)head, buffer);
                    if (old_punt == NULL)
                        printf("\nDato non trovato nella lista\n");
                    else
                        elim_nodo((void *)old_punt);
                break;

        case 5:

                if(head->next == head) //se punta alla cima
                    printf("Lista vuota!!\n");

                else
                {
                     printf("*--- VISUALIZZA LISTA ---*\n\n");
                    visita((void*) punt ,(void*)head);
                }
                break;

        }



    }while(scelta != 6);

    return 0;
}

void *crealista_sentinella()
{
    struct lista
    {   INFO_FIELD info;
        struct lista *p_next;
    };

    struct lista *testa; /* il tipo non importa, nel main ho il cast */

    testa = (struct lista *) calloc(1,sizeof(struct lista)); //testa->p_next=NULL; con calloc posso evitare tale istruzione return testa;
}

/*     insl_nodo: inserisce dato dopo nodo corrente.
        Crea il nodo nuovo e lo inserisce
        dopo il nodo puntato da p_punt o head (quindi inserirebbe in testa) */
void insl_nodo(short len_info, INFO_FIELD *p_dato, void *p_punt)
{
    struct lista {
        INFO_FIELD info;
        struct lista *p_next;
    } *ptr; /* Crea nodo e inserisci le info con la memcpy*/


    ptr = calloc(1, sizeof(struct lista));

    if (ptr == NULL)
    printf("\nAllocazione del nodo non riuscita\n");
    else
    {
        memcpy(ptr, p_dato, len_info); /* Aggancia ptr al successivo di p_punt o phead */
        ptr->p_next = ((struct lista *)p_punt)->p_next; /* Aggancia p_punt al nuovo nodo*/
        ((struct lista *)p_punt)->p_next = ptr; //*p_punt = ptr;    Non mi serve a niente ricordare dove sia avvenuto l'inserimento
    }
}

/*     Eliminazione nodo: Viene effettuata una visita sulla lista e appena viene trovato il nodo  da eliminare */

void elim_nodo(void *p_punt)
{
    struct lista {
        INFO_FIELD info;
        struct lista *p_next;
    } *ptr;

    ptr = ((struct lista*)p_punt)->p_next; /* Punt->next, sara' il successivo del suo successivo */
    ((struct lista*)p_punt)->p_next = ptr->p_next;
    free(ptr); //libera heap

}

/*
    cerca_lista: Tale function si occupa di restituire il puntatore al nodo che possiede
     il campo info uguale a quello della chiave buffer (stringa da cercare ad esempio) */

void *cerca_lista(void *p_head, char buffer[])
{
    struct lista {
        INFO_FIELD info;
        struct lista *p_next;
        } *punt;

    punt = p_head;

    while(punt->p_next != p_head)
    { /* se strcmp restituisce 0, e' ok*/
        if ( !strcmp((*punt).info.nome, buffer) )
        return punt;

        punt = punt->p_next;
    } /* Il ciclo uscire ad un nodo prima, però punt sara' avanzato e controlliamo per l'ultima  volta*/

    if ( !strcmp((*punt).info.nome, buffer) )
        return punt; //Eccolo: Era l'ultimo!
    else
        return NULL; //NON HO TROVATO NIENTE
}


/* cerca_lista_p: Tale function si occupa di restituire il puntatore PRECEDENTE al nodo che possiede
   il campo info uguale a quello della chiave buffer (stringa da cercare ad esempio), tale che
   possiamo effettuare l'eliminazione in mezzo. La particolarita' di questa function e' quello di
   SALVARE il puntatore "VECCHIO", prima che venga aggiornato.
   PS La function e' adatta per cercare in mezzo, ma non in testa perche' non avrebbe l'opportunita'
   di salvare il precedente (nel main abbiamo un dovuto controllo*/

void *cerca_lista_p(void *p_head, char buffer[])
{
    struct lista {
        INFO_FIELD info;
        struct lista *p_next;
        } *punt, *prec;

    punt = p_head;

    while(punt->p_next != p_head)
    { /* se strcmp restituisce 0, e' ok*/
        if ( !strcmp((*punt).info.nome, buffer) )
        return prec; //resitituisci il predecessore

        prec = punt;
        punt = punt->p_next;
    } /* Il ciclo uscire ad un nodo prima, però punt sara' avanzato e controlliamo per l'ultima  volta*/

    if ( !strcmp((*punt).info.nome, buffer) )
        return prec; //Eccolo: Era l'ultimo!
    else
        return NULL; //NON HO TROVATO NIENTE
}

int is_testa(void *p_head, char *buffer)
{
    struct lista
    {
        INFO_FIELD info;
        struct lista *p_next;
    } *punt; punt = p_head;

    /* se strcmp restituisce 0, e' ok*/
    if ( !strcmp((*punt).info.nome, buffer) )
        return 1;
    else
        return 0; //NON HO TROVATO NIENTE
}

/* visita la lista a partire dalla testa.
    Quando un nodo ripuntera' alla testa, si ferma. */

void visita(void *punt, void *head)
{
    struct lista {
        INFO_FIELD info;
        struct lista *p_next;
        } *ptr;

    ptr = punt;
    int i=1;

/* Essendo una lista circolare, se il prossimo riparte dalla testa si ferma*/
while (ptr != head)
{
    printf("%d NOME = %s \t\n", i++, (*ptr).info.nome);
    ptr = ptr->p_next;
}
}
