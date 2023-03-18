//https://www.acwing.com/problem/content/4312/

#include <iostream>
#include <cmath>
#include <set>

using namespace std;

typedef pair<int, int> PII;

int n, x, y, a, b, k;

int gcd (int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main ()
{
    cin >> n >> x >> y;

    set<PII> m;

    while (n--)
    {
        cin >> a >> b;

        int t = gcd(a - x, b - y);

        a = (a - x) / t, b = (b - y) / t;

        if (m.count({a, b})) continue;
        else m.insert({a, b});
    }

    cout << m.size() << endl;

    return 0;
}