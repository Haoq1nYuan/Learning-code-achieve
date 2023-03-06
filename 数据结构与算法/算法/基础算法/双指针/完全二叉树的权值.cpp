//https://www.acwing.com/problem/content/1242/

#include <iostream>

using namespace std;

typedef long long ll;

const int N = 100010;

ll a[N];

int main ()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        scanf("%lld", &a[i]);
        a[i] += a[i - 1];
    }
    
    int ans, cnt = 0;
    ll maxs = -1e18;
    for (int i = 1, st = 1; i <= n; i++, st *= 2)
    {
        cnt++;
        int len = min(n, i + st - 1);
        ll sum = a[len] - a[i - 1];
        i += st - 1;
        
        if (sum > maxs) 
        {
            maxs = sum;
            ans = cnt;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}