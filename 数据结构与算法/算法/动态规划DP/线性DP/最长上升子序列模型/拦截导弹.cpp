//https://www.acwing.com/problem/content/1012/

//贪心思路，尽可能利用少的导弹
//对于飞来的所有导弹，高度低的导弹接在高度较高的导弹后面，
//如果无法接，那么就新开一条下降子序列

#include <iostream>
#include <sstream>

using namespace std;

const int N = 1010;

int a[N], f[N], g[N], ans, cnt, n = 1;
//g数组存储每一个序列的末尾值

int main ()
{
    while (cin >> a[n]) n++;
    
    for (int i = n - 1; i; i--)
    {
        f[i] = 1;
        
        for (int j = n - 1; j > i; j--)
            if (a[i] >= a[j]) f[i] = max(f[i], f[j] + 1);
            
        ans = max(f[i], ans);
    }

    //贪心    
    for (int i = 1; i < n; i++)
    {
        int k = 0;
        while (k < cnt && g[k] < a[i]) k++;
        g[k] = a[i];
        if (k == cnt) cnt++;
    }
    
    cout << ans << endl << cnt << endl;
    
    return 0;
}