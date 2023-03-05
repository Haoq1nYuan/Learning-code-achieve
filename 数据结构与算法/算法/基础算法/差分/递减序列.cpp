//https://www.acwing.com/problem/content/102/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;

const int N = 100010;

int a[N], b[N];
int n;

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", &a[i]);
        b[i] = a[i] - a[i - 1];
    }
    
    ll p = 0, q = 0;
    for (int i = 2; i <= n; i++)
        if (b[i] > 0) p += b[i];
        else q -= b[i];
        
    cout << max(p, q) << endl;
    cout << abs(p - q) + 1 << endl;
    
    return 0;    
}