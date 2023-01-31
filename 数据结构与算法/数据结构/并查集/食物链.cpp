//https://www.acwing.com/problem/content/242/

//带权并查集
/*
我们用每个节点到根节点的距离和3的模数来表示节点之间的关系：
mod 3 = 1:可以吃根节点
mod 3 = 2:可以被根节点吃
mod 3 = 0:和根节点同类
*/
#include <iostream>
using namespace std;

const int N = 100010;
typedef long long ll;
typedef unsigned long long ull;

int n, k, t, x, y, ans;

//d数组存储节点到父节点的距离，但是随着路径压缩的进行，
//父节点变成根节点，在数值上就表示节点到根节点的距离了
int p[N], d[N];

int Find ( int u )
{
    if ( p[u] != u )
    {
        int t = Find(p[u]);
        //此处用+=的原因是可能在这之前x所在集合连接到的y所在集合中，但是连接的操作只得到了d[px];
        //d[x]并没有被更新，但是它还保留着原来的值，所以需要在这基础上+=
        d[u] += d[p[u]];
        p[u] = t;
    } 
    return p[u];
}

int main ()
{   
    cin >> n >> k;

    for ( int i = 1; i <= n; i++ ) p[i] = i; 

    while ( k-- )
    {
        cin >> t >> x >> y;

        if ( x > n || y > n ) ans++;
        else
        {
            int px = Find(x), py = Find(y);
            if (t == 1)
            {
                if ( px == py && (d[x] - d[y]) % 3 ) ans++;
                else if ( px != py )
                {
                    p[px] = py;
                    //此时x所在集合的根节点px距离y所在集合根节点py的距离还是未知的
                    // ( d[px] + d[x] ) % 3 = d[y] % 3;
                    d[px] = d[y] - d[x];
                    //注意，连接两个集合后d[x]并没有更新，这需要放在Find函数中进行
                }
            }
            else
            {
                if ( px == py && (d[x] - d[y] - 1) % 3 ) ans++;
                else if ( px != py )
                {
                    p[px] = py;
                    // ( d[px] + d[x] ) % 3 = ( d[y] + 1 ) % 3
                    d[px] = d[y] + 1 - d[x];
                    //同上，d[x]未更新
                }
            }
        }
    }

    cout << ans;

    return 0;
}