//https://www.acwing.com/problem/content/description/274/

//注意状态表示：f[i][j] 表示由第一个序列的前 i 个字母和第二个序列的前 j 个字母且以 b[j] 结尾的所有 LICS 的长度最大值

//朴素版，三重循环---TLE
#include <iostream>

using namespace std;

const int N = 3010;

int n, a[N], b[N];
int f[N][N];

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            //不选 a[i] 的情况
            f[i][j] = f[i - 1][j];
            
            //选 a[i] 的情况
            if (a[i] == b[j])
            {
                for (int k = 1; k < j; k++)
                    if (b[j] > b[k])
                        f[i][j] = max(f[i][j], f[i - 1][k] + 1);
                        //对于上面为什么是 f[i - 1][k]，因为此时 a[i] 已经与 b[j] 匹配，
                        //当我们讨论 b[j] 前面一个匹配的 b[k] 时，自然不能将 a[i] 包含进去，以免出现错误
            }
        }
        
    //找到所有末尾数字不同的LICS之间最大的长度
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[n][i]);
    
    cout << ans << endl;
    
    return 0;
}

//优化过程
/*
我们发现，在 a[i] = b[j] 时，b[j] > b[k] <=> a[i] > b[k]
此时 k 循环就与 j 无关了，我们可以把这一块代码提到 j 循环外面去 
再来分析一下这一块代码的本质，它是求满足 a[i] > b[j] 的所有 f[i][j] + 1 的最大值
并且每一轮 j 循环用到的都是上一轮的结果

所以我们可以先用一个数组 g[i][j] 来代表该代码块的结果，相当于一个滚动数组
g[i][j] 表示满足 a[i] > b[j] 的所有 f[i][j] + 1 的最大值
上一轮的结果就是 g[i][j - 1]

下面讨论如何更新 g[i][j]:
1.g[i][j] 是由 g[i][j - 1] 传递而来
2.先找到更新 g[i][j] 的条件：
  对于朴素版的解法，a[i] = b[j] 时，可以用 g[i][j] 求得 f[i][j] 
  而 a[i] != b[j] 时，有两种情况，a[i] > b[j] 和 a[i] < b[j]
  无论是哪种情况，在朴素版代码中，虽然当前循环 b[j] 不会被用到，但是当前的 b[j] 一定会成为往后 k 循环中的某个 b[k]，并与未来的某个 a[i] 匹配。
  (因为状态表示规定每一个 f[i][j] 都是由 b[j] 的值结尾)
  所以当我们更新 g[i][j] 时，一定时因为当前优化代码中的 b[j](记作A) 满足了在未来某时刻朴素版代码 k 循环中的 b[j](新的) > b[k](也就是A)。
  因为这个过程是在朴素版中的未来某时刻出现的，出现的大前提(也就是k循环出现的前提)满足a[i] = b[j]，
  所以我们可以在更新 g[i][j] 时用到这个条件，也就是当 a[i] > b[k](在优化代码中提前出现并被记作b[j]，即A)，
  即a[i] = b[j](本质上是未来某时刻的b[k]) 时才更新 g[i][j]。
  
  搞清楚更新条件之后，我们来讨论如何更新：
  其实很好理解了，因为这个更新操作是在未来的 k 循环中进行的，参考朴素版代码：
  maxv = max(maxv, f[i - 1][k] + 1);
  在将 f[i - 1][k] 中第二维换成当前优化代码中的 j 即可(b[j](现在) <=> b[k](未来))
  
  综上，满足 a[i] > b[j] 时，g[i][j] = max(g[i][j], f[i - 1][j] + 1);
*/

//滚动数组优化，爆内存
#include <iostream>

using namespace std;

const int N = 3010;

int n, a[N], b[N];
int f[N][N], g[N][N];

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    for (int i = 1; i <= n; i++)
    {
        //初始长度为 0 + 1 = 1
        g[i][0] = 1;
        for (int j = 1; j <= n; j++)
        {
            //不选a[i]的情况
            f[i][j] = f[i - 1][j];
            
            //选a[i]的情况
            if (a[i] == b[j]) f[i][j] = max(f[i][j], g[i][j - 1]);
            
            //更新g[i][j]值
            g[i][j] = g[i][j - 1];
            if (a[i] > b[j]) g[i][j] = max(g[i][j], f[i - 1][j] + 1);
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[n][i]);
    
    cout << ans << endl;
    
    return 0;
}

//用一个变量代替 g 数组
/*
我们不难发现，不管是用到 g[i][j] 时还是更新 g[i][j] 时
都只会用到上一轮 j 循环的结果，这自然就可以只用一个变量来存。
更新操作不受影响
*/
#include <iostream>

using namespace std;

const int N = 3010;

int n, a[N], b[N];
int f[N][N];

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    for (int i = 1; i <= n; i++)
    {
        int maxv = 1;
        for (int j = 1; j <= n; j++)
        {
            //不选a[i]的情况
            f[i][j] = f[i - 1][j];
            
            //选a[i]的情况
            if (a[i] == b[j]) f[i][j] = max(f[i][j], maxv);
            
            //更新maxv值
            if (a[i] > b[j]) maxv = max(maxv, f[i - 1][j] + 1);
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[n][i]);
    
    cout << ans << endl;
    
    return 0;
}

//可有可无的空间优化，优化掉 i 维数组
#include <iostream>

using namespace std;

const int N = 3010;

int n, a[N], b[N];
int f[N];

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    for (int i = 1; i <= n; i++)
    {
        int maxv = 1;
        for (int j = 1; j <= n; j++)
        {
            //选a[i]的情况
            if (a[i] == b[j]) f[j] = max([j], maxv);
            
            //更新maxv值
            if (a[i] > b[j]) maxv = max(maxv, f[j] + 1);
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
    
    cout << ans << endl;
    
    return 0;
}