#include <iostream>
#include <cstring>

using namespace std;

const int N = 1000010;

int n;
bool st[N];

void set (int begin, int len)
{
    while (begin <= n)
    {
        st[begin] ^= 1;
        begin += len + 1;
    }
}

int main ()
{   
    while (cin >> n)
    {   
        memset(st, 1, sizeof(st));
        for (int i = 2; i <= n; i++) set(i, i - 1);
        
        for (int i = 1; i <= n; i++) if (st[i]) cout << i << ' ';
        puts("");
    }

    return 0;
}