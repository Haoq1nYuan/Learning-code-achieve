//https://www.acwing.com/problem/content/1564/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010, M = 100010;

int n, l;
bool st[N];
int h[N], e[M], ne[M], idx;
int q[N];

void add (int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs (int x)
{
    int hh = 0, tt = 0;
    q[0] = x;
    
    memset(st, 0, sizeof(st));
    st[x] = true;
    
    int ans = 0;
    for (int j = 0; j < l; j++)
    {
        //只遍历当前一层关注的人，所以要先记录当前队列中的元素个数
        int len = tt - hh + 1;
        while (len--)
        {
            auto t = q[hh++];
            
            //当前层新入队的元素就是下一层的所有关注着
            for (int i = h[t]; i != -1; i = ne[i])
                if (!st[e[i]]) 
                {
                    q[++tt] = e[i];
                    st[e[i]] = true;
                    //只要出现一个粉丝，就多一个转发量
                    ans++;
                }
        }
    }
    
    return ans;
}

int main ()
{
    cin >> n >> l;
    
    memset(h, -1, sizeof(h));
    
    for (int i = 1; i <= n; i++)
    {
        int num;
        scanf("%d", &num);
        while(num--)
        {
            int x;
            scanf("%d", &x);
            //为了宽搜时方便，我们令 "a关注b" 为 "a <- b"
            add(x, i);
        }
    }
    
    int c;
    cin >> c;
    
    while (c--)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", bfs(x));
    }
    
    return 0;
}
