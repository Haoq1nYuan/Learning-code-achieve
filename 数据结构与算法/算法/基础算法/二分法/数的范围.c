//https://www.acwing.com/problem/content/791/

#include<stdio.h>
#define N 100010
#define M 10010

long n, i;
long r, l, mid, s, e, ans[M][3];
int q, k, a[N];

int main ( int argc, char *argv[] )
{ 
    scanf( "%ld%d", &n, &q );
    for ( i = 0; i < n; i++ ) 
        scanf( "%d", &a[i] );

    for ( i = 0; i < q; i++ ) {
        scanf( "%d", &k );
        l = 0;
        r = n-1;
        while ( l < r ) {
            mid = ( l+r ) / 2;
            if ( a[mid] >= k ) r = mid;
            else l = mid + 1;
        }
        if ( a[l] == k ) {
            ans[i][0] = l;
            l = 0;
            r = n-1;
            while ( l < r ) {
                mid = ( l+r+1 ) / 2;
                if ( a[mid] <= k ) l = mid;
                else r = mid - 1;
            }
            ans[i][1] = r;
        } else {
            ans[i][0] = -1;
            ans[i][1] = -1;
        }
    }

    for ( i = 0; i < q; i++ ) 
        printf( "%ld %ld\n", ans[i][0], ans[i][1] );

    return 0;
}