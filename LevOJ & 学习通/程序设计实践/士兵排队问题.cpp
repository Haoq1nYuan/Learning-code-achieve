#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10010;

int n, x[N], y[N];

int main ()
{
    while (scanf("%d", &n) != EOF)
    {
        int rex = 0, rey = 0, sum = 0;

        for (int i = 1; i <= n; i++)
            cin >> x[i] >> y[i];
        
        sort(x + 1, x + 1 + n);
        sort(y + 1, y + 1 + n);

        for (int i = 1; i <= n; i++) x[i] -= i;

        sort(x + 1, x + 1 + n);

        if (n % 2)
        {
            rex = x[n / 2 + 1];
            rey = y[n / 2 + 1];
        }
        else
        {
            rex = (x[n / 2] + x[n / 2 + 1]) / 2;
            rey = (y[n / 2] + y[n / 2 + 1]) / 2;
        }

        for (int i = 1; i <= n; i++) sum += abs(x[i] - rex) + abs(y[i] - rey);

        cout << sum << endl;    
    }

    return 0;
}