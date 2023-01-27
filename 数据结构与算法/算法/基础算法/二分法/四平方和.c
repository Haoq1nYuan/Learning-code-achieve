//https://www.acwing.com/problem/content/1223/

//dfs枚举结果都正确，但是n = 3038163超时 (78分)
/* #include<stdio.h>
#include<math.h>
#define N 5000000

long n;
long num[5], guide[5] = { N, N, N, N };
int count;

void dfs ( long target )
{
    if ( count == 4 ) 
    {
        if ( target == 0 ) 
        {
            int i = 4;
            while ( i >= 0 ) 
            {
                i--;
                if ( num[i] > guide[i] ) break;
                else if ( num[i] == guide[i] ) continue;
                else if ( num[i] < guide[i] ) 
                {
                    for ( int j = 0; j < 4; j++ )
                        guide[j] = num[j];
                    return;
                }
            }
        }
        return;
    }

    long l = (int)sqrt( target * 0.5 );
    long r = (int)sqrt( target );
    if ( target < l * l ) return;
    for ( long i = l; i <= r; i++ ) 
    {
        target -= i * i;
        num[count++] = i;
        dfs( target );
        count--;
        target += i * i;
    }
}

int main ( int argc, char *argv[] )
{
    scanf( "%ld", &n );

    dfs( n );
 
    printf( "%ld %ld %ld %ld\n", guide[3], guide[2], guide[1], guide[0] );

    return 0;
} */

//优化
/*
首先分析时间复杂度：
对于每个数，最大约为N=2200，枚举两个数为O(n^2)=4840000，
枚举三个数为O(n^3)约为1.06*10^10 > 1*10^8会超时，所以最多枚举2个数
其次思考思路：空间换时间
首先枚举a和b，令n -= a^2 + b^2，最后用二分或者哈希判断每组c和d是否满足c^2 + d^2 = n.
此时时间复杂度就是O( N^2 * logN )(二分)或者O( N^2 * 1 )(哈希)
*/
//枚举+二分
//C语言没有函数重载，排序的时候会浪费大量时间，不过忽略排序部分二分法的运用还是有优化作用的
/* #include<stdio.h>
#define N 2500010

long n, m, r, l, mid;
long S[N][3], box[3];

void sort ( long S[m][3] )
{
    for ( long i = 0; i < m-1; i++ )
    {
        if ( S[i][0] > S[i+1][0] ) change( S, i );
        else if ( S[i][0] == S[i+1][0] )
        {
            if ( S[i][1] > S[i+1][1] ) change( S, i );
            else if ( S[i][1] == S[i+1][1] && S[i][2] > S[i+1][2] ) change( S, i );
            else continue;
        }
        else continue;
    }
}

void change ( long S[m][3], long k )
{
    box[0] = S[k][0], box[1] = S[k][1], box[2] = S[k][2];
    S[k][0] = S[k+1][0], S[k][1] = S[k+1][1], S[k][2] = S[k+1][2];
    S[k+1][0] = box[0], S[k+1][1] = box[1], S[k+1][2] = box[2];
}

int main ( int argc, char *argv[] )
{
    scanf( "%ld", &n );
    for ( long c = 0; c*c <= n; c++ )
        for ( long d = c; d*d + c*c <= n; d++ )
        {
            S[m][0] = c*c + d*d;
            S[m][1] = c;
            S[m++][2] = d;
        }

    sort( S );

    for ( long a = 0; a*a <= n; a++ )
        for ( long b = a; b*b + a*a <= n; b++ )
        {
            long t = n - a*a - b*b;
            l = 0, r = m - 1;
            while ( l < r )
            {
                mid = l + r >> 1;
                if ( S[mid][0] >= t ) r = mid;
                else l = mid + 1;
            }

            if ( S[l][0] == t && S[l][1] >= b )
            {
                printf( "%ld %ld %ld %ld\n", a, b, S[l][1], S[l][2] );
                return 0;
            }
        }    

    return 0;
} */

//枚举+哈希优化
//拉链法
#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 5000010

int h[N], e[N][2], ne[N], idx;  
int n, count;

void add ( int k, int c )
{    
    e[idx][0] = k;
    e[idx][1] = c;
    if ( h[k] == -1 )   //如果没有节点，直接在head后插入
    {
        ne[idx] = h[k];
        h[k] = idx++;
        count++;
    }
    else     //如果插入过节点，则尾插
    {
        ne[idx] = ne[count-1];
        ne[count-1] = idx++;
    }
}

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );

    memset( h, -1, sizeof(h) );

    for ( int c = 0; c*c*2 <= n ; c++ )
        for ( int d = c; c*c + d*d <= n; d++ )
        {
            int sum = c*c + d*d;
            add( sum, c );
        }

    for ( int a = 0; a*a*4 <= n; a++ )
        for ( int b = a; a*a + b*b <= n/2; b++ )
        {
            int i = n - a*a - b*b;
            if ( e[h[i]][0] )
            {
                int d = sqrt( e[h[i]][0] - e[h[i]][1] * e[h[i]][1] );
                printf( "%d %d %d %d\n", a, b, e[h[i]][1], d );
                return 0;
            }
        }

    return 0;
} 

//开放寻址法
#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 5000010
#define M 0x3f3f3f3f

int h[N];
int n;

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );

    memset( h, 0x3f, sizeof(h) );

    for ( int c = 0; c*c*2 <= n ; c++ )
        for ( int d = c; c*c + d*d <= n; d++ )
        {
            int sum = c*c + d*d;
            if ( h[sum] == M ) h[sum] = c;
        }

    for ( int a = 0; a*a*4 <= n; a++ )
        for ( int b = a; a*a + b*b <= n/2; b++ )
        {
            int i = n - a*a - b*b;
            if ( h[i] != -1 )
            {
                int d = sqrt( i - h[i] * h[i] );
                printf( "%d %d %d %d\n", a, b, h[i], d );
                return 0;
            }
        }

    return 0;
}