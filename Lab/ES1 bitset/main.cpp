#include <iostream>
#include <bitset>
#include <time.h>
#include "Header.h"

#define Nstud 20

using namespace std;

int main()
{
    unsigned int Nlez = 12;
    int presenzeTot[20];

    bitset<Nstud> presenze[Nlez];


    cout << "Presenze di tutti gli studenti(colonna) per ogni lezioni (riga)" << endl;
    for(unsigned int k = 0; k < Nlez; k++)
    {
        cin >> presenze[k];
        cout << presenze[k] << endl;
    }

    srand(time(NULL));
    int L = rand()%Nlez;  //fissa una lezione random
    int S = rand()%Nstud; //fissa uno studente random
    cout <<"Studente numero: "<< S+1
         << " Presente alla lezione numero: " << L+1 << endl;
    cout <<"\t\t\t"
         << ( (presenze[L].test(S)) ? "Si, presente": "No, assente")<< endl;

    //conta_presenze(presenzeTot, presenze, Nlez );

    for(int i = 0; i < Nstud ; i++)
         presenzeTot[i] = 0;

    for(unsigned int k = 0; k < Nstud; k++)
    {
        for(unsigned int j = 0; j< Nlez; j++)
        {
          presenzeTot[k] += (int)presenze[j][k];
        }
    }

    //inverti
    unsigned int temp;
    for (int i = 0; i < 10 ;i++)
	{
		temp = presenzeTot[19-i];
		presenzeTot[19-i] = presenzeTot[i];
		presenzeTot[i] = temp;
	}

    cout <<"Presenze  ";
    for(int i = 0; i < Nstud; i++)
       cout << " " << presenzeTot[i] ;

 //studenti x lezioni

    cout << "\nLezione n. "<< L+1 <<endl;
    cout << "Studenti presenti: "<< presenze[L].count() << endl;


    cout << "Studente n. ";
   for(int i = 19; i >= 0; i--)
    {
        if(presenze[L].test(i) == 1)
            cout << " "<< 20-i;
   }

    return EXIT_SUCCESS;
}
