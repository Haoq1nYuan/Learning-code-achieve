#include <iostream>
#include <cstring>

using namespace std;

const int N = 500010;

int k;
string a;
char b, e;
int ne[N], last;
int cnt, ans;

void check (int p)
{
    for (int i = p; i < cnt; i++)
        if (a[i] == e) 
        {
            ans++;
            while (ne[i] != 0)
            {
                i = ne[i];
                ans++;
            }
            break;
        }
}

int main ()
{
    cin >> k >> a >> b >> e;

    for (char p : a)
    {
        if (p == e) 
        {
            if (last != 0) ne[last] = cnt;
            last = cnt;
        }
        cnt++;
    }

    for (int i = 0; i < cnt - k + 1; i++)
        if (a[i] == b) check(i + k - 1);
    
    cout << ans << endl;

    return 0;
}