#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 200000

int set ( long long int *a, int i, int j, int length ) 
{
    int isprime=1, l;
    if ( i!=0 && a[i-1]<=a[i] ) {
        isprime = 0;
    }
    if ( j!=length && a[j]>=a[j+1] ) {
        isprime = 0;
    }
    return isprime;
}

int main ( int argc, char * argv[] ) 
{
    int n;
    scanf( "%d",&n );
    while ( n-- ) {
        int i, j, length, count=0, flag=0;
        long long int a[N];
        memset( a, 0, sizeof(a) );
        scanf( "%d",&length );
        while ( count!=length ) {
            scanf( "%lld",&a[count] ); 
            count++;
        }
        for ( i=0; i<length; i++ ) {
            for ( j=i; a[j]==a[j+1]; j++);   //这种表示方法就包括了j=length-1的情况
            if ( set(a,i,j,length-1) ) {
                flag++;
            }
            i = j;  
        }
        if ( flag==1 ) {
            printf( "YES\n" );
        } else {
            printf( "NO\n" );
        }
    }
    return 0;
}