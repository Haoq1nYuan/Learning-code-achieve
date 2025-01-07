#include <iostream>
#include <cstdio>

using namespace std;

int x;

int main ()
{
    cin >> x;

    for ( int i = 1; i <= x; i++ )
        if ( i % 2 ) cout << i << endl;

    return 0;
}