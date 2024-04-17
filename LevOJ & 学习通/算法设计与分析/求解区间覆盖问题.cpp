#include <iostream>
#include <algorithm>

using namespace std;

const int N = 205;

int n, m, ans;
int x[N], dist[N];

int main ()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> x[i];

    if (n <= m) cout << n << endl;
    else 
    {
        sort(x + 1, x + 1 + n);

        for (int i = 1; i < n; i++) dist[i] = x[i + 1] - x[i] - 1;

        sort(dist + 1, dist + n, greater<int>());

        ans = x[n] - x[1] + 1;

        int cnt = 1;
        while (cnt < m) ans = ans - dist[cnt++];

        cout << ans << endl;
    }   

    return 0;
}