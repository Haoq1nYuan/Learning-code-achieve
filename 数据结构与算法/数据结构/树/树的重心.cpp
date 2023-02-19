//https://www.acwing.com/problem/content/848/

#include <iostream>
#include <cstring>

using namespace std;
const int N =100010, M = N * 2;

int n;
int h[N], e[M], ne[M], idx;
int ans = N;
bool st[M];

//头插，将b插入a中，a作为根，处在链表开头
//遍历的时候从根节点开始递归，递归到最末子节点后层层返回
void add (int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

//返回以编号u为根节点的子树中节点数量
int dfs (int u)
{
    //更新判重数组，表示当前节点已被遍历过
    st[u] = true;
    
    int size = 0, sum = 0;
    //遍历u的所有子树中节点个数
    for ( int i = h[u]; i != -1; i = ne[i] )
    {
        if (st[e[i]]) continue;
        
        //s是以e[i]为根节点的子树中节点数
        int s = dfs(e[i]);
        size = max(size, s);
        
        //sum表示以u为根节点的子树中除根节点以外的其他节点的总数
        sum += s;
    }
    
    //经过for循环，size表示连接u节点的所有子树中节点数的最大值
    //n - (sum + 1) 表示在u节点之上的所有节点的数量，两者取最大值
    size = max(size, n - sum - 1);
    //最后在取最大值的相对最小值
    ans = min(ans, size);
    
    //返回根节点+子树节点数
    return sum + 1;
}

int main () 
{
    cin >> n;
    
    memset(h, -1, sizeof(h));
    
    for ( int i = 0; i < n - 1; i++ )
    {
        int a, b;
        cin >> a >> b;
        //因为是无向边，所以需要互相连接
        add(a, b), add(b, a);
    }
    //从编号1的结点开始，这里的节点编号可以任意
    dfs(1);
    
    cout << ans;
    
    return 0;
}