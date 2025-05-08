//https://www.acwing.com/problem/content/872/

//先枚举每个数的质因子分解情况，存到哈希表中
//在套用公式求即可
#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int n;

int main ()
{
    cin >> n;
    
    unordered_map<int, int> prime;
    
    while (n--)
    {
        int x;
        cin >> x;
        //求当前这个数的质因子分解情况
        for (int i = 2; i <= x / i; i++)
        {
            while (x % i == 0)
            {
                x /= i;
                prime[i]++;
            }
        }
        //不要忘了大于sqrt(n)的质因子
        if (x > 1) prime[x]++;
    }
    
    ll res = 1;
    for (auto k : prime) res = res * (k.second + 1) % mod; 
    
    cout << res;
    
    return 0;
}