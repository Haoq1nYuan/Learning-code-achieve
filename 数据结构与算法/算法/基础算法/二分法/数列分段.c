//https://www.luogu.com.cn/problem/P1182

#include<stdio.h>
#define P 100010

int N, M, i;
long l, r, mid;
long a[P];

int check ( long mid )
{
    int count = 1;
    long sum = mid;
    for ( i = 1; i <= N; i++ ) {
        if ( a[i] <= sum ) {
            sum -= a[i];
        } else {
            sum = mid - a[i];
            count++;
        }
    }
    return count <= M;
}

int main ( int argc, char *argv[] )  
{
    scanf( "%d %d", &N, &M );
    for ( i = 1; i <= N; i++ ) {
        scanf( "%ld", &a[i] );
        l = ( l>a[i]?l:a[i] );
        r += a[i];
    }

    while ( l < r ) {
        mid = ( l + r ) / 2;
        if ( check( mid ) ) r = mid;
        else l = mid + 1;   
    }

    printf( "%ld\n", r );

    return 0;
}