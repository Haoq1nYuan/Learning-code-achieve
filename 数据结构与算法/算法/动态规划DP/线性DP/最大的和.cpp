#include <iostream>
#include <cstring>

using namespace std;

const int N = 50010;

int T, n, a[N];
int f[N], b[N];

int main ()
{
    cin >> T;
    
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        
        memset(f, -0x3f, sizeof(f));
        memset(b, -0x3f, sizeof(b));
        
        //得到左半部分所有分解情况的最大元素和
        //tem表示以a[i]为右端点的连续元素序列，它们的和是时刻最大的
        int tem = 0;
        for (int i = 1; i < n; i++) //右半部分最少留一个元素
        {
            tem = max(tem, 0) + a[i];
            //将包含a[i]的连续序列和包含a[i - 1]的连续序列进行比较
            //对于为什么只需用i - 1的情况去更新i，因为如果遇到连续几次a[i]都不取的情况，
            //即tem一直小于0，f[i - 1]依然保留着最初的最大值，所以原本的最大值都会一直传递下去，
            //直到遇到某个tem满足更新条件
            f[i] = max(f[i - 1], tem);
        }
        
        //得到右半部分所有分解情况的最大元素和
        tem = 0;                       
        for (int i = n; i > 1; i--) //左半部分最少留一个元素
        {
            tem = max(tem, 0) + a[i];
            b[i] = max(b[i + 1], tem);
        }
        
        int res = -0x3f3f3f3f;
        for (int i = 1; i < n; i++) res = max(res, f[i] + b[i + 1]);
        
        cout << res << endl;
    }
    
    return 0;
}