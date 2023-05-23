#include <iostream>
#include <algorithm>

using namespace std;

int n;

struct Piont 
{
    int ai, bi, id;

    bool operator< (const Piont& b)const
    {
        return ai + max(b.ai, bi) + b.bi < bi + max(b.bi, ai) + b.ai;
    }
} p[1005];

int main ()
{
    while (scanf("%d", &n) != EOF)
    {
        int a = 0, b = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i].ai;
            p[i].id = i;
        }
        
        for (int i = 1; i <= n; i++) cin >> p[i].bi;

        sort(p + 1, p + 1 + n);

        for (int i = 2; i <= n; i++) a += p[i].ai;
        for (int i = 1; i < n; i++) b += p[i].bi;

        cout << p[1].ai + max(a, b) + p[n].bi << endl;
    }

    return 0;
}