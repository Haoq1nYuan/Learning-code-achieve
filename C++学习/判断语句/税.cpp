#include <iostream>
#include <cstdio>

using namespace std;

double a;

int main ()
{
    cin >> a;

    if ( a <= 2000 ) cout << "Isento";
    else if ( a <= 3000 ) printf( "R$ %.2lf", (a-2000)*0.08 );
    else if ( a <= 4500 ) printf( "R$ %.2lf", 80 + (a-3000)*0.18 );
    else printf( "R$ %.2lf", 80 + 1500*0.18 + (a-4500)*0.28 );

    return 0;
}