#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double x, y, a, b;

int main ()
{
    cin >> x >> y >> a >> b;

    printf( "%.4lf", sqrt( pow(a-x,2.0) + pow(b-y,2.0) ) );

    return 0;
}