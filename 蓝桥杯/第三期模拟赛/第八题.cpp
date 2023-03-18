//

#include <iostream>

using namespace std;

const int N = 110;

int l1, r1, l2, r2;
int n, m, t;
int st[N][N];
int k[N][N];
int cnt;

void turn (int a, int b, int c, int d)
{
    k[a][b] += 1;
    k[c + 1][b] -= 1;
    k[a][d + 1] -= 1;
    k[c + 1][d + 1] += 1;
}

int main ()
{
    cin >> n >> m >> t;
    
    while (t--)
    {
        cin >> l1 >> r1 >> l2 >> r2;
        turn(l1, r1, l2, r2);
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            k[i][j] += k[i - 1][j] + k[i][j - 1] - k[i - 1][j - 1];
            if (k[i][j] == 0) cnt++;
        }   

    cout << cnt;

    return 0;
}