//https://www.acwing.com/problem/content/908/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

struct Range
{
    int l, r;
    
    bool operator< (const Range &k)const
    {
        return l < k.l;
    }
}range[N];

int main ()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        range[i] = {a, b};
    }
    
    sort(range, range + n);
    
    //小根堆存储每个区间组的右端点
    //并对所有区间组按照右端点从小到大排序
    priority_queue<int, vector<int>, greater<int>> heap;
    
    for (int i = 0; i < n; i++)
    {
        int a = range[i].l, b = range[i].r;
        
        //如果堆顶区间组和新区间有交集，那么新建一个区间组
        if (heap.empty() || heap.top() >= a) heap.push(b);
        else 
        {
            //如果没有交集，那么直接更新堆中区间的右端点
            heap.pop();
            heap.push(b);
        }
    }
    
    cout << heap.size() << endl;
    
    return 0;
}