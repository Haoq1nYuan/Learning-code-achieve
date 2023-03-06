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

//离散化
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int b[2 * N], idx;

int main ()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        //左端点存储为偶数，右端点存储为奇数
        b[idx++] = l * 2;
        b[idx++] = r * 2 + 1;
    }
    
    sort(b, b + idx);
    
    //res存储教室数，也代表整个活动过程中同时进行的活动数的最大值
    //这个时刻对应的教室数就是最少需要的教室数
    int res = -0x3f3f3f3f, t = 0;
    for (int i = 0; i < idx; i++)
    {
        //如果碰到左端点，教室+1；碰到结束点，教室-1
        //不断寻找当前教室数的最大值，这既是
        if (b[i] % 2 == 0) t++;
        else t--;
        res = max(res, t);
    }
    
    cout << res << endl;
    
    return 0;
}