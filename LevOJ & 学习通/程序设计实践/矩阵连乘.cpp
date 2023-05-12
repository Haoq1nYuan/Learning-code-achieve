#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010;

typedef long long ll;

int n;
int x, y;
ll g[N][2];
ll f[N][N];

int main ()
{
    while (scanf("%d", &n) != EOF)
    {
        memset(f, 0, sizeof(f));
        bool flag = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> x >> y;
            g[i][0] = x, g[i][1] = y;

            if (x != g[i - 1][1] && g[i - 1][1]) 
            {
                puts("invalid argument");
                flag = 1;
                break;
            }   
        }

        if (flag) continue;

        for (int len = 2; len <= n; len++)
            for (int l = 1; l + len - 1 <= n; l++)
            {
                int r = l + len - 1;
                f[l][r] = f[l][r - 1] + g[l][0] * g[r - 1][1] * g[r][1];

                for (int k = l; k < r; k++)
                    f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + g[l][0] * g[k][1] * g[r][1]);
            }

        cout << f[1][n] << endl;
    }

    return 0;
}