//https://www.acwing.com/problem/content/845/

//朴素对角线
#include <iostream>
#include <cstring>

using namespace std;

int n;
int p[11], pre[11][11];
int mark[11][11];

void dfs (int k)
{
    if (k == n + 1) 
    {
        for ( int i = 1; i <= n; i++ )
        {
            for ( int j = 1; j <= n; j++ )
                if (mark[i][j]) cout << 'Q';
                else cout << '.';
            puts("");
        }
        puts("");

        return;
    }
    
    for ( int i = 1; i <= n; i++ )
        if (p[i] == 0 && pre[k][i] == 0)
        {
            p[i] = 1;
            for ( int j = i + 1; j <= n && k + j - i <= n; j++ ) pre[k + j - i][j]++;
            for ( int j = i - 1; j >= 1 && k + i - j <= n; j-- ) pre[k + i - j][j]++;
            mark[k][i] = 1;
            dfs(k + 1);
            p[i] = 0;
            for ( int j = i + 1; j <= n && k + j - i <= n; j++ ) pre[k + j - i][j]--;
            for ( int j = i - 1; j >= 1 && k + i - j <= n; j-- ) pre[k + i - j][j]--;
            mark[k][i] = 0;
        }
}

int main () 
{
    cin >> n;
    
    dfs(1);
    
    return 0;
}

//当然也可以用两个数组来表示正对角线和反对角线，观察到在同一负对角线上 k + i 始终不变
//在同一正对角线上 n - i + k 始终不变