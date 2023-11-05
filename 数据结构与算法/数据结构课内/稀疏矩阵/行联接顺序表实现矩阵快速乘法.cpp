#include <iostream>
#define MAXSIZE 100
#define MAXROW 10
#define Elemtype int

using namespace std;

typedef struct 
{
    int i, j;

    Elemtype e;
} Triple;

typedef struct 
{
    Triple data[MAXSIZE + 1];

    int rpos[MAXROW + 1]; // 各行第一个非零元的位置表

    int r, c, n;
} RLSMatrix;

int r, c, n, x, y, data, acc[MAXROW + 1];

// 构建行联接顺序表
void InitSMatrix (RLSMatrix &a)
{
    cin >> r >> c >> n;
    a.r = r, a.c = c, a.n = n;

    for (int i = 1; i <= a.n; i++)
    {
        cin >> x >> y >> data;
        a.data[i] = {x, y, data};
    }

    int num[r + 1] = {0};
    for (int p = 1; p <= a.n; p++) num[a.data[p].i]++;

    a.rpos[1] = 1;
    for (int row = 2; row <= a.r; row++)
        a.rpos[row] = a.rpos[row - 1] + num[row - 1];
}

// 快速乘法，假设矩阵尺寸满足乘法条件
void MultSMatrix (RLSMatrix a, RLSMatrix b, RLSMatrix &q)
{
    q.r = a.r, q.c = b.c, q.n = 0;

    // 遍历矩阵a的每一行
    for (int arow = 1; arow <= a.r; arow++)
    {
        // q中arow行各位置的的累加量
        int acc[q.c + 1] = {0};

        // 结构矩阵的行数与a相同，故用arow作索引
        // 与此同时，每遍历一次就计算当前行非零首元在q.data中的索引
        q.rpos[arow] = q.n + 1;

        // 计算当前行非零元素在a.data中的索引结尾
        int tp = 0; 
        if (arow < a.r) tp = a.rpos[arow + 1];
        else tp = a.n + 1;

        // 从左往右遍历a.data中在arow行内的所有元素
        for (int p = a.rpos[arow]; p < tp; p++)
        {
            // 计算a中每一个非零元的所在列
            int brow = a.data[p].j;

            // a中的行与b中的列相乘，故brow就相当于b中的行
            // 计算当前行在b.data中的索引结尾
            int t = 0;
            if (brow < b.r) t = b.rpos[brow + 1]; 
            else t = b.n + 1;

            // 从左往右遍历b.data中在brow行内的所有元素
            for (int s = b.rpos[brow]; s < t; s++)
            {
                // 求得当前元素所在列，b的列与q的列相同
                int col = b.data[s].j;
                // 累加在q[arow][col]上的乘积
                acc[col] += a.data[p].e * b.data[s].e;
            }
        }

        // 将累加量计入q中相应位置
        // q.data[]下标为q.n，因为q.n是动态更新的，每填入一个元素就加1
        for (int col = 1; col <= q.c; col++)
            if (acc[col]) q.data[++q.n] = {arow, col, acc[col]};
    }
}

// 打印稀疏矩阵
void Show (RLSMatrix m)
{
    int k = 1, row = 1;
    for (int col = 1; col <= m.c; col = (col % m.c) + 1)
    {
        if (m.data[k].j == col && m.data[k].i == row) cout << m.data[k++].e << ' ';
        else cout << 0 << ' ';

        if (col == m.c)
        {
            cout << endl;
            if (++row > m.r) break;
        } 
    }   
}

int main ()
{
    RLSMatrix a, b, q;
    InitSMatrix(a);
    InitSMatrix(b);
    
    MultSMatrix(a, b, q);

    Show(q);

    return 0;
}