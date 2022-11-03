#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Header.h"
#define Max_Len 32
int main()
{
   /* char carattere;

    printf("Inserisci una lettera\n");
    scanf("%c", &carattere);

        printf(" '%c' cambio: %c\n",carattere, carattere^32);
 */

   /*char car;
   int n_bit;

   srand(time(NULL));
   //car = 97 + rand()%26;
   //printf("Lettera : %c\n", car);

   printf( "Inserisci una lettera: " );
   scanf(" %c", &car);
   printf("Inserire il numero di bit (<0 per girare a sinistra) (>0 per girare a destra): ");
   scanf(" %d", &n_bit);

   if(n_bit < 0)
    {
        printf ( "Nuovo valore: %c", car << n_bit * -1);
    }
   else
   {
       printf ( "Nuovo valore: %c", car >> n_bit );
   }
*/


 /*Scrivere una function C che, dopo aver estratto i bit da una variabile intera X (tipo char, short o long),
 ne calcola il relativo valore dalla formula: Val_X = b[n-1]2^(n-1)+...+b[2]2^2+b[1]2^1+b[0]2^0
 dove b e’ l’array dei bit di X. Confrontare il risultato con il valore della variabile X dichiarata
 una volta signed ed un’altra unsigned.*/
/*
    char ch = 0;     unsigned char uc = 0;
    short sh = 0;    unsigned short us = 0;
    long lo = 0;     unsigned long ul = 0;

    int scelta, i;
    short bit[Max_Len], k;

    union word32bit{
        long l;
        short s[2];
        char c[4];
    }word;


    do{
        puts("Che tipo di dato vuoi inserire?(0 per uscire):\n");
        puts("[1] - intero char");
        puts("[2] - intero short");
        puts("[3] - intero long");
        scanf(" %d",&scelta);

    switch (scelta)
    {
        case 1:
            printf( "Immettere un intero char: " );
            scanf(" %d", &(word.c[0]));
            bit_show(sizeof(char),word.c, bit);


            for(i = 0; i < sizeof(char)*8; i++)
                ch += bit[i] * pow(2,i);

            for(i = 0; i < sizeof(char)*8; i++)
                uc += bit[i] * pow(2,i);

            printf( "Valore array: " );

            for(k = sizeof(char)*8-1; k >= 0; k--)
                (k%4 == 0) ? printf( " %1d", bit[k]) : printf( "%1d", bit[k] );


            printf( "\nValore signed char: %d\n ", ch );
            printf( "\nValore unsigned char: %d\n ", uc );
        break;

        case 2:
            printf( "Immettere un intero short: " );
            scanf(" %d", &(word.s[0]));
            bit_show(sizeof(short),word.c, bit);

            for(i = 0; i < sizeof(short)*8; i++)
                sh += bit[i] * pow(2,i);

            for(i = 0; i < sizeof(short)*8; i++)
                us += bit[i] * pow(2,i);

            for(k = sizeof(short)*8-1; k >= 0; k--)
                (k%4 == 0) ? printf( " %1d", bit[k]) : printf( "%1d", bit[k] );

            printf( "\nValore signed short: %d\n ", sh );
            printf( "\nValore unsigned short: %d\n ", us );
        break;

        case 3:
            printf( "Immettere un intero long: " );
            scanf(" %d", &(word.l));
            bit_show(sizeof(long),word.c, bit);

            for(i = 0; i < sizeof(long)*8; i++)
                lo += bit[i] * pow(2,i);

            for(i = 0; i < sizeof(long)*8; i++)
                uc += bit[i] * pow(2,i);

            for(k = sizeof(long)*8-1; k >= 0; k--)
                (k%4 == 0) ? printf( " %1d", bit[k]) : printf( "%1d", bit[k] );

            printf( "\nValore signed long: %d\n ", lo );
            printf( "\nValore unsigned long: %d\n ", ul );
        break;

        default:
            break;
    }

    }while (scelta != 0);
    */




  /* Scrivere una function C per estrarre dalla variabile intera X i k bit più significativi o meno significativi,
     dove X e k sono i parametri di input, usando:
      1)Una maschera.
      2)L’operatore di shift (>> o <<).
      3)Il prodotto o la divisione per potenza 2. */

 /*  #define n_len 16
   int scelta, i, n;
   short x, mask, shift, potenza;
   unsigned char bit[n_len], k;
   printf( "Inserisci il valore della variabile: " );
   scanf(" %d", &x);

   printf( "\nQuali bit vuoi estrarre?\n[1]Piu' significativi\n[2]Meno significativi\n" );
   scanf( " %d", &scelta );

    printf( "Quanti bit vuoi estrarre?\n" );
    scanf("%d", &n);

    printf( "Visualizzazione numero: " );
    bit_show2(x,bit);
    for(k = 0; k < n_len; k++)
        (k%4 == 0) ? printf(" %1u", bit[k]) : printf( "%1u", bit[k]);

    mask = estrai_mask(x,scelta,n);
    printf("\nEstrazione con mask: ");
    bit_show2(mask,bit);
    for(k = 0; k < n_len; k++)
        (k%4 == 0) ? printf(" %1u", bit[k]) : printf( "%1u", bit[k]);

    shift = estrai_shift(x,scelta,n);
    printf("\nEstrazione con shift: ");
    bit_show2(shift,bit);
    for(k = 0; k < n_len; k++)
        (k%4 == 0) ? printf(" %1u", bit[k]) : printf( "%1u", bit[k]);

    potenza = estrai_potenza(x,scelta,n);
    printf("\nEstrazione con potenza: ");
    bit_show2(potenza,bit);
    for(k = 0; k < n_len; k++)
        (k%4 == 0) ? printf(" %1u", bit[k]) : printf( "%1u", bit[k]);*/




  /*Scrivere due function C di conversione di un intero positivo (int) da base 10 a base 2
    mediante l’ algoritmo delle divisioni successive realizzato rispettivamente:
    - Usando gli operatori di quoziente e resto della divisione intera;
    - Usando gli operatori bitwise*/
/*
    unsigned char   n, bit[8];
    char k;

    printf( "Inserire un intero positivo: " );
    scanf("%d", &n);

    printf( "\nOperazione con division: " );
    char_bit_division(n,bit);

    for(k = 7; k >= 0; k--)
        {
            printf("%d",bit[k]);
            if(k%4 == 0)
                printf(" ");
        }

    printf( "\nOperazione con bitwise: " );
    bitwise_division(n,bit);

    for(k = 7; k >= 0; k--)
    {
        printf("%d", bit[k]);
        if(k%4 == 0)
            printf(" ");
    }*/





   /*Scrivere una function C di conversione di un intero positivo da base 2 a base 10
    che generi un array di caratteri contenenti le cifre decimali.*/



    unsigned char x, bit[8], array[8];
    char k;
    short int i, size, v_dec;
    printf( "Inserisci un intero: " );
    scanf("%d", &x);

    printf( "Numero in binario: " );
    char_bit_division(x,bit);

    for(k = 7; k >= 0; k--)
    {
        printf("%u", bit[k]);
        if(k%4 == 0)
            printf(" ");
    }

    v_dec = decimale(x,bit);
    printf( "\nIl valore decimale e' %d", v_dec );

    printf("\nArray: ");
    size = crea_array(v_dec, array);

    for(i = 0; i < size; i++)
        printf( "[%d]", array[i]);
        printf("\n");

    return 0;
}


