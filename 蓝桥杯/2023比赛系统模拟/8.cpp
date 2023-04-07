#include <iostream>

using namespace std;

const int N = 1e8;

int a[2][N];
int n, cnt;
bool flag;

int main ()
{
    cin >> n;

    for (int i = 1; !flag; i++)
    {
        if (i == 4) a[1][3] = 1;
        for (int j = 1; j <= i / 2 + 1; j++)
        {
            if (j == 1 || j == i) a[i % 2][j] = 1;
            else a[i % 2][j] = a[(i - 1) % 2][j] + a[(i - 1) % 2][j - 1];

            if (a[i % 2][j] == n) 
            {
                flag = true;
                cnt += j;
                break;
            }
        }

        if (!flag) cnt += i;
    }

    cout << cnt << endl;

    return 0;
}