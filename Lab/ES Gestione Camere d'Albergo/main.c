#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Camera{

    char cliente[20];
    int info;
    int pnext;

}CAMERA;


void check_in(CAMERA [], short *, short *, char *);
void check_out(CAMERA[], short*, short *, char *);
void Visualizza_Prenotati(CAMERA[], short);

int main()
{
    /** Simulare in C la gestione delle camere di un albergo mediante liste lineari
        rappresentate su un array di struct:
        i principali campi sono le informazioni (numero di camera, cliente, etc.)
        ed i link(puntatori ai nodi della lista) **/



        CAMERA ListaLibera[9] = {{" ", 1, 1}, {" ", 2, 2}, {" ", 3, 3}, {" ", 4, 4}, {" ", 5, 5},
                                 {" ", 6, 6}, {" ", 7, 7}, {" ", 8, 8}, {" ", 9, -1}};
        char nome[20];
        char scelta;
        short p_libera = 0, p_dati = -1;    //p_libera puntatore alla testa di ListaLibera(camere libere) che è piena
                                            //p_dati puntatore alle testa di ListaDati(camere occupate) che è vuota (-1 indica la fine)

        do{
            printf("\n*---- GESTIONE CAMERE ALBERGO -----*\n");
            printf("*[1] - Inserisci Prenotazione      *\n");
            printf("*[2] - Elimina Prenotazione        *\n");
            printf("*[3] - Visualizza clienti prenotati*\n");
            printf("*[4] - Esci                        *\n");
            printf("*----------------------------------*\n");
            printf("\nScelta: ");
            scanf(" %c", &scelta);
            fflush(stdin);

            switch(scelta){

                case '1':
                        if(p_libera != -1)
                        {
                            printf("Inserisci il nome del cliente: ");
                            gets(nome);
                            printf("\n");
                            check_in(ListaLibera, &p_libera, &p_dati, nome );
                        }
                        else
                            printf("\n\nTUTTE CAMERE OCCUPATE\n\n");
                         break;

                case '2':
                        if(p_dati != -1)
                        {
                           printf("Inserisci il nome del cliente da eliminare: ");
                            gets(nome);
                            printf("\n");
                            check_out(ListaLibera, &p_libera, &p_dati, nome );
                        }
                        else
                            printf("\n\nLIBERA\n\n");
                         break;

                case '3':

                        if(p_dati!=-1)
                        {
                            printf("Le camere prenotate dai clienti\n[Numero stanza, Nome  Cliente]:\n");
                            Visualizza_Prenotati(ListaLibera, p_dati);
                        }
                        else
                            printf("\nNessun cliente\n");
                        break;

            }
            fflush(stdin);
        }while(scelta != '4');


    return 0;
}


/*_____________________ Inserisci_Prenotazione ______________________
 Viene inserito il cliente in ListaDati.
 Quando si deve inserire un cliente:
  - salviamo la testa di ListaDati
  - facciamo puntare p_dati alla nuova testa presa da p_libera
  - inseriamo informazioni al nuovo nodo
  - p_libera puntera' al suo successivo
  - facciamo il link del nuovo nodo aggiunto a p_dati iniziale */

void check_in(CAMERA ListaLibera [], short *p_libera, short *p_dati, char *nome)
{
    short temp = *p_dati;       /* Inizialemente conterra la testa di ListaDati .
                                   Quando avro' la nuova testa p_dati(rubato da p_libera), mi servira'
                                   per agganciare la nuova testa a quella vecchia, cioe' temp*/

    /* Aggiungi in testa a ListaDati (p_dati puntera' a p_libera, precedentemente modificato */
    (*p_dati) = (*p_libera);                     //p_dati puntera' alla nuova testa di ListaLibera


    strcpy(ListaLibera[*p_dati].cliente, nome);  //copio il nome inserito nella struct di ListaDati

    *p_libera = ListaLibera[*p_libera].pnext;    //p_livera punta al successivo

    ListaLibera[*p_dati].pnext = temp;           //agganciala nuova testa a quella vecchia salvata
}



/*_____________________ Elimina_Prenotazione ______________________
    Viene eliminato il cliente in ListaDati.
    Si hanno 2 casi: eliminazione in testa e eliminazione in mezzo.
     Se l'eliminazione e' in testa, ossia l'elemento da eliminare e' la testa della ListaDati.

     PRIMO CASO: - salvo l'indice della testa
                 - Punta al successivo della testa
                 - aggancia il nodo scartato da p_libera
                 - egli di venta la nuova p_libera

    SECONDO CASO: - Salviamo l'indice della camera successiva a p_dati
                  - Scavalca temp1, agganciando p_dati al successivo di temp
                  - Aggancia il nodo eliminato alla testa di ListaLibera
                  - Fai diventare egli la nuova testa di lista libera */

void check_out(CAMERA Listalibera[], short *p_libera, short *p_dati, char *nome)
{
    short temp1;
    short temp2 = *p_dati;

    if(strcmp(Listalibera[*p_dati].cliente, nome)== 0)
    {
        temp1 = *p_dati;
        *p_dati = Listalibera[*p_dati].pnext;
        Listalibera[temp1].pnext = *p_libera;
        *p_libera = temp1;
    }
    else
    {
        while(Listalibera[temp2].pnext != -1)
        {
            if(strcmp(Listalibera[Listalibera[temp2].pnext].cliente, nome)==0)
            {
                /* Salviamo l'indice della camera successiva a p_dati*/
                 temp1 = Listalibera[temp2].pnext;

                /* Scavalca temp1, agganciando p_dati al successivo di temp1 */

                Listalibera[temp2].pnext = Listalibera[temp1].pnext;

                /* Aggancia il nodo eliminato alla testa di ListaLibera */

                Listalibera[temp1].pnext = *p_libera;

                /* Fai diventare egli la nuova testa di lista libera*/

                *p_libera = temp1;
            }

        temp2 = Listalibera[temp2].pnext;
        }
    }
}


void Visualizza_Prenotati(CAMERA Listalibera[],short p_dati)
{
    printf("\n");
    printf("\t");
    while(p_dati!= -1)
    {
        printf("[%hd, %s]\n ", Listalibera[p_dati].info, Listalibera[p_dati].cliente);
        p_dati = Listalibera[p_dati].pnext;

    }
}
