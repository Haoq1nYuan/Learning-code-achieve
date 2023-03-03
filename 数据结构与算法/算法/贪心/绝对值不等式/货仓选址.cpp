//https://www.acwing.com/problem/content/106/

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 100010;

int a[N];

int main ()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    sort(a, a + n);
    
    int x = n / 2;
    int res = 0;
    for (int i = 0; i < n; i++) res += abs(a[x] - a[i]);

    cout << res << endl;

    return 0;
}