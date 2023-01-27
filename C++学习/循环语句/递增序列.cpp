#include <iostream>
#include <cstdio>

using namespace std;

int x;

int main ()
{
    while ( cin >> x, x )
    {
        int j = 0;
        while ( j < x ) cout << ++j << " ";
        printf( "\n" );
    }
    
    return 0;
}