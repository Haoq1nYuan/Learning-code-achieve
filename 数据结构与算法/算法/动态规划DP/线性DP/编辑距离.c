//https://www.acwing.com/problem/content/901/

//线性dp
/*
状态表示：dp[i][j]表示所有将字符串a[1~i]变成b[1~j]的方案的操作数的集合，属性是min
状态划分：画图画图画图
    1.a[i]被删掉：dp[i][j] = min( dp[i-1][j] + 1, dp[i][j] );
    2.a[i]是插入的：dp[i][j] = min( dp[i][j-1] + 1, dp[i][j] );
    3.a[i]是被替换的：
        如果a[i] == b[j], dp[i][j] = min( dp[i-1][j-1], dp[i][j] );
        如果a[i] != b[j], dp[i][j] = min( dp[i-1][j-1] + 1, dp[i][j] );
*/
#include<stdio.h>
#include<string.h>
#define min(a,b) ((a)>(b)?(b):(a))
#define N 1010

int n, m, time;
char a[N][15], b[15];
int dp[15][15];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &m );
    getchar();
    for ( int i = 1; i <= n; i++ ) gets( *(a+i)+1 );

    while ( m-- ) 
    {
        scanf( "%s%d", b+1, &time );

        int ans = 0;

        for ( int c = 1; c <= n; c++ )
        {
            for ( int i = 1; i <= strlen(a[c]); i++ ) dp[i][0] = i;
            for ( int i = 1; i <= strlen(b); i++ ) dp[0][i] = i;

            for ( int i = 1; i <= strlen(a[c]); i++ )
                for ( int j = 1; j <= strlen(b); j++ )
                {
                    dp[i][j] = min( dp[i-1][j] + 1, dp[i][j-1] + 1 );
                    if ( a[c][i] == b[j] ) dp[i][j] = min( dp[i][j], dp[i-1][j-1] );
                    else dp[i][j] = min( dp[i][j], dp[i-1][j-1] + 1 );
                }
            
            if ( dp[strlen(a[c])][strlen(b)] <= time ) ans++;

            memset( dp, 0 ,sizeof(dp) );
        }

        printf( "%d\n", ans );
    }

    return 0;
}