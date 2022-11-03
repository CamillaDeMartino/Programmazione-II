#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define MAX_GRADO 4
///struttura input
typedef struct {
    char nome[20];
    int padre; /* Indice che individua il padre*/
}nodo;


///struttura output
typedef struct {
    char nome[20];
    int grado;                  /* Numero di figli per quel nodo */
    int figlio[MAX_GRADO];       /* Gli indici ai figli. Punta al iesimo figlio */

}nodo_link;

void azzera_grado (nodo_link link[]);
void azzera_grado (nodo_link link[]);
void costruisci_albero(nodo_link [],nodo [],int * );
void visita_livelli (nodo_link [], int );
void enqueue (nodo_link , int *, nodo_link []);
void dequeue (int *,nodo_link [],nodo_link *,int );



#endif // HEADER_H_INCLUDED
