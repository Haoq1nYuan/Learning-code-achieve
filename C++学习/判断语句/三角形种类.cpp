#include <iostream>
#include <cstdio>

using namespace std;

double a, b, c;

int main ()
{
    cin >> a >> b >> c;
    
    if ( a < b ) swap(a, b);
    if ( a < c ) swap(a, c);
    
    if ( a >= b + c )
    {
        cout << "NAO FORMA TRIANGULO" << endl;
        return 0;
    }
    if ( a*a == b*b + c*c ) cout << "TRIANGULO RETANGULO" << endl;
    else if ( a*a < b*b + c*c ) cout << "TRIANGULO ACUTANGULO" << endl;
    else if ( a*a > b*b + c*c ) cout << "TRIANGULO OBTUSANGULO" << endl;
    if ( a == b && b == c ) cout << "TRIANGULO EQUILATERO" << endl;
    else if ( a == b || a == c || b == c ) cout << "TRIANGULO ISOSCELES" << endl;
    
    return 0;
}