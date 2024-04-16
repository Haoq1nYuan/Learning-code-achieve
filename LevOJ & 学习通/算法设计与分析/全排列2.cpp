#include <iostream>
#include <cstring>

using namespace std;

int n, mark[15];
bool st[15];

void dfs (int idx)
{
    if (idx == n)
    {
        for (int i = 0; i < n; i++) cout << mark[i];
        cout << endl;

        return;
    }

    for (int i = 1; i <= n; i++)
        if (!st[i])
        {
            st[i] = true;
            mark[idx] = i;
            dfs(idx + 1);
            st[i] = false;
        }
}

int main ()
{
    while (cin >> n) 
    {
        memset(st, 0, sizeof st);
        
        dfs(0);
    }

    return 0;
}