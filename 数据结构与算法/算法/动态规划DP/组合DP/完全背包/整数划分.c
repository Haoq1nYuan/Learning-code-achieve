//https://www.acwing.com/problem/content/902/

//完全背包DP解法
/*
状态含义：从前i个物品中选，且满足总体积为j的所有方案数的集合
状态计算：参考完全背包问题
*/
//朴素版本
#include<stdio.h>
#define N 1010
#define mod 1000000007

int n;
int dp[N][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );

    dp[0][0] = 1;

    for ( int i = 1; i <= n; i++ )
        for ( int j = 0; j <= n; j++ )
        {
            //不选
            dp[i][j] = ( dp[i][j] + dp[i-1][j] ) % mod;
            //选至少1个
            for ( int k = 1; k * i <= j; k++ )
                dp[i][j] = ( dp[i][j] + dp[i-1][j-k*i] ) % mod;
        }

    printf( "%d\n", dp[n][n] );

    return 0;
}

//减少k循环优化
#include<stdio.h>
#define N 1010
#define mod 1000000007

int n;
int dp[N][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );

    dp[0][0] = 1;

    for ( int i = 1; i <= n; i++ )
        for ( int j = 0; j <= n; j++ )
        {
            //不选
            dp[i][j] = ( dp[i][j] + dp[i-1][j] ) % mod;
            //选至少1个
            if ( j >= i ) dp[i][j] = ( dp[i-1][j] + dp[i][j-i] ) % mod;
        }

    printf( "%d\n", dp[n][n] );

    return 0;
}

//一维dp优化
#include<stdio.h>
#define N 1010
#define mod 1000000007

int n, dp[N];

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );

    dp[0] = 1;
    for ( int i = 1; i <= n; i++ )
        for ( int j = i; j <= n; j++ )
            dp[j] = ( dp[j] + dp[j-i] ) % mod;

    printf( "%d\n", dp[n] ); 

    return 0;
}

//第二种解法
/*
状态表示：总和是i，且恰好能表示成j个数的和方案的集合
状态划分：
    1.j个数中最小值为1：dp[i][j] += dp[i-1][j-1]
    2.j个数中最小值大于1：
        1.将每个数都-1，总体-j
        2.dp[i][j] += dp[i-j][j]
    3.最后算总和：ans = dp[n][1] + dp[n][2] + …… + dp[n][n]
*/
#include<stdio.h>
#define N 1010
#define mod 1000000007

int n, ans;
int dp[N][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );

    dp[0][0] = 1;
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= i; j++ )
            dp[i][j] = ( dp[i-j][j] + dp[i-1][j-1] ) % mod;

    for ( int i = 1; i <= n; i++ ) ans = ( ans + dp[n][i] ) % mod;

    printf( "%d\n", ans );

    return 0;
}