//https://www.acwing.com/problem/content/description/909/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

struct Range
{
    int l, r;
    
    bool operator< (const Range &k)const
    {
        return l < k.l;
    }
} range[N];

int main ()
{
    int s, t;
    cin >> s >> t;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        int a, b;
        scanf("%d%d", &a, &b);
        range[i] = {a, b};
    }
    
    sort(range, range + n);
    
    int res = 0;
    bool success = false;
    for (int i = 0; i < n; i++)
    {
        int j = i, r = -2e9;
        //用j来枚举每一个左端点 <= s 的区间，寻找最大的右端点
        while (j < n && range[j].l <= s)
        {   
            r = max(r, range[j].r);
            j++;
        }
        
        //如果满足条件的区间最大右端点不能覆盖目标区间，说明无解
        if (r < s)
        {
            res = -1;
            break;
        }
        
        //否则说明存在某个区间可以覆盖目标区间开头的一部分，更新res
        //注意，此处更新 res 一定要在判断 r >= t 的前面
        res++; 
        
        //如果此时右端点大于目标区间的右端点，则说明全部覆盖完成
        if (r >= t)
        {
            success = true;
            break;
        }
        
        //更新目标区间的左端点
        s = r;
        //更新i，从本轮用于覆盖目标区间的区间右边第一个区间开始遍历
        i = j - 1;
    }
    
    if (!success) res = -1;
    
    cout << res << endl;
    
    return 0;
}