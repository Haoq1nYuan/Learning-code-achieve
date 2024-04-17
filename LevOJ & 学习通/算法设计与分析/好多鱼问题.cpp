#include <iostream>
#include <vector>

using namespace std;

const int N = 1005;

int up, down, n, s[N], ans;

int main ()
{
    cin >> down >> up >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];

    for (int i = down; i <= up; i++)
        for (int j = 1; j <= n; j++)
            if ((i >= 2 * s[j] && i <= 10 * s[j]) || (s[j] >= 2 * i && s[j] <= 10 * i))
         // if ((i / s[j] >= 2 && i / s[j] <= 10) || (s[j] / i >= 2 && s[j] / i <= 10))  除法下取整，会将10.x取为10
            {
                ans ++;
                break;
            }

    cout << up - down + 1 - ans << endl;

    return 0;
}