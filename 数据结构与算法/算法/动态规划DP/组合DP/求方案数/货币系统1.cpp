//https://www.acwing.com/problem/content/1023/

#include <iostream>

using namespace std;

typedef long long ll;

const int N = 3005;

int n, m, a;
ll f[N];

int main ()
{
    cin >> n >> m;
    
    f[0] = 1;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        for (int j = a; j <= m; j++)
            f[j] += f[j - a];
            //f[i][j] = f[i - 1][j] + f[i][j - a];
    }
    
    cout << f[m] << endl;
    
    return 0;
}