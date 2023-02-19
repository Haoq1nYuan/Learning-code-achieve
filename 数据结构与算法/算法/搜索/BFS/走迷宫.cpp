//https://www.acwing.com/problem/content/846/

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 110;

int n, m;
//a存储地图，d存储当前位置到点点(1, 1)的距离
int a[N][N], d[N][N];
//偏移量
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

queue<pair<int, int>> k;

int bfs ()
{
    //初始化距离
    memset(d, -1, sizeof(d));
    d[1][1] = 0;
    
    k.push({1, 1});
    
    while (k.size())
    {
        auto t = k.front();
        k.pop();
        
        //对每个位置，先讨论全所有可行的下一个位置，也就是说，每一层的所有可行位置都是一起算好的
        for ( int i = 0; i < 4; i++ )
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            
            //这里d[x][y]的限制是关键，它防止后面几层的距离覆盖掉原先较短的距离，保证我们求的是最短距离
            if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;
                k.push({x, y});
            }
        }
    }
    
    return d[n][m];
}

int main ()
{
    cin >> n >> m;
    for ( int i = 1;i <= n; i++ )
        for ( int j = 1; j <= m; j++ ) cin >> a[i][j];
    
    cout << bfs();
    
    return 0;
}