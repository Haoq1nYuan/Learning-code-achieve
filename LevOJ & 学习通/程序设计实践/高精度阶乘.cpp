#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 100010;

int n;
int t[N];

int main ()
{
    while (scanf("%d", &n) != EOF)
    {
        vector<int> c;
        c.push_back(1);

        for (int i = 1; i <= n; i++)
        {
            vector<int> b;
            int k = i;
            while (k)
            {
                b.push_back(k % 10);
                k /= 10;
            }

            memset(t, 0, sizeof(t));
            for (int i = 0; i < b.size(); i++)
            {
                int tem = 0;
                for (int j = 0; j < c.size(); j++) 
                {
                    tem = b[i] * c[j];
                    t[i + j + 1] += (tem + t[i + j]) / 10;
                    t[i + j] = (tem + t[i + j]) % 10;
                }
            }

            int length = c.size() + b.size() - 1;
            while (length && t[length] == 0) length--;

            c.clear();
            for (int i = 0; i <= length; i++) c.push_back(t[i]);
        }

        for (int i = c.size() - 1; i >= 0; i--) cout << c[i];
        puts("");
    }

    return 0;
}