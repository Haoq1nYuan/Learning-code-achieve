#include <iostream>
#include <cstdio>

using namespace std;

int n, x;

int main ()
{
    cin >> n;
    
    while ( n-- )
    {
        cin >> x;
        
        if ( x % 2 == 0 && x != 2 ) 
        {
            printf( "%d is not prime\n", x );
            continue;
        }
        
        bool isprime = true;
        for ( int i = 2; i*i <= x; i++ )
            if ( x % i == 0 ) 
            {
                isprime = false;
                break;
            }
            
        if ( isprime ) printf( "%d is prime\n", x );
        else printf( "%d is not prime\n", x );
    }
    
    return 0;
}