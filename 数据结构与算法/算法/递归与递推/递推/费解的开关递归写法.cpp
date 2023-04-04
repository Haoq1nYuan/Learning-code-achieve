//https://www.acwing.com/problem/content/description/97/

#include <iostream>
#include <cstdio>

using namespace std;

int n, cnt;
int g[7][7], backup[7][7];
int dx[] = {1, 0, -1, 0, 0}, dy[] = {0, 1, 0, -1, 0};

void turn (int x, int y)
{
    for (int i = 0; i <= 4; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        g[a][b] ^= 1;
    }
}

bool dfs (int c, int &count)
{
    if (c == 6)
    {
        for (int i = 1; i <= 5; i++)
            if (!g[5][i]) return false;
          
        if (count <= 6) return true;
        else return false;
    }
    
    for (int i = 1; i <= 5; i++)
        if (!g[c - 1][i]) turn(c, i), count++;
        
    return dfs(c + 1, count);
}

int main ()
{
    cin >> n;
    
    while (n--)
    {
        cnt = -1;
        for (int i = 1; i <= 5; i++)
            for (int j = 1; j <= 5; j++)
            {
                scanf("%1d", &g[i][j]);
                backup[i][j] = g[i][j];
            }
                
        //枚举一遍第一行的操作方式
        for (int p = 0; p < 32; p++)
        {
            int count = 0;
            
            int k = 1, tem = p;
            while (tem)
            {
                if (tem & 1) turn(1, k), count++;
                tem >>= 1;
                k++;
            }
            
            if (dfs(2, count)) 
            {
                if (cnt != -1) cnt = min(cnt, count);
                else cnt = count;
            }
            
            for (int i = 1; i <= 5; i++)
                for (int j = 1; j <= 5; j++) 
                    g[i][j] = backup[i][j];
        }
        
        cout << cnt << endl;
    }
    
    return 0;
}