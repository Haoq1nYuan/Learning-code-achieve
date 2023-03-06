//https://www.acwing.com/problem/content/97/

//题目性质：结果与顺序无关，和按法有关，且每个格子最多按一次

/*
枚举第一行的操作(32种情况)，第二行的操作由第一行操作后的结果决定，以此类推。
到最后一行的时候，特判最后一行的情况，如果全亮就说明方案成立。
*/

//递归第一行：位运算
//第2~4行的操作：记录偏移量
//时间复杂度：32*25*5*500 = 2*10^6 = 2000000
#include<stdio.h>
#include<string.h>

int n;
int state[7][7], backup[7][7];
int dx[5] = { 0, 1, -1, 0, 0 }, dy[5] = { 0, 0, 0, -1, 1 };   //偏移量小技巧，相同位置组成的二元组表示一个完整偏移

void turn ( int x, int y )
{
    for ( int i = 1; i <= 5; i++ )
    {
        int a = x + dx[i], b = y + dy[i];
        //if ( a < 1 || a > 5 || b < 1 || b > 5 ) continue;
        state[a][b] ^= 1;   //异或运算符可以高效地实现1和0的互换
    }
}

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );
    while ( n-- ) 
    {
        for ( int i = 1; i <= 5; i++ ) 
            for ( int j = 1; j <= 5; j++ )
            {
                scanf( "%1d", &state[i][j] );
                backup[i][j] = state[i][j];  //拷贝一个最初状态，方便讨论完第一行的一个操作方案后复原
            }
 
        int res = 7; 
        for ( int op = 0; op < 32; op++ )  //讨论第一行的所有操作方案（五位二进制）的十进制数
        {
            int step = 0;   //step记录真实操作次数
            
            //首先按照op的二进制形式0和1的排列顺序对第一行进行操作
            for ( int i = 0; i < 5; i++ )  
                if ( op >> i & 1 )   //结果为真则说明对应位上是1，与运算和1结合能够很好的判断二进制数第0位是1还是0
                {
                    step++;
                    turn( 1, i+1 );
                } 
            
            //对第2~4行依次进行操作
            for ( int i = 1; i <= 4; i++ ) 
                for ( int j = 1; j <= 5; j++ )
                    if ( state[i][j] == 0 )
                    {
                        step++;
                        turn( i+1, j );
                    } 
                    
            //判断最后一行是否都亮
            int judge = 1;
            for ( int i = 1; i <= 5; i++ )
                if ( state[5][i] == 0 )
                {
                    judge = 0;
                    break;
                }
            if ( judge ) res = res>step?step:res;
            
            //还原矩阵原状态
            for ( int i = 1; i <= 5; i++ )
                for ( int j = 1; j <= 5; j++ )
                    state[i][j] = backup[i][j];
        } 

        if ( res > 6 ) res = -1;
        
        printf( "%d\n", res );
    }

    return 0;
}
