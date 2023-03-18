//https://www.acwing.com/problem/content/3795/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010;

int t, n, k, cnt;
int prime[N];
bool st[N];

void get_primes (int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i]) prime[cnt++] = i;
        
        for (int j = 0; j <= n / i; j++)
        {
            st[prime[j] * i] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

int main ()
{
    cin >> t;
    
    get_primes(1010);
    
    while (t--)
    {
        cin >> n >> k;
        
        int ans = 0;
        for (int i = 0; prime[i] + prime[i + 1] + 1 <= n; i++)
            if (!st[prime[i] + prime[i + 1] + 1]) ans++;
        
        if (ans >= k) puts("YES");
        else puts("NO");
    }
    
    return 0;
}