//https://www.acwing.com/problem/content/885/

#include <iostream>
#include <cmath>

using namespace std;
const int N = 110;
const double eps = 1e-6;

int n;
double a[N][N];

int gauss ()
{
    int c, r;  //c表示列，r表示行
    for (c = 0, r = 0; c < n; c++)
    {
        int t = r;  
        //找到当前这一列中首元绝对值最大的一行，更新到t
        for (int i = r; i < n; i++)
            if (fabs(a[i][c]) > fabs(a[t][c])) t = i;
        
        //因为c++中浮点数的存储存在误差，
        //所以当某个浮点数小于1e-6时我们就可以认定它为0.
        //如果发现当前一列的元素绝对值最大也还是0，
        //说明当前一列的所有元素都是0，直接向右移动一列
        if (fabs(a[t][c]) < eps) continue;
        
        //如果当前一列元素不都为0，那么我们交换t行和r行
        for (int i = c; i <= n; i++) swap(a[t][i], a[r][i]);
        
        //把r行的首元变为1，即r行元素同除r行首元，行内其他元素相应变化
        //注意，如果不存储首元的值，必须从行尾开始修改元素值
        for (int i = n; i >= c; i--) a[r][i] /= a[r][c];
        
        //将当前列中r + 1 ~ n行元素消为0
        for (int i = r + 1; i < n; i++)
            //如果当前行的元素为0，就无需操作
            if (fabs(a[i][c]) > eps)
                //依然是从后往前修改，
                //注意，此时a[r][c] = 1，r + 1 ~ n每一行的c列元素都是直接减去 a[r][c]*本身
                //所以整体变换方式为：行i -= 行r * a[i][c]
                for (int j = n; j >= c; j--)
                    a[i][j] -= a[r][j] * a[i][c];
                    
        r++;  //当前行的工作做完，就需要换到下一行，同时往右移一列
    }
    
    //如果 r < n，说明该增广矩阵不是满秩矩阵，有无穷多解或无解
    if (r < n)
    {
        //从r开始遍历行，如果发现之后的行中最右侧常数列出现非0数，
        //说明系数矩阵和增广矩阵秩不同，一次方程组无解，返回2，
        //否则说明两矩阵秩相同，有无穷多解，返回1
        for (int i = r; i < n; i++)
            if (fabs(a[i][n]) > eps) return 2;
        return 1;
    }
    else
    {
        //如果增广矩阵满秩，那么只有一解，且系数矩阵变换后就是一个对角元素全为1的上三角矩阵。
        //所以只要从下往上消去每一行中除首元和常数项的其他元素就行。
        //消去其他元素后，每一行都可以表示为 xk = ck 的形式，
        //所以a[i][n]存储的就是线性方程组的第i + 1个解，我们只需要改变该值即可
        
        //i表示行，j表示列
        //对于每一个i行，该行非0首元在i列，所以我们从i + 1列开始遍历
        //第i行中第j列元素只能用第j列的非0首元（即1）消去且不会对常数项以外的元素造成影响
        //所以我们只需要用a[j][n]*a[i][j]来减a[i][n]
        for (int i = n - 1; i >= 0; i--)
            for (int j = i + 1; j < n; j++)
                a[i][n] -= a[i][j] * a[j][n];
        return 0;
    }
}

int main ()
{
    cin >> n;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            scanf("%lf", &a[i][j]);
            
    int t = gauss();
    
    //t = 1表示无穷多解，t = 2表示无解，t = 0表示唯一解
    if (t == 2) puts("No solution");
    else if (t == 1) puts("Infinite group solutions");
    else
    {
        for (int i = 0; i < n; i++) 
        {
            if (fabs(a[i][n]) < eps) a[i][n] = 0;
            printf("%.2lf\n", a[i][n]);
        }
    }
    
    return 0;
}