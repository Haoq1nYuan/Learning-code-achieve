//https://www.acwing.com/problem/content/799/

#include <iostream>
using namespace std;

const int N = 100010;

int n, m, x[N], k[N];
int l, r, c;

int main ()
{
    cin >> n >> m;
    for ( int i = 1; i <= n; i++ ) cin >> x[i], k[i] = x[i] - x[i-1];

    while ( m-- )
    {
        cin >> l >> r >> c;
        k[l] += c;
        k[r+1] -= c;
    } 

    for ( int i = 1; i <= n; i++ )
    {
        x[i] = x[i-1] + k[i];
        cout << x[i] << ' ';
    }

    return 0;
}