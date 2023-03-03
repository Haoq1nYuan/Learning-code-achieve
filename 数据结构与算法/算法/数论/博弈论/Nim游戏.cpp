//https://www.acwing.com/problem/content/893/

#include <iostream>

using namespace std;
const int N = 100010;

int c[N], res;

int main ()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &c[i]);
        res ^= c[i];
    }
    
    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}