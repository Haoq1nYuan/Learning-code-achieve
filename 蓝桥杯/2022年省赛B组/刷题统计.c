#include<stdio.h>

long long a, b, n, tem;
int day;

int main ( int argc, char *argv[] ) {
    scanf( "%lld %lld %lld", &a, &b, &n );
    tem = n / ( 5*a + 2*b );
    n -= tem * ( 5*a + 2*b );
    while ( n > 0  ) {
        day++;
        if ( day < 6 && day > 0 ) 
            n -= a;
        else if ( day > 5 )
            n -= b;
    }
    printf( "%lld\n", day + 7 * tem );
    return 0;
}