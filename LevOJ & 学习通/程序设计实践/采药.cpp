#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010;

int T, m, t, w;
int f[N];

int main ()
{
    while (cin >> T >> m)
    {
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= m; i++)
        {
            cin >> t >> w;
            for (int j = T; j >= t; j--)
                f[j] = max(f[j], f[j - t] + w);
        }

        cout << f[T] << endl;
    }

    return 0;
}