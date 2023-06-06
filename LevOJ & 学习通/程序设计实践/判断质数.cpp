#include <iostream>

using namespace std;

int n;

int main ()
{
    while (scanf("%d", &n) != EOF)
    {
        bool flag = false;
        for (int i = 2; i < n; i++)
            if (n % i == 0) 
            {
                cout << "No" << endl;
                flag = true;
                break;
            }

        if (!flag) cout << "Yes" << endl;
    }

    return 0;
}