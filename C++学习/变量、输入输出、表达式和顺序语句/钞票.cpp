#include <iostream>
#include <cstdio>

using namespace std;

int n, num[7] = { 100, 50, 20, 10, 5, 2, 1, };

int main ()
{
    cin >> n;
    
    cout << n << endl;

    for ( int i = 0; i < 7; i++ )
    {
        printf( "%d nota(s) de R$ %d,00\n", n/num[i], num[i] );
        n %= num[i];
    }

    return 0;
}