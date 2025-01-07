#include<stdio.h>
#include"node.h"
#include<stdlib.h>

/* typedef struct _node {
    int value;
    struct _node *next;
} Node; */

typedef struct _list
{
    Node * head;    //此处head为指向指针的指针
} List;

void *add(List* pList, int number)   
{
    //add to the linked-list
    Node *p=(Node*)malloc(sizeof(Node));    //创建新的链表块，但是此时还未被使用，只是脱离链表主体单独存在的，需要调用的时候就被调用
    p->value = number;
    p->next = NULL;

    //find the last
    Node *last = pList->head;
    if ( last ) {     //NULL的->是无效的，即last->head在head=NULL时是无效的，故需要事先讨论是否为空链表
        while( last->next ) {    //给第n个链表块赋值（n>1）
            last = last->next;     //当下一个链表块为NULL时，last正好停在上一个有number的链表块中
        }
        //attach
        last->next = p;
    } else {
        pList->head = p;   //将p赋值给head，同时给第一个链表块（即此时last所指的结构体）赋值，这个过程之后last->next更新为NULL
    }    
}

void print(List *pList)
{
    Node *p;
    //链表的遍历
    for( p=pList->head; p; p=p->next){  
        printf("%d\t",p->value);
    }
    printf("\n");
}

int main ( int argc, char const *argv[] ) 
{
    //设置一个链表头
    List list;           
    list.head = NULL;
    int number;
    do {
        scanf("%d", &number);
        if(number!=-1){
            add(&list, number);
        }
    } while ( number!=-1 );

    //链表的输出
    print( &list );

    //链表的查找
    scanf("%d",&number);
    Node* p;
    int isfound=0;
    for( p=list.head; p; p=p->next){
        if(p->value == number){
            printf("找到了\n");
            isfound = 1;
            break;
        }
    }
    if(!isfound){
        printf("没找到\n");
    }
    
    //链表的删除
    Node *q;
    for( q = NULL, p=list.head; p; q=p, p=p->next){
        if(p->value == number){
            if( q ){
                q->next = p->next;
            } else {
                list.head = list.head->next;  //  list.head = p->next
            }
            free(p);
            break;
        }
    }

    print( &list );

    //链表的清除
    for( p=list.head; p; p=q){
        q = p->next;
        free(p);
    }

    return 0;
}