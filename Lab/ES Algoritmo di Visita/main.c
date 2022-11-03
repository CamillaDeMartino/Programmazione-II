#include <stdio.h>
#include <stdlib.h>

typedef struct Persona
{
    char nome[20];
    int next;
}PERSONA;

int main()
{
   /**  Simulare in C l’algoritmo di visita di una lista lineare gia’ memorizzata mediante
        un array statico di struct in cui il primo campo contiene l’informazione ed
        il secondo contiene il link al nodo successivo (in questo caso il link è l’indice di una componente dell’array).
        Memorizzando nell’array i dati come mostrato nella figura che segue, l’output del programma consiste
        nell’elenco di nomi ordinato alfabeticamente.**/

        int p_testa = 3;

        PERSONA vettore[] = {{"Anna",5},{"Mario", 8},{"Giuseppe", 6},
                             {"Angela", 0},{"Valeria", -1},{"Fabrizio", 7},
                             {"Marianna", 1},{"Giovanni", 2}, {"Patrizia", 10},
                             {"Valentina",4},{"Sara",9}};

        while(p_testa != -1)
        {
            printf(" %s\n", vettore[p_testa].nome);
            p_testa = vettore[p_testa].next;
        }
    return 0;
}
