//https://www.acwing.com/problem/content/887/

#include <iostream>

using namespace std;
const int mod = 1e9 + 7;
const int N = 2010;

//c[i][j]表示从i个物品中选j个物品的组合数
int n, c[N][N];

void init ()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            //如果当前列为0，那么将元素初始化为1，即在i个物品中选0个物品的方案数只有1
            if (!j) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
}

int main ()
{
    init();
    
    cin >> n;
    
    while (n--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        
        printf("%d\n", c[a][b]);
    }
    
    return 0;
}