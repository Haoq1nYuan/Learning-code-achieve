//https://www.acwing.com/problem/content/9/

//分组背包dp---划分成好多组，每组中有各不相同的物品，且只能从每组中取一个物品
/*
状态表示：dp[i][j]表示在前i组中选，且总体积<=j的所有方案总价值的集合，属性为max
状态划分：
    1.第i组物品不选：dp[i][j] = dp[i-1][j]
    2.第i组物品选第k个：dp[i][j] = max( dp[i][j], dp[i-1][j-v[i][k]] + w[i][k] )

*/
//朴素算法
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 105

int n, V, s[N], v[N][N], w[N][N];
int dp[N][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &V );
    for ( int i = 1; i <= n; i++ )
    {
        scanf( "%d", &s[i] );
        for ( int j = 1; j <= s[i]; j++ ) 
            scanf( "%d%d", &v[i][j], &w[i][j] );
    }

    for ( int i = 1; i <= n; i++ )
        for ( int j = 0; j <= V; j++ )
            for ( int k = 0; k <= s[i]; k++ )
                if ( j >= v[i][k] )   //此处的判断不能写在for循环里面，因为v数组中元素值不是单调排列的
                    dp[i][j] = max( dp[i][j], dp[i-1][j-v[i][k]] + w[i][k] );

    printf( "%d\n", dp[n][V] );

    return 0;
}

//二维转一维优化
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 105

int n, V, s[N], v[N][N], w[N][N];
int dp[N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &V );
    for ( int i = 1; i <= n; i++ )
    {
        scanf( "%d", &s[i] );
        for ( int j = 1; j <= s[i]; j++ ) 
            scanf( "%d%d", &v[i][j], &w[i][j] );
    }

    for ( int i = 1; i <= n; i++ )
        for ( int j = V; j >= 0; j-- )
            for ( int k = 0; k <= s[i] ; k++ )
                if ( j >= v[i][k] ) dp[j] = max( dp[j], dp[j-v[i][k]] + w[i][k] );

    printf( "%d\n", dp[V] );

    return 0;
}