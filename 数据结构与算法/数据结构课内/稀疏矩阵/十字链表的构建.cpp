#include <iostream>

using namespace std;

typedef struct OLNode
{
    int i, j, e;
    struct OLNode *right, *down;
} OLNode, *OLink; 

typedef struct
{
    OLink *rhead, *chead;
    int r, c, n;
} CrossList;

// 构建十字链表
void CreateSMatrix_OL (CrossList &m)
{
    // 录入十字链表尺寸及非零元个数
    int r, c, n;
    cin >> r >> c >> n;
    m.r = r, m.c = c, m.n = n;

    // 已定义过的变量申请内存空间无需指明类型
    m.rhead = new OLink[n + 1];
    m.chead = new OLink[n + 1];
    
    // 所有指针指向NULL
    for (int i = 1; i <= n; i++)
    {
        m.rhead[i] = NULL;
        m.chead[i] = NULL;
    }

    int i, j, e;
    for (int s = 1; s <= n; s++)
    {
        cin >> i >> j >> e;

        OLNode *p = new OLNode;
        p -> i = i;
        p -> j = j;
        p -> e = e;

        // 首先构建行向量
        // 如果新元所在行没有元素或者该非零元在该行中的旧首元左边
        // 则直接更新该行首元的位置
        // 十字链表中，每一行每一列的末尾元指针都指向NULL，就是从这个判断中延续下去的
        // NULL指针不断被传递到末尾位置。
        if (m.rhead[i] == NULL || m.rhead[i] -> j > j)
        {
            // 新元指向旧首元
            p -> right = m.rhead[i];
            // 更新指向首元的指针
            m.rhead[i] = p;
        }
        else // 若该非零元在该行中的首元右边
        {
            // 一直向右遍历，直到遍历到新元所在列的左侧最近一列上的非零元
            for (OLNode *q = m.rhead[i]; q && q -> j < j; q = q -> right)
            {
                // 插入新元
                p -> right = q -> right;
                q ->right = p;
            }
        }

        // 构建列向量的过程同理
        if (m.chead[j] == NULL || m.chead[j] -> i > i)
        {
            p -> down = m.chead[j];
            m.chead[j] = p;
        }
        else
        {
            for (OLNode *q = m.chead[j]; q && q -> i < i; q = q -> down)
            {
                p -> down = q -> down;
                q -> down = p;
            }
        }
    }
}

// 打印矩阵
void Show (CrossList x)
{
    for (int i = 1; i <= x.r; i++)
        for (OLNode *t = x.rhead[i]; t; t = t -> right) 
            cout << "r:" << t -> i << " c:" << t -> j << " e:" << t -> e << endl;
}

int main ()
{
    CrossList c;

    CreateSMatrix_OL(c);

    Show(c);

    return 0;
}