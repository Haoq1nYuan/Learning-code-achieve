#include <iostream>

using namespace std;

const int N = 205;

int n, m;
bool mark[N];
string str;

int main ()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        
        mark[int(ch)] = true;
    }

    cin >> m;

    for (int i = 1; i <= m; i++)
    {
        cin >> str; 

        for (int j = 0; str[j]; j++)
            if (mark[int(str[j])]) 
            {
                int tem = (int)(str[j]);

                while (mark[tem])
                {
                    tem ++;
                    if (str[j] >= 'a' && str[j] <= 'z' && tem == 123) tem = 97;
                    else if (str[j] >= '0' && str[j] <= '9' && tem == 58) tem = 48;
                }

                str[j] = char(str[j] + tem - int(str[j]));
            }

        cout << str << endl;
    }

    return 0;
}