//https://www.acwing.com/problem/content/1218/

#include<stdio.h>

int n, res;

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );

    res = n;
    while ( n > 2 )
    {
        res += n/3;
        n -= n/3 * 2;   //注意这边除法运算是在*2前面的
    }

    printf( "%d\n", res );

    return 0;
}