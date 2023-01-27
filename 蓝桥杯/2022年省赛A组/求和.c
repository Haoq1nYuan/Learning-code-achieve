#include<stdio.h>

#define N 200000 

int a[N];

int main ( int argc, char *argv[] ) 
{
    int i, box, j, length;
    long int S = 0, n, sum = 0;
    scanf( "%ld",&n );
    i = 0;
    while ( n-- ) {
        scanf( "%d",&a[i] );
        sum += a[i];
        i++;
    }
    box = i;
    for ( i=0; i<box-1; i++ ) {
        sum -= a[i];
        S += a[i]*sum;
    }
    printf( "%ld\n",S );
    return 0;
}
