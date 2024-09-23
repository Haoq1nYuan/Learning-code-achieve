// https://acwing.com/problem/content/93/

// 自己想的
/*
    核心：当感觉状态转移不是很明晰时，意味着你需要升维（增加第二维、第三维……）
    注意审题：本题要求是以0为起点，以n-1为终点！！！并非所有路径。
*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 20, S = 1 << N;

int n, dist[N][N];
int f[S][N];   
/* 
    点集经过状态为i，且当前路径以j为终点的所有情况
    状态表示：0表示不经过，1表示经过。最终状态为全1（经过次序不定）
*/
vector<int> markOne;
vector<int> markZero;

int main ()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];
    
    memset(f, 0x3f, sizeof f);
    for (int i = 0; i < n; i++) 
        f[(1 << i) + 1][i] = dist[0][i];

    for (int s = 1; s < (1 << n) - 1; s += 2)  // 确保最低位始终为1
    {
        if (s >> n - 1 & 1) continue;   // 所有中间状态的最高位不能为1
        
        markOne.clear();
        markZero.clear();

        for (int i = 1; i < n; i++)
            if (s >> i & 1) markOne.push_back(i);
            else markZero.push_back(i);
        
        for (int i = 0; i < markOne.size(); i++)   // 遍历所有可能的终点
            for (int j = 0; j < markZero.size(); j++)
            {
                int a = markZero[j], b = markOne[i];
                f[s + (1 << a)][a] = min(f[s + (1 << a)][a], f[s][b] + dist[b][a]);
            }
    }
    
    cout << f[(1 << n) - 1][n - 1] << endl;

    return 0;
}

// y总做法
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20, M = 1 << N;

int n;
int w[N][N];
int f[M][N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            cin >> w[i][j];

    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;

    for (int i = 0; i < 1 << n; i ++ )         // 遍历所有状态
        for (int j = 0; j < n; j ++ )          // 遍历当前状态的路径终点
            if (i >> j & 1)                    // 确保当前状态的对应二进制位上数值为1
                for (int k = 0; k < n; k ++ )  // 遍历当前路径终点的前驱节点
                    if (i >> k & 1)            // 确保当前状态的对应二进制位上数值为1
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);   // 状态转移

    cout << f[(1 << n) - 1][n - 1];

    return 0;
}