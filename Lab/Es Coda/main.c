#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#define Max_size 5
int main()
{
    /** Simulare in C la gestione di una coda(queue) tramite array statico creando le funzioni di manipolazione
        enqueue()[inserimento] e dequeue()[eliminazione].
        Il programma deve prevedere un menù che consenta di scegliere l’operazione da eseguire. Le informazioni NON vanno spostate!  **/


        /* NB non e' il miglior modo, dato che non posso sfruttare le eliminazioni lasciate da TESTA
                (SOLUZIONE?ARRAY CIRCOLARE!) */


        char ch, temp[Max_size];
        int top = 0, bottom = 0;
        int scelta;

        do{
            printf("Scegliere un operazione:\n[1]Inserimento\n[2]Eliminazione\n[3]Esci\n");
            scanf(" %d", &scelta);

            switch(scelta){
                case 1:
                    printf("Inserire carattere: ");
                    scanf(" %c", &ch);
                    enqueue(ch, temp, &bottom);
                    break;

                case 2:
                    dequeue(&top, &bottom);
                    break;
            }

            for(int i = top; i < bottom; i++ )
                printf("[%c]\n", temp[i]);

        }while(scelta != 3);





        /**ARRAY CIRCOLARE**/

        /**Simulare in C la gestione di una coda(queue) tramite array statico circolare creando le funzioni
            di manipolazione enqueue() [inserimento] e dequeue()[eliminazione].
            Il programma deve prevedere un menù che consenta di scegliere l’operazione da eseguire. **/

/*
      int testa = 0;
      int fondo = 0;
      int numelem = 0;
      char ch, temp[Max_size];
      int scelta;


        do{
            printf("Scegliere un operazione:\n[1]Inserimento\n[2]Eliminazione\n[3]Esci\n");
            scanf(" %d", &scelta);

            switch(scelta){
                case 1:
                    printf("Inserire carattere: ");
                    scanf(" %c", &ch);
                    enqueue_cir(ch, temp, &fondo, &numelem, testa );
                    break;

                case 2:
                    dequeue_cir(&testa, &numelem);
                    break;
            }


            for(int i = numelem-1; i >=0 ; i-- )
                printf("[%c]\n", temp[i]);

        }while(scelta != 3);

        */

    return 0;
}
