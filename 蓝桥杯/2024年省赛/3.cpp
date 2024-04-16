#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100000;

int gcd (int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int n, h[N];
double ans = 0;
int x[4];
bool st[N];

int res[4];

void dfs (int k)
{
    if (k == 4) 
    {
        double tem = (double)gcd(x[1], x[3]) * gcd(x[2], x[3]) / gcd((double)(x[1] * x[2]) / gcd(x[1], x[2]), x[3]);

        if (ans < tem)
        {
            ans = tem;

            for (int i = 1; i < 4; i++) res[i] = x[i];
        }   

        return;
    }

    for (int i = 1; i <= n; i++)
        if (!st[i])
        {
            st[i] = true;
            x[k] = h[i];

            dfs (k + 1);

            st[i] = false;
        }
}

int main ()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    sort(h + 1, h + 1 + n);

    dfs(1);

    for (int i = 1; i <= 3; i++) cout << res[i] << ' ';

    return 0;
}