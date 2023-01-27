#include <iostream>
#include <cstdio>

using namespace std;

double a, b, c;

int main ()
{
    cin >> a >> b >> c;
    
    double big = max( a, b );
    big = max( big, c );
    
    if ( a == big && b + c > a || b == big && a + c > b || c == big && b + a > c ) printf( "Perimetro = %.1lf", a + b + c );
    else printf( "Area = %.1lf", (a + b) * c /2 );
    
    return 0;
}