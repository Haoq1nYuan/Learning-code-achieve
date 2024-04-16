#include <iostream>

using namespace std;

int n, cnt = 0;

bool check (int x)
{
    int k = 1;
    while (x)
    {
        int tem = (x % 10);

        if (tem % 2 != k % 2) return false;

        x /= 10;

        k++;
    }

    return true;
}

int main ()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        if (check(i))
        {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}