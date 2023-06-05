//https://www.acwing.com/problem/content/1026/

#include <iostream>

using namespace std;

const int N = 20010;

int n, V;
int v[N], f[N];

int main ()
{
    cin >> V >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    
    for (int i = 1; i <= n; i++) 
        for (int j = V; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + v[i]);
            
    cout << V - f[V] << endl;
    
    return 0;
}