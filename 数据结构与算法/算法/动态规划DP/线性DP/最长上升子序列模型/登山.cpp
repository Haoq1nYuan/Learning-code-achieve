//https://www.acwing.com/problem/content/1016/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010;

int n, a[N];
int f[N], r[N], l[N], ans;

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
            
        r[i] = f[i];
    }
    
    //memset(f, 0, sizeof(f));
    for (int i = n; i; i--)
    {
        f[i] = 1;
        for (int j = n; j > i; j--)
            if (a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
            
        l[i] = f[i];
    }
    
    for (int i = 1; i <= n; i++) ans = max(ans, r[i] + l[i] - 1);
    
    cout << ans << endl;
    
    return 0;
}