#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct tree {
        int valore;
        int esiste;
}ALBERO;

void costruisci_albero_binario( ALBERO [], int, int []);
void visita_inorder(ALBERO [], int , int );
#endif // HEADER_H_INCLUDED
