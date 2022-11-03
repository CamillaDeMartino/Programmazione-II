#include <iostream>
#include <stack>

using namespace std;

void showstack(stack <int> s);

int main()
{

 stack <int> s;

 cout << "\ns.size() = " << s.size();
 if ( s.empty() )
 cout << "\tstack vuoto\n";
 else
 cout << "\tstack non vuoto\n";

 s.push(10);
 cout << "s.push(10) ==> Lo stack s contiene:"; showstack(s);
 s.push(30);
 cout << "s.push(30) ==> Lo stack s contiene:"; showstack(s);
 s.push(20);
 cout << "s.push(20) ==> Lo stack s contiene:"; showstack(s);
 s.push(5);
 cout << "s.push(5) ==> Lo stack s contiene:"; showstack(s);
 s.push(1);
 cout << "s.push(1) ==> Lo stack s contiene:"; showstack(s);

 cout << "\ns.size() = " << s.size();

 if ( !s.empty() )
 {
    cout << "\ns.top() = " << s.top();
    s.pop();
    cout << "\ns.pop() ==> Lo stack s contiene:"; showstack(s);
 }

    return 0;
}


void showstack(stack <int> s)
{
 while ( !s.empty() )
 {
 cout << '\t' << s.top();
 s.pop();
 }
 cout << '\n';
}
