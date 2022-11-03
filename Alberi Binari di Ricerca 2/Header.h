#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct tree {
        int valore;
        struct tree *sx, *dx;
}ALBERO;

void costruisci_albero_binario(ALBERO **, int  , int []);
int foglia(ALBERO *);
void visita_inorder(ALBERO *);

#endif // HEADER_H_INCLUDED
