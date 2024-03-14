//https://www.acwing.com/problem/content/95/

//自己写的
/* #include<stdio.h>

int n, m;
int state[26];

void ans ( int u )
{   
    if ( u > m ) 
    {
        for ( int i = 1; i <= m; i++ ) 
            printf( "%d ", state[i] );
        printf( "\n" );
        return;
    }

    for ( int j = 1; j <= n; j++ ) 
    {
        if ( j > state[u-1] )   //此处附加的条件是为了保证后面一个数始终大于前面一个数
        {
            state[u] = j;
            ans( u+1 );
        }
    }
}

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &m );

    ans( 1 );

    return 0;
}
 */

//y总解答
/* #include<stdio.h>

int n, m;
int a[26];

void ans ( int u, int start )
{
    if ( u > m )
    {
        for ( int i = 1; i <= m; i++ ) 
            printf( "%d ", a[i] );
        printf( "\n" );

        return;
    }

    for ( int i = start; i <= n; i++ )
    {
        a[u] = i;
        ans( u+1, i+1 );
        //a[u] = 0;
    }
}

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &m );

    ans( 1, 1 );

    return 0;
} */

//剪枝优化
#include<stdio.h>

int n, m;
int a[26];

void ans ( int u, int start )
{
    if ( u + n - start < m ) return;   
    //此处为剪枝，表示如果数位u-1和它后面能枚举的大于start的数的总数量(即n-start+1)小于m的话，则直接返回。
    //u-1+n-start+1 = u+n-start < m

    if ( u > m )
    {
        for ( int i = 1; i <= m; i++ ) 
            printf( "%d ", a[i] );
        printf( "\n" );

        return;
    }

    for ( int i = start; i <= n; i++ )
    {
        a[u] = i;
        ans( u+1, i+1 );
        //a[u] = 0;
    }
}

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &m );

    ans( 1, 1 );

    return 0;
}