#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct{

    char nome[20];
    int eta;
}INFO_FIELD;


struct Persona{

    INFO_FIELD info;
    struct Persona *p_next;

};

struct Persona *crea_lista();
int vista(struct Persona **, char []);
void insl_testa(INFO_FIELD, struct Persona **);
void insl_nodo(INFO_FIELD, struct Persona **);
void elim_testa(struct Persona **);
void elim_nodo(struct Persona **);
void visualizza_list(struct Persona *);
#endif // HEADER_H_INCLUDED
