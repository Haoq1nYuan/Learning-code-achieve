//Í¨Ë×Ð´·¨
/* #include <iostream>
#include <cstdio>

using namespace std;

int a, b, c, d;

int main ()
{
    cin >> a >> b >> c >> d;

    if ( a < c )
    {
        if ( b <= d ) printf( "O JOGO DUROU %d HORA(S) E %d MINUTO(S)", c-a, d-b );
        else printf( "O JOGO DUROU %d HORA(S) E %d MINUTO(S)", c-a-1, 60-b+d );
    }
    else if ( a > c )
    {
        if ( b <= d ) printf( "O JOGO DUROU %d HORA(S) E %d MINUTO(S)", 24-a+c, d-b );
        else printf( "O JOGO DUROU %d HORA(S) E %d MINUTO(S)", 23-a+c, 60-b+d );
    }
    else 
    {   if ( b < d ) printf( "O JOGO DUROU %d HORA(S) E %d MINUTO(S)", 0, d-b );
        else if ( b > d )printf( "O JOGO DUROU %d HORA(S) E %d MINUTO(S)", 23, 60-b+d );
        else printf( "O JOGO DUROU %d HORA(S) E %d MINUTO(S)", 24, 0 );
    }

    return 0;
} */

//¼ò½àÐ´·¨
#include <iostream>
#include <cstdio>

using namespace std;

int a, b, c, d;

int main ()
{
    cin >> a >> b >> c >> d;

    b += a*60;
    d += c*60;
    a = ( d - b + 60 * 24 ) % ( 24 * 60 );
    a = a ? a : ( 24 * 60 );

    printf( "O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", a/60, a%60 );

    return 0;
}