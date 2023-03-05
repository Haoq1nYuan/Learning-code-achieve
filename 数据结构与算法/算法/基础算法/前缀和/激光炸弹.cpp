//https://www.acwing.com/problem/content/101/

#include <iostream>

using namespace std;

const int N = 5010;

int k[N][N];

int main ()
{
    int n, r;
    cin >> n >> r;
    r = min(r, 5001);
    
    while (n--)
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        k[x + 1][y + 1] += w;
    }
    
    for (int i = 1; i <= 5001; i++)
        for (int j = 1; j <= 5001; j++)
            k[i][j] += k[i - 1][j] + k[i][j - 1] - k[i - 1][j - 1];
            
    // if (r > 5001) 
    // {
    //     cout << k[5001][5001] << endl;     
    //     return 0;
    // }
            
    int res = 0;        
    for (int i = r; i <= 5001; i++)
        for (int j = r; j <= 5001; j++)
            res = max(k[i][j] - k[i - r][j] - k[i][j - r] + k[i - r][j - r], res); 
    
    cout << res << endl;
    
    return 0;
}