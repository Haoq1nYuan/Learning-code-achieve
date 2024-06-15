#include <iostream>
#include <cstring>

using namespace std;

const int N = 10005;

int n, m, k, a[N];
int f[N];  // 到达位置i的所有跳法中踩到水坑次数最小的方案

int main ()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        a[x] = 1;
    }

    memset(f, 0x3f, sizeof f);

    if (a[1]) f[1] = 1;
    else f[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        for (int j = i - k; j < i; j++)
            if (j > 0) f[i] = min(f[j], f[i]);  // 次数此处对于j的判断必须放在循环里面，否则会跳过一些情况。

        if (a[i]) f[i] += 1;
    }

    cout << f[n] << endl;

    return 0;
}
