//https://www.acwing.com/problem/content/719/

//递推解法
/* #include<stdio.h>

int n, f[46];

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );

    f[1] = 0;
    f[2] = 1;

    for ( int i = 3; i <= n ; i++ ) 
        f[i] = f[i-1] + f[i-2];

    for ( int i = 1; i <= n; i++ )
        printf( "%d ", f[i] );

    return 0;
} */

//滚动数组优化(用2个变量代替数组，节省空间)
#include<stdio.h>

int n;

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );

    int a = 0, b = 1;
    for ( int i = 1; i <= n; i++ ) 
    {
        printf( "%d ", a );
        int sum = a + b;
        a = b;
        b = sum;
    }

    return 0;
}
