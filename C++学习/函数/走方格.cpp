#include <iostream>
using namespace std;

int n, m, res;

void ans ( int x, int y )
{
    if ( x == n && y == m ) 
    {
        res++;
        return;
    }

    if ( x > n || y > m ) return;

    ans(x+1, y);
    ans(x, y+1);

    return;
}

int main ()
{
    cin >> n >> m;

    ans(0, 0);

    cout << res;

    return 0;
}