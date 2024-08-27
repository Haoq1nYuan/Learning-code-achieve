//https://www.acwing.com/activity/content/problem/content/1111/

#include <iostream>
#include <set>

using namespace std;
typedef pair<int, int> PII;

int n, res;

int main ()
{
    cin >> n;
    
    set<PII> S;
    
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        S.insert({b,a});
    }
    
    int x = -2e9;
    auto i = S.begin();
    
    for ( ; i != S.end(); i++)
    {
        auto t = *i;
        int a = t.second, b = t.first;
        
        if (x < a) 
        {
            res++;
            x = b;
        }
        else continue;
    }
    
    cout << res << endl;
    
    return 0;
}

// ²»ÓÃSTLÈÝÆ÷
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100005;

struct range
{
    int a, b;
    
    bool operator< (const range &tem)const 
    {
        return a < tem.a;
    }
} r[N];

int n, cnt;

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        int a, b;
        cin >> a >> b;
        r[i] = {a, b};
    }
    
    sort (r + 1, r + 1 + n);
    
    for (int i = 1; i <= n; i++)
    {
        int j = i, cur_a = r[j].a, cur_b = r[j].b;
        
        while (j <= n && r[j].b >= cur_a && r[j].a <= cur_b) 
        {
            cur_b = min(cur_b, r[j].b);
            cur_a = max(cur_a, r[j].a);
            j ++;
        }
        
        cnt ++;
        
        if (j == n + 1) break;
        
        i = j - 1;
    }
    
    cout << cnt << endl;
    
    return 0;
}