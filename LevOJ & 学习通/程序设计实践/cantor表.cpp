#include <iostream>

using namespace std;

int n, dx[] = {1, -1}, dy[] = {-1, 1};

int main ()
{
    while (scanf("%d", &n) != EOF)
    {
        int x = 1, y = 1, p = 1;    
        bool flag = false;

        for (int i = 1; i < n; i++)
        {
            if (flag) 
            {
                x += dx[p], y += dy[p];
                flag = false;
            }
            else if (x == 1) 
            {
                y++;
                p = (p + 1) % 2;
                flag = true;
            }
            else if (y == 1) 
            {
                x++;
                p = (p + 1) % 2;
                flag = true;
            }
            else 
            {
                x += dx[p];
                y += dy[p];
            }
        }

        cout << x << '/' << y << endl;
    }

    return 0;
}