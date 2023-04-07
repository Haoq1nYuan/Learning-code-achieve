#include <iostream>

using namespace std;

const int N = 100010;

int n, m, a[N], tem[N], k;

//½µÐò
void merge_sort1 (int l, int r, int *a)
{
    if (l >= r) return;

    int mid = (l + r) / 2;

    merge_sort1(l, mid, a);
    merge_sort1(mid + 1, r, a);

    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
    {
        if (a[i] > a[j]) tem[k++] = a[i++];
        else tem[k++] = a[j++]; 
    }

    while (i <= mid) tem[k++] = a[i++];
    while (j <= r) tem[k++] = a[j++];

    for (int p = l; p <= r; p++) a[p] = tem[p];
}

//ÉýÐò
void merge_sort2 (int l, int r, int *a)
{
    if (l >= r) return;

    int mid = (l + r) / 2;

    merge_sort2(l, mid, a);
    merge_sort2(mid + 1, r, a);

    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
    {
        if (a[i] < a[j]) tem[k++] = a[i++];
        else tem[k++] = a[j++]; 
    }

    while (i <= mid) tem[k++] = a[i++];
    while (j <= r) tem[k++] = a[j++];

    for (int p = l; p <= r; p++) a[p] = tem[p];
}

int main ()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) a[i] = i;

    while (m--)
    {
        int p, q;
        cin >> p >> q;

        if (!p) merge_sort1(1, q, a);
        else merge_sort2(q, n, a);
    }

    for (int i = 1; i <= n; i++) cout << a[i] << ' ';

    return 0;
}