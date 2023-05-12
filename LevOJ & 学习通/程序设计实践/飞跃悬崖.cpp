#include <iostream>

using namespace std;

typedef long long ll;

ll a[55];
int n;

int main ()
{
    while (scanf("%d", &n) != EOF)
    {
        a[1] = 3, a[2] = 9;
        for (int i = 3; i <= n; i++)
            a[i] = 2 * a[i - 1] + a[i - 2];
            
        cout << a[n] << endl;
    }

    return 0;
}