//https://www.acwing.com/problem/content/1052/

//dfs暴搜
#include<stdio.h>

int t, m, n, res;

void dfs ( int power, int max, int number )
{
    if ( number < 0 ) 
    {
        if ( max == 0 ) res++;
        return;
    }

    for ( int i = power; i <= max; i++ ) 
        dfs( i, max-power, number-1 );

    return;
}

int main ( int argc, char *argv[] )
{
    scanf( "%d", &t );

    while ( t-- )
    {
        scanf( "%d%d", &m, &n );

        dfs(0, m, n);

        printf( "%d\n", res );

        res = 0;
    } 

    return 0;
}

//dp优化，第一种思想
//详见完全背包--“整数划分”
/*
状态表示：
    集合定义：对于dp[i][j]的集合包含所有总和是i，且分成j个分身的的方案
    集合属性：数量
状态计算：
    状态划分：分为最小值为0和不为0两类
        1.最小值为0，则满足该条件的所有方案中都有一个0，去除该0之后方案数不变：dp[i][j] = dp[i][j-1]
        2.最小值不为0，则令所有方案同时减去1，得到的方案dp表示为dp[i-j][j]
*/
#include<stdio.h>
#include<string.h>

int t, m, n, ans;
int dp[15][15];

int main ( int argc, char *argv[] ) 
{
    scanf( "%d", &t );

    while ( t-- )
    {
        scanf( "%d%d", &m, &n );

        dp[0][0] = 1;
        for ( int i = 0; i <= m; i++ )  //因为每个分身的能量可以是0，所以i从0开始枚举
            for ( int j = 1; j <= n; j++ )
            {
                dp[i][j] = dp[i][j-1];
                if ( j <= i ) dp[i][j] += dp[i-j][j];
            }

        printf( "%d\n", dp[m][n] );

        memset( dp, 0, sizeof(dp) );
    }
    return 0;
}

//完全背包dp
/*
状态表示：dp[i][j][k]表示所有从能量值为 0 ~ i 的分身中选，且总能量和为 j 且有 k 个分身的方案的集合
状态划分：
    1.不选能量值为 i 的分身：dp[i][j][k] += dp[i-1][j][k].
    2.选u个能量值为 i 的分身：dp[i][j][k] += dp[i][j-u*i][k-u].
*/
//朴素写法
#include<stdio.h>
#include<string.h>

int t, n, m;
int dp[15][15][15];

int main ( int argc, char *argv[] )
{
    scanf( "%d", &t );

    while ( t-- )
    {
        scanf( "%d%d", &m, &n );

        //本题初始条件：
        /*只选0个能量的分身，可以一直选到第 n-1 个分身，这些都是1种方案
        如果不先把只选0个能量的分身的情况全部讨论掉，就需要在后面将i从0
        开始讨论，i = 0 时会出现负下标*/
        for ( int i = 0; i < n; i++ ) dp[0][0][i] = 1;
        
        for ( int  i = 1; i <= m; i++ )
            for ( int j = 0; j <= m; j++ )
                for ( int k = 0; k <= n; k++ )
                {
                    dp[i][j][k] = dp[i-1][j][k];
                    for ( int u = 1; u*i <= j && u <= k; u++ )
                        dp[i][j][k] += dp[i-1][j-u*i][k-u];
                }
            
        printf( "%d\n", dp[m][m][n] );

        memset( dp, 0, sizeof(dp) );
    }

    return 0;
}

//u循环优化
//dp[i][j][k] = dp[i-1][j][k] + dp[i][j-i][k-1] 注意条件要满足 j >= i 
#include<stdio.h>
#include<string.h>

int t, n, m;
int dp[15][15][15];

int main ( int argc, char *argv[] )
{
    scanf( "%d", &t );

    while ( t-- )
    {
        scanf( "%d%d", &m, &n );

        for ( int i = 0; i < n; i++ ) dp[0][0][i] = 1;
        
        for ( int  i = 1; i <= m; i++ )
            for ( int j = 0; j <= m; j++ )
                for ( int k = 0; k <= n; k++ )
                {
                    dp[i][j][k] = dp[i-1][j][k];
                    if ( j >= i && k > 0 ) 
                        dp[i][j][k] = dp[i-1][j][k] + dp[i][j-i][k-1];
                }
            
        printf( "%d\n", dp[m][m][n] );

        memset( dp, 0, sizeof(dp) );
    }

    return 0;
}

//i循环优化
//思路
#include<stdio.h>
#include<string.h>

int t, n, m;
int dp[15][15];

int main ( int argc, char *argv[] )
{
    scanf( "%d", &t );

    while ( t-- )
    {
        scanf( "%d%d", &m, &n );

        for ( int i = 0; i < n; i++ ) dp[0][i] = 1;
        
        for ( int  i = 1; i <= m; i++ )
            for ( int j = 0; j <= m; j++ )
                for ( int k = 0; k <= n; k++ )
                {
                    //不选，可以省略
                    dp[j][k] = dp[j][k];
                    //dp[i][j][k] = dp[i-1][j][k];

                    //选
                    if ( j >= i && k > 0 ) 
                        dp[j][k] = dp[j][k] + dp[j-i][k-1];   
                        //dp[i][j][k] = dp[i-1][j][k] + dp[i][j-i][k-1];
                        //此处要求就用到当前i循环的数据，所以j是从小到大遍历
                }
            
        printf( "%d\n", dp[m][n] );

        memset( dp, 0, sizeof(dp) );
    }

    return 0;
}

//最终结果
#include<stdio.h>
#include<string.h>

int t, n, m;
int dp[15][15];

int main ( int argc, char *argv[] )
{
    scanf( "%d", &t );

    while ( t-- )
    {
        scanf( "%d%d", &m, &n );

        for ( int i = 0; i < n; i++ ) dp[0][i] = 1;
        
        for ( int  i = 1; i <= m; i++ )
            for ( int j = i; j <= m; j++ )
                for ( int k = 1; k <= n; k++ )
                    dp[j][k] = dp[j][k] + dp[j-i][k-1];
            
        printf( "%d\n", dp[m][n] );

        memset( dp, 0, sizeof(dp) );
    }

    return 0;
}