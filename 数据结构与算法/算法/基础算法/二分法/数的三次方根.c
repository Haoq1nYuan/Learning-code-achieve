//https://www.acwing.com/problem/content/792/

#include<stdio.h>

double n;
double mid, r, l;

int main ( int argc, char *argv[] )
{
    
    scanf( "%lf", &n );
    l = -10000;
    r = 10000;
    while ( r-l > 1e-8 ) {
        mid = ( l + r ) / 2;
        if ( mid * mid * mid >= n ) r = mid;
        else l = mid;
    }

    printf( "%.6lf\n", r );

    return 0;
}