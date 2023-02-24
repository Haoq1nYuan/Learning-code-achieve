//https://www.acwing.com/problem/content/871/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;
const int N = 100;

int cnt[N], k;

void yue (int a)
{
    vector<int> k;
    int len = sqrt(a);
    for (int i = 1; i <= len; i++)
    {
        if (a % i == 0 && i * i == a) k.push_back(i);
        else if (a % i == 0) 
        {
            k.push_back(i);
            k.push_back(a / i);
        }
    }
        
    sort(k.begin(), k.end());
    
    for (int i = 0; i < k.size(); i++) cout << k[i] << ' ';
    puts("");
}

int main ()
{
    int n;
    cin >> n;
    
    while (n--)
    {
        memset(cnt, 0, sizeof(cnt));
        k = 0;
        int a;
        cin >> a;
        yue(a);
    }
    
    return 0;
}