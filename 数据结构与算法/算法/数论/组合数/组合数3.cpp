//https://www.acwing.com/problem/content/889/

#include <iostream>

using namespace std;

typedef long long ll;

//快速幂
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

//计算组合数
int C (int a, int b, int p)
{
    //如果 b > a，无方案可选
    if (b > a) return 0;
    
    int res = 1;
    for (int i = 1, j = a; i <= b; i++, j--)
    {
        //计算分子乘积
        res = (ll)res * j % p;
        //用逆元代替分母除法，只有同模时有效
        res = (ll)res * qmi(i, p - 2, p) % p;
    }
    return res;
}

int lucas (ll a, ll b, int p)
{
    //如果 a < p 且 b < p，那么直接算组合数即可
    if (a < p && b < p) return C(a, b, p);
    //此处不能保证 a/p 和 b/p 后就都 < p，所以还是只能写为 lucas(a / p, b / p, p)
    else return (ll)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}

int main ()
{
    int n;
    cin >> n;
    
    while (n--)
    {
        ll a, b;
        int p;
        cin >> a >> b >> p;
        cout << lucas(a, b, p) << endl;
    }
    
    return 0;
}