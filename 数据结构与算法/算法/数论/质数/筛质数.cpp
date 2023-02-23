//https://www.acwing.com/problem/content/870/

//∆”Àÿ…∏∑®
#include <iostream>

using namespace std;
const int N =1000010;

int cnt;
bool st[N];

void get_prime (int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i]) cnt++;
        
        for (int j = i + i; j <= n; j += i) st[j] = true;
    }
}

int main ()
{
    int n;
    cin >> n;
    
    get_prime(n);
    
    cout << cnt;
    
    return 0;
}