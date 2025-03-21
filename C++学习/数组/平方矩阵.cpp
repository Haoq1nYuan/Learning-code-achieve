//https://www.acwing.com/problem/content/755/

//距边界最小长度 + 1 = 元素值
#include <iostream>
#include <cstdio>

using namespace std;

int n;

int main ()
{
    while ( cin >> n, n )
    {
        for ( int i = 0; i < n; i++ )
            for ( int j = 0; j < n; j++ )
            {
                int ans = min( min( j, n-1-j ), min( i, n-1-i ) );
                
                cout << ans+1 << " ";
                
                if ( j == n-1 ) puts( "" );
            }
        
        puts( "" );
    }
    
    return 0;
}

//回型写法
/* #include <iostream>
#include <cstdio>

using namespace std;

int n;

int main ()
{
    while(cin >> n, n)
    {
        for (int i = 0; i < n; i ++ )
        {
            for (int j = i; j < n - i; j ++ )
            {
                a[j][i] = a[i][j] = i + 1;
                a[j][n - i - 1] = a[n - i - 1][j] = i + 1;
            }
        }
        for (int i = 0; i < n; i ++ )
        {
            for (int j = 0; j < n; j ++ )
                cout << a[i][j] << ' ';
            cout << endl;
        }
        cout << endl;
    }

    return 0;
} */