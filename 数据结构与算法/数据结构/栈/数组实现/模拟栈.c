//https://www.acwing.com/problem/content/830/

//一目了然写法
/* #include<stdio.h>
#define N 100010

int m, num;
char how[10];
int stk[N], t;

void add ( int x )
{
    stk[++t] = x;
}

void delete ()
{
    t--;
}

int empty ()
{
    return t > 0 ;
}

int get ()
{
    return stk[t];
}

int main ( int argc, char *argv[] )
{
    scanf( "%d", &m );

    while ( m-- )
    {
        scanf( "%s", how );

        if ( how[0] == 'p' && how[1] == 'u' ) 
        {
            scanf( "%d", &num );
            add(num);
        }
        else if ( how[1] == 'o' ) delete();
        else if ( how[0] == 'e' ) 
        {
            if ( empty() ) printf( "NO\n" );
            else printf( "YES\n" );
        }
        else
        {
            printf( "%d\n", get() ); 
        }
    } 

    return 0;
} */

//简洁写法
#include<stdio.h>
#define N 100010

int m, num;
char how[10];
int stk[N], t;

int main ( int argc, char *argv[] )
{
    scanf( "%d", &m );

    while ( m-- )
    {
        scanf( "%s", how );

        if ( how[0] == 'p' && how[1] == 'u' ) 
        {
            scanf( "%d", &num );
            stk[++t] = num;
        }
        else if ( how[1] == 'o' ) t--;
        else if ( how[0] == 'e' ) 
        {
            if ( t ) printf( "NO\n" );
            else printf( "YES\n" );
        }
        else printf( "%d\n", stk[t] ); 
    } 

    return 0;
}
