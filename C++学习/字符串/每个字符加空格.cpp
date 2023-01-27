#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string k;

int main ()
{
    getline(cin, k);
    
    for ( char c : k )  cout << c << " ";
    
    return 0;
}