//https://www.acwing.com/problem/content/description/1212/

#include <iostream>

using namespace std;

const int N = 100010;

int n, a[N], ans;

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    for (int i = 1; i <= n; i++)
    {
        int maxf = -0x3f3f3f3f, minf = 0x3f3f3f3f;
        for (int j = i; j <= n; j++)
        {
            maxf = max(maxf, a[j]);
            minf = min(minf, a[j]);
            if (maxf - minf == j - i) ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}