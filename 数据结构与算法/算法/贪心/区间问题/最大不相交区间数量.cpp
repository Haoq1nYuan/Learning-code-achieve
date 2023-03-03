//https://www.acwing.com/problem/content/910/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

struct Range
{
    int l, r;
    
    bool operator< (const Range &k)const
    {
        return r < k.r;
    }
} range[N];

int main ()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        range[i] = {a, b};
    }
    
    sort(range, range + n);
    
    int res = 0;
    int x = -2e9;
    
    for (int i = 0; i < n; i++)
    {
        int a = range[i].l, b = range[i].r;
        
        if (x < a)
        {
            res++;
            x = b;
        }
    }
    
    cout << res << endl;
    
    return 0;
}