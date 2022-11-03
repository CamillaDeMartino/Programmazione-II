#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 20


typedef struct Persona {
    char Nome[MAX_NAME];
    short Eta;
    }PERSONA;
    /* Prototipi */
    void Inserisci_Struct(PERSONA Vet_ite[], PERSONA Vet_ric[], short N);
    void Stampa_Struct(PERSONA Vet[], short N);
    void selection_sort_Ite(PERSONA Vet[], short N);
    void selection_sort_Ric(PERSONA Vet[], short N);
    short Min(PERSONA Vet[], short N);
    void Scambia(PERSONA *a, PERSONA *b);
int main()
{
    PERSONA *Vet_ite, *Vet_ric;
    short N; puts("*---- SELECTION SORT ITERATIVO E RICORSIVO CON SCAMBI REALI ----*");
    /*____ INPUT ____*/
    puts("Inserire la lunghezza N della struttura:\n");
    scanf("%hd", &N);
    Vet_ite = (PERSONA *) malloc(sizeof(PERSONA)*N);
    Vet_ric = (PERSONA *) malloc(sizeof(PERSONA)*N);
    /* Per comodita', inserisco i valori in ambo i vettori */
    Inserisci_Struct(Vet_ite, Vet_ric, N); /* ORDINA */
    selection_sort_Ite(Vet_ite, N);
    selection_sort_Ric(Vet_ric, N);

    printf("\nORDINAMENTO PER NOME...\n\n");
    printf("ORDINAMENTO REALE CON SELECTION SORT ITERATIVO\n");
    Stampa_Struct(Vet_ite, N);
    printf("ORDINAMENTO REALE CON SELECTION SORT RICORSIVO\n");
    Stampa_Struct(Vet_ric, N);
    printf("\n");
    return 0;
}



void Inserisci_Struct(PERSONA Vet_ite[], PERSONA Vet_ric[], short N)
{
    short i, eta;
    char nome[MAX_NAME];
    for(i=0;i<N;i++)
    {
    printf("STRUCT N°%hd \n", i+1);
    printf("Inserisci nome :");
    fflush(stdin);
    gets(nome);

    printf("Inserisci eta :");
    fflush(stdin);
    scanf("%hd", &eta);
    /* Copia le info nei 2 vettori struct */
    strcpy(Vet_ite[i].Nome, nome);
    strcpy(Vet_ric[i].Nome, nome);
    Vet_ite[i].Eta=eta;Vet_ric[i].Eta=eta;
    }
}

void Stampa_Struct(PERSONA Vet[], short N)
{ short i;
for(i=0;i<N; i++)
printf("Nome: %s \n Eta: %hd\n\n", Vet[i].Nome, Vet[i].Eta);
}

void selection_sort_Ite(PERSONA Vet[], short N)
{
    short i, i_Min;
    for(i=0; i<N-1; i++)
    {
        i_Min = Min(&Vet[i], N-i);
        Scambia(&Vet[i], &Vet[i_Min+i]);
    }

}

short Min(PERSONA Vet[], short N)
{
    short i=0, i_min; i_min = i;
    for(i=1; i<N; i++)
        if(strcmp(Vet[i].Nome, Vet[i_min].Nome)<0 )
        i_min=i;
    return i_min;
}


void Scambia(PERSONA *a, PERSONA *b)
{
    PERSONA tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
void selection_sort_Ric(PERSONA Vet[], short N)
{
    short i_Min;
    if(N == 1)
        return Vet;
    i_Min = Min(Vet, N);
    Scambia(Vet, &Vet[i_Min]);
    selection_sort_Ric(Vet+1, N-1);
}
