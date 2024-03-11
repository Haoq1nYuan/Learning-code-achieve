// https://www.acwing.com/problem/content/1060/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 100005;

int n, w;
int f[N][3];   // f[i][0]：买入；f[i][1]：卖出后第一天；f[i][2]：卖出后>=2天

int main ()
{
    cin >> n;
    
    memset(f, -0x3f, sizeof f);
    for (int i = 0; i <= n; i++) f[i][1] = 0, f[i][2] = 0;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> w;
        
        f[i][1] = f[i - 1][0] + w;
        f[i][0] = max(f[i - 1][0], f[i - 1][2] - w);
        f[i][2] = max(f[i - 1][1], f[i - 1][2]);
    }
    
    cout << max(f[n][1], f[n][2]) << endl;

    return 0;
}