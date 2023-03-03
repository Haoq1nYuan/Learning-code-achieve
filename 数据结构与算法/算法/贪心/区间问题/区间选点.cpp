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