#include<stdio.h>

int main ( int argc, char * argv[] ) 
{
    int i, j, n, c;
    while ( scanf( "%d",&n )!=EOF ) {
        c = 0;
        for( i=5; i<=n; i+=5 ){
            j=i;
            while( j%5 == 0 ){
                c++;
                j/=5;
            }
        }
        printf( "%d\n",c );
    }
    return 0;
}