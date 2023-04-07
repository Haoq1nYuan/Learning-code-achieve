#include <iostream>

using namespace std;

const int N = 105;

int n, a[N];
int st[N], cnt;
int had[N];

void dfs (int u)
{
    if (!st[u] && u) st[u]++, cnt++;

    for (int i = 1; i <= n; i++)
        if (!had[i])
        {
            had[i] = true;
            dfs(u + a[i]);
            had[i] = false;
            if (u >= a[i]) 
            {
                had[i] = true;
                dfs(u - a[i]);
                had[i] = false;
            }
        }
}

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    dfs(0);

    cout << cnt << endl;

    return 0;
}