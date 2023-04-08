#include <iostream>
#include <cstdio>

using namespace std;

const int N = 10010;

int n, s[N], c[N];
int mid = 0x3f3f3f3f, maxl, minl;
bool flag;

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d%d", &s[i], &c[i]);
        mid = min(mid, s[i] / c[i]);
    }

    for (int i = mid - 1; i > 0; i--)
    {
        for (int j = 1; j <= n; j++)
            if (s[j] / i != c[j]) 
            {
                flag = true;
                minl = i + 1;
            }
        if (flag) break;
    }

    flag = false;
    for (int i = mid + 1; i; i++)
    {
        for (int j = 1; j <= n; j++)
            if (s[j] / i != c[j])
            {
                flag = true;
                maxl = i - 1;
            }
        if (flag) break;
    }

    cout << minl << ' ' << maxl << endl;

    return 0;
}