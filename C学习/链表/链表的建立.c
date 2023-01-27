#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node
{
    long int num;
    char name[20];
    struct Node *next;
}N;

N *create ( N *head ) 
{
    //创建单个新节点
    N *newcode = ( N * )malloc( sizeof(N) );
    scanf( "%ld %s", &newcode->num, &newcode->name );
    newcode->next = NULL;

    //定义辅助结构体指针
    N *box;
    head = newcode;  //执行完该语句后head就相当于newcode（在成员组成和大小上）
    box = newcode;   //用另一个结构体指针来实现链表的增长，该指针也相当于newcode（在成员组成和大小上）

    //通过box实现链表增长
    while ( newcode->num ) {
        newcode->next = NULL;    //newcode始终是一个单节点
        box->next = newcode;     //将下一个节点的地址赋给box->next      
        box = box->next;         //将box指向节点后移                   
        newcode = ( N * )malloc( sizeof(N) );                         
        scanf( "%ld %s", &newcode->num, &newcode->name );
    }
    /*第一次加入循环的时候，box->next = newcode执行完head->next，box->next的地址都和第一个newcode的地址相同。
    当向内存申请空间后，newcode的地址增加了一个sizeof(N),随即进入第二个循环。一进入第二个循环，新节点newcode的
    指针就指向NULL，此时head->next，box->next的地址相同，执行box->next = newcode后地址也都加了sizeof(N),在执
    行box = box->next后，因为是box所指结构体内部成员地址转换，所以不影响head和head->next的指向.在这之后head和
    head->next的地址就不会动了，head指向newcode最初节点的地址，head->next指向第二个newcode节点的地址。而n次循
    环后box所指结构体增加了n个节点，而head所指结构体和box所指的相同，故可以用head来从头输出每个节点的数据。*/

    //free掉num为0的结构体所占空间
    free( newcode );

    //返回head，此时head依旧指向第一个节点，但是在这之后仍有好多新添加的节点
    return head;
}

void print ( N *head )
{
    N *p = head;
    while ( p ) {
        printf( "%ld\t%s\n", p->num, p->name );
        p = p->next;
    }
}

int main ( int argc, char *argv[] )
{
    N *head = NULL;
    head = create( head );
    printf( "建立的列表块是：\n");
    print( head );
    return 0;
}