//https://www.acwing.com/problem/content/838/

#include <iostream>
using namespace std;

const int N = 100010;

int n, m, p[N];
string h;
int a, b;

//返回x的根节点+路径优化
int Find ( int x )
{
    //为什么用递归而不用迭代，因为递归可以直接让一条路径上的节点全都指向根节点，只需要算一次就好
    if ( p[x] != x ) p[x] = Find(p[x]);
    return p[x];
}

int main ()
{
    cin >> n >> m;

    for ( int i = 1; i <= n; i++ ) p[i] = i;

    while ( m-- )
    {
        cin >> h >> a >> b;
        if ( h[0] == 'M' ) p[Find(a)] = Find(b); //将a所在的集合的根节点连在b所在集合的根节点后面
        else
        {
            if (Find(a) == Find(b)) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}