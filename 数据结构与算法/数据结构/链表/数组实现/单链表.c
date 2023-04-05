//https://www.acwing.com/problem/content/828/

//单链表的数组实现：
#include<stdio.h>
#define N 100010

int m, x, k;
char how[2];

//假设链表中节点下标按照0，1，2，3……的顺序延伸
//每个节点有2个值e和ne
//head,idx,ne[N]都相当于指针ne[idx]表示当前idx指向的下一个指针
//注意，idx在链表中的分布和节点下标不同，不是按0，1，2，3……的顺序存放的
int e[N];       //e[N]的值就是每个节点存储的值，e的下标就为节点下标
int ne[N];      //ne[N]的值表示next指针指向的下一个节点的下标，ne的下标为next指针所在节点的下标
int head;       //head表示连接头节点的第一个节点的下标，最开始是-1
int idx;        //idx是一个指针，表示当前已经存储到的那个节点的下标（后面就是空节点）

//初始化
void init ()
{
    head = -1;
    idx = 0;
}

//节点头插
void add_to_head ( int x )
{
    e[idx] = x;      //把x存储到下标为idx的节点上
    ne[idx] = head;  //将该节点的next指针指向head
    head = idx;      //将head指针指向idx指针
    idx++; 
}

//节点插入到下标是p的节点（第p+1个节点）后面
void add_behind_p ( int p, int x )
{
    e[idx] = x;
    ne[idx] = ne[p];
    ne[p] = idx;
    idx++;
}

//删除下标是p的节点后面的节点
void remove_behind_p ( int p )
{
    ne[p] = ne[ne[p]];
}

int main ( int argc, char *argv[] )
{
    scanf( "%d", &m );

    init();

    while ( m-- )
    {
        scanf( "%s", how );

        if ( how[0] == 'H' ) 
        {
            scanf( "%d", &x );
            add_to_head( x );
        }
        else if ( how[0] == 'D' ) 
        {
            scanf( "%d%d", &k, &x );
            //此处特判，如果k为0，表示删除头节点，
            //只需要使头节点指向头节点的next指针指向的节点（删除了原本的第一个节点）
            if ( !k ) head = ne[head];  
            remove_behind_p( k-1 );
        }
        else if ( how[0] == 'I' ) 
        {
            scanf( "%d%d", &k, &x );
            add_behind_p( k-1, x );
        }
    }

    for ( int i = head; i != -1; i = ne[i] ) printf( "%d ", e[i] );
    printf( "\n" );

    return 0;
}