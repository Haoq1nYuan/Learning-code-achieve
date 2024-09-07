// https://www.acwing.com/problem/content/1066/

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 11, M = 1 << 10, K = 110;   // N: 行数上界; M: 状态上界; K: 国王数上界

int n, k;
vector<int> state;    // 存储所有合法状态
int cnt[M];           // 存储所有合法状态中含有的国王数量
vector<int> head[M];  // 两个状态之间的转移关系
ll f[N][K][M];        // f[i][k][j]: 已经摆了i行，摆放k个国王，且当前第i行状态为j

bool check (int state)  // 判断状态state本身是否合法（仅判断是否有相邻1）
{
    for (int i = 0; i < n; i++) 
        if ((state >> i & 1) && (state >> i + 1 & 1)) 
            return false;
    return true;
}

int count (int state)  // 计算状态state中含有的国王数量（1的个数）
{
    int res = 0;
    for (int i = 0; i < n; i++) res += state >> i & 1;
    return res;
}

int main () 
{
    cin >> n >> k;
    
    // 首先预处理所有的合法状态并且计算出状态中对应的国王数量
    for (int i = 0; i < 1 << n; i++)  
        if (check(i)) 
        {
            state.push_back(i);
            cnt[i] = count(i);
        }
    
    // 预处理所有合法状态的所有可能的后继状态
    for (int i = 0; i < state.size(); i++) 
        for (int j = 0; j < state.size(); j++) 
        {
            int a = state[i], b = state[j];
            // 既要满足a和b之间不存在相同列同时为1，也要满足不存在相邻列同时为1
            if ((a & b) == 0 && check(a | b))  
                head[i].push_back(j); 
        }
        
    // 开始动态规划
    f[0][0][0] = 1;  // 入口：合法状态n
    for (int i = 1; i <= n; i++)   // 摆放到第i行
        for (int j = 0; j <= k; j++)   // 当前共摆放j个国王
            for (int a = 0; a < state.size(); a++)   // 当前状态
                for (int b: head[a])   // 遍历当前状态的所有合法前驱状态
                {
                    int c = cnt[state[a]];
                    if (j >= c) f[i][j][a] += f[i - 1][j - c][b];
                }

    ll ans = 0;
    for (int i = 0; i < state.size(); i++) ans += f[n][k][i];
    cout << ans << endl;

    return 0;
}

// 最后的求和可以整合在动态规划体中，此时N需要多开一个元素位
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 12, M = 1 << 10, K = 110;   // N: 行数上界; M: 状态上界; K: 国王数上界

int n, k;
vector<int> state;    // 存储所有合法状态
int cnt[M];           // 存储所有合法状态中含有的国王数量
vector<int> head[M];  // 两个状态之间的转移关系
ll f[N][K][M];        // f[i][k][j]: 已经摆了i行，摆放k个国王，且当前第i行状态为j

bool check (int state)  // 判断状态state本身是否合法（仅判断是否有相邻1）
{
    for (int i = 0; i < n; i++) 
        if ((state >> i & 1) && (state >> i + 1 & 1)) 
            return false;
    return true;
}

int count (int state)  // 计算状态state中含有的国王数量（1的个数）
{
    int res = 0;
    for (int i = 0; i < n; i++) res += state >> i & 1;
    return res;
}

int main () 
{
    cin >> n >> k;
    
    // 首先预处理所有的合法状态并且计算出状态中对应的国王数量
    for (int i = 0; i < 1 << n; i++)  
        if (check(i)) 
        {
            state.push_back(i);
            cnt[i] = count(i);
        }
    
    // 预处理所有合法状态的所有可能的后继状态
    for (int i = 0; i < state.size(); i++) 
        for (int j = 0; j < state.size(); j++) 
        {
            int a = state[i], b = state[j];
            // 既要满足a和b之间不存在相同列同时为1，也要满足不存在相邻列同时为1
            if ((a & b) == 0 && check(a | b))  
                head[i].push_back(j); 
        }
        
    // 开始动态规划
    f[0][0][0] = 1;  // 入口：合法状态n
    for (int i = 1; i <= n + 1; i++)   // 摆放到第i + 1行，最终f[n + 1][k][0]即为结果
        for (int j = 0; j <= k; j++)   // 当前共摆放j个国王
            for (int a = 0; a < state.size(); a++)   // 当前状态
                for (int b: head[a])   // 遍历当前状态的所有合法前驱状态
                {
                    int c = cnt[state[a]];
                    if (j >= c) f[i][j][a] += f[i - 1][j - c][b];
                }

    cout << f[n + 1][k][0] << endl;

    return 0;
}