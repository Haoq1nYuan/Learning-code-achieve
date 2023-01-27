#include <iostream>
using namespace std;

int n, k[10], e[10];

void dfs ( int num )
{
    if ( num == n )
    {
        for ( int i = 0; i < n; i++ )
            cout << e[i] << ' ';
        
        cout << endl;
    }

    for ( int i = 1; i <= n; i++ )
        if ( k[i] == 0 )
        {
            e[num] = i;
            k[i] = 1;
            dfs(num+1);
            k[i] = 0;
        }
    
} 

int main ()
{
    cin >> n;

    dfs(0);

    return 0;
}