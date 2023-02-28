//https://www.acwing.com/problem/content/891/

#include <iostream>

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int n;

int qmi (int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        if (k & 1) res = (ll)res * a % p;
        k >>= 1;
        a = (ll)a * a % p;
    }
    return res;
}

int main ()
{
    cin >> n;
    
    int a = n * 2, b = n;
    int res = 1;
    
    //求组合数
    for (int i = a; i > a - b; i--) res = (ll)res * i % mod;
    for (int i = 1; i <= b; i++) res = (ll)res * qmi(i, mod - 2, mod) % mod;
    //除以n + 1
    res = (ll)res * qmi(n + 1, mod - 2, mod) % mod;
    
    cout << res << endl;
    
    return 0;
}