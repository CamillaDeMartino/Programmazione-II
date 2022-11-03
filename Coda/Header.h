#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

void enqueue(char , char [], int *);
void dequeue(int *, int *);

void enqueue_circ(char, char [], int *, int*, int);
void dequeue_circ( int *, int *);


typedef struct{
    char nome[20];
    }INFO_FIELD;

void *creaLista_sentinella();
void visualizza(void *p_punt);
void insl_nodo(int len_info, INFO_FIELD *p_dato, void **p_punt);
void elim_nodo(void *p_punt);


#endif // HEADER_H_INCLUDED
