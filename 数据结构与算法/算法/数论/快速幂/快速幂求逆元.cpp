//https://www.acwing.com/problem/content/878/

#include <iostream>

using namespace std;
typedef long long ll;

int qmi (int a, int p, int m)
{
    int res =  1;
    while (p)
    {
        if (p & 1) res = (ll)res * a % m;

        p >>= 1;
        a = (ll)a * a % m; 
    }

    return res;
}

int main ()
{
    int n;
    scanf("%d", &n);

    while (n--)
    {
        int a, p;
        scanf("%d%d", &a, &p);

        int t = qmi(a, p - 2, p);
        if (!(a % p)) puts("impossible");
        else printf("%d\n", t); 
    }

    return 0;
}