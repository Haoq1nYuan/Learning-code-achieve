//https://www.acwing.com/problem/content/1021/

#include <iostream>

using namespace std;

const int N = 6010;

int n, m, v, w, s;
int f[N];

int main ()
{
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> v >> w >> s;
        
        for (int j = m; j >= 0; j--)
            for (int k = 0; k <= s && k * v <= j; k++)
                f[j] = max(f[j], f[j - k * v] + k * w);
    }
    
    cout << f[m] << endl;
    
    return 0;
}