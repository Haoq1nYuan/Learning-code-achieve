#include <iostream>
#define MAXLEN 100

using namespace std;

typedef struct
{
    char ch[MAXLEN];
    int length;
}sstring;

int var[MAXLEN];
int k;

void Index (sstring a, sstring b)
{
    int i = 0, j = 0;

    while (i < a.length)
        if (a.ch[i] == b.ch[j])
        {
            if (j == b.length - 1) 
            {
                var[++k] = i - b.length + 1;
                j = 0;
                i = var[k] + 1;
            }
            else 
            {
                j ++;
                i ++;
            }
        }
        else
        {
            i -= j - 1;
            j = 0;
        }
}

int main ()
{
    sstring a = {"ababcabcacbab", 13};
    sstring b = {"abc", 3};

    Index(a, b);

    for (int i = 1; i <= k; i++)
        cout << var[i] << ' '; 

    return 0;
}