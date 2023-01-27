#include <iostream>
using namespace std;

int n, res;

void ans ( int num )
{
    if ( num == n ) 
    {
        res++;
        return;
    }

    if ( num > n ) return;
    
    ans(num + 1);

    ans(num + 2);

    return;
}

int main ()
{
    cin >> n;

    ans(0);

    cout << res << endl;

    return 0;
}