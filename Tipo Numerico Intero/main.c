#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int main()
{
    /**CAMBIAMENTO DI BASE**/


    /** Scrivere due function C di conversione di un intero positivo (int) da base 10 a base 2
        mediante l’ algoritmo delle divisioni successive realizzato rispettivamente:
        - Usando gli operatori di quoziente e resto della divisione intera;
        - Usando gli operatori bitwise. **/

/*
        unsigned char num;
        unsigned char bit[8];

        printf("Inserisci il numero da convertire in binario: ");
        scanf("%d", &num);

        printf("\nStampa con algortimo divisioni\n");
        char_bit_division(num,bit);
        stampa_bit(bit);
        printf("\nStampa con bitwise\n");
        op_bitwise(num,bit);
        stampa_bit(bit);

        */



        /** Scrivere una function C di conversione di un intero positivo da base 2 a base 10
            che generi un array di caratteri contenenti le cifre decimali.**/
/*

        unsigned char num, bit[8], array[8];
        short lunghezza = 0;

        printf("Inserisci il numero da convertire in binario: ");
        scanf(" %d", &num);

        printf("Numero in binario:\n");
        char_bit_division(num, bit);
        stampa_bit(bit);
        printf("\n");

        lunghezza = conversione_array(bit, array);

        for(int i = lunghezza - 1; i >= 0; i--)
            printf("[%d]\n", array[i]);


            */


        /**Ripetere l’esercizio precedente nel caso che l’input sia una stringa di caratteri contenenti i bit del numero.**/
/*
        int i;
        short len;
        unsigned char bit[8], array[8], n;

        for(i = 7; i >= 0; i--)
        {
            printf("Inserire il bit[%d]: ", -(i-7));
            scanf(" %d", &n);
            bit[i] = n;
        }

        len = conversione_array(bit,array);
        for(int i = len - 1; i >= 0; i--)
            printf("[%d]\n", array[i]);

            */



            /**OPERAZIONI ARITMETICHE CON BITWISE**/


        /**Scrivere una function C per eseguire l'addizione aritmetica in base 2 mediante gli operatori bitwise.**/

/*
        int op1,op2, somma;

        printf("Inserire il primo operatore: ");
        scanf(" %d", &op1);
        printf("Inserire il secondo operatore: ");
        scanf(" %d", &op2);

        somma = addizione_aritmetica(op1,op2);

        printf("%d + %d = %d", op1, op2, somma);

        */


        /**Scrivere una function C per eseguire la sottrazione aritmetica in base 2 mediante gli operatori bitwise. **/
/*
        int op1,op2, sottr;

        printf("Inserire il primo operatore: ");
        scanf(" %d", &op1);
        printf("Inserire il secondo operatore: ");
        scanf(" %d", &op2);

        sottr = sottr_aritmetica(op1, op2);

        printf("%d - %d = %d", op1, op2, sottr);

        */




        /**COMPLEMENTO A 2 E BIASED**/


        /**Scrivere una function C che, fissato il numero n di bit, calcoli la rappresentazione di un intero:
            -per complemento a 2;
            -per eccesso B (B-biased) **/
/*
            int n_bit, num;
            int complemento, biased;

            printf("Fissa un numero di bit: ");
            scanf("%d", &n_bit);

            printf("Inserire il numero: ");
            scanf("%d", &num);

            complemento = complemento_a2(n_bit, num);

            if(complemento > 0)
                printf("Rappresentazione per complemento a 2: %d", complemento);
            else
                printf("Fuori range");
            printf("\n");
            biased = rapp_biased(n_bit, num);

             if(biased > 0)
                printf("Rappresentazione per biased: %d", biased);
            else
                printf("Fuori range");

                */



        /**Conoscendo la rappresentazione degli interi in C, riscrivere la function C per l'addizione binaria di due interi
            megiante gli operatori bitwise (Esercizio 8).
            Se l'operazione da implementare deve essere l'addizione algebrica
            (cioè deve valere anche per gli interi negativi rappresentati per complemento a 2),
            quale accorgimento va usato nella traduzione in C dell'algoritmo... e perchè...?


            RISPOSTA: Basta cambiare la condizione del while!
            Diverso e non maggiore a 0, perche' se facessi 2+(-1) e seguendo l'algoritmo
            per l'addizione aritmetica, essendo -1 rappresentato in complemento a due,
            su 4 bit avremo 0010+1111. Si arrivera' ad un passaggio in cui il riporto
            sara' 1000, ma il C lo vedrebbe come un numero negativo e uscirebbe dalla
            condizione del while, senza finire l'algoritmo.
            Fatto cio', utilizzando valori positivi e negativi, cioe' rappresentati
            col C2, si ridurra' tutto ad una somma algebrica.**/


        int op1,op2, somma;

        printf("Inserire il primo operatore: ");
        scanf(" %d", &op1);
        printf("Inserire il secondo operatore: ");
        scanf(" %d", &op2);

        somma = addizione_aritmetica2(op1,op2);

        printf("%d + %d = %d", op1, op2, somma);

    return 0;
}
