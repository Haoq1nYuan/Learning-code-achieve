//https://www.acwing.com/problem/content/description/854/

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int N = 2010, M = 10010;

int n, m;
int h[N], w[M], e[M], ne[M], idx;
int dist[N], cnt[N];
int st[N];

void add (int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa ()
{
    //本题新建了一个虚拟源点，所有点到这个源点的距离都是0，
    //这样子整张图的负环存在情况并不会受影响
    //本题中只是需要一个dist数组下降的趋势，如果存在趋势，就使cnt+1
    //memset(dist, 0x3f, sizeof(dist));
    //dist[1] = 0;
    //其实也可以写为：
    memset(dist, 0, sizeof(dist));
    dist[0] = 0; //不过没啥意义
    
    queue<int> q;
    q.push(0);
    
    //因为我们不确定是不是有不连通的点，
    //所以我们在将虚拟节点送入队列后需要将所有点都放入队列中
    for ( int i = 1; i <= n; i++ )
    {
        st[i] = true;
        q.push(i);
    }
    
    while (q.size())
    {
        int t = q.front();
        q.pop();
        
        st[t] = false;
        
        //因为存在负环，并且没有边数限制，所以如果存在负环
        //一定会导致cnt > n，所以以此为判断依据
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                
                if (cnt[j] > n) return true;
                
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    
    return false;    
}

int main ()
{
    cin >> n >> m;
    
    memset(h, -1, sizeof(h));
    
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    } 
    
    if (spfa()) puts("Yes");
    else puts("No");
     
    return 0;
}

/*一个小优化，为了更快的让负环中的某个点的 cnt 达到 n + 1，
我们一是可以不使用st数组，这样可以让队列中很快充满可能在负环中的点
对这些点优先遍历就可以节省时间；二是可以用栈来存储*/

//栈和st数组优化
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;
const int N = 2010, M = 10010;

int n, m;
int h[N], w[M], e[M], ne[M], idx;
int dist[N], cnt[N];
int st[N];

void add (int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa ()
{
    stack<int> s;
    for ( int i = 0; i <= n; i++ ) s.push(i);
    
    while (s.size())
    {
        int t = s.top();
        s.pop();
        
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                
                if (cnt[j] > n) return true;
                
                s.push(j);
            }
        }
    }
    
    return false;    
}

int main ()
{
    cin >> n >> m;
    
    memset(h, -1, sizeof(h));
    
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    } 
    
    if (spfa()) puts("Yes");
    else puts("No");
     
    return 0;
}