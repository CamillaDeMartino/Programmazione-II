#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

void push_s(char, char [], int *);
void pop_s(int *);

typedef struct{

    char nome[20];
    int eta;

}INFO_FIELD;
char *crea_lista();
void visualizza(void *);
void insl_nodo(int, INFO_FIELD *, void *);
void elim_nodo(void *);
#endif // HEADER_H_INCLUDED
