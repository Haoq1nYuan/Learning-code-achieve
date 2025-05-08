//https://www.acwing.com/problem/content/877/

#include <iostream>

using namespace std;

typedef long long ll;

int qmi (int a, int k, int p)
{
    //res存储次幂结果 mod p，肯定在int范围内
    int res = 1;
    //不断左移k的二进制数，每一位都对应2的一个次幂
    while (k)
    {
        //如果k的二进制数还未右移完，就更新结果
        //k的第n位二进制位对应a^(2^(n - 1))
        if (k & 1) res = (ll)res * a % p;
        //k右移一位
        k >>= 1;
        //a幂次加一
        a = (ll)a * a % p; 
    }

    return res;
}

int main ()
{
    int n;
    scanf("%d", &n);
    
    while (n--)
    {
        int a, k, p;
        scanf("%d%d%d", &a, &k, &p);
        
        printf("%d\n", qmi(a, k, p));
    }
    
    return 0;
}