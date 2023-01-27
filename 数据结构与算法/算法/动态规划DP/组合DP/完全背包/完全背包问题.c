//https://www.acwing.com/problem/content/3/

//完全背包DP
/*
状态定义：dp[i][j]表示一个包含“从前i个物品中选，且总体积不超过j”的所有方案的总价值的集合，
         属性是max，注意，此处不是一共选i个物品
状态划分：
    1.第i个不选：dp[i][j] = dp[i-1][j]
    2.第i个选了k个(k>=1)：
        选1个：dp[i][j] = dp[i-1][j-v[i]] + w[i]
        选k个：dp[i][j] = dp[i-1][j-v[i]*k] + w[i]*k
    3.最后取最大值即可
*/

//朴素写法---TLE
/* #include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 1010

int n, V, w[N], v[N];
int dp[N][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &V );
    for ( int i = 1; i <= n; i++ ) 
        scanf( "%d%d", &v[i], &w[i] );
    
    for ( int i = 1; i <= n; i++ )
        for ( int j = 0; j <= V; j++ )
            for ( int k = 0; k*v[i] <= j; k++ )
                dp[i][j] = max( dp[i][j], dp[i-1][j-k*v[i]] + w[i]*k );

    printf( "%d\n", dp[n][V] );
    
    return 0;
} */

//优化掉k层循环
/*
dp[i][j] = max( dp[i-1][j], dp[i-1][j-v[i]]+w[i], dp[i-1][j-2*v[i]]+2*w[i],……, dp[i-1][0]+j )
dp[i][j-x[i]] = max(        dp[i-1][j-v[i]]     , dp[i-1][j-2*v[i]]+  w[i],……, dp[i-1][0]+j-w[i] )
两式相结合：dp[i][j] = max( dp[i-1][j], dp[i][j-v[i]]+w[i] ).这样可以优化掉k层循环
*/
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 1010

int n, V, w[N], v[N];
int dp[N][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &V );
    for ( int i = 1; i <= n; i++ ) 
        scanf( "%d%d", &v[i], &w[i] );
    
    for ( int i = 1; i <= n; i++ )
        for ( int j = 0; j <= V ; j++ )
        {
            //for ( int k = 0; k*v[i] <= j; k++ )
                //dp[i][j] = max( dp[i][j], dp[i-1][j-k*v[i]] + w[i]*k );
            //此处因为省略了k层循环，所以不选的情况没办法用 k = 0 时 dp[i][j] = do[i-1][j] 顺带计算，故必须先写上以便后面进行max比较
            //不选
            dp[i][j] = dp[i-1][j];
            //选k个
            if ( j >= v[i] ) dp[i][j] = max( dp[i][j], dp[i][j-v[i]] + w[i] );
        }  

    printf( "%d\n", dp[n][V] );
    
    return 0;
}

//优化掉v,w数组
/*
在上面一部优化中我们可以发现，每次i循环只用到了v[i],w[i]，所以可以省略掉读入这两个数组的操作，直接在每次i循环后读入该i对应的价值和体积
*/
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 1010

int n, V, w, v;
int dp[N][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &V );
    
    for ( int i = 1; i <= n; i++ )
    {
        scanf( "%d%d", &v, &w );
        for ( int j = 0; j <= V ; j++ )
        {
            //for ( int k = 0; k*v[i] <= j; k++ )
                //dp[i][j] = max( dp[i][j], dp[i-1][j-k*v[i]] + w[i]*k );
            //此处因为省略了k层循环，所以不选的情况没办法用 k = 0 时 dp[i][j] = do[i-1][j] 顺带计算，故必须先写上以便后面进行max比较
            //不选
            dp[i][j] = dp[i-1][j];
            //选k个
            if ( j >= v ) dp[i][j] = max( dp[i][j], dp[i][j-v] + w ); 
        } 
    } 

    printf( "%d\n", dp[n][V] );
    
    return 0;
}

//滚动数组优化空间
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 1010

int n, V, w, v;
int dp[2][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &V );

    for ( int i = 1; i <= n; i++ )
    {
        scanf( "%d%d", &v, &w );
        for ( int j = 0; j <= V ; j++ )
        {
            //for ( int k = 0; k*v[i] <= j; k++ )
                //dp[i][j] = max( dp[i][j], dp[i-1][j-k*v[i]] + w[i]*k );
            //此处因为省略了k层循环，所以不选的情况没办法用 k = 0 时 dp[i][j] = do[i-1][j] 顺带计算，故必须先写上以便后面进行max比较
            //不选
            dp[i&1][j] = dp[(i-1)&1][j];
            //选k个
            if ( j >= v ) dp[i&1][j] = max( dp[i&1][j], dp[i&1][j-v] + w );
        }  
    }

    printf( "%d\n", dp[n&1][V] );
    
    return 0;
}

//二维转一维优化
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 1010

int n, V, w, v;
int dp[N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &V );
    
    for ( int i = 1; i <= n; i++ )
    {
        scanf( "%d%d", &v, &w );
        /*注意下面j是从小到大循环，和0-1背包问题优化不同
        因为替换掉的是dp[i][j-v]，完全背包问题要求第i层每个j的计算是用到的都是第本层的数据
        从小到大循环可以保证在计算较大的j时 j - v 已经被更新过*/
        for ( int j = v; j <= V ; j++ )   
        {                                 
            //dp[i][j] = dp[i-1][j];
            //不选的情况换为：dp[j] = dp[j]，可以直接省略

            //选k个
            dp[j] = max( dp[j], dp[j-v] + w );
            //dp[i][j] = max( dp[i][j], dp[i][j-v] + w );
            //在算dp[j]的时候dp[j-v]已经被算出来了，且就在第i层，所以是等价变换
        }
    }

    printf( "%d\n", dp[V] );
    
    return 0;
}

//最终代码
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 1010

int n, V, w, v;
int dp[N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &V );
    
    for ( int i = 1; i <= n; i++ )
    {
        scanf( "%d%d", &v, &w );
        for ( int j = v; j <= V ; j++ ) 
            dp[j] = max( dp[j], dp[j-v] + w );
    }

    printf( "%d\n", dp[V] );
    
    return 0;
}