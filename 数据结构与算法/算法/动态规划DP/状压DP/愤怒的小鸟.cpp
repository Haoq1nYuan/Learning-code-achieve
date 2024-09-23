// https://www.acwing.com/problem/content/526/

// 暴搜

// 状压DP
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

typedef pair<double, double> PDD;

const int N = 18;
const double eps = 1e-8;  // 声明为浮点数

int t, n, m;
PDD pos[N];
int path[N][N];
int f[1 << N];

bool cmp (double x, double y)
{
    if (fabs(x - y) < eps) return true;
    else return false;
}

void init () 
{
    // 通过两个点就可以确定抛物线的参数a, b
    /*
        两个点(x1, y1)和(x2, y2)需要满足：
        1. x坐标不相同
        2. 构造出的抛物线开口向下，即a < 0
    */
    // 对于每一条抛物线，都用一个二进制状态表示该抛物线经过的所有点
    for (int i = 0; i < n; i++)
    {
        path[i][i] = 1 << i;  // 仅经过一个点，也需要初始化
        for (int j = 0; j < n; j++)
        {
            double x1 = pos[i].first, y1 = pos[i].second;
            double x2 = pos[j].first, y2 = pos[j].second;
            
            if (cmp(x1, x2)) continue;  // 不满足条件1
            
            double a = (y1 / x1 - y2 / x2) / (x1 - x2);
            double b = y1 / x1 - a * x1;
            
            if (a >= 0) continue;        // 不满足条件2
            
            for (int k = 0; k < n; k++)   // 将当前抛物线经过的所有点对应索引置1
            {
                double x3 = pos[k].first, y3 = pos[k].second;
                if (cmp(a * x3 * x3 + b * x3, y3)) path[i][j] += 1 << k;
            }
        }
    }
}

int main ()
{
    cin >> t;
    while (t--) 
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)  // 此处从0开始，便于后续二进制操作
            cin >> pos[i].first >> pos[i].second;
        
        // 预处理所有可能的抛物线（n^2条）
        memset(path, 0, sizeof path);
        init();
        
        // 状态压缩DP
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        // 遍历点集的所有覆盖状态（如：10001001……中1表示当前索引对应的点被某个抛物线穿过）
        for (int i = 0; i < 1 << n; i++)  
        { 
            int idx = -1;
            for (int j = 0; j < n; j++)  // 找到当前状态中第一个未被穿过的点对应的索引
                if (!(i >> j & 1)) 
                {
                    idx = j;
                    break;
                }
                
            if (idx == -1) break;   // 若idx为-1，说明此时所有点都被覆盖
            
            // 处理所有的状态转移：由i转换至i | path[idx][k]，即将抛物线所经过的所有点合并后的新状态
            for (int k = 0; k < n; k++)
                f[i | path[idx][k]] = min(f[i | path[idx][k]], f[i] + 1);
        }
        
        cout << f[(1 << n) - 1] << endl;   // f[(1 << n) - 1]表示所有点都被覆盖的情况(1111……11)
    }
    
    return 0;
} 