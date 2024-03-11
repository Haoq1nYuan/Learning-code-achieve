// https://www.acwing.com/problem/content/489

// 分组背包套0-1背包
#include <iostream>
#include <vector>

using namespace std;

const int N = 32005, M = 65;
typedef pair<int, int> PII;

int n, m, v, p, q;
PII major[M];
vector<PII> minor[M];
int f[M][N];

int main ()
{
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++)
    {
        cin >> v >> p >> q;
        
        if (q) minor[q].push_back({v, v * p});
        else major[i] = {v, v * p};
    }
    
    for (int i = 1; i <= m; i++)
    {
        // 如果i为附件，不应该跳过，否则会导致f[i][1…n]均未更新！！！

        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j];
            
            if (minor[i].size() == 0 && j >= major[i].first) 
            {
                f[i][j] = max(f[i][j], f[i - 1][j - major[i].first] + major[i].second);
            }
            
            if (minor[i].size() == 1)
            {
                if (j >= minor[i][0].first + major[i].first)
                {
                    f[i][j] = max(f[i][j], f[i - 1][j - minor[i][0].first - major[i].first] + 
                    minor[i][0].second + major[i].second);
                }
                
                if (j >= major[i].first)
                {
                    f[i][j] = max(f[i][j], f[i - 1][j - major[i].first] + major[i].second);
                }
            }
            
            if (minor[i].size() == 2)
            {
                if (j >= minor[i][0].first + minor[i][1].first + major[i].first)
                {
                    f[i][j] = max(f[i][j], f[i - 1][j - minor[i][0].first - minor[i][1].first - major[i].first] + 
                    minor[i][0].second + minor[i][1].second + major[i].second);
                }
                
                if (j >= minor[i][0].first + major[i].first)
                {
                    f[i][j] = max(f[i][j], f[i - 1][j - minor[i][0].first - major[i].first] + 
                    minor[i][0].second + major[i].second);
                }
                
                if (j >= minor[i][1].first + major[i].first)
                {
                    f[i][j] = max(f[i][j], f[i - 1][j - minor[i][1].first - major[i].first] + 
                    minor[i][1].second + major[i].second);
                }
                
                if (j >= major[i].first)
                {
                    f[i][j] = max(f[i][j], f[i - 1][j - major[i].first] + major[i].second);
                }
            }
        }
    }
    
    cout << f[m][n] <<  endl;
    
    return 0;
}

// 简洁写法：二进制分组
#include <iostream>
#include <vector>

using namespace std;

const int N = 32005, M = 65;
typedef pair<int, int> PII;

int n, m, v, p, q;
PII major[M];
vector<PII> minor[M];
int f[M][N];

int main ()
{
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++)
    {
        cin >> v >> p >> q;
        
        if (q) minor[q].push_back({v, v * p});
        else major[i] = {v, v * p};
    }
    
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j];
            
            for (int state = 0; state < (1 << minor[i].size()); state++) // size：2, state(2)：00, 01, 10, 11
            {                                                            // size：1, state(2)：00, 01
                int vs = major[i].first, ws = major[i].second;           // size：0, state(2)：00
                
                for (int k = 0; k < minor[i].size(); k++) // k：0, 1
                    if ((state >> k) & 1)
                    {
                        vs += minor[i][k].first;
                        ws += minor[i][k].second;
                    }
                
                if (j >= vs) f[i][j] = max(f[i][j], f[i - 1][j - vs] + ws);
            }
        }
    
    cout << f[m][n] <<  endl;
    
    return 0;
}

// 一维优化
#include <iostream>
#include <vector>

using namespace std;

const int N = 32005, M = 65;
typedef pair<int, int> PII;

int n, m, v, p, q;
PII major[M];
vector<PII> minor[M];
int f[N];

int main ()
{
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++)
    {
        cin >> v >> p >> q;
        
        if (q) minor[q].push_back({v, v * p});
        else major[i] = {v, v * p};
    }
    
    for (int i = 1; i <= m; i++)
        for (int j = n; j >= 1; j--)
        {
            for (int state = 0; state < (1 << minor[i].size()); state++)
            {                                      
                int vs = major[i].first, ws = major[i].second;
                
                for (int k = 0; k < minor[i].size(); k++) 
                    if (state >> k & 1)
                    {
                        vs += minor[i][k].first;
                        ws += minor[i][k].second;
                    }
                
                if (j >= vs) f[j] = max(f[j], f[j - vs] + ws);
            }
        }
    
    cout << f[n] << endl;
    
    return 0;
}