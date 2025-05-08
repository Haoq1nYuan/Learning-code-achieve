//https://www.acwing.com/problem/content/145/

//将每个数转换为31位二进制数，最大为2^32-1 = 0111 1111 1111 1111 1111 1111 1111 1111B
//为了保证两个数异或结果最大，则需要从高位(31位)开始，两个数的二进制位要尽量不同
#include <iostream>
using namespace std;

const int N = 3100010;

int n, x[N], ans;

//son的二维部分只存储0或1
//注意，每个数都必须存入31位，并且从高位向低位存储
int son[N][2], idx;

void insert ( int u )
{
    int p = 0;
    for ( int i = 30; i >= 0; i-- )
    {
        int k = u >> i & 1;
        if ( !son[p][k] ) son[p][k] = ++idx;
        p = son[p][k];
    }
}

int Search ( int u )
{
    int p = 0, num = 0;
    for ( int i = 30; i >= 0; i-- )
    {
        int k = u >> i & 1;
        if ( !son[p][!k] ) 
        {
            p = son[p][k];
            num += k << i;  //左移操作，替换2次幂计算形式
        }
        else 
        {
            p = son[p][!k];
            num += !k << i;
        }        
    }
    return num;
}

int main ()
{       
    cin >> n;
    for( int i = 0; i < n; i++ ) 
    {
        cin >> x[i];
        insert(x[i]);
    }

    for ( int i = 0; i < n; i++ )
    {
        //找到从高位到低位01串尽可能和x[i]不同的那个数
        int k = Search(x[i]);
        ans = max( ans, k ^ x[i] );
    }

    cout << ans;

    return 0;
}