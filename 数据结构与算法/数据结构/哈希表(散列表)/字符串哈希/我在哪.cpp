//https://www.acwing.com/problem/content/description/1462/

//ÎÒÐ´µÄ
#include <iostream>
#include <unordered_map>

using namespace std;

typedef unsigned long long ull;

const int N = 110, P = 131;

int n;
string a;

ull h[N], p[N];

bool check (int k)
{
    unordered_map<ull, int> cnt;
    for (int i = 1; i + k - 1 <= n; i++)
        for (int j = i + k - 1; j <= n; j++)
        {
            ull num = h[j] - h[i - 1] * p[j - i + 1];
            cnt[num]++;
            if (cnt[num] > 1) return false;
        }
    return true;
}

int main ()
{
    cin >> n >> a;
    
    a = ' ' + a;
    p[0] = 1;
    
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + a[i];
    }
    
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    
    cout << l << endl;
    
    return 0;
}

//y×Ü
#include <iostream>
#include <unordered_set>

using namespace std;

int n;
string str;
unordered_set<string> S;

bool check(int mid)
{
    S.clear();
    for (int i = 0; i + mid - 1 < n; i ++ )
    {
        string s = str.substr(i, mid);
        if (S.count(s)) return false;
        S.insert(s);
    }

    return true;
}

int main()
{
    cin >> n >> str;

    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << r << endl;

    return 0;
}
