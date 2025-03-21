#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int Mod = 1337;

int a;
string b;

int qmi (int a, int b)
{   
    int res = 1;
    a %= Mod;
    while (b)
    {
        if (b & 1) res = (ll)res * a % Mod;
        a = (ll)a * a % Mod;
        b >>= 1;
    }

    return res;
}

int main ()
{
    while (scanf("%d", &a) != EOF)
    {
        cin >> b;
        vector<int> p;
        for (auto k : b) p.push_back(k - '0');

        int ans = 1, len = p.size();
        for (int i = len - 1; i >= 0; i--)
        {
            ans = (ll)ans * qmi(a, p[i]) % Mod;
            a = qmi(a, 10);
        }

        cout << ans << endl;
    }

    return 0;
}