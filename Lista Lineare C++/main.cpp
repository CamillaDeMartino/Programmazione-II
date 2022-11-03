#include <iostream>
#include <iterator>
#include <forward_list>

using namespace std;

void showForwList(forward_list <int> flist);

int main()
{
    forward_list <int> flist;
    forward_list <int>::iterator it; //iteratore sulla lista

 if ( flist.empty() )
 cout << "\tlista lineare vuota\n";
 else
 cout << "\tlista lineare non vuota\n";

 flist.push_front(10);  //ineserise in testa
 cout << "flist.push_front(10) ==> La lista contiene:";
 showForwList(flist);
 flist.push_front(30);
 cout << "flist.push_front(30) ==> La lista contiene:";
 showForwList(flist);
 flist.push_front(20);
 cout << "flist.push_front(20) ==> La lista contiene:";
 showForwList(flist);

 it = flist.insert_after(flist.begin(),{1,3,5});                //inserisce dopo il primo nodo i numeri 3 e 5 e pone it al 5
 cout << "it=flist.insert_after(flist.begin(),{1,3,5}) ==> La lista contiene:";
 showForwList(flist);

 cout << "*it = " << *it << endl;
 it = flist.insert_after(it,7);    //inserisce dopo il nodo puntato da it
 cout << "it=flist.insert_after(it,7) ==> La lista contiene:";
 showForwList(flist);

 cout << "*it = " << *it << endl;
 it = flist.begin();   //mette it al primo nodo
 advance(it,3);        //fa avanzare it fino al terzo nodo
 cout << "it=flist.begin(); advance(it,3); ==> *it = " << *it << endl;

 it = flist.insert_after(it,9);
 cout << "it=flist.insert_after(it,9) ==> La lista contiene:";
 showForwList(flist);

 cout << "*it = " << *it << endl;

 flist.pop_front();             //elimina dalla testa
 cout << "flist.pop_front() ==> La lista contiene:";
 showForwList(flist);

 it = flist.begin();
 cout << "*it = " << *it << endl;

 flist.erase_after(it,flist.end());         //elimina nodi da quello puntato da it fino alla fine
 cout << "flist.erase_after(it,flist.end()) ==> La lista contiene:";
 showForwList(flist);

    return 0;
}

void showForwList(forward_list <int> flist)
{
 for ( int &r : flist )
 cout << '\t' << r;
 cout << '\n';
}
