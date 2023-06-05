//https://www.acwing.com/problem/content/description/280/

#include <iostream>

using namespace std;

const int N = 100005;

int n, m, v;
int f[N];  

int main ()
{
    cin >> n >> m;
    
    f[0] = 1;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> v;
        for (int j = m; j >= v; j--)
            f[j] += f[j - v];  
        // f[i][j] = f[i - 1][j] + f[i - 1][j - v] 优化一维之后逆序遍历第二维
    }
            
    cout << f[m] << endl;
    
    return 0;
}