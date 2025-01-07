#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char s1[5], s2[20], c;
int M, i;

typedef struct queue 
{
    int capacity;
    int number;
    int front;
    int rear;
    char **name;
} Q;

void origin ( Q *queue )
{
    queue->name = ( char** )malloc( sizeof( char* ) * ( M + 1 ) );
    for ( i = 0; i <= M; i++ ) {
        queue->name[i] = ( char* )malloc( 20 );
        memset( queue->name[i], '0', 20 ); 
    }    
    queue->capacity = M;
    queue->number = 0;
    queue->front = 1;
    queue->rear = 0;
}

void in ( char *name, Q *queue )
{
    queue->rear++;
    queue->number++;
    strcpy( queue->name[ queue->rear ], name );
}

void out ( Q *queue )
{
    memset( queue->name[ queue->front ], '0', 20 );
    queue->front++;
    queue->number--;
}

void print ( Q *queue )
{
    while ( queue->number > 0 ) {
        printf( "%s\n", queue->name[ queue->front ] );
        memset( queue->name[ queue->front ], '0', 20 );    
        queue->front++;
        queue->number--;
    }
}

void Free ( Q *queue ) 
{
    for ( i = 0; i <= M; i++ ) {
        free( queue->name[i] );
    }
    free( queue->name );
    free( queue );
}

int main ( int argc, char *argv[] )
{
    scanf( "%d", &M );
    
    Q *vip = ( Q* )malloc( sizeof(Q) );
    Q *normal = ( Q* )malloc( sizeof(Q) );
    origin( vip );
    origin( normal );

    while ( M-- ) {
        scanf( "%s", s1 );
        if ( s1[0] == 'I' ) {
            scanf( "%s", s2 );
            getchar();
            scanf( "%c", &c );
            if ( c == 'V' ) 
                in( s2, vip );
            else if ( c == 'N' )
                in( s2, normal ); 
        } else if ( s1[0] == 'O' ) {
            getchar();
            scanf( "%c" , &c );
            if ( c == 'V' ) 
                out( vip );
            else if ( c == 'N' ) 
                out( normal );
        }
    }

    print( vip );
    print( normal );

    Free( vip );
    Free( normal );

    return 0;
}