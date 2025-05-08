// https://www.acwing.com/problem/content/868/

#include <iostream>
#include <cmath>

using namespace std;

int n, x;

int main ()
{
    cin >> n;
    while (n--)
    {
        cin >> x;
        
        if (x == 1) 
        {
            cout << "No" << endl; 
            continue;
        }

        bool flag = true;
        for (int i = 2; i <= sqrt(x); i++)
            if (x % i == 0) flag = false;
        
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    
    return 0;
}