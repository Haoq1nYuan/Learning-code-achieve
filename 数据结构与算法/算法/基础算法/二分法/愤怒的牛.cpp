// https://www.acwing.com/problem/content/description/4179/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m, h[N];

bool check (int x)
{
    int last = h[1];
    int num = 1;
    
    for (int i = 1; i <= n; i++)
        if (h[i] - last >= x)
        {
            last = h[i];
            num ++;
        }
        
    if (num < m) return false;
    else return true;
}

int main ()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> h[i];
    sort (h + 1, h + 1 + n);
    
    int l = 1, r = h[n] - h[1];
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    
    cout << l << endl;
    
    return 0;
}