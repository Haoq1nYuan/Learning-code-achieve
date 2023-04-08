#include <iostream>
#include <cstring>

using namespace std;

int c[40] = {1, 6, 3, 4, 6, 7, 0, 7, 8, 2, 7, 6, 8, 9, 5, 6, 5, 6, 1, 4, 0, 1,
0, 0, 9, 4, 8, 0, 9, 1, 2, 8, 5, 0, 2, 5, 3, 3};
int day[13] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int ans;
bool st[40];

void check (int p, int mon)
{
    for (int i = p; i < 37; i++)
        for (int j = i + 1; j < 38; j++) 
        {
            if (c[i] == 0 && !st[c[j]]) ans++, st[c[j]] = true;
            if (c[i] == 1 && !st[10 + c[j]]) ans++, st[10 + c[j]] = true;
            if (c[i] == 2 && !st[20 + c[j]] && 20 + c[j] <= day[mon]) ans++, st[20 + c[j]] = true;
            if (c[i] == 3 && !st[30 + c[j]] && 30 + c[j] <= day[mon]) ans++, st[30 + c[j]] = true; 
        }
}

int main ()
{
    for (int i = 1; i <= 9; i++)
    {
        memset(st, 0, sizeof(st));
        for (int k = 0; k < 37; k++)
            if (c[k] == 0)
                for (int j = k + 1; j < 38; j++)
                    if (c[j] == i) check(j + 1, i);
    }

    for (int i = 10; i <= 12; i++)
    {
        memset(st, 0, sizeof(st)); 
        for (int k = 0; k < 37; k++)
            if (c[k] == 1)
                for (int j = k + 1; j < 38; j++)
                    if (c[j] == i % 10) check(j + 1, i);
    }

    cout << ans << endl;

    return 0;
}