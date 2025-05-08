//https://www.acwing.com/problem/content/839/

#include <iostream>
using namespace std;

const int N = 100010;

//size数组维护每个集合中元素的数量
int n, m, p[N], Size[N];
string h;
int a, b;

int Find ( int x )
{
    if ( p[x] != x ) p[x] = Find(p[x]);
    return p[x];
}

int main ()
{
    cin >> n >> m;

    for ( int i = 1; i <= n; i++ ) p[i] = i, Size[i] = 1;

    while ( m-- )
    {
        cin >> h;
        if ( h[0] == 'C' ) 
        {
            cin >> a >> b;
            //此处加一个特判，可能a和b已经在一个连通块内，那就不需要之后的操作
            if ( Find(a) == Find(b) ) continue;
            //更新b所在集合的size
            Size[Find(b)] += Size[Find(a)];  // 需排在链接操作前面
            //链接a和b所在集合
            p[Find(a)] = Find(b); 
        }
        else if ( h[1] == '1' )
        {
            cin >> a >> b;
            if (Find(a) == Find(b)) puts("Yes");
            else puts("No");
        }
        else 
        {
            cin >> a;
            cout << Size[Find(a)] << endl;;
        }
    }

    return 0;
}