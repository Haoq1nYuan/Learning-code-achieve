#include <iostream>

using namespace std;

const int N = 1000010;

int n, k;
int a[N];
int q[N], h, t = -1;

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    cin >> k;

    for (int i = 1; i <= n; i++) 
    {
        if (i - 2 * k > q[h]) h++;

        while (t >= h && a[q[t]] >= a[i]) t--;

        q[++t] = i;

        if (i > k) cout << a[q[h]] << ' ';
    }

    for (int i = 1; i <= k; i++) cout << a[q[h]] << ' ';

    return 0;
}