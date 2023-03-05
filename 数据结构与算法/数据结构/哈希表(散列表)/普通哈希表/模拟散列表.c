//https://www.acwing.com/problem/content/842/

//哈希表（类似于多链表的数组表示）

//拉链法
//相应思考：2022年蓝桥杯省赛C组数位排序
#include<stdio.h>
#include<string.h>
#define N 100003   //取模：大于范围的第一个质数，数组长度与其相同

int h[N], e[N], ne[N], idx;  
int n, x;
char c[2];

void insert ( int x )
{
    int k = ( x % N + N ) % N;   //保证余数是正数
    e[idx] = x;     
    ne[idx] = h[k];  
    h[k] = idx;    
    idx++;
}

int find ( int x )
{
    int k = ( x % N + N ) % N;
    for ( int i = h[k]; i != -1; i = ne[i] )   
        if ( e[i] == x )
            return 1;

    return 0;
}

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );
    memset( h, -1, sizeof(h) );    

    while ( n-- )
    {
        scanf( "%s%d", &c, &x );
        if ( c[0] == 'I' ) insert( x );
        else 
        {
            if ( find( x ) ) puts( "Yes" );
            else puts( "No" );
        }
    }

    return 0;   
}

//开放寻址法
#include<stdio.h>
#include<string.h>
#define N 200003       //数组长度要求为数据范围的2~3倍且为最近的质数，模数与其相同
#define null 0x3f3f3f3f   //规定数组空位置为一个大于10^9的且四个字节相同的四字节数，这样不会出现null==x的情况

int h[N];  //存储取模后的值
int n, x;
char c[2];

int find ( int x )
{
    int k = ( x % N + N ) % N;

    //下面循环条件都表示如果说在模数为k的下标处已经有原数值存放，则向后继续查找知道发现空位置
    //“ h[k] != null ”用于存放操作的地址选取
    //“ h[k] != x ”用于查找操作的地址选取
    while ( h[k] != null && h[k] != x )  
    {
        //对于一个取模数（假设为k），数组只有一个下标与之对应（即k，它存放第一个取模为k的数），
        //如果出现冲突，则需要令k+1，则下标k+1存放的就是第二个取模为k的数
        k++;       
        if ( k == N ) k = 0;   //类似于环状数组，k的存储是可以跨越首尾以达到连续存储的目的
    }

    return k;
}

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );

    memset( h, 0x3f, sizeof(h) );   //详见末尾解释

    while ( n-- ) 
    {
        scanf( "%s%ld", &c, &x );
        if ( c[0] == 'I' ) h[find(x)] = x;
        else 
        {
            if ( h[find(x)] == null ) puts( "No" );
            else puts( "Yes" );
        }
    }

    return 0;
}
/*
const int null = 0x3f3f3f3f 和  memset(h, 0x3f, sizeof h)之间的关系：
首先，必须要清楚memset函数到底是如何工作的
先考虑一个问题，为什么memset初始化比循环更快？
答案：memset更快，为什么？因为memset是直接对内存进行操作。memset是按字节（byte）进行复制的

void * memset(void *_Dst,int _Val,size_t _Size);
这是memset的函数声明
第一个参数为一个指针，即要进行初始化的首地址
第二个参数是初始化值，注意，并不是直接把这个值赋给一个数组单元（对int来说不是这样）
第三个参数是要初始化首地址后多少个字节
h是int类型，其为4个字节， 第二个参数0x3f八位为一个字节，所以0x3f * 4(从高到低复制4份) = 0x3f3f3f3f

这也说明了为什么在memset中不设置除了-1， 0以外常见的值，这样不会因为*4之后就改变数值
0它*4后值不变很好理解；-1的补码是11111111，*4后32位都是1，转换为原码后还是-1
如果不是这两个数：
比如1, 字节表示为00000001，memset(h, 1, 4)则表示为0x01010101


为什么不设为0x7fffffff（32个1）？
首先它不满足每个字节都相同，其次，如果做加法的话很容易造成数值上溢，变成负值，
再次，虽然它很大，但也和0x3f3f3f3f一个量级。
*/