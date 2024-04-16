#include <iostream>
#include <cmath>

using namespace std;

int n;
char ans[200][200];

void get (int x, int y, int u)
{
    if (u == 1)
    {
        ans[x][y] = 'X';
        return;
    }

    int tem = pow(3, u - 2);

    get(x, y, u - 1);
    get(x, y + 2 * tem, u - 1);
    get(x + tem, y + tem, u - 1);
    get(x + 2 * tem, y, u - 1);
    get(x + 2 * tem, y + 2 * tem, u - 1);
}

int main ()
{
    while (cin >> n)
    {
        for (int i = 0; i < pow(3, n - 1); i++)
            for (int j = 0; j < pow(3, n - 1); j++)
                ans[i][j] = ' ';

        get(0, 0, n);

        for (int i = 0; i < pow(3, n - 1); i++)
        {
            for (int j = 0; j < pow(3, n - 1); j++) 
                cout << ans[i][j];
            cout << endl;
        }
        
        cout << '-' << endl;
    }

    return 0;
}