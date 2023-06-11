//https://www.dotcpp.com/oj/problem2980.html?sid=12368324&lang=1#editor

#include <iostream>
#include <cstring>

using namespace std;

const int N = 100;

int n;
int t[N], k;

int main ()
{
    scanf("%d", &n);

    int tem = n;

    for (int i = 1; i <= 32; i++)
    {
        t[++k] = n & 1;
        n >>= 1;
    }

    if (tem > 0) for (int i = k; i; i--) cout << t[i];
    else 
    {
        int i = 0;
        for (i = k - 1; i; i--) t[i] &= 1;

        t[0]++;
        while (t[i] == 2) t[i] = 0, t[++i]++;

        for (int i = k; i; i--) cout << t[i];
    }

    return 0;
}