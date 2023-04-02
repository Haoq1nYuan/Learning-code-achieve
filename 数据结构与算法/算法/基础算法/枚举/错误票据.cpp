//https://www.acwing.com/problem/content/1206/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <sstream>

using namespace std;

const int N = 100010;

int n, a[N], k;
string str;

int main ()
{
    cin >> n;
    getchar();
    
    while (n--) 
    {
        getline(cin, str);
        stringstream tem(str);
        
        while (tem >> a[++k]);
        k--;
    }

    sort(a + 1, a + k + 1);
    
    int b, c;
    for (int i = 2; i <= k; i++)
    {
        if (a[i] == a[i - 1]) b = a[i];
        else if (a[i] == a[i - 1] + 2) c = a[i] - 1;
    }
    
    cout << c << ' ' << b << endl;
    
    return 0;
}