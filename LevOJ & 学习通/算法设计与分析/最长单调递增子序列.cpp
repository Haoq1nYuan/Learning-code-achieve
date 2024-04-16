#include <iostream>
#include <cstring>

using namespace std;

const int N = 10005;

int n;
string str;
int x[N], idx, f[N];

int main ()
{
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> str;

            int ans = 0;

            idx = 1;
            for (auto ch : str) x[idx++] = int(ch - 'a');
            idx --;

            memset(f, 0, sizeof f);
            
            for (int i = 1; i <= idx; i++)
            {
                f[i] = 1;

                for (int j = 1; j < i; j++) 
                    if (x[j] < x[i]) f[i] = max(f[i], f[j] + 1);

                ans = max(ans, f[i]);
            }

            cout << ans << endl;
        }
    }
    
    return 0;
}