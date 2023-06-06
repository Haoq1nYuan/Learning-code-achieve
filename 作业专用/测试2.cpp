#include <iostream>

using namespace std;

const int N = 10;

int n, g[N][N], b[N][N];

int main ()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> g[i][j];
    
    int i = 2, j = 3;

    cout << g[i][j] << ' ' << g[n - j + 1][i] << ' ' << g[n - i + 1][n - j + 1] << ' ' << g[j][n - i + 1] << endl; 

    return 0;
}