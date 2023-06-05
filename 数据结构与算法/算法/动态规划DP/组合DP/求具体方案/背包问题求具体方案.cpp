//https://www.acwing.com/problem/content/12/

//很像图论问题
//先做一遍01背包，再逆推

#include <iostream>

using namespace std;

const int N = 1010;

int n, V;
int v[N], w[N];
int f[N][N];

int main ()
{
    cin >> n >> V;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    
    for (int i = n; i >= 1; i--)
        for (int j = 0; j <= V; j++)
        {
            f[i][j] = f[i + 1][j];
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i + 1][j - v[i]] + w[i]);
        }
    
    int j = V;
    for (int i = 1; i <= n; i++)
        if (j >= v[i] && f[i][j] == f[i + 1][j - v[i]] + w[i]) 
        {
            cout << i << ' ';
            j -= v[i];
        }
    
    return 0;
}