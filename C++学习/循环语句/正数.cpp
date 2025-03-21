#include <iostream>
#include <cstdio>

using namespace std;

double a;
int count;

int main ()
{
    for ( int i = 1; i <= 6; i++ )
    {
        cin >> a;
        if ( a > 0 ) count++;
    }

    printf( "%d positive numbers", count );

    return 0;
}