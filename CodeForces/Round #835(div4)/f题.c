#include<stdio.h>

#define N 200000

long long int a[N];

void sort ( long long int *a, int length ) 
{ 
    int i, j, box;
    for ( i=0; i<length-1; i++ ) {
        for ( j=i+1; j<length; j++ ) {
            if ( a[j]>a[i] ) {
                box = a[i];
                a[i] = a[j];        
                a[j] = box;
            }
        }
    }
}

int set ( int k, int d, long long int c, long long int *a )
{
    int result = 0, i = 0, count = 0;
    while ( d > 0 ) {
        if ( count < k ) {
            if ( i < sizeof(a)/sizeof(a[0]) ) {
                c -= a[i];
                i++;
                count++;
            } else if ( i == sizeof(a)/sizeof(a[0]) ) {
                count++;
                i = 0;
            }
        } else if ( count == k ) {
                count = 1;
                c -= a[0];
        }
        d--;
    }
    if ( c <= 0 ) {
        result = 1;
    }
    return result;
}

int main ( int argc, char * argv[] ) 
{
    int n;
    scanf( "%d",&n );
    while ( n-- ) {
        int t, i, d, length, head, tail, k, box;
        long long int c;
        scanf( "%d %lld %d",&t, &c, &d );
        i = 0;
        while ( t-- ) {
            scanf( "%lld",&a[i++] );
        }
        box = i;
        length = sizeof(a)/sizeof(a[0]);
        sort( a, length );
        head = 0;
        tail = box;
        while ( head <= tail ) {
            k = ( head + tail )/2;
            if ( set( k, d, c, a ) ) {
                head = k+1;
            } else {
                tail = k-1;
            }
        }
        if ( head == box+1 ) {
            printf( "Infinity\n" );
        } else if ( tail == -1 ) {
            printf( "Impossible\n" );
        } else {
            printf( "%d\n",k );
        }
    }
    return 0;
}