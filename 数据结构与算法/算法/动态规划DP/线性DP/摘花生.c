//https://www.acwing.com/problem/content/description/1017/

//dfs暴力枚举----TLE
/* #include<stdio.h>

int t, r, c, res;
int m[105][105];

void ans ( int x, int y, int sum )
{
    if ( x == r && y == c ) 
    {
        sum += m[x][y];
        res = res>sum?res:sum;
        return;
    }

    if ( y < c )
    {
        sum += m[x][y];
        ans( x, y+1, sum );
        sum -= m[x][y];
    } 

    if ( x < r )
    {
        sum += m[x][y];
        ans( x+1, y, sum );
        sum -= m[x][y];
    }

    return;
}

int main ( int argc, char *argv[] )
{
    scanf( "%d", &t );

    while ( t-- )
    {
        scanf( "%d%d", &r, &c );
        for ( int i = 1; i <= r; i++ )
            for ( int j = 1; j <= c; j++ )
                scanf( "%d", &m[i][j] );

        int sum = 0;
        res = 0;
        ans( 1, 1, sum );

        printf( "%d\n", res );
    } 

    return 0;
} */

//dp优化---线性dp
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))

int t, r, c;
int m[105][105], dp[105][105];    //dp[i][j]的i表示向东南走了i-1格，j表示向东走了j-1格

int main ( int argc, char *argv[] )
{
    scanf( "%d", &t );

    while ( t-- )
    {
        scanf( "%d%d", &r, &c );

        for ( int i = 1; i <= r; i++ )
            for ( int j = 1; j <= c; j++ )
                scanf( "%d", &m[i][j] ); 

        for ( int i = 1; i <= r; i++ )
            for ( int j = 1; j <= c; j++ )
                dp[i][j] = m[i][j] + max( dp[i-1][j], dp[i][j-1] );
        
        printf( "%d\n", dp[r][c] );
    }

    return 0;
}

//滚动数组+dp优化空间复杂度
#include<stdio.h>
#include<string.h>
#define max(a,b) ((a)>(b)?(a):(b))

int t, m[2][105], dp[2][105], r, c;

int main ( int argc, char *argv[] )
{
    scanf( "%d", &t );

    while ( t-- )
    {
        scanf( "%d%d", &r, &c );

        for ( int i = 1; i <= r; i++ )
            for ( int j = 1; j <= c; j++ )
            {
                scanf( "%d", &m[i&1][j] );
                dp[i&1][j] = max( dp[i&1][j-1], dp[(i-1)&1][j] ) + m[i&1][j];
            }

        printf( "%d", dp[r&1][c] );

        memset( dp, 0, sizeof(dp) );
    }
    return 0;
}