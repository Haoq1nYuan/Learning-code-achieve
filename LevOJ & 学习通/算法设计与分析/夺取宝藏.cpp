#include <iostream>
#include <cstring>

using namespace std;

const int N = 1005;

int m, n, w[N][N], ans;
int f[N][N][2];  // z = 0 表示前一步向右走，z = 1 表示前一步向下走

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
            {
                f[i][j][0] = w[i][j] + max(f[i][j - 1][0], f[i][j - 1][1]);
                f[i][j][1] = w[i][j] + max(f[i - 1][j][0], f[i - 1][j][1]);
            }

        cout << max(f[n][m][0], f[n][m][1]) << endl;
    }

    return 0;
}