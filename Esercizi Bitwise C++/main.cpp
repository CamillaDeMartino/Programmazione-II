#include <iostream>
#include <bitset>
#include "Header.h"

using namespace std;

int main()
{
    //Esempio usi

    /*
    bitset<8> A = 'A', a = 'a', r;

    r = A ^ a;
    cout << "A ^ a = " << r << endl;
    cout << "Dec =  " << r.to_ulong() << endl;
    cout << "Size = " << r.size() << endl;
    cout << "Count = "<< r.count() << endl;

    unsigned short N = 125;
    bitset<8> Bits (N); //oppure Bits = N;

    cout << "Bits = "<< Bits << endl;

    bitset<8> Bits2 = 0x0F;

    cout << Bits << " & 00001111 = " << (Bits2 & Bits) << endl;


    */


    /** Scrivere una function C
            char low_upp(char ch)
        che cambia il carattere in input da minuscolo a maiuscolo e viceversa automaticamente.**/

/*
    char ch, newc;
    cout << "Inserire un carattere: " << endl;
    cin >> ch;

    newc = ch^32;
    bitset<8> Bits(ch);


    if( Bits.to_ulong() >= 65 && Bits.to_ulong() <= 90 )
        cout << "Inserito il carattere maiuscolo, convertito: "<< newc<< endl;
    else
        cout << "Inserito il carattere minuscolo, convertito: "<< newc<< endl;

*/


/** Scrivere una function C
    char rotate(char ch, char n_bit)
    per ruotare di n bit (n_bit), verso sinistra o verso destra (rispettivamente per n_bit<0 e per n_bit>0), il
    contenuto di una variabile char mediante gli operatori bitwise.**/


    /*
    char newc, ch, mask;
    int n_bit;
    cout << "Inserisci il carattere: "<<endl;
    cin >> ch;

    mask = ch;
    bitset<8> Bits(ch);

    cout << Bits <<endl;

    cout << "n_bit da ruotare? (<0 se a sx): "<<endl;
    cin >> n_bit;

    if(n_bit < 0 )
    {
        n_bit = -n_bit;
        Bits = (Bits << n_bit);
        cout << Bits << endl;

        mask = mask >> (Bits.size()- n_bit);

        bitset <8> Bits2 (mask);
        bitset <8> Bits3;
        for(int i = 0; i < Bits.size(); i++)
            Bits3[i] = Bits2[i] | Bits [i];

        cout << Bits3 << endl;
    }

    else
    {
        Bits = (Bits >> n_bit);
        cout << Bits << endl;

        mask = mask << (Bits.size()- n_bit);

        bitset <8> Bits2 (mask);
        bitset <8> Bits3 ;
        for(int i = 0; i < Bits.size(); i++)
            Bits3[i] = Bits2[i] | Bits [i];

        cout << Bits3 << endl;
    }
*/

/** Scrivere una function C per invertire l'ordine dei bit di una variabile intera char A mediante operatori
    bitwise. **/

/*
    char A = 'a';
    char mask = 0;

    bitset <8> Bits(A);

    cout << "A bit: "<< Bits << endl;

    for(int i = 0; i < Bits.size(); i++)
    {
        mask = mask << 1;
        mask = mask | Bits[i];
    }

    Bits = mask;
    cout << "A invertito bit: "<< Bits << endl;
*/



/** Scrivere una function C che estragga da una variabile intera char A i suoi bit di posto pari mediante
    operatori bitwise.**/
/*
    char A = -13;

    bitset <8> Bits(A);
    bitset <8> Bits2;

    for(int i = 0; i < Bits.size(); i++)
    {
        if(i%2 == 0)
        {
            Bits2[i/2] = Bits[i];
        }
    }

    cout << Bits <<endl;
    cout << Bits2<<endl;

    */



    /** Scrivere una funzione C++ per contare il numero di bit uguali a zero e il numero di bit uguali a 1 in una
        variabile di tipo int, facendo uso del template bitset<N> (e dei metodi collegati) e visualizzando i singoli
        bit del risultato **/

        int a, uno = 0,zero = 0;

        printf("Inserisci un tipo intero: ");
        scanf(" %d", &a);

        bitset<4> Bits(a);

        cout << Bits << endl;


        for(int i = 0; i < Bits.size(); i ++)
            if (Bits.test(i) == 1)
                {
                    uno ++;
                }
            else
                    zero++;


    cout<<"Bit 1:   "<< uno << endl;
    cout<<"Bit 0:   "<< zero << endl;

    return 0;
}
