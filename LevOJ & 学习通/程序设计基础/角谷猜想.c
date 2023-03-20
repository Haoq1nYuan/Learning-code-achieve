#include<stdio.h>

int main ( int argc, char * argv[] ) 
{   
    int n, count = 0;
    scanf( "%d",&n );
    do {
        if ( n%2==0 ) {   
            n/=2;
        } else if ( n%2 ) {
            n = (3*n+1)/2;
        } 
        count++;
    } while ( n != 1 );
    printf( "%d\n",count );
    return 0;
}