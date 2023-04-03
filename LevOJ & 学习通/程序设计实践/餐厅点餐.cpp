#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 15;

int T, a, b, c, d, e, minl, maxl, num;
int wa[N], wb[N], wc[N], wd[N], we[N];
bool cd[N], ce[N];

void dfs (int cntd, int cnte, int cost)
{   
    if (cntd <= 2 && cnte <= 2 && cntd && cnte)
    {
        for (int i = 1; i <= a; i++)
            for (int j = 1; j <= b; j++)
                if (cost + wa[i] + wb[j] >= minl && cost + wa[i] + wb[j] <= maxl) num++;

        for (int i = 1; i <= c; i++) 
            if (cost + wc[i] >= minl && cost + wc[i] <= maxl) num++;
    }

    if (cntd < 2) 
        for (int i = 1; i <= d; i++) 
            if (!cd[i]) 
            {
                cd[i] = true;
                dfs(cntd + 1, cnte, cost + wd[i]); 
                cd[i] = false;
            }

    if (cnte < 2)
        for (int i = 1; i <= e; i++)
            if (!ce[i])
            {
                ce[i] = true;
                dfs(cntd, cnte + 1, cost + we[i]);
                ce[i] = false;
            }
}

int main ()
{
    cin >> T;
    while (T--)
    {
        memset(cd, 0, sizeof(cd));
        memset(ce, 0, sizeof(ce));
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
        for (int i = 1; i <= a; i++) scanf("%d", &wa[i]);
        for (int i = 1; i <= b; i++) scanf("%d", &wb[i]);
        for (int i = 1; i <= c; i++) scanf("%d", &wc[i]);
        for (int i = 1; i <= d; i++) scanf("%d", &wd[i]);
        for (int i = 1; i <= e; i++) scanf("%d", &we[i]);
        cin >> minl >> maxl;

        dfs(0, 0, 0);

        cout << num << endl;
    }

    return 0;
}
