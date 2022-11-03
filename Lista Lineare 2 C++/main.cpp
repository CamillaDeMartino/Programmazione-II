#include <iostream>
#include <iterator>
#include <list>

using namespace std;

void showForwList(list <int> Blist);
void showBackwList(list <int> Blist);

int main()
{
    list <int> Blist;
    list <int>::iterator it;
    list <int>::reverse_iterator rit; //iteratore per lista bidirezionale

 if ( Blist.empty() )
 cout << "\tlista bidirezionale vuota\n";
 else
 cout << "\tlista bidirezionale non vuota\n";

 Blist.push_front(10);         //inserisce in testa
 cout << "Blist.push_front(10) ==> La lista bidirezionale contiene forward:";
 showForwList(Blist);
 Blist.push_front(30);
 cout << "Blist.push_front(30) ==> La lista bidirezionale contiene forward:";
 showForwList(Blist);
 Blist.push_back(20);       //inserisce in coda
 cout << "Blist.push_back(20) ==> La lista bidirezionale contiene forward:";
 showForwList(Blist);

 cout << "                    ==> La lista bidirezionale contiene backward:";
 showBackwList(Blist);

 it = Blist.begin();
 ++it;                  //pone it al secondo nodo
 cout << "it=Blist.begin(); ++it; ==> *it = " << *it << endl;

 it = Blist.insert(it,{1,3,5});  //inserisce prima del nodo puntato da iit
 cout << "it=Blist.insert(it,{1,3,5}) ==> La lista contiene:";
 showForwList(Blist);

 cout << "*it = " << *it << endl;

 it = Blist.end();
 it--;  //punta all'ultimo nodo
 cout << "it=Blist.end(); it--; ==> *it = " << *it << endl;

 rit = Blist.rbegin();  //rit punta all'ultimo nodo
 cout << "rit=Blist.rbegin(); ==> *rit = " << *rit << endl;

 it = Blist.insert(it,2,15);    //inserisce 15, 15 prima del nodo puntatp da it
 cout << "it=Blist.insert(it,2,15}) ==> La lista contiene:"; showForwList(Blist);

 Blist.pop_front();
 cout << "Blist.pop_front() ==> La lista contiene:"; showForwList(Blist);

 Blist.pop_back();
 cout << "Blist.pop_back() ==> La lista contiene:"; showForwList(Blist);

 it = Blist.end();      //it punta oltre la fine
 advance(it,-3); // arretra di 3 n = −3<0: vale solo per iteratori bidirezionali e ad accesso random
 cout << "it=Blist.end(); advance(it,-3); ==> *it = " << *it << endl;

    return 0;
}

void showForwList(list <int> Blist)
{
 /// visita lista in avanti
  list <int> :: iterator it;

    for ( it = Blist.begin(); it != Blist.end(); it++ )
    cout << '\t' << *it;

 cout << '\n';
}

void showBackwList(list <int> Blist)
{ /// visita lista all’indietro

 list <int> :: reverse_iterator rit;

    for ( rit = Blist.rbegin(); rit != Blist.rend(); rit++ )
    cout << '\t' << *rit;

 cout << '\n';
}
