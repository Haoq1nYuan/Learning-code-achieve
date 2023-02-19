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
        if (rb < k.first) 
        {
            if (lb != -2e9) res.push_back({lb, rb});
            lb = k.first, rb = k.second;
        }
        else rb = max(rb, k.second);
    }
    
    //此处if判断的作用是压入最后一个区间，但是防止n为0，把[-2e9, -2e9]压入res容器中
    if (lb != -2e9) res.push_back({lb, rb});
    
    cout << res.size() << endl;
     
    return 0;
}
