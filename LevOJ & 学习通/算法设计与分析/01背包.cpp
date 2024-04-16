#include <iostream>
#include <cstring>

using namespace std;

const int N = 20005;

int n, m;
int f[N];

int main ()
{   
    while (cin >> m >> n)
    {
        memset(f, 0, sizeof f);

        for (int i = 1; i <= n; i++)
        {
            int v = 0, w = 0;
            cin >> v >> w;

            for (int j = m; j >= v; j--)
                f[j] = max(f[j], f[j - v] + w);
        }

        cout << f[m] << endl;
    }

    return 0;
}