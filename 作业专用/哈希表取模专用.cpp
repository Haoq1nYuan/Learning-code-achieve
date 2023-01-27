#include <iostream>
#include <cstdio>

using namespace std;

int n;

int main ( int argc, char *argv[] )
{
    cin >> n;

    int flag = 1;
    
    for ( int i = n; 1 ; i++ ) 
    {
        int j;
        for ( j = 2; j < i; j++ )
        {    
            if ( i % j == 0 ) break;
        }
        if ( j == i ) 
        {
            printf( "%d", j );
            return 0;
        }
    }
}