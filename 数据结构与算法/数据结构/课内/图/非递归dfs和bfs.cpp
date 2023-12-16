#include <iostream>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

// 单链表的结点定义
struct ArcNode 
{     
  int adjvex;                // 该弧所指向的顶点的位置
  struct ArcNode *nextarc;   // 指向下一条弧的指针
};

// 顶点定义
struct VNode 
{ 
    int data;      // 顶点信息
    ArcNode *firstarc;    // 指向第一条依附该顶点的结点
};

// 图的定义
struct ALGraph
{  
	VNode vertices[100];   //顶点一维数组
    int v, e;           // 图的点数边数
};

bool st[100];

void addEdge (ALGraph &G, int v, int w) 
{
    ArcNode *p = new ArcNode;  // 新建一个节点
    p->adjvex = w;

    G.vertices[v].data = v;

    // 头插法
    p->nextarc = G.vertices[v].firstarc;
    G.vertices[v].firstarc = p;
}

void DFS (ALGraph G, int v) 
{
    memset(st, 0, sizeof(st));

    stack<int> s;
    st[v] = true;
    cout << v << ' ';
    s.push(v);

    while(!s.empty()) 
    {
        auto i = G.vertices[s.top()].firstarc;
        while (i)
            if (!st[i->adjvex])
            {
                st[i->adjvex] = true;
                cout << i->adjvex << " ";
                s.push(i->adjvex);
                break;
            }
            else i = i->nextarc;
        
        if (!i) s.pop();
    }
}

void BFS (ALGraph G, int v)
{
    memset(st, 0, sizeof(st));

    queue<int> q;
    st[v] = true;
    cout << v << " ";
    q.push(v);

    while (!q.empty())
    {
        auto i = G.vertices[q.front()].firstarc;
        q.pop();
        for (; i; i = i->nextarc)
            if (!st[i->adjvex])
            {
                st[i->adjvex] = true;
                cout << i->adjvex << ' ';
                q.push(i->adjvex);
            }
    }
}

int main () 
{
    ALGraph g;
    cout << "请输入图的点数和边数：";
    cin >> g.v >> g.e;

    for(int i = 1; i <= g.v; i++)
        g.vertices[i].firstarc = NULL;

    int a, b;
    cout << "请依次输入所有边：" << endl;
    for (int i = 1; i <= g.e; i++)
    {
        cin >> a >> b;
        addEdge(g, a, b);
    }

    int st = 0;
    cout << "请输入遍历的起点编号：";
    cin >> st;
    cout << "深度优先遍历(从顶点" << st << "开始):";
    DFS(g, st);
    cout << endl;
    cout << "广度优先遍历(从顶点" << st << "开始):";
    BFS(g, st);

    return 0;
}


/*
样例1：   
6 8
1 2
1 4
2 5
3 1
3 6
4 6
4 2
6 5
输出：
dfs：1 4 2 5 6
bfs：1 4 2 6 5

样例2：
6 8
1 3
1 2
2 3
2 6
3 4
5 2
5 4
6 4
输出：
dfs：1 2 6 4 3
bfs：1 2 3 6 4

样例3：
5 6
1 2
1 5
1 4
2 3
4 5
5 3
输出：
dfs：1 4 5 3 2
bfs：1 4 5 2 3
*/