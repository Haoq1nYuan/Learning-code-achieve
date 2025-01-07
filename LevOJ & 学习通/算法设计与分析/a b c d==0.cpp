#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 2005, M = 4000005;

int t, n, m[N][10], sum[M];
ll ans;

void search (int tar, int len)
{
    int l = 1, r = len, mid = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;

        if (sum[mid] > tar) r = mid - 1;
        else if (sum[mid] < tar) l = mid + 1;
        else 
        {
            ans ++;

            int tem = mid - 1;
            while (sum[tem] == tar)
            {
                ans ++;
                tem --;
            }

            tem = mid + 1;
            while (sum[tem] == tar)
            {
                ans ++; 
                tem ++;
            }

            return;
        }
    }

    return;
}

int main ()
{
    cin >> t;

    while (t--)
    {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 4; j++) cin >> m[i][j];

        int idx = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                sum[idx++] = m[i][1] + m[j][2];
        idx--;

        sort(sum + 1, sum + 1 + idx);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                int s = m[i][3] + m[j][4];

                search(-s, idx);
            }

        cout << ans << endl;
    }

    return 0;
}