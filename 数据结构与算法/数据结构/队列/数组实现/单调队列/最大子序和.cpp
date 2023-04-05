//https://www.acwing.com/problem/content/137/

#include <iostream>

using namespace std;

const int N = 300010;

int n, m, a[N], ans = -0x3f3f3f3f;
int q[N], h, t = -1;

int main ()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];
    }
    
    q[++t] = 0;
    
    for (int i = 1; i <= n; i++)
    {
        //因为这里是存储的前缀和，根据前缀和的计算公式，我们需要存储到 i - m 的前一个下标
        if (h <= t && i - m > q[h]) h++;
        //对于每一个新入对的序列，都要计算前缀和差
        ans = max(ans, a[i] - a[q[h]]);
        //保证窗口最左端永远最小，方便 a[i] - a[q[h]] 计算时取到相对最大值
        //因为当前窗口左端点就是整个窗口中所有前缀和的最小值，所以无需考虑长度小于 i - q[h] 的序列 
        while (h <= t && a[q[t]] >= a[i]) t--;
        
        q[++t] = i;
    }
    
    cout << ans << endl;
    
    return 0;
}