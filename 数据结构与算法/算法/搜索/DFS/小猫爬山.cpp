//https://www.acwing.com/problem/content/description/167/

//每次递归枚举车子
#include <iostream>
#include <algorithm>

using namespace std;

int n, w;
int c[20], sum[20];
int ans = 20;

void dfs (int u, int k)
{
    //最优性剪枝，此处只能为 >= 不能为 ==
    //因为可能出现某一次递归更新了ans，而回溯一层之后下一次递归需要新开一辆车，这就会导致cnt = ans + 1
    //我们需要剪掉这种情况，不能单单在 k == ans 时剪枝
    if (k >= ans) return;
    
    if (u == n)
    {
        ans = k;
        return;
    }
    
    //枚举当前每一辆车是否能够再放入一只小猫
    for (int i = 0; i < k; i++)
        if (c[u] + sum[i] <= w)
        {
            sum[i] += c[u];
            dfs(u + 1, k);
            sum[i] -= c[u];
        }
        
    //如果没有车能够容纳小猫，那么就新开一辆    
    sum[k] = c[u];
    dfs(u + 1, k + 1);
    sum[k] = 0;
}

int main ()
{
    cin >> n >> w;
    for (int i = 0; i < n; i++) cin >> c[i];
    
    //此处的排序和倒置就是为了将重量重的小猫先放到车中，然后再看轻猫是否能够钻空子
    sort(c, c + n);
    reverse(c, c + n);
    
    dfs(0, 0);
    
    cout << ans << endl;
    
    return 0;
}

//这道题如果每次递归都枚举小猫，会出现大量重复情况，只是改变了先后顺序