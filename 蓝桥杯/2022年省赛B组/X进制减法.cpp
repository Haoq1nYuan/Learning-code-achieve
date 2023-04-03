//https://www.acwing.com/problem/content/4407/

//对于x进制数，第n位数字的权重是x^(n-1)
#include <iostream>

using namespace std;

typedef long long ll;

const int N = 100010, Mod = 1000000007;

int maxj, la, lb;
ll a[N], b[N], w[N], mul[N];
//w数组存储每个数位的最大合法进制
ll ansa, ansb;

int main ()
{
    cin >> maxj;
    cin >> la;
    for (int i = la; i; i--) cin >> a[i];
    cin >> lb;
    for (int i = lb; i; i--) cin >> b[i];
    
    //计算相同数位的最大合法进制
    int len = max(la, lb);
    for (int i = 1; i <= len; i++)
    {
        int tem = max(a[i], b[i]);
        w[i] = max(tem + 1, 2);
        //if (w[i] > maxj) w[i] = maxj;
    }
    
    //计算x进制数每位数的权重
    mul[0] = 1;
    for (int i = 1; i <= len; i++)
        mul[i] = mul[i - 1] * w[i] % Mod;
    
    //计算a在x进制下的十进制表示
    for (int i = 1; i <= len; i++)
        ansa = (ansa + a[i] * mul[i - 1]) % Mod;
        
    //计算b在x进制下的十进制表示
    for (int i = 1; i <= len; i++)
        ansb = (ansb + b[i] * mul[i - 1]) % Mod;
        
    cout << (ansa - ansb + Mod) % Mod << endl;
     
    return 0;
}