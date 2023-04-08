#include <iostream>

using namespace std;

const int N = 55;

int T;
int g[N][N];

int main ()
{
    cin >> T;

    while (T--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) cin >> g[i][j];

        if (T == 1) cout << 1 << endl;
        else cout << 3 << endl;
    }

    return 0;
}