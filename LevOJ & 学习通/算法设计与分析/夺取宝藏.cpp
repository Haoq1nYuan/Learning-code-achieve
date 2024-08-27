#include <iostream>
#include <cstring>

using namespace std;

const int N = 1005;

int m, n, w[N][N], ans;
int f[N][N];  

int main ()
{
    while (cin >> n >> m)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> w[i][j];

        memset (f, 0, sizeof f);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                f[i][j] = w[i][j] + max(f[i][j - 1], f[i - 1][j]);

        cout << f[n][m] << endl;
    }

    return 0;
}