//https://www.acwing.com/problem/content/425/

#include <iostream>

using namespace std;

const int N = 1005;

int T, M;
int t[N], w[N];
int f[N];

int main ()
{
    cin >> T >> M;
    for (int i = 1; i <= M; i++) cin >> t[i] >> w[i];
    
    for (int i = 1; i <= M; i++)
        for (int j = T; j >= t[i]; j--)
            f[j] = max(f[j], f[j - t[i]] + w[i]);
            
    cout << f[T] << endl;
    
    return 0;
}