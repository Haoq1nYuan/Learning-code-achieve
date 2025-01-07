#include <iostream>
#include <cstdio>

using namespace std;

int a, n, sum;

int main ()
{
    cin >> a;
    
    while ( cin >> n, n <= 0 );
    
    for ( int i = 1; i <= n; i++ )
        sum += a++;

    cout << sum;

    return 0;
}
