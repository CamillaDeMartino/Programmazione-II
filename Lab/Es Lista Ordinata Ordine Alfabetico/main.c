#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Lista
{
    char nome[20];
    struct Lista *p_next;
};
 struct Lista *crea_lista();
 void lista_ordinata(struct Lista **head, char *elenco[]);
 void insl_testa(char *testo, struct Lista **head);
 void insl_nodo(char *testo, struct Lista **punt);
 void visualizza(struct Lista *head);
int main()
{
    /** Scrivere una function C per costruire una lista ordinata in ordine alfabetico
         a partire da un elenco di nomi in ordine casuale, come nel seguente. **/

            char *elenco[]={ "Anna","Mario","Giuseppe","Angela","Valeria","Fabrizio",   //uso l'array frastagliato
                             "Marianna","Giovanni","Patrizia","Valentina","Sara" };


            struct Lista *head;

            head = crea_lista();

            printf("\n****LISTA ORDINATA****\n");
            lista_ordinata(&head, elenco);
            visualizza(head);

    return 0;
}

struct Lista *crea_lista()
{
    struct Lista *head;
    head = NULL;
    return head;
}

void lista_ordinata(struct Lista **head, char *elenco[])
{
    int esito, i = 0;
    struct Lista  *punt;
    struct Lista  *prec;

    insl_testa(elenco[i], head);   //inserisci il primo elemento;
    i++;

    for(i = 1; i < 11; i++)         //i parte da 1 perchè abbiamo gia inserito un nome/elemento
    {
        punt = *head;
        esito = strcmp(elenco[i], (*head)->nome);

        if(esito == -1)                     //strcmp restituirà zero se le stringhe sono identiche,
        {                                  //altrimenti darà un numero positivo se la prima stringa è maggiore della seconda,
           insl_testa(elenco[i], head);   // altrimenti restituirà un valore negativo.
        }
        else
        {
            prec = *head;           //salvo il precedente (mi serve per l'inserimento in mezzo)
            punt = punt->p_next;    //avanzo punt perche' gia' ho considerato con l'if il primo nodo

            while(punt != NULL && esito != -1)   //esito = -1 significa che ha inserito
            {
                esito = strcmp(elenco[i], punt->nome);
                if(esito == -1)
                    insl_nodo(elenco[i], &prec);
                else if(punt -> p_next == NULL)   //se il prossimo ndo è NULL, inserisco in coda
                    insl_nodo(elenco[i], &punt);

                    prec = punt;
                    punt = punt -> p_next;
            }


        }

    }
}

void insl_testa(char *testo, struct Lista **head)
{
    struct Lista *ptr;

    ptr = (struct Lista *)calloc(1,sizeof(struct Lista));
    strcpy(ptr -> nome, testo);
    ptr -> p_next = *head;
    *head = ptr;
}


void insl_nodo(char *testo, struct Lista **punt)
{
    struct Lista *ptr;

    ptr = (struct Lista *)calloc(1, sizeof(struct Lista));
    strcpy(ptr -> nome, testo);
    ptr -> p_next = (*punt) -> p_next;
    (*punt) ->p_next = ptr;
    *punt = ptr;
}


void visualizza(struct Lista *head)
{
    do{

        printf("Nome: %s\n", head->nome);
        head = head ->p_next;
    }while(head != NULL);
}
