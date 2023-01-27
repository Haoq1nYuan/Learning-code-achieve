//https://www.acwing.com/problem/content/1049/

//背包DP
/*
状态：dp[i][j]表示所有满足“从前i件物品中选，且糖果总数目n%k=j”的方案中最多的糖果数目
状态计算：
1.选第1件物品：
    把所有方案分成两部分，一部分是w[i]，一部分是dp[i-1][( ( j - w[i] ) % k + k ) % k]
    推导过程：后面一部分的糖果总数s满足 (s + w[i]) % k = j，即 s + w[i] = j + n*k，
    移项后取正模就是 s % k = ((j - w[i]) % k + k) % k + 0.
2.不选第1件物品：dp[i][j] = dp[i-1][j]
*/
#include<stdio.h>
#include<string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define null -0x3f3f3f3f
#define N 105

int n, k, maxW, w[N];
int dp[N][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &k );
    for ( int i = 1; i <= n; i++ ) scanf( "%d", &w[i] );

    //需要将数组初始化为无穷小,因为dp[0][i]之类无意义
    //memset( dp, -0x3f, sizeof(dp) );   
    for ( int i = 1; i < k; i++ ) dp[0][i] = null;
    dp[0][0] = 0;

    for ( int i = 1; i <= n; i++ )
        for ( int j = 0; j < k; j++ )
            dp[i][j] = max( dp[i-1][j], dp[i-1][( ( j - w[i] ) % k + k ) % k] + w[i] );

    printf( "%d\n", dp[n][0] );

    return 0;
}