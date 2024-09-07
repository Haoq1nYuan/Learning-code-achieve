// https://www.acwing.com/problem/content/1051/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 100005;

typedef long long ll;

int T, n, w;
ll f[N][2];

int main ()
{
    cin >> T;
    
    while (T--)
    {
        cin >> n;
        
        memset(f, 0, sizeof f);
        f[0][1] = -0x3f3f3f3f;           // 不合法方案初始化为负无穷，对于答案没有影响。
        
        for (int i = 1; i <= n; i++)
        {
            cin >> w;
            
            f[i][0] += max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = f[i - 1][0] + w;
        }
        
        cout << max(f[n][1], f[n][0]) << endl;
    }
    
    return 0;
}