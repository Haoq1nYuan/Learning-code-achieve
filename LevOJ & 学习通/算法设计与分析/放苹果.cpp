#include <iostream>

using namespace std;

int n, m, ans;

void dfs (int start, int end, int num)
{
    if (num > m) return;

    if (end == 0 && num <= m)
    {
        ans ++;
        return;
    }

    for (int i = start; i <= end; i++)
    {
        if (i > end - i && i != end) continue;
        dfs (i, end - i, num + 1);
    }
}

int main ()
{
    while (cin >> n >> m) 
    {
        ans = 0;
        dfs(1, n, 0);

        cout << ans << endl;
    }

    return 0;
}