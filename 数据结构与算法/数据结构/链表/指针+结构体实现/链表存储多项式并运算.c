#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int number, power, time;
int Time[2];
int i = 0;

typedef struct num
{
    int number;
    int power;
    struct num *next;
} N;

void create ( N *head )
{
    N *position = head;
    scanf( "%d", &time );
    Time[i++] = time;
    while ( time-- ) {
        scanf( "%d %d", &number, &power );
        N *newcode = ( N* )malloc( sizeof( N ) );
        newcode->number = number;
        newcode->power = power;
        newcode->next  = NULL;
        if ( !position ) {
            head->next = newcode;
        } else {
            while ( position->next ) {
                position = position->next;
            }
            position->next = newcode;
        }
    } 
}

void sum ( N *H1, N *H2 )
{   
    printf( "The sum of the two formulas:\n" );
    printf( "F(x) = " );
    N *head = H1;
    N *head2 = H2; 
    int flag1 = 1, flag2 = 1;
    int box1 = Time[0], box2 = Time[1];    
    while ( box1 && box2 ) {
        if ( flag1 == 1 ) 
            head = head->next;
        if ( flag2 == 1 ) 
            head2 = head2->next;
        flag1 = 1;
        flag2 = 1;
        if ( head->power == head2->power ) {
            if ( head->power ) 
                printf( "%d*x^%d ", head->number + head2->number, head->power ); 
            else 
                printf( "%d\n", head->number + head2->number );
            box1--;
            box2--;
        } else if ( head->power > head2->power ) {
            printf( "%d*x^%d ", head->number, head->power );
            box1--;
            flag2 = 0;
        } else {
            printf( "%d*x^%d ", head2->number, head2->power );
            box2--;
            flag1 = 0;
        }
        if ( box1 > 0 && box2 > 0 ) {
            printf( "+ " );
        }
    }
    if ( box1-- ) {
        head = head->next;
        if ( head->power )
            printf( "%d*x^%d ", head->number, head->number );
        else 
            printf( "%d\n", head->number );
        if ( box1 > 1 ) 
            printf( "+ " );
    }
    if ( box2-- ) {
        head2 = head2->next;
        if ( head2->power )
            printf( "%d*x^%d ", head2->number, head2->power );
        else 
            printf( "%d\n", head2->number );
        if ( box2 > 1 ) 
            printf( "+ " );
    }
}

void multiply ( N *H1, N *H2 )
{
    printf( "The multiply of the two formulas:\n" );
    printf( "F(x) = " );
    int box1 = Time[0], box2 = Time[1];
    N *head = H1->next;
    N *head2 = H2->next;
    int M = head->power + head2->power;
    int *a = ( int* )malloc( sizeof(int) * (M+1) );
    memset( a, 0 , 4 * (M+1) );
    while ( box1-- ) {
        int result;
        int tem = box2;
        N *position = head2;
        while ( tem-- ) {
            a[ head->power + position->power ] += head->number * position->number;
            position = position->next;
        }
        head = head->next;
    }
    int tem = M;
    while ( tem >= 0 ) {
        if ( a[tem] ) {
            if ( tem > 0 ) {
                printf( "%d*x^%d ", a[tem], tem );
                printf( "+ " );
            } else if ( tem == 0 ) {
                printf( "%d\n", a[tem] );
            }
        } else {
            continue;
        }
        tem--;
    }
    free(a);
}

void Free ( N *list )
{
    while ( list->next ) {
        N *p = list->next;
        list->next = p->next;
        free( p );
    }
    free( list );
}
 
int main ( int argc, char *argv[] )
{
    N *head = ( N* )malloc( sizeof( N ) );
    head->next = NULL;
    create( head );

    N *head2 = ( N* )malloc( sizeof( N ) );
    head2->next = NULL;
    create( head2 );

    sum( head, head2 );

    multiply( head, head2 );

    Free( head );
    Free( head2 );

    return 0;
}