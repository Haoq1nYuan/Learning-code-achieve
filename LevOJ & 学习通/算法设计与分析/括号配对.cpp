#include <iostream>
#include <cstring>

using namespace std;

const int N = 85;

int n;
string str;

char stack[N], idx = -1;

int main ()
{
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            bool flag = false;
            idx = -1;
            memset (stack, 0, sizeof stack);

            if (i == 1) getchar();
            getline(cin, str);

            for (int i = 0; str[i]; i++)
                if (str[i] == '(' || str[i] == '{') stack[++idx] = str[i];
                else if (str[i] == '}')
                {
                    if (stack[idx] == '{') idx--;
                    else 
                    {
                        flag = true;
                        break;
                    }
                } 
                else if (str[i] == ')')
                {
                    if (stack[idx] == '(') idx--;
                    else 
                    {
                        flag = true;
                        break;
                    }
                }

            if (!flag && idx == -1) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}