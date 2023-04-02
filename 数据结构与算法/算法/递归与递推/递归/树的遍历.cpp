//https://www.acwing.com/problem/content/1499/

//哈希表--最直观的方法
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;
 
const int N = 35;

int n, mid[N], bac[N];
// l[i] = j 和 r[i] = k 分别表示 i 节点的左儿子 j 和右儿子 k
// g 存储中序遍历中每一个元素的下标
unordered_map<int, int> l, r, g;

int build (int ml, int mr, int bl, int br)
{
    //当前子树的根节点为后序子数列中的最后一个元素
    int root = bac[br];
    //当前子树的根节点对应下标
    int rg = g[root];
    
    //下面根据后序遍历中找到的根节点在中序遍历中找到对应元素，并判断子树的存在情况
    //如果左子树存在，递归得到左子树根节点
    if (ml < rg) l[root] = build(ml, rg - 1, bl, bl + rg - ml - 1);
    //如果右子树存在，递归得到右子树根节点
    if (mr > rg) r[root] = build(rg + 1, mr, bl + rg - ml, br - 1);
    
    return root;
}

//队列为什么可以按照层序，每层从左向右遍历？
//根据代码，我们在遍历时会优先将该层所有节点的第一子节点推入队列，而这些点在队列中排列顺序就是从左向右的
//并且父节点比第一子结点要先入队，所以必先将父节点输出再输出第一子结点
void bfs (int root)
{
    queue<int> q;
    q.push(root);
    
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        cout << t << ' ';
        //如果 t 有左儿子，就将该儿子的下标推入队列
        if (l.count(t)) q.push(l[t]);
        //有左儿子同理
        if (r.count(t)) q.push(r[t]);
    }
}

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> bac[i];
    for (int i = 1; i <= n; i++) 
    {
        cin >> mid[i];
        //存储一下中序数列中每个元素的下标
        g[mid[i]] = i;
    }
    
    //重建二叉树，两对参数依次是中序遍历的左右端点，后序遍历的左右端点
    int root = build(1, n, 1, n);    
    
    //用宽搜层序输出该树
    bfs(root);
    
    return 0;
}


//不用哈希--直接层序存储，省去bfs过程
#include <iostream>
#include <vector>

using namespace std;

const int N = 40;

//g存储中序遍历中每个数的下标
int n, mid[N], bac[N], g[N];
vector<int> level[N];

//参数依次为中序序列左右端点，后序遍历左右端点，遍历的深度
void build (int ml, int mr, int bl, int br, int d)
{
    int root = bac[br];
    int rg = g[root];

    //将该层的节点存下来
    level[d].push_back(root);
    
    //先判断左右子树是否存在
    if (rg > ml) build(ml, rg - 1, bl, bl + rg - ml - 1, d + 1);
    if (rg < mr) build(rg + 1, mr, bl + rg - ml, br - 1, d + 1);
}

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> bac[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> mid[i];
        g[mid[i]] = i;
    }
    
    build(1, n, 1, n, 1);
    
    //对于每一层的元素，level 中本身就是从左向右排列的，所以直接输出就行
    for (int i = 1; i <= n; i++)
        for (int t : level[i])
            cout << t << ' ';
    
    return 0;
}