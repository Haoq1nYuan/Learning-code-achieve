//https://www.acwing.com/problem/content/792/

#include<stdio.h>

double n;
double mid, r, l;

int main ( int argc, char *argv[] )
{
    
    scanf( "%lf", &n );
    l = -10000;
    r = 10000;
    //题目要求保留到 n 位小数，我们一般把条件设成 n + 2 位小数，这样可以避免四舍五入的误差
    while ( r-l > 1e-8 ) {
        mid = ( l + r ) / 2;
        if ( mid * mid * mid >= n ) r = mid;
        else l = mid;
    }

    printf( "%.6lf\n", r );

    return 0;
}