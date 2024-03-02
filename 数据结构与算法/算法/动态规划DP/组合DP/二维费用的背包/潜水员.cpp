//https://www.acwing.com/problem/content/1022/

/*
1.本题需要知道：当体积 j - v 为负时，这时也是合法的，我们把它看作 0 
2.为什么呢？观察这道题的要求：求至少需要体积 v，重量 m 的情况下，能拿到价值的最小值
  “至少”的意思就是，如果当前物品的体积 vi 比 v 大，我也可以选，只不过会导致 v - vi < 0
  对于这种情况，我们把 v - vi 统一看作 0 
  重量同理。

3.所以，我们在执行体积重量的遍历时，需要从最大值遍历到 0，考虑到所有情况
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 100;

int n, m, k, a, b, c;
int f[N][N];

int main ()
{
    cin >> n >> m >> k;
    
    memset(f, 0x3f, sizeof(f));
    //这里设置一个入口，因为我们规定所有体积/重量小于 0 的情况都是由 f[0][0] 转化而来
    f[0][0] = 0;
    
    while (k--)
    {
        cin >> a >> b >> c;
                   
        for (int i = n; i >= 0; i--)  // 此处要循环至0，因为必须确保f数组从f[0][0]处开始更新
            for (int j = m; j >= 0; j--)
                f[i][j] = min(f[i][j], f[max(0, i - a)][max(0, j - b)] + c);
    }
            
    cout << f[n][m] << endl;
      
    return 0;
}
