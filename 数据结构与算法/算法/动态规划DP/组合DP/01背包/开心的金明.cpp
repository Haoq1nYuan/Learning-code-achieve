// https://www.acwing.com/problem/content/428/

// 模板题，价值定义不同
#include <iostream>

using namespace std;

const int N = 30005, M = 30;

int n, m, v, p;
int f[N];

int main ()
{
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++)
    {
        cin >> v >> p;
        for (int j = n; j >= v; j--)
            f[j] = max(f[j], f[j - v] + v * p);
    }
    
    cout << f[n] << endl;
    
    return 0;
}