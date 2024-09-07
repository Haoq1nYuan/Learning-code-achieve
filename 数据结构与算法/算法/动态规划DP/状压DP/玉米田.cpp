//https://www.acwing.com/problem/content/329/

#include <iostream>
#include <vector>

using namespace std;

const int N = 15, mod = 1e8, M = 1 << 12;

int n, m, g[N][N];
vector<int> state[N];
vector<int> head[N][M];
int f[N][M];

bool check (int state, int row) 
{
    for (int i = 0; i < n; i++)
        if (((state >> i & 1) && (state >> i + 1 & 1)) || 
            (state >> i & 1 && !g[row][i + 1]))   
            // 需要注意，此处的state >> i必须与1进行直接比较，以便只计算第i位的二进制数
            // 如果直接用state >> i && !g[row][i + 1]进行计算，此时只要state的任意一个数位上为1即判断为true
                return false;
    
    return true;
}

int main () {
    cin >> m >> n;
    
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];
            
    for (int i = 1; i <= m; i++)
        for (int s = 0; s < 1 << n; s++)
            if (check(s, i)) 
                state[i].push_back(s);
    
    for (int row = 1; row < m; row++)
        for (int i = 0; i < state[row].size(); i++)
            for (int j = 0; j < state[row + 1].size(); j++)
            {
                int a = state[row][i], b = state[row + 1][j];
                if ((a & b) == 0)
                    head[row + 1][b].push_back(a);
            }
    
    for (int i = 0; i < state[1].size(); i++) f[1][state[1][i]] = 1;
    
    for (int i = 2; i <= m; i++)
        for (int s: state[i])
            for (int s_pre: head[i][s])
                f[i][s] = (f[i][s] + f[i - 1][s_pre]) % mod;
            
    int ans = 0;
    for (int s: state[m]) ans = (ans + f[m][s]) % mod;
    cout << ans << endl;
    
    return 0;
}