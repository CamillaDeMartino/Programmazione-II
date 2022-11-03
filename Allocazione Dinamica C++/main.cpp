#include <iostream>
#include <vector>

using namespace std;

int main()
{

    //Array 1D
/*
    vector<int> v = {7, 5 , 16, 8};
    for(auto&x: v)
        cout<<x<<endl;

    cout<<endl;

    v.pop_back();
    for(auto&x: v)
        cout<<x<<endl;

    cout<<endl;

    v.push_back(25);
    for(auto&x: v)
        cout<<x<<endl;

    cout<<endl;

    v.push_back(32);
    for(auto&x: v)
        cout<<x<<endl;

    cout<<endl;

    */



  //Array 2D

    /*
    int m = 3;

    vector<vector<int>> A {{1,2,3}, {4,5}, {6}};

    cout<<"A.size() = "<< A.size()<<endl;
    cout<<"A[0].size() = "<< A[0].size()<<endl;
    cout<<"A[1].size() = "<< A[1].size()<<endl;
    cout<<"A[2].size() = "<< A[2].size()<<endl;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < A[i].size(); j++)
            cout<<A[i][j]<<" ";

        cout<<endl;
    }

    */


    int m = 3, n = 2;

    //inzializzi a 0

   vector<vector<int>> A(m);

    for(int i = 0; i < m; i++)
            A[i].resize(n);

    //oppure

    /*vector<vector<int>> A;
    A.resize(m,vector<int>(n));*/


    //oppure con valori

    //vector<vector<int>> A (m, vector <int> (n,5));

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            cout << A[i][j] << " ";

        cout<<endl;
    }
            return 0;
}
