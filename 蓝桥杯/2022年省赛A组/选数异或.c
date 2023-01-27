#include<stdio.h>

#define N 100010
#define M (int)(2e7)
#define max(c,b) c>b?c:b
 
long int n, m, x, l, r, A;
long int last[M], a[N];

int main ( int argc, char *argv[] )
{
    int i;
    scanf( "%ld %ld %ld", &n, &m, &x );
    for ( i = 1; i<=n; i++ ) {
        scanf( "%ld", &A );
        a[i] = max( a[i-1], last[A ^ x] );
        last[A] = i;
    }
    while ( m-- ) {
        scanf( "%ld %ld", &l, &r );
        if ( a[r] >= l )
            printf( "yes\n" );
        else
            printf( "no\n" );
    }
    return 0;
}