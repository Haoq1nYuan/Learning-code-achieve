//https://www.acwing.com/problem/content/96/

//深度优先搜索解法dfs 
#include<stdio.h>

int n, i;
int state[10];    //下标存储数字出现位置，值代表数字
int used[10];     //used为判重数组，0表示下标对应的数字还没有使用过，1代表使用过了

void ans ( int u )
{
    if ( u > n ) 
    {
        for ( i = 1; i <= n; i++ ) 
            printf( "%d ", state[i] );
        printf( "\n" );

        return;
    }

    for ( int j = 1; j <= n; j++ )  //此处不能定义y的全局变量，因为每层递归y的值都需要刷新为0，这样回溯到上一层的时候y的值就会被改变。
    {
        if ( !used[j] ) 
        {
            state[u] = j;
            used[j] = 1;
            ans( u+1 );
            //以下为恢复现场
            //state[u] = 0;  
            used[j] = 0;     //这个操作是必要的，因为回溯到上一层之后它会作为判断条件并影响其他儿子的数据读入
        }
    }
}

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );

    ans(1);

    return 0;
}