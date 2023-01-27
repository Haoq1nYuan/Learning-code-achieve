//https://www.acwing.com/problem/content/778/

//findº¯Êý
#include <iostream>
#include <string>
using namespace std;

string a, b;

int main ()
{
    cin >> a >> b;

    if ( a.size() < b.size() ) swap(a, b);

    for ( int i = 0; i < a.size(); i++ )
    {
        if ( a.find(b) != -1 ) 
        {
            cout << "true";
            return 0;
        }
        else a = a.substr(1) + a[0];
    }

    cout << "false";

    return 0;
}