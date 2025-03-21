//朴素做法
/* #include <iostream>
#include <cstdio>

using namespace std;

int n;

int main ()
{
    cin >> n;
    
    for ( int i = 1; i <= n/2; i++ )
    {
        int j = 2*i - 1;
        int count = (n - j) / 2;
        int box = count;
        while ( count-- ) cout << " ";
        while ( j-- ) cout << "*";
        while ( box-- ) cout << " ";
        cout << endl;
    }
    
    int k = n; 
    while ( k-- ) cout << "*";
    cout << endl;
    
    for ( int i = n/2; i >= 1; i-- )
    {
        int j = 2*i - 1;
        int count = (n - j) / 2;
        int box = count;
        while ( count-- ) cout << " ";
        while ( j-- ) cout << "*";
        while ( box-- ) cout << " ";
        cout << endl;
    }
    
    return 0;
}
 */

//曼哈顿距离
// abs(i-a) + abs(j-b) <= n/2 ,矩阵中心点为(a,b)，矩阵边长为n
#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf( "%d", &n );
    for( int i = 0; i < n; ++i )
    {
        for( int j = 0 ; j < n; ++j ) 
        {
            if ( abs(i-n/2) + abs(j-n/2) <= n/2 ) printf( "*" );
            else printf( " " );
        }
        puts( "" );
    }

    return 0;
}