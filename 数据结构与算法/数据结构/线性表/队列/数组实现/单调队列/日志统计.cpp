//https://www.acwing.com/problem/content/description/1240/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

typedef pair<int, int> PII;

int n, d, k;
PII log[N];
int cnt[N], ans[N], idx;
bool st[N];

int main ()
{
    cin >> n >> d >> k;
    for (int i = 1; i <= n; i++) scanf("%d%d", &log[i].first, &log[i].second);
    
    sort(log + 1, log + n + 1);

    for (int i = 1, j = 1; i <= n; i++)
    {
        while (log[j].first - log[i].first < d && j <= n)
        {
            cnt[log[j].second]++;
            if (cnt[log[j].second] >= k && !st[log[j].second]) 
            {
                ans[idx++] = log[j].second;
                st[log[j].second] = true;
            }
            j++;
        }
        
        cnt[log[i].second]--;
    }

    sort(ans, ans + idx);
    
    for (int i = 0; i < idx; i++) printf("%d\n", ans[i]);
    
    return 0;
}