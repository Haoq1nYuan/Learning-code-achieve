//https://www.acwing.com/problem/content/781/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int n, minc = 200;
string k[205], len;
int l, r, mid;

bool check ( int length )
{
    len = k[0].substr(k[0].size() - length);
    int i;

    for ( i = 1; i < n; i++ )
        if ( k[i].substr(k[i].size() - length) != len ) return false;
    
    if ( i == n ) return true;
    else return false;
}

int main ()
{
    while ( cin >> n, n )
    {
        for ( int i = 0; i < n; i++ ) 
        {
            cin >> k[i];
            minc = min( minc, (int)k[i].size() );
        }

        l = 0, r = minc;
        while ( l < r )
        {
            mid = ( l + r + 1 ) / 2;
            if ( check(mid) ) l = mid;
            else r = mid - 1;
        }
        
        cout << k[0].substr(k[0].size() - r) << endl;
        
        for ( int i = 0; i < n; i++ ) k[i] = "";
    }

    return 0;
}