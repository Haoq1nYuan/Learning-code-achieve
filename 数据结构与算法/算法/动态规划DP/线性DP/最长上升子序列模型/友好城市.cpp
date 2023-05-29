//https://www.acwing.com/problem/content/1014/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5010;

int n, f[N], ans;

struct P
{
    int a, b;
    
    bool operator< (const P& k)const
    {
        return a < k.a;
    }
} p[N];

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i].a >> p[i].b;
    
    sort(p + 1, p + 1 + n);
    
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (p[i].b > p[j].b) f[i] = max(f[i], f[j] + 1);
            
        ans = max(f[i], ans);
    }
        
    cout << ans << endl;
        
    return 0;
}