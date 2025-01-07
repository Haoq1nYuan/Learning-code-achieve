#include <iostream>
#include <cstdio>

using namespace std;

int x, y, sum;

int main ()
{
    cin >> x >> y;
    
    if ( x > y ) swap(x, y);

    for ( int i = x+1; i < y; i++ )
        if ( i % 2 ) sum += i;

    cout << sum;

    return 0;
}