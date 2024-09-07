// https://www.acwing.com/problem/content/294/

// 原始解法：老老实实判断两行状态，且不构建合法状态转移表
// 需要注意：本题由于需要开三位数组，空间占用较大，且当前状态仅和上一轮状态有关，因此可以直接使用滚动数组优化
#include <iostream>
#include <vector>

using namespace std;

const int N = 105, S = 1 << 10;

int n, m, g[N];
vector<int> state;
int f[2][S][S];   // 摆到第i行，状态为j，且前一行状态为k
int cnt[S];

bool check (int state) 
{
    for (int i = 0; i < m; i++)
        if ((state >> i & 1) && ((state >> i + 1 & 1) || (state >> i + 2 & 1)))
            return false;
            
    return true;
}

int count (int state)
{
    int res = 0;
    for (int i = 0; i < m; i++) res += state >> i & 1;
    return res;
}

int main () 
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            g[i] = (g[i] << 1) + (ch == 'P' ? 0 : 1);
        }
    
    for (int s = 0; s < 1 << m; s++)
        if (check(s))
        {
            state.push_back(s);
            if (!cnt[s]) cnt[s] = count(s); 
        }
    
    // 不构建合法的状态转移表head
    for (int row = 1; row <= n; row ++)  
        for (int i = 0; i < state.size(); i++)
            for (int j = 0; j < state.size(); j++)
                for (int k = 0; k < state.size(); k++)
                {
                    int a = state[i], b = state[j], c = state[k];
                    if ((c & a) || (a & b) || (c & b)) continue;
                    if (a & g[row]) continue;
                    
                    f[row & 1][i][j] = max(f[row & 1][i][j], f[row - 1 & 1][j][k] + cnt[a]);
                }
    
    int ans = 0;
    for (int i = 0; i < state.size(); i++)
        for (int j = 0; j < state.size(); j++)
            ans = max(ans, f[n & 1][i][j]);
    cout << ans << endl;
    
    return 0;
}

// 优化最后求解过程：600ms
#include <iostream>
#include <vector>

using namespace std;

const int N = 105, S = 1 << 10;

int n, m, g[N];
vector<int> state;
int f[2][S][S];   // 摆到第i行，状态为j，且前一行状态为k
int cnt[S];

bool check (int state) 
{
    for (int i = 0; i < m; i++)
        if ((state >> i & 1) && ((state >> i + 1 & 1) || (state >> i + 2 & 1)))
            return false;
            
    return true;
}

int count (int state)
{
    int res = 0;
    for (int i = 0; i < m; i++) res += state >> i & 1;
    return res;
}

int main () 
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            g[i] = (g[i] << 1) + (ch == 'P' ? 0 : 1);
        }
    
    for (int s = 0; s < 1 << m; s++)
        if (check(s))
        {
            state.push_back(s);
            if (!cnt[s]) cnt[s] = count(s); 
        }
    
    for (int row = 1; row <= n + 2; row ++)   // 此处遍历到n + 2
        for (int i = 0; i < state.size(); i++)
            for (int j = 0; j < state.size(); j++)
                for (int k = 0; k < state.size(); k++)
                {
                    int a = state[i], b = state[j], c = state[k];
                    if ((c & a) || (a & b) || (c & b)) continue;
                    if (a & g[row]) continue;
                    
                    f[row & 1][i][j] = max(f[row & 1][i][j], f[row - 1 & 1][j][k] + cnt[a]);
                }
                
    cout << f[n + 2 & 1][0][0] << endl;   // 后两维表示第n+2行和第n+1行都不摆放的情况，间接说明前i行摆放完成
    
    return 0;
}

// 构建合法状态转移表：300ms
#include <iostream>
#include <vector>

using namespace std;

const int N = 105, S = 1 << 10;

int n, m, g[N];
vector<int> state;
vector<int> head[S];
int f[2][S][S];   // 摆到第i行，状态为j，且前一行状态为k
int cnt[S];

bool check (int state) 
{
    for (int i = 0; i < m; i++)
        if ((state >> i & 1) && ((state >> i + 1 & 1) || (state >> i + 2 & 1)))
            return false;
            
    return true;
}

int count (int state)
{
    int res = 0;
    for (int i = 0; i < m; i++) res += state >> i & 1;
    return res;
}

int main () 
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            g[i] = (g[i] << 1) + (ch == 'P' ? 0 : 1);
        }
    
    for (int s = 0; s < 1 << m; s++)
        if (check(s))
        {
            state.push_back(s);
            if (!cnt[s]) cnt[s] = count(s); 
        }

    // 构建合法转移状态，此时不考虑地形影响
    // 注意：切忌构建复杂的状态转移表，仅仅考虑一种转移标准即可，无需落实到每一行的后继状态
    for (int s: state)
        for (int s_pre: state)
            if ((s & s_pre) == 0) 
                head[s].push_back(s_pre);  
    
    for (int row = 1; row <= n + 2; row ++)
        for (int s: state)
        {
            if (s & g[row]) continue;  // 将判断放在外层循环，提升效率
            for (int s_pre: head[s])
                for (int s_pre_pre: head[s_pre])
                {
                    if (s_pre_pre & s) continue;
                    f[row & 1][s][s_pre] = max(f[row & 1][s][s_pre], f[row - 1 & 1][s_pre][s_pre_pre] + cnt[s]);
                }
        }
                
    cout << f[n + 2 & 1][0][0] << endl;
    
    return 0;
}