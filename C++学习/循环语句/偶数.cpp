#include <iostream>
#include <cstdio>

using namespace std;

int main ()
{   
    for ( int i = 1; i <= 100 ; i++ )
        if ( i % 2 == 0 ) cout << i << endl;

    return 0;
}