/*
-------题目描述-------

小邋遢 MS.Jinlin 是个爱打扮的公主，他有很多晚礼服如 "LALA" "NIHAOMA" "WOBUHAO" "NIHAOBUHAO" 等众多衣服，
可是由于衣服太多他要把它们装进箱子，但是作为公主，肯定是会突发奇想觉得哪件衣服好看，就把他拿了出来，
当然那件衣服上面的衣服也被拿出来了，而且会弄乱了，小邋遢在经过几次的叠衣服和取衣服后，他想知道箱子里最上面的衣服是哪一件，
如果箱子为空的话，就告诉她 Empty ，如果有多件一样的衣服，肯定是取走最上面的哪一件啦。

-------输入描述-------

第 1 行，输入N，代表共计进行了几次操作。

第 2 行至第 N+1 行，进行 in out 操作（in 为 放入衣服，out 为 取出衣服）

格式如下：

    in name1
    out name2

-------输出描述-------

输出 NN 次操作结束后箱子最上面的衣服名字，若箱子为空，输出 Empty。
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int N, i;
char s1[3], s2[10];

typedef struct stack
{
    int capacity; //本题中无需检查是否爆栈，故capacity就没有用了，但是为了规范，还是保留在这
    int number;
    char **Array;
} S;

void in ( char *name, S *clothes )
{
    strcpy( clothes->Array[ ++clothes->number ], name ) ;
}

void out ( char *name, S *clothes )
{
    while ( strcmp( clothes->Array[clothes->number], name ) != 0 ) 
        clothes->number--;
    clothes->number--;
}

int main ( int argc, char *argv[] ) 
{   
    scanf( "%d", &N );

    S *clothes = ( S* )malloc( sizeof( S ) );
    clothes->Array = ( char** )malloc( sizeof( char* ) * ( N + 1 ) );
    for ( i = 0; i <= N; i++ ) 
    {
        clothes->Array[i] = ( char* )malloc( sizeof( char ) * 10 );
        memset( clothes->Array[i], '0', 10 );
    }
    clothes->capacity = N;
    clothes->number = 0;

    while ( N-- ) 
    {
        scanf( "%s %s", s1, s2 );
        getchar();
        if ( strcmp( s1, "in" ) == 0 ) 
            in( s2, clothes );
        if ( strcmp( s1, "out" ) == 0 ) 
            out( s2, clothes );
    }   

    if ( clothes->number != 0 ) 
        printf( "%s\n", clothes->Array[clothes->number] );
    else 
        printf( "Empty\n" );

    for ( i = 0; i <= N; i++ ) 
        free( clothes->Array[i] );
    free( clothes->Array );
    free( clothes );

    return 0;
}