//https://www.acwing.com/problem/content/description/3488/

//滑动窗口+Trie树
#include <iostream>

using namespace std;

const int N = 100010, M = 3100010;

int n, m, a[N];
//cnt数组存储当前节点下标出现的次数
//在窗口中出现的cnt值一定不为0
int son[M][2], idx, cnt[M];
int ans;

void insert (int x, int v)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int t = x >> i & 1;
        if (!son[p][t]) son[p][t] = ++idx;
        p = son[p][t];
        cnt[p] += v;
    }
}

int search (int x)
{
    int p = 0;
    
    int num = 0;
    for (int i = 30; i >= 0; i--)
    {
        int t = x >> i & 1;
        //如果当前窗口中存在当前位不同的数
        if (cnt[son[p][!t]])
        {
            p = son[p][!t];
            //如果当前位不同，说明可以异或得到1
            //num左移实现乘二，+1 说明该位异或结果为1
            num = (num << 1) + 1;
        }
        else
        {
            p = son[p][t];
            //如果当前位相同，则只需要左移一位，新出现的一位异或后是0
            num <<= 1;
        }
    }
    
    return num;
}

int main ()
{
    //题目给出一个长度为 m 的滑动窗口
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] ^= a[i - 1];
    }
    
    //第二个参数 1 表示插入，-1 表示删除
    insert(a[0], 1);
    //从第一个数开始遍历，寻找以它为右端点的滑动窗口中与它异或值最大的数
    for (int i = 1; i <= n; i++)
    {
        //如果超出最长序列宽度，则将超出数字删除
        if (i - m - 1 >= 0) insert(a[i - m - 1], -1);
        ans = max(ans, search(a[i]));
        //将新出现的数和窗口中的某个数字进行异或操作之后
        //要将新数加入窗口中
        insert(a[i], 1);
    }
            
    cout << ans << endl;
    
    return 0;
}