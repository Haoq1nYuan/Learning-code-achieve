//https://www.acwing.com/problem/content/805/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100010;

typedef pair<int, int> PII;

vector<PII> item, res;

int main ()
{
    int n;
    cin >> n;
    
    while (n--)
    {
        int l, r;
        cin >> l >> r;
        
        item.push_back({l, r});
    }
    
    //此处排序自动将左边界和右边界按照字典序排序
    sort(item.begin(), item.end());
    
    //注意，此处初始有边界也可以设为无穷小，方便进行max操作
    //但是这里初始左边界必须设为小于-1e9的数
    int lb = -2e9, rb = -2e9;
    for (auto k : item)
    {
        //若下一个序列与当前母序列无交集，则多加一条序列，更新左右端点
        if (rb < k.first) 
        {
            if (lb != -2e9) res.push_back({lb, rb});
            lb = k.first, rb = k.second;
        }
        else rb = max(rb, k.second); //否则只需延长母序列的右端点
    }
    
    //此处if判断的作用是压入唯一的一个区间。
    //做一个判断，防止把[-2e9, x(x为最末序列的右端点)]压入到res容器中（区间合并情况非唯一）
    if (lb != -2e9) res.push_back({lb, rb});
    
    cout << res.size() << endl;
     
    return 0;
}
