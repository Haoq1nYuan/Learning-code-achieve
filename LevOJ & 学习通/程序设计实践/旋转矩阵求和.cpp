#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

int n, k;
ll g[11][11];
ll b[11][11];
ll m[11][11];

void turn ()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            b[i][j] = g[n - j + 1][i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            g[i][j] = b[i][j];
            m[i][j] += g[i][j];
        }
}

int main ()
{
    while (scanf("%d", &n) != EOF)
    {   
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) 
            {
                scanf("%d", &g[i][j]);
                m[i][j] = g[i][j];
            }

        cin >> k;

        int c = k / 4;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                m[i][j] += c * (g[i][j] + g[n - i + 1][n - j + 1] + g[j][n - i + 1] + g[n - j + 1][i]);

        for (int i = 1; i <= k % 4; i++) turn();

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) 
                if (j != n) printf("%lld ", m[i][j]);
                else printf("%lld\n", m[i][j]);
    }

    return 0;
}