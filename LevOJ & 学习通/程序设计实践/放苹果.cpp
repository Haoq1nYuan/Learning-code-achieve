#include <iostream>

using namespace std;

const int N = 30;

int n, m;

int main ()
{
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
        for (int j = i; j <= m; j++)
            f[j] += f[j - i];
    
    cout << f[m] << endl;

    return 0;
}