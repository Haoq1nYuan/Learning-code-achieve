//https://www.acwing.com/problem/content/1025/

#include <iostream>

using namespace std;

const int N = 1010;

int n, a[5] = {0, 10, 20, 50, 100};
int f[N];

int main ()
{
    cin >> n;
    
    f[0] = 1;
    
    for (int i = 1; i <= 4; i++)
        for (int j = a[i]; j <= n; j++)
            f[j] += f[j - a[i]];
            
    cout << f[n] << endl;
    
    return 0;
}