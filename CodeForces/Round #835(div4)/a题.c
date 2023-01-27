#include<stdio.h>
int main ( int argc, char grgv[] )
{
    int n;
    scanf( "%d",&n );
    while( n-- ) {
        int a,b,c,box;
        scanf( "%d %d %d",&a,&b,&c);
        if ((a>b&&a<c)||(a>c&&a<b)) {
            printf( "%d\n",a );
        }
        if ((b>a&&b<c)||(b>c&&b<a)) {
            printf( "%d\n",b );
        }
        if ((c>b&&c<a)||(c>a&&c<b)) {
            printf( "%d\n",c );
        }
    }
    return 0;
}   