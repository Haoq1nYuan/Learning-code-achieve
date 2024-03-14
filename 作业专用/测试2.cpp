#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int m[] = {0, 3, -3, 1, -1};

int main ()
{
    string k = "234158x76";

    int idx = k.find('x');

    cout << k << endl;

    for (int i = 1; i <= 4; i++)
    {
        if (idx + m[i] < 0 || idx + m[i] >= 9 || (idx == 3 || idx == 6 && m[i] == -1) || (idx == 2 || idx == 5 && m[i] == 1)) continue;

        string tem = k;
        swap(tem[idx], tem[idx + m[i]]);
        cout << tem << endl;
    }

    return 0;
}