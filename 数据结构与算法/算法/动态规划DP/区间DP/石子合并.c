//https://www.acwing.com/problem/content/284/

//区间合并
/*
状态表示：dp[i][j]表示所有将区间[i,j]中这么多堆石子合并成一堆的方案的代价的集合，属性为min
状态划分：
    1.左半边的最后一堆是第i堆.
    …………
    2.左半边的最后一堆是第k堆；dp[i][j] = min( dp[i][k], dp[k+1][j] ) + s[j] - s[i-1];  //s数组为部分和
    …………
    3.左半边的最后一堆是第j-1堆.
*/
#include <stdio.h>
#include <string.h>
#define min(a,b) ((a)>(b)?(b):(a))
#define N 305

int n, m[N], s[N];
int dp[N][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );
    for ( int i = 1 ; i <= n; i++ ) 
    {
        scanf( "%d", &m[i] );
        s[i] += s[i-1] + m[i];  //前缀和便于之后将左右两堆物品合并时快速求出花费的代价
    }

    memset(dp, 0x3f, sizeof dp);
    for (int i = 0; i <= n; i++) dp[i][i] = 0;  // 合并一个石子的代价为0
    
    for ( int len = 2; len <= n; len++ )  //先枚举区间长度
        for ( int i = 1; i + len - 1 <= n; i++ )    //再枚举左右端点
        {
            int j = i + len - 1;

            for ( int k = i; k < j; k++ )
                dp[i][j] = min( dp[i][j], dp[i][k] + dp[k + 1][j] + s[j] - s[i-1] );
        }

    printf( "%d\n", dp[1][n] );

    return 0;
}