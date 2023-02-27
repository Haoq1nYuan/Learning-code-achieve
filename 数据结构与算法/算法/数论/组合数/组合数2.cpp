//https://www.acwing.com/problem/content/888/

#include <iostream>

using namespace std;
//模数是质数，所以可以用费马小定理和乘法逆元
const int mod = 1e9 + 7;
const int N = 100010;
typedef long long ll;

int fact[N], infact[N];

int qmi (int a, int b, int p)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = (ll)res * a % p;
        b >>= 1;
        a = (ll)a * a % p;
    }
    return res;
}

int main ()
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (ll)fact[i - 1] * i % mod;
        infact[i] = (ll)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
    
    int n;
    cin >> n;
    
    while (n--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        
        printf("%d\n", (ll)fact[a] * infact[b] % mod * infact[a - b] % mod);
    }
    
    return 0;
}