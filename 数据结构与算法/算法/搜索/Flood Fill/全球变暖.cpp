//https://www.acwing.com/problem/content/1235/

//flood fill算法

/*
1.先求出有多少个不同的连通块
  循环遍历矩阵，对遇到的没有被标记且为陆地的点进行bfs或dfs操作，
  找到与该点相邻的所有陆地，并打上标记
2.统计有多少个连通块会被淹没
  一共有多少个单元，一共有多少个点与海相邻，若两个值相同，则岛屿会被淹没
*/

#include <iostream>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1010;

int n, cnt;
//g数组存储地图
char g[N][N];
//st判重
bool st[N][N];
//q存储坐标
PII q[N * N];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

void bfs (int a, int b, int &total, int &bound)
{
    int hh = 0, tt = 0;
    q[0] = {a, b};
    st[a][b] = true;
    
    while (hh <= tt)
    {
        //每次出队一个元素，表示有一个连通的点
        PII t = q[hh++];
        total++;
        
        bool if_bound = false;
        //遍历当前点的四周各点
        for (int i = 0; i < 4; i++)
        {
            int m = t.x + dx[i], p = t.y + dy[i];
            
            if (m < 0 || m >= n || p < 0 || p >= n) continue;
            
            if (st[m][p]) continue;
            
            if (g[m][p] == '.') 
            {
                if_bound = true;
                continue;
            }
            
            //如果以上判断都不满足，那么说明该点当前方向上的点是个未被遍历的陆地
            q[++tt] = {m, p};
            st[m][p] = true;
        }
        
        //当前点四周存在海洋，说明该点为边界点
        if (if_bound) bound++;
    }
}

int main ()
{
    cin >> n;
    
    for (int i = 0; i < n; i++) scanf("%s", g[i]);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!st[i][j] && g[i][j] == '#')
            {
                int total = 0, bound = 0;
                bfs(i, j, total, bound);
                //注意，这道题题述不清楚，单个陆地也是一座岛屿
                //if (total == 1) continue;
                if (total == bound) cnt++;
            }
    
    cout << cnt << endl;
    
    return 0;
}