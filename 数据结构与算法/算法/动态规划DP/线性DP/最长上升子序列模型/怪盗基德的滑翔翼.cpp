//https://www.acwing.com/problem/content/1019/

//为什么要做两遍最长上升子序列？
//对于每一个房子，怪盗基德都有向左向右两种选择方式，
//所以要讨论每一个房子左右两端的最长上升子序列，把所有这些结果取一个max

#include <iostream>
#include <cstring>

using namespace std;

const int N = 105;

int k, n, a[N], f[N], res;

int main ()
{
    cin >> k;
    
    while (k--)
    {
        memset(f, 0, sizeof(f));
        res = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        
        for (int i = 1; i <= n; i++)
        {
            f[i] = 1;
            for (int j = 1; j < i; j++)
                if (a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
                
            res = max(f[i], res);
        }
    
        for (int i = n; i; i--)
        {
            f[i] = 1;
            for (int j = n; j > i; j--)
                if (a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
                
            res = max(res, f[i]);
        }
        
        cout << res << endl;
    }
    
    return 0;   
}