//https://www.acwing.com/problem/content/description/904/

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
#include <stdio.h>
#define min(a,b) ((a)>(b)?(b):(a))
#define N 1010

int n, m;
char a[N], b[N];
int dp[N][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%s", &n, a+1 );
    getchar();
    scanf( "%d%s", &m, b+1 );
    
    //考虑到之后会用到下标为0的情况，所以需要初始化
    //如果需要将a的前i个字母与b的前0个字母匹配，则只能用删除操作且操作数为i
    for ( int i = 0; i <= n; i++ ) dp[i][0] = i;
    //如果需要将a的前0个字母与b的前i个字母匹配，则只能用添加操作且操作数为i
    for ( int i = 0; i <= m; i++ ) dp[0][i] = i;

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
        {
            dp[i][j] = min( dp[i-1][j] + 1, dp[i][j-1] + 1 );
            if ( a[i] == b[j] ) dp[i][j] = min( dp[i][j], dp[i-1][j-1] );
            else dp[i][j] = min( dp[i][j], dp[i-1][j-1] + 1 );  
        }

    printf( "%d\n", dp[n][m] );

    return 0;
}