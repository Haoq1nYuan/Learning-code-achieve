#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 500010;

int n, k, a[N], c[N];
priority_queue<PII, vector<PII>, greater<PII>> heap;
bool st[N];
int b[N];

int main ()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        b[i] = a[i];
        heap.push({a[i], i});
    }

    for (int i = 1; i <= k; i++)
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, w = t.first;

        if (b[ver] != w) 
        {
            i--;
            continue;
        }

        st[ver] = true;

        int bb = ver + 1, ee = ver - 1;
        while (st[bb]) bb++;
        while (st[ee]) ee--;
        a[ee] += w, b[ee] = a[ee];
        a[bb] += w, b[bb] = a[bb];
        if (ee) heap.push({a[ee], ee});
        if (bb <= n) heap.push({a[bb], bb});
    }

    for (int i = 1; i <= n; i++)
        if (!st[i]) cout << a[i] << ' ';

    return 0;
}