#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double a, b, c;

int main ()
{
    cin >> a >> b >> c;

    if ( a == 0 || b*b - 4*a*c < 0 ) cout << "Impossivel calcular";
    else 
    {
        printf( "R1 = %.5lf\n", ( (-1)*b + sqrt(b*b - 4*a*c) ) / (2*a) );
        printf( "R2 = %.5lf", ( (-1)*b - sqrt(b*b - 4*a*c) ) / (2*a) );
    }

    return 0;
}