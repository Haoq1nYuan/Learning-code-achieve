//https://www.acwing.com/problem/content/description/915/

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 100010;

int x[N];

int main ()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) scanf("%d", &x[i]);
    
    sort(x, x + n);
    
    ll res = 0;
    for (int i = 0; i < n; i++) res += x[i] * (n - i - 1);
    
    cout << res << endl;
    
    return 0;
}