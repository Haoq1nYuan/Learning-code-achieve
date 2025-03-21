//https://www.acwing.com/problem/content/777/

//反转函数
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

string k, str;
int t;

int main ()
{
    getline(cin, k);
    
    reverse(k.begin(), k.end());
    
    stringstream ss(k);
    
    while ( ss >> str )
    {
        reverse(str.begin(), str.end());
        cout << str << " ";
    }
    
    return 0;
}

//偷懒写法
#include <iostream>
using namespace std;

int main ()
{
    string str, output;

    while (cin >> str)
        output = str + ' ' + output;

    cout << output;

    return 0;
}

//string字符串数组
#include <iostream>
using namespace std;

string str[10000];
int n;

int main ()
{   
    while ( cin >> str[n] ) n++;

    for ( int i = n - 1; i >= 0; i-- ) cout << str[n] << " ";

    return 0;
}