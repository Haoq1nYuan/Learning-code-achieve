//https://www.acwing.com/problem/content/1104/

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 305;

int n, x1, y1, x2, y2;
int d[N][N];
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

queue<pair<int, int>> q;

int bfs ()
{
    q.push({x1, y1});
    d[x1][y1] = 0;
    
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        
        for ( int i = 0; i < 8; i++ )
        {
            int x = t.first + dx[i], y = t.second + dy[i];

            if ( x >= 0 && x < n && y >= 0 && y < n && d[x][y] == 0)
            {
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
    }
    
    return d[x2][y2];
}

int main ()
{
    int t;
    cin >> t;
    
    while (t--)
    {
        memset(d, 0, sizeof(d));
        
        cin >> n >> x1 >> y1 >> x2 >> y2;
        
        //这里只需要特判一下坐标前后相同的情况即可
        if ( x1 == x2 && y1 == y2 ) cout << 0 << endl;
        else cout << bfs() << endl;
    }
    
    return 0;
}