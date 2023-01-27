#include<stdio.h>
#include<string.h>

#define N 200000
#define max(a,b) ( (a)>(b)?(a):(b) )

long long int a[N];

int set ( int box, long long int *a ) {
    int count=0, i, j;
    for ( i=0; i<box-1; i++ ) {
        if ( a[i] == 1 ) {
            for ( j=i+1; j<box; j++ ) {
                if ( a[j] == 0 ) {
                    count++;
                }
            }
        } 
    }    
    return count;
}

int main ( int argc, char * argv[] )
{
    int n;
    scanf( "%d",&n );
    while ( n-- ) {
        int num, i, j, box, p;
        long long int result;
        memset( a, 0, sizeof(a) );
        scanf( "%d",&num );
        i = 0;
        while ( num-- ) {
            scanf( "%lld",&a[i] );
            i++;
        }
        box = i;
        result = set( box, a );
        for ( i=0; i<box; i++ ) {
            if ( a[i] == 0 ) {
                a[i] = 1;
                p = i;
                break;
            }
        }
        result = max( set( box, a ), result );
        a[p] = 0;
        for ( i=box-1; i>=0; i-- ) {
            if ( a[i] == 1 ) {
                a[i] = 0;
                break;
            }
        }
        result = max( set( box, a ), result );
        printf( "%lld\n",result );
    }
    return 0;
}
