#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1005;

int n;

struct cost
{
    int a, b;
} C[N];

bool cmp (cost m, cost n)
{
    return max(n.a, m.b) + m.a + n.b < max(m.a, n.b) + n.a + m.b;
}

int main ()
{
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) cin >> C[i].a;
        for (int i = 1; i <= n; i++) cin >> C[i].b;

        sort(C + 1, C + 1 + n, cmp); 

        int ans = C[1].a + C[n].b, delay = 0;

        // 设置一个delay偏移量，动态对比A，B两条线的用时情况
        for (int i = 1; i < n; i++)
            if (C[i].b <= C[i + 1].a - delay) 
            {
                ans += C[i + 1].a - delay;
                delay = 0;
            }
            else 
            {
                delay += C[i].b - C[i + 1].a;
                ans += C[i].b;
            }

        // 此法不易懂
        // int suma = 0, sumb = 0;
        // ans += C[1].a + C[n].b;
        // for (int i = 2; i <= n; i++) suma += C[i].a;
        // for (int i = 1; i < n; i++) sumb += C[i].b;
        // ans += max(suma, sumb);

        cout << ans << endl;
    }

    return 0;
}