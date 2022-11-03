#include <iostream>
#include <queue>

using namespace std;

void showqueue(queue <int> q);

int main()
{
    queue <int> q;
    cout << "\nq.size() = " << q.size();

 if ( q.empty() )
 cout << "\tcoda vuota\n";
 else
 cout << "\tcoda non vuota\n";

 q.push(10);
 cout << "q.push(10) ==> La coda q contiene:"; showqueue(q);
 q.push(30);
 cout << "q.push(30) ==> La coda q contiene:"; showqueue(q);
 q.push(20);
 cout << "q.push(20) ==> La coda q contiene:"; showqueue(q);
 q.push(5);
 cout << "q.push(5) ==> La coda q contiene:"; showqueue(q);
 q.push(1);
 cout << "q.push(1) ==> La coda q contiene:"; showqueue(q);

 cout << "\nq.size() = " << q.size();

 if ( !q.empty() )
 {
    cout << "\nq.front() = " << q.front();
    q.pop();
    cout << "\nq.pop() ==> La coda q contiene:"; showqueue(q);
 }
    return 0;
}

void showqueue(queue <int> q)
{
 while ( !q.empty() )
 {
    cout << '\t' << q.front();
    q.pop();
 }

 cout << '\n';
}
