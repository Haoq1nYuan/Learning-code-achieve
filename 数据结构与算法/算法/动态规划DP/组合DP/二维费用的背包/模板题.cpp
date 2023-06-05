//https://www.acwing.com/problem/content/8/

/*
与01背包结合，可以从三维优化到二维
*/

#include <iostream>

using namespace std;

const int P = 105;

int N, V, M;
int v, m, w;
int f[P][P];

int main ()
{
    cin >> N >> V >> M;
    
    for (int i = 1; i <= N; i++) 
    {
        cin >> v >> m >> w;
        for (int j = V; j >= v; j--)
            for (int k = M; k >= m; k--)
                f[j][k] = max(f[j][k], f[j - v][k - m] + w);
    }
    
    cout << f[V][M] << endl;
    
    return 0;
}