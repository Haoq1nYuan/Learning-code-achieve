// https://www.acwing.com/problem/content/323/

// dp写法
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 10, M = 20;

int n, w[N][N];
double f[N][N][N][N][M];
double X;

double get (int xl, int xr, int yl, int yr)
{
    double area = w[xr][yr] - w[xl - 1][yr] - w[xr][yl - 1] + w[xl - 1][yl - 1] - X;
    
    return area * area / n;
}

int main ()
{
    cin >> n;
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
        {
            cin >> w[i][j];
            w[i][j] += w[i - 1][j] + w[i][j - 1] - w[i - 1][j - 1];
        }
        
    X = (double)w[8][8] / n;
    
    for (int lenx = 1; lenx <= 8; lenx++)
        for (int leny = 1; leny <= 8; leny++)
            for (int xl = 1; xl + lenx - 1 <= 8; xl++)
                for (int yl = 1; yl + leny - 1 <= 8; yl++)
                {
                    int xr = xl + lenx - 1;
                    int yr = yl + leny - 1;
                    
                    for (int k = 1; k <= n; k++)
                    {
                        if (k == 1) f[xl][xr][yl][yr][k] = get(xl, xr, yl, yr);
                        else 
                        {
                            f[xl][xr][yl][yr][k] = 0x3f3f3f3f;
                            
                            // 横切
                            for (int cut = xl; cut < xr; cut++)
                            {
                                // 选下半部分
                                f[xl][xr][yl][yr][k] = min(f[xl][xr][yl][yr][k], f[xl][cut][yl][yr][k - 1] + get(cut + 1, xr, yl, yr));
                                // 选上半部分
                                f[xl][xr][yl][yr][k] = min(f[xl][xr][yl][yr][k], f[cut + 1][xr][yl][yr][k - 1] + get(xl, cut, yl, yr));
                            }
                            
                            // 纵切
                            for (int cut = yl; cut < yr; cut++)
                            {
                                // 选右半部分
                                f[xl][xr][yl][yr][k] = min(f[xl][xr][yl][yr][k], f[xl][xr][yl][cut][k - 1] + get(xl, xr, cut + 1, yr));
                                // 选左半部分
                                f[xl][xr][yl][yr][k] = min(f[xl][xr][yl][yr][k], f[xl][xr][cut + 1][yr][k - 1] + get(xl, xr, yl, cut));
                            }
                        }
                    }
                }
    
    printf("%.3lf", sqrt(f[1][8][1][8][n]));

    return 0;
}

// 记忆化搜索写法
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 10, M = 20;

int n, w[N][N];
double f[N][N][N][N][M];
double X;

double get (int xl, int xr, int yl, int yr)
{
    double area = w[xr][yr] - w[xl - 1][yr] - w[xr][yl - 1] + w[xl - 1][yl - 1] - X;
    
    return area * area / n;
}

double dp (int xl, int xr, int yl, int yr, int k)
{
    double &v = f[xl][xr][yl][yr][k];
    
    if (k == 1) return get(xl, xr, yl, yr);
    if (v >= 0) return v;  // 可能会有0出现
    
    v = 0x3f3f3f3f;
    
    for (int cut = xl; cut < xr; cut++)
    {
        v = min(v, dp(xl, cut, yl, yr, k - 1) + get(cut + 1, xr, yl, yr));
        v = min(v, dp(cut + 1, xr, yl, yr, k - 1) + get(xl, cut, yl, yr));
    }
    
    for (int cut = yl; cut < yr; cut++)
    {
        v = min(v, dp(xl, xr, yl, cut, k - 1) + get(xl, xr, cut + 1, yr));
        v = min(v, dp(xl, xr, cut + 1, yr, k - 1) + get(xl, xr, yl, cut));
    }
}

int main ()
{
    cin >> n;
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
        {
            cin >> w[i][j];
            w[i][j] += w[i - 1][j] + w[i][j - 1] - w[i - 1][j - 1];
        }
        
    X = (double)w[8][8] / n;
    
    memset(f, -1, sizeof f);  // 初始化浮点数为nan(not a number)
    
    printf("%.3lf", sqrt(dp(1, 8, 1, 8, n)));

    return 0;
}
