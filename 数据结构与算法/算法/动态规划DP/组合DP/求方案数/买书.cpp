//https://www.acwing.com/problem/content/1025/

// k层循环的优化方法与完全背包推导过程类似
/*
f[i][j] = f[i - 1][j] + f[i - 1][j - c[i]] + ……
f[i][j - c[i]] = f[i - 1][j - c[i]] + f[i - 1][j - 2 * c[i]] + ……
f[i][j] = f[i - 1][j] + f[i][j - c[i]]
*/

#include <iostream>

using namespace std;

const int N = 1010;

int n, a[5] = {0, 10, 20, 50, 100};
int f[N];

int main ()
{
    cin >> n;
    
    f[0] = 1;
    
    for (int i = 1; i <= 4; i++)
        for (int j = a[i]; j <= n; j++)  
            f[j] += f[j - a[i]];

    cout << f[n] << endl;
    
    return 0;
}
