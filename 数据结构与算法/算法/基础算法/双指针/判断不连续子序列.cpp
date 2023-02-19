//https://www.acwing.com/problem/content/2818/

#include <iostream>

using namespace std;
const int N = 100010;

int n, m, a[N], b[N];

int main ()
{
    cin >> n >> m;
    for ( int i = 1; i <= n; i++ ) scanf( "%d", &a[i] );
    for ( int j = 1; j <= m; j++ ) scanf( "%d", &b[j] ); 
    
    int j = 1;
    for ( int i = 1; i <= m; i++ )
        if ( j <= n && a[j] == b[i] ) j++;
    
    if ( j - 1 == n ) cout << "Yes";
    else cout << "No";
    
    return 0;
}