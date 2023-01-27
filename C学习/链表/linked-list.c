#include <stdio.h>
#include "node.h"
#include <stdlib.h>

/* typedef struct _node {
    int value;
    struct _node *next;
} Node; */

int main ( int argc, char const *argv[] ) 
{
    Node * head =NULL;  //设置一个链表头
    int number;
    do {
        scanf("%d", &number);
        if(number!=-1){

            //add to the linked-list
            Node *p=(Node*)malloc(sizeof(Node));  //创建新的链表块，但是此时还未被使用，只是脱离链表主体单独存在的，需要调用的时候就被调用
            p->value = number;
            p->next = NULL;

            //find the last
            Node *last = head;
            if ( last ) {     //NULL的->是无效的，即last->head在head=NULL时是无效的，故需要实事先讨论是否为空链表
                while( last->next ) {    //给第n个链表块赋值（n>1）
                    last = last->next;   //当下一个链表块为NULL时，last正好停在上一个有number的链表块中
                }
                //attach
                last->next = p;
            } else {
                head = p;   //将head赋值为p，同时给第一个链表块（即此时last所指的结构体）赋值，这个过程之后last->next更新为NULL
            }
            
        }
    } while ( number!=-1 );
    Node *result = head;
    while ( result ) {
        printf( "%d\n", result->value );
        result = result->next;
    }
    return 0;
}