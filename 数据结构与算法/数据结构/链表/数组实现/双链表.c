//https://www.acwing.com/problem/content/829/

//双链表表示双向链表，而不是两条链表
//插入第k个数的下标为k+1，与单链表不同
#include<stdio.h>
#define N 100010

int m, target, num;
char how[5];
int h, t, nel[N], ner[N], e[N], idx;

void init ()
{
    //头节点为0号点，尾节点为1号点
    h = 0;
    t = 1;
    ner[h] = t;
    nel[t] = h;
    idx++;
}

//此处表示在k节点的左侧插入一个点，
//如果要实现在k节点的右侧插入，就相当于在l节点右侧一个节点的左侧插入，即传入ner[k]和x
void add_behind_k ( int k, int x )  
{
    e[idx] = x;

    //将新节点的左指针指向双链表的k节点
    nel[idx] = k;
    //将新节点的右指针指向k节点后面一个节点
    ner[idx] = ner[k];
    
    //将k节点的右指针指向新节点
    ner[k] = idx;
    //将k后面一个节点的左指针指向新节点
    nel[ner[idx]] = idx;

    //更新下标
    idx++;
}

void remove_k ( int k )
{
    //将k节点的左节点的右指针指向k节点的右节点
    ner[nel[k]] = ner[k];
    //将k节点的右节点的左指针指向k节点的左节点
    nel[ner[k]] = nel[k];
}

int main ( int argc, char *argv[] )
{
    scanf( "%d", &m );

    init();

    while ( m-- )
    {
        scanf( "%s%d", how, &num );
        if ( how[0] == 'L' ) add_behind_k( h, num );
        else if ( how[0] == 'R' ) add_behind_k( nel[t], num );
        else if ( how[0] == 'D' ) remove_k( num+1 ); //此处第k个的意思是下标为1+k的数
        else if ( how[1] == 'L' )
        {
            scanf( "%d", &target );
            add_behind_k( nel[num+1], target );
        }
        else if ( how[1] == 'R' )
        {
            scanf( "%d", &target );
            add_behind_k( num+1, target );
        }
    }

    for ( int i = ner[h]; i != t; i = ner[i] ) printf( "%d ", e[i] );

    return 0;
}