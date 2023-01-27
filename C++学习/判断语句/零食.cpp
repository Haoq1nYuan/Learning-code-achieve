#include <iostream>
#include <cstdio>

using namespace std;

int x, y;

int main ()
{
    cin >> x >> y;

    if ( x == 1 ) printf( "Total: R$ %.2lf", 1.0*4*y );
    else if ( x == 2 ) printf( "Total: R$ %.2lf", 4.5*y );
    else if ( x == 3 ) printf( "Total: R$ %.2lf", 5.00*y );
    else if ( x == 4 ) printf( "Total: R$ %.2lf", 2.00*y );
    else printf( "Total: R$ %.2lf", 1.5*y ); 

    return 0;
}