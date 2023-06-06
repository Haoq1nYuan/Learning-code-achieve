#include <iostream>

using namespace std;

const int N = 25;

int n, a[N];

int main ()
{
    while (scanf("%d", &n) != EOF)
    {
        bool flag = false;
        int ans = 0; 
        for (int i = 1; i <= n; i++) cin >> a[i];

        int k = 0;
        while (!flag)
        {
            sort(a + 1, a + 1 + n);
            a[++k]= a[1] * a[2] + 1;

            for (int i = 3; i <= n; i++) b[++k] = a[i];
        }
    }

    return 0;
}