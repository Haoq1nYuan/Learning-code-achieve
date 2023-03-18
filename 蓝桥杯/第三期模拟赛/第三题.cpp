#include <iostream>

using namespace std;

int cnt;
int mon[] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main ()
{
    for (int i = 1900; i <= 9999; i++)
    {
        if ((i % 400 == 0) || (i % 100 && i % 4 == 0)) mon[2] = 29;
        else mon[2] = 28;

        int si = 0, tem = i;
        while (tem)
        {
            si += tem % 10;
            tem /= 10;
        }

        for (int m = 1; m <= 12; m++)
        {
            int sm = mon[m] % 10 + mon[m] / 10;

            int sd = si - sm;
            for (int j = 1; j <= mon[m]; j++)
                if (j % 10 + j / 10 == sd) cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}