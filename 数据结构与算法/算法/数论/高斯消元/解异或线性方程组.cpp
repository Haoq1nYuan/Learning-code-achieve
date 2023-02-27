//https://www.acwing.com/problem/content/886/

#include <iostream>

using namespace std;

const int N = 110;

int n;
int a[N][N];

int gauss ()
{
    int r, c;
    for (r = 0, c = 0; c < n; c++)
    {
        //找到非0行，注意，此处t必须初始化r，
        //因为如果当前列元素全为0，那么应该直接跳到下一行，
        //而这一步需要判断当前列中某一行元素为0，不妨设t = r
        //当然，这里对哪一行的非零首元没有要求，只要是非零首元就行
        int t = r;
        for (int i = r; i < n; i++)
            if (a[i][c]) 
            {
                t = i;
                break;
            }

        if (!a[t][c]) continue;
        
        //互换r行和t行
        for (int i = c; i <= n; i++) swap(a[t][i], a[r][i]);
        
        //将r + 1 ~ n - 1行中第c列的1变为0，每一行其他元素相应异或运算即可
        for (int i = r + 1; i < n; i++)
            if (a[i][c])
                for (int j = n; j >= c; j--)
                    a[i][j] ^= a[r][j];
                    
        r++;
    }
    
    if (r < n)
    {
        for (int i = r; i < n; i++)
            if (a[i][n]) return 2;
        return 1;
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
            for (int j = i + 1; j < n; j++)
                a[i][n] ^= a[i][j] * a[j][n];
        return 0;
    }
}

int main ()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            scanf("%d", &a[i][j]);
            
    int t = gauss();
    
    if (t == 2) puts("No solution");
    else if (t == 1) puts("Multiple sets of solutions");
    else 
    {
        for (int i = 0; i < n; i++)
            printf("%d\n", a[i][n]);
    }
    
    return 0;
}