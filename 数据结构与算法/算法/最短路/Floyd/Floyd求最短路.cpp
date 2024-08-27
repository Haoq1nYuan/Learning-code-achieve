//https://www.acwing.com/problem/content/856/

#include <iostream>

using namespace std;
const int N = 205, M = 20010;

int n, m, k;

//主要要搞懂g[i][j]的含义，它的值表示从i到j的最短路
//g[i][j]也可以分为i到j路径上任何一个点到两端的距离
//即g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
int g[N][N];

void floyd ()
{
    //最初g数组由三个量表示，g[k, i, j]，k 表示 i 经过
    // 1~k 内的某些点到达 j 所需要的最短路
    //而 d[k, i, j] = d[k-1, i, k] + d[k-1, k, j]
    //当前循环必须用到上一次的数据
    //所以此处的k循环一定要写在外面，不然无法省略掉k维
    for ( int k = 1; k <= n; k++ )
        for ( int i = 1; i <= n; i++ )
            for ( int j = 1; j <= n; j++ )
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

int main ()
{
    cin >> n >> m >> k;
    
    //注意，图中存在自环，且自环会作为数据在函数中调用，
    //所以必须单独初始化自环为0
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j) g[i][j] = 0;
            else g[i][j] = 0x3f3f3f3f;
            
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        //依然是省略掉较长边
        g[x][y] = min(g[x][y], z);
    }
    
    floyd();
    
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        
        if (g[x][y] > N*M) puts("impossible");
        else cout << g[x][y] << endl;
    }
    
    return 0;
}