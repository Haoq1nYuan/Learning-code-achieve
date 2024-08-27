// 暴力解法
#include <iostream>

using namespace std;

const int N = 10010;

int n, x[N], ans;

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];

    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (x[i] > x[j]) ans ++;

    cout << ans << endl;

    return 0;
}

// 分治法优化
#include <iostream>

using namespace std;

const int N = 10010;

int n, x[N], tem[N], ans;

int merge_sort (int *q, int l, int r)
{
    if (l >= r) return 0;

    int mid = (l + r) / 2;
    int res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);

    int idx = 1, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j]) tem[idx++] = q[i++];
        else 
        {
            tem[idx++] = q[j++];
            res += mid - i + 1;
        }
    }

    while (i <= mid) tem[idx++] = q[i++];
    while (j <= r) tem[idx++] = q[j++];

    for (int i = 1; i < idx; i++) q[l + i - 1] = tem[i];

    return res;
}

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];

    cout << merge_sort(x, 1, n) << endl;

    return 0;
}