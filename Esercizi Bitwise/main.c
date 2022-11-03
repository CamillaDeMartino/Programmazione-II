#include <stdio.h>
#include <stdlib.h>

int main()
{
    /**visualizzare in output mediante operatori bitwise gli 8 bit di un tipo char**/

    /*
    unsigned char bit[16][4] = {'0','0','0','0',  '0','0','0','1',  '0','0','1','0',  '0','0','1','1',
                                '0','1','0','0',  '0','1','0','1',  '0','1','1','0',  '0','1','1','1',
                                '1','0','0','0',  '1','0','0','1',  '1','0','1','0',  '1','0','1','1',
                                '1','1','0','0',  '1','1','0','1',  '1','1','1','0',  '1','1','1','1'};
    unsigned char c, dx, sx;

    c = 'z';
    sx = c >> 4;
    dx = (c << 4); dx = c >> 4;

    printf("char = %c, dec = %d, hex = %02x\n", c,c,c);
    printf("bin = %c%c%c%c %c%c%c%c", bit[sx][0], bit[sx][1], bit[sx][2], bit[sx][3],
                                      bit[0][dx], bit[1][dx], bit[2][dx], bit[3][dx]);

     */


     /** Scrivere una function C
            char low_upp(char ch)
        che cambia il carattere in input da minuscolo a maiuscolo e viceversa automaticamente**/

/*
       char c;
       int ASCII;

       printf("Inserisci una lettera: ");
       scanf("%c", &c);

       printf("Lettera inserita %c, lettera cambiata: %c", c, low_up(c));
        printf("\n");
*/


    /**  Scrivere una function C
            char rotate(char ch, char n_bit)
         per ruotare di n bit (n_bit), verso sinistra o verso destra (rispettivamente per n_bit < 0 e per n_bit > 0), il
         contenuto di una variabile char mediante gli operatori bitwise.**/

/*
         char c, c_ruotato;
         int n_bit;
         printf("Inserisci un carattere: ");
         scanf("%c", &c);

         printf("Inserisci gli n_bit da ruotare( < 0) verso sinistra ( >0) verso destra: ");
         scanf("%d", &n_bit);
         show(c);
         printf("\n");
         c_ruotato = ruota(c,n_bit);
         show(c_ruotato);

    */


    /**Scrivere una function C per estrarre dalla variabile intera X i k bit più significativi o meno significativi,
       dove X e k sono i parametri di input, usando:
        1) Una maschera.
        2) L’operatore di shift (>> o <<).
        3) Il prodotto o la divisione per potenze di 2.**/

/*
        char x, mask, shift, potenza;
        int k, n_scelta;

        printf("Inserire un numero: ");
        scanf("%d", &x);

        printf("Quali bit si vogliono estrarre? 1.Piu' significativi, 2.Meno significativi\nInserire scelta: ");
        scanf("%d", &n_scelta);

        printf("Quanti bit si vogliono estrarre?: ");
        scanf("%d", &k);

        mask = estrarre_mask(x,n_scelta,k);

        printf("\nNumero inserito\n");
        bit_show(x);
        printf("\nBit estratti con mask\n");
        bit_show(mask);

        shift = estrarre_shift(x,n_scelta,k);

        printf("\nBit estratti con shift\n");
        bit_show(shift);

        potenza = estrarre_potenza(x,n_scelta,k);

        printf("\nBit estratti con potenza\n");
        bit_show(shift);
        */


    /**Scrivere una function C per invertire l'ordine dei bit di una variabile intera char A mediante operatori
        bitwise.**/

        /*
        char a, mask = 0;
        printf("Inserisci carattere: ");
        scanf("%d", &a);

        printf("Inserito: ");
        bit_show(a);

        for (int i = 0; i < 8; i++)         //a = 1011
          {                                 //mask = 0000
             mask = mask << 1;              // a&1 = 1011 & 0001 = 0001
             mask = mask | a&1;             //mask | a = 0000 | 0001 = 0001
             a = a >> 1;                    // a >> 1 = 0101
          }                                 //mask << 1 = 0010
        printf("\nInvertito: ");
        bit_show(mask);
        */


        /** Scrivere una function C che estragga da una variabile intera char A i suoi bit di posto pari mediante
            operatori bitwise  **/

        /*
            char ch, mask = 0;

            printf("Inserisci intero: ");
            scanf(" %d", &ch);

            printf("Inserito: ");
            bit_show(ch);
            printf("\n");

            for(int k = 0; i < 8; i++)
            {
                ch = ch >> 1;
                if(k %2 == 0)
                {
                   mask = mask << 1;
                   mask = mask | ch&1;
                }
            }

	    bit_show(mask);

            */



/** Mediante operatori bitwise, scrivere una funzione C per invertire (0 diventa 1 e 1 diventa 0) i 4 bit più
    significativi, lasciando gli altri inalterati, di
    • una variabile intera char.
    • una variabile intera short.
    • una variabile intera qualsiasi.
    Visualizzare i bit degli operandi e del risultato.**/

/*
    char A = 'a';
    char mask = 0, xor;


    bit_show(A);
    printf("\nInverito: \n");
    for(int i = 0; i < 4; i++)
    {
        mask = mask << 1|1;
    }

    mask = mask << 4;

    xor = mask ^ A;

    bit_show(xor);

    */


/** Scrivere una funzione C per scambiare il valore di due bit, fissati in input, di una variabile intera. Es.: bit 1 e 2
    di 0000 1100 ⇒ 0000 1010; il bit 1 diventa uguale al bit 2 e il bit 2 diventa uguale al bit 1.**/

    unsigned char bit[8];
    char A = 'a';
    int n1, n2, j = 7;

    printf("Inserisci bit 1: ");
    scanf(" %d", &n1);

    printf("Inserisci bit 2: ");
    scanf(" %d", &n2);
    bit_show(A);
    printf("\n");

    bit_show2(A,bit);
    scambiare(bit,n1,n2);

    for(int k = 0; k < 8; k++)
        (k%4 == 0) ? printf(" %1d", bit[k]) : printf ("%1d", bit[k]);

/** Scrivere una function C per eseguire l'addizione aritmetica binaria di due numeri naturali mediante gli operatori bitwise.**/

/*
    int op1, op2, risultato;

    printf("Inserire il primo numero: ");
    scanf("%d", &op1);

    printf("Inserire il secondo numero: ");
    scanf("%d", &op2);

    risultato = addizione_binaria(op1,op2);
    printf("%d + %d = %d", op1, op2, risultato);

*/



   /**Scrivere una function C per eseguire la sottrazione aritmetica binaria di due numeri naturali mediante gli operatori bitwise. **/
/*
   int op1, op2, risultato;

    printf("Inserire il primo numero: ");
    scanf(" %d", &op1);

    printf("Inserire il secondo numero: ");
    scanf(" %d", &op2);

    risultato = sottrazione_binaria(op1,op2);
    printf("%d - %d = %d", op1, op2, risultato);

*/

    return 0;
}
