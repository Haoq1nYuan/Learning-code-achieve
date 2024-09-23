// https://www.acwing.com/problem/content/293/

/*
    核心：先枚举所有的横向长方形的摆放方式，然后再判断是否合法.
    合法状态需满足：
        1. 相邻状态之间不能有1重合的情况，只能是1相邻.（101与010存在1相邻，110与011存在1重合），即相邻两列之间横向的方块不能重叠
        2. 相邻两列之间，后一列在被前一列伸出的横向方块填补后空白部分需要满足：连续0的数量不能为奇数
*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 11, S = 1 << N;

int n, m;
vector<int> state;    // 1: 放置列内横向方块（伸向右侧一列），0: 不放（由左侧一列伸出填满）
vector<int> head[S];
ll f[N + 2][S];           // 摆放到第i-1列，且由第i-1列伸出到第i列的所有情况的集合

bool check (int state)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (!(state >> i & 1)) 
        {
            cnt++;
        
            while (++i < n)
                if (!(state >> i & 1)) cnt ++;
                else break;
            
            if (cnt % 2) return false;
            
            cnt = 0;
            i--;
        }
    
    return true;
}

int main ()
{
    while (cin >> n >> m, n)
    {
        state.clear();
        for (int i = 0; i < S; i++)
            head[i].clear();

        for (int s = 0; s < 1 << n; s++)  // 本题对单独列的状态没有限制，但是对相邻两列的叠加状态有限制，即条件2
            state.push_back(s);

        for (int s: state)
            for (int s_pre: state)
                if ((s & s_pre) == 0 && check(s | s_pre))  // 条件1，2
                    head[s].push_back(s_pre);
        
        memset(f, 0, sizeof f);    
        f[1][0] = 1;
            
        for (int col = 2; col <= m + 1; col++)
            for (int s: state)
                for (int s_pre: head[s])
                    f[col][s] += f[col - 1][s_pre];
                    
        cout << f[m + 1][0] << endl;   // f[m + 1][0]表示已经摆放好前m列，且第m列没有横向伸出边界的方块
    }
    
    return 0;
}

// 将判断合法前驱状态的操作融合进状态转移的过程中
/*
    核心：先枚举所有的横向长方形的摆放方式，然后再判断是否合法.
    合法状态需满足：
        1. 相邻状态之间不能有1重合的情况，只能是1相邻.（101与010存在1相邻，110与011存在1重合），即相邻两列之间横向的方块不能重叠
        2. 相邻两列之间，后一列在被前一列伸出的横向方块填补后空白部分需要满足：连续0的数量不能为奇数
*/
#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 11, S = 1 << N;

int n, m;
ll f[N + 2][S];           // 摆放到第i-1列，且由第i-1列伸出到第i列的所有情况的集合

bool check (int state)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (!(state >> i & 1)) 
        {
            cnt++;
        
            while (++i < n)
                if (!(state >> i & 1)) cnt ++;
                else break;
            
            if (cnt % 2) return false;
            
            cnt = 0;
            i--;
        }
    
    return true;
}

int main ()
{
    while (cin >> n >> m, n)
    {
        memset(f, 0, sizeof f);    
        f[1][0] = 1;
            
        for (int col = 2; col <= m + 1; col++)
            for (int s = 0; s < 1 << n; s++)
                for (int s_pre = 0; s_pre < 1 << n; s_pre++)
                    if ((s & s_pre) == 0 && check(s | s_pre))
                        f[col][s] += f[col - 1][s_pre];
                    
        cout << f[m + 1][0] << endl;   // f[m + 1][0]表示已经摆放好前m列，且第m列没有横向伸出边界的方块
    }
    
    return 0;
}