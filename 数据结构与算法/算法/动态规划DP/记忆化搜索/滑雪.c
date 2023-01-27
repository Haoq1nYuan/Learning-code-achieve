//https://www.acwing.com/problem/content/903/

//记忆化搜索

//本题的路径长是算上起点的，所以说已被计算过的点的值最小为1
//故无需将所有点的值初始化为-1

/*
状态表示：dp[i][j]表示所有从(i,j)开始划的路线的长度的集合，属性是max
状态计算：
    由于整个矩阵是无规则排列的，所以可能出现某个值在用到的时候还未被计算出来，所以必须用到DP函数的递归
    对于向哪划，可以用偏移量解决
*/
#include <stdio.h>
#define max(c,d) ((c)>(d)?(c):(d))
#define N 305

int r, c, h[N][N], ans;
int dp[N][N];

int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };  //从左往右分别是向上，向右，向下，向右

int DP ( int x, int y )
{
    //防止重复计算相同位置的路径最大值，降低复杂度
    if ( dp[x][y] ) return dp[x][y];  //如果dp[x][y]不为0，说明已经被计算过了

    //初始化要计算的位置的值，一开始就是一个单位长度
    dp[x][y] = 1;
    for ( int i = 0; i <= 3; i++ )
    {
        int a = x + dx[i];
        int b = y + dy[i];
        if ( a >= 1 && a <= r && b >= 1 && b <= c && h[x][y] > h[a][b] )
            dp[x][y] = max( dp[x][y], DP(a, b) + 1 );
    }

    return dp[x][y];
}

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &r, &c );
    for ( int i = 1; i <= r; i++ )
        for ( int j = 1; j <= c; j++ )  
            scanf( "%d", &h[i][j] );

    for ( int i = 1; i <= r; i++ )
        for ( int j = 1; j <= c; j++ )
            ans = max( ans, DP(i, j) );

    printf( "%d\n", ans );

    return 0;
}