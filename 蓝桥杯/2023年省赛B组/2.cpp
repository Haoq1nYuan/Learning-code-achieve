/* #include <iostream>
#include <cmath>

using namespace std;

int len = 23333333;
int i, j;  // i -> 1; j -> 0;
double ans, k0, k1;

int main ()
{
    for (int i = 11666667; i <= len; i++)    
    {
        j = len - i;

        k1 = (double)i / len * log2((double)len / i);
        k0 = (double)j / len * log2((double)len / j);

        ans = i * k1 + j * k0;

        if (ans - 11625907.5798 < 1e-7) 
        {
            cout << j << endl;
            break;
        }
    }

    return 0;
}
 */
#include <iostream>
#include <cmath>

using namespace std;

int len = 23333333;

int main ()
{
    double j = 11027420;
    double i = len - j;

    double k0 = j / len * log2(len / j);
    double k1 = i / len * log2(len / i);

    double ans = k0 * j + k1 * i;

    cout << (double)(ans - 11625907.5798) << endl;

    return 0;
}

