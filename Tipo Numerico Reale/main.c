#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int main()
{
    /** Scrivere una function C per visualizzare la rappresentazione binaria (s,e,m) di un numero float.
        Verificare che il valore del numero ottenuto coincida con il dato iniziale**/

        /*  Utilizziamo la UNION perche' abbiamo la necessita' di prendere
            da input un valore float, ma all'interno della funzione "ESTRAI_SEM",
            dobbiamo lavorare in valore interi.
            f ed i, sono 2 tipi diversi che condividono la stessa area di memoria     */



            union fl_int
            {
                float x;
                int n;
            }f;

            printf("Inserisci un float: ");
            scanf("%f", &f.x);

            char bit[32];
            float verifica;

            verifica = estrarre_sem(f.n, bit);

            printf("Segno\tEsponente\tMantissa");
            printf("\n%d",bit[0]);
            printf("  ");

            for(int i = 1; i < 9; i++)
                printf("%d", bit[i]);
            printf("  ");

            for(int i = 9; i < 32; i++)
                printf("%d", bit[i]);

            printf("\n\nVERIFICA\nApplicando (-1)^s*(l.m)*b^(e-bias), avremo: %.3f \n", verifica);


    return 0;
}
