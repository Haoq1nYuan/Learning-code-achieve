#include<stdio.h>

void Printout ( unsigned long long N ) ;

void Printdigit ( int result ) ;

int main ( int argc, char argv[] ) 
{
    int long long N;
    scanf( "%lld", &N );
    Printout( N );
    return 0;
}

void Printout ( unsigned long long N )
{
    if ( N>=10 ) {
        Printout ( N/10 ) ;   //简单递归
    }
    Printdigit ( N%10 ) ;   //此处调用不能加else语句，虽然在上面的if语句中已经进入到下一层的Printout函数中去了，但是外面一层函数的语句还是要执行完
}

void Printdigit ( int result ) 
{
    printf( "%d\n", result );
}