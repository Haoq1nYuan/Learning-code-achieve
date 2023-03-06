//https://www.acwing.com/problem/content/3771/

#include <iostream>

using namespace std;

int n, ans;
string a;

int main ()
{
    cin >> n >> a;
    
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 'x') continue;
        
        int j = i + 1;
        while (a[j] == 'x') j++;
        
        if (j - 1 - i >= 2) ans += j - i - 2;
        
        i = j - 1;
    }
    
    cout << ans << endl;
    
    return 0;
}