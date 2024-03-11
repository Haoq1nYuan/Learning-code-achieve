// https://www.acwing.com/problem/content/description/1071/

// 不带高精度：6/11
#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 60;

int n;
ll f[N][N], w[N];

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    
    memset(f, 0x3f, sizeof f);
    for (int i = 0; i < n; i++) f[i][i + 1] = 0;
    
    for (int len = 3; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            
            for (int k = i + 1; k < j; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j] + w[i] * w[j] * w[k]);
        }
    
    cout << f[1][n] << endl;
    
    return 0;
}

// 结合高精度
#include <iostream>
#include <vector>

using namespace std;

const int N = 60;

int n, k;
vector<int> f[N][N], w[N];

vector<int> add (vector<int> a, vector<int> b)
{
    vector<int> c;
    
    int tem = 0;
    for (int i = 0, j = 0; i < a.size() || j < b.size(); i++, j++)
    {
        if (i < a.size()) tem += a[i];
        if (j < b.size()) tem += b[i];
        
        c.push_back(tem % 10);
        tem /= 10;
    }
    
    if (tem) c.push_back(tem);
    
    return c;
}

vector<int> mul (vector<int> a, vector<int> b)
{
    vector<int> c;
    int t[a.size() + b.size()] = {0};
    
    for (int i = 0; i < b.size(); i++)
    {
        int tem = 0;
        for (int j = 0; j < a.size(); j++)
        {
            tem = a[j] * b[i];
            t[i + j + 1] += (t[i + j] + tem) / 10;
            t[i + j] = (t[i + j] + tem) % 10;
        }
    }
    
    int len = a.size() + b.size() - 1;
    while (!t[len]) len--;
    
    for (int i = 0; i <= len; i++) c.push_back(t[i]);
    
    return c;
}

bool cmp (vector<int> a, vector<int> b)
{
    if (a.size() != b.size()) return a.size() > b.size();
    
    // for (int i = a.size() - 1; i >= 0; i--)  此法错误
    //     if (a[i] > b[i]) return true;
        
    // return false;
    
    int idx = a.size() - 1;
    while (a[idx] == b[idx] && idx) idx--;
    
    return a[idx] > b[idx];
}

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        
        while (k)
        {
            w[i].push_back(k % 10);
            k /= 10;
        }
    }
    
    for (int len = 3; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            
            f[i][j] = vector<int>(N, 1);     // 确保f[i][j]初次更新能够成功
            
            for (int k = i + 1; k < j; k++)
            {
                vector<int> turn = mul(mul(w[i], w[j]), w[k]);
                
                turn = add(add(f[i][k], f[k][j]), turn);
                
                if (cmp(f[i][j], turn)) f[i][j] = turn;
            }
        }
    
    for (int i = f[1][n].size() - 1; i >= 0; i--) cout << f[1][n][i];
    
    return 0;
}

