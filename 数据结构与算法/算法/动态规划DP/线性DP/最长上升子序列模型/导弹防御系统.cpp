//https://www.acwing.com/problem/content/189/

//dfs + 剪枝 + 下降上升双树 + 贪心

#include <iostream>
#include <cstring>

using namespace std;

const int N = 55;

int n, a[N], ans;
int up[N], down[N];

//u代表遍历到第几个数，xu表示下降子序列个数，su表示上升子序列个数
//对于每一个数，讨论其放在xu中和su中的不同情况
void dfs (int u, int xu, int su) 
{
    //对于最坏的情况，也就是所有元素自成一个序列或者已经超过n的时候，这时需要剪枝
    if (xu + su >= ans) return;
    
    //如果没有超过n，且所有导弹都被考虑到，此时就是最优解
    if (u == n + 1)
    {
        ans = xu + su;
        return;
    }
    
    //情况1：将当前来袭导弹放到下降子序列中
    int k = 1;
    while (k <= xu && down[k] <= a[u]) k++;
    int t = down[k];
    down[k] = a[u];
    if (k > xu) dfs(u + 1, xu + 1, su);
    else dfs(u + 1, xu, su);
    down[k] = t;  //恢复现场
    
    //情况2：将当前来袭导弹放到上升子序列中
    k = 1;
    while (k <= su && up[k] >= a[u]) k++;
    t = up[k];
    up[k] = a[u];
    if (k > su) dfs(u + 1, xu, su + 1);
    else dfs(u + 1, xu, su);
    up[k] = t;    //恢复现场
}

int main ()
{
    while (cin >> n, n)
    {
        //此处初始化up，down数组没有必要，因为每一组up，down数组都是先被a数组元素赋值后再比较的
        //memset(up, 0, sizeof(up));
        //memset(down, 0, sizeof(down));
        
        for (int i = 1; i <= n; i++) cin >> a[i];
        
        //最坏情况
        ans = n;
        
        //从第一个开始遍历，第一个参数为 1
        dfs(1, 0, 0);
        
        cout << ans << endl;
    }
    
    return 0;
}