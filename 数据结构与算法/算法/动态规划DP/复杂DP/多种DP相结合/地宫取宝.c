//https://www.acwing.com/problem/content/1214/

/*
题目性质：
1.一定要以递增的顺序取物品（价值从小到大排列）
2.初始情况为dp[1][1][0][-1] = 1(物品的价值可以等于0),dp[1][1][1][c[1][1]] = 1.

集合定义：
dp[i][j][k][w]所有走到(i, j)点，已取了k件物品，且最后一件物品的价值是w的所有方案的集合
集合属性：count
状态计算：
分为四类，注意状态转移的时候要全加起来，而不是像前面几题一样取max
最后一步向下走到(i, j)：
    1.不取 dp[i][j][k][w] = ( dp[i][j][k][w] + dp[i-1][j][k][w] ) % mod;   
    2.取  首先需要满足c[i][j] == w，前一个价值可能是从小于w的任意一个价值
          所以需要循环一遍，把每一种情况的方案数都加上    
          dp[i][j][k][w] = ( dp[i][j][k][w] + dp[i-1][j][w-1][c] ) % mod;   1 <= c <= 一组数据中所有物品价值的最大值;
最后一步向右走到(i, j)就是将i-1换成j-1
*/

//四维dp
#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 55
#define mod 1000000007

int n, m, k, maxc, res;
int c[N][N], dp[N][N][13][14];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d%d", &n, &m, &k );

    for ( int i = 1; i <= n; i++ )
        for ( int  j = 1; j <= m; j++ )
        {
            scanf( "%d", &c[i][j] );
            c[i][j]++;
            maxc = max( maxc, c[i][j] );
        }

    dp[1][1][0][0] = 1;
    dp[1][1][1][c[1][1]] = 1;
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            for ( int u = 0; u <= k; u++ )
                for ( int w = 0; w <= maxc; w++ )   //w=0表示没有任何物品，不是物品价值为0
                {
                    //不取
                    dp[i][j][u][w] = ( dp[i][j][u][w] + dp[i][j-1][u][w] ) % mod;
                    dp[i][j][u][w] = ( dp[i][j][u][w] + dp[i-1][j][u][w] ) % mod;
                    //取
                    if ( u > 0 && c[i][j] == w ) 
                    {
                        for ( int c = 0; c < w; c++ )
                        {
                            dp[i][j][u][w] = ( dp[i][j][u][w] + dp[i][j-1][u-1][c] ) % mod;
                            dp[i][j][u][w] = ( dp[i][j][u][w] + dp[i-1][j][u-1][c] ) % mod;
                        }
                    }
                }
    
    for ( int i = 1; i <= maxc; i++ ) res = ( res + dp[n][m][k][i] ) % mod;

    printf( "%d\n", res );

    return 0;
}