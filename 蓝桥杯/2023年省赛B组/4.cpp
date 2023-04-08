#include <iostream>
#include <cstring>

using namespace std;

const int N = 15;

int T, n;
int t[N], d[N], l[N];
bool flag;
bool st[N];

void dfs (int cnt, int time)
{
    if (cnt == n) 
    {
        flag = true;
        return;
    }

    for (int i = 1; i <= n; i++)
        if (!st[i] && time <= t[i] + d[i])
        {
            st[i] = true;
            dfs(cnt + 1, time + l[i]);
            st[i] = false;
        }
}

int main ()
{
    cin >> T;

    while (T--)
    {
        flag = 0;
        memset(st, 0, sizeof(st));

        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d%d%d", &t[i], &d[i], &l[i]);

        dfs(0, 0);

        if (flag) puts("Yes");
        else puts("No");
    }

    return 0;
}