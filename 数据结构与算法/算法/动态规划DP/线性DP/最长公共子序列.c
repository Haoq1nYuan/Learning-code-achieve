//https://www.acwing.com/problem/content/899/

//线性dp
/*
状态表示：dp[i][j]表示所有在a[1]~a[i]与b[1]~b[j]范围内的公共子序列的长度的集合，属性是max
状态划分：
    1.选a[i]但不选b[j]：dp[i][j] = dp[i][j-1]
    2.选a[i]和b[j]：如果 a[i] == b[i], 则 d[i][j] = d[i-1][j-1] + 1
    3.不选a[i]但选b[j]：dp[i][j] = dp[i-1][j]
    4.都不选：dp[i][j] = dp[i-1][j-1]      
    在上述情况1中，dp[i][j-1] 又包含选 a[i] 或不选 a[i] 的情况，
    会造成判断重复，但是本题要求max，重复不会对结果造成影响.情况3也是这样
    不过通过观察发现，情况4又被包含在情况3和情况1中，故可以省略掉情况4的讨论
    并且情况4恒比情况2小1，所以可以直接省略
*/
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 1010

int n, m;
char a[N], b[N];
int dp[N][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &m );
    getchar();
    gets(a+1);
    gets(b+1);

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
        {
            dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
            if ( a[i] == b[j] ) dp[i][j] = max( dp[i][j], dp[i-1][j-1] + 1 );
        }

    printf( "%d\n", dp[n][m] );

    return 0;
}

//如果说要在输出最长长度的同时输出该最长公共子序列呢？
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 1010

int n, m;
char a[N], b[N], ans[N];
int dp[N][N];

char *specific ( char *ans, char *a, char *b )
{
    int i = n, j = m;
    int k = dp[n][m];

    while ( k )
    {
        if ( dp[i][j] == dp[i-1][j] ) i--;  //不选a[i]但选b[i]
        else if ( dp[i][j] == dp[i][j-1] ) j--;  //不选b[i]但选a[i]
        else   //都选的情况，才能读入字符
        {
            ans[--k] = a[i];
            i--;
            j--;
        }
    } 

    return ans;
}

int main ( int argc, char *argv[] )
{
    scanf( "%d%d%s%s", &n, &m, a+1, b+1 );

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
        {
            dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
            if ( a[i] == b[j] ) dp[i][j] = max( dp[i][j], dp[i-1][j-1] + 1 );
        }

    printf( "%d\n", dp[n][m] );
    printf( "%s\n", specific( ans, a, b ) );    

    return 0;
}