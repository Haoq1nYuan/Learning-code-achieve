//https://www.acwing.com/problem/content/776/

//朴素写法
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string k, l;
int Max, count;

int main ()
{
    getline(cin, k);
    
    for ( int i = 0; i < k.size(); i++ )
    {
        int j = i;
        while ( k[j] != ' ' && j < k.size() - 1 ) 
            count++, j++;
        
        if ( count > Max ) 
        {
            Max = count;
            l = k.substr(i, count);   //注意此处参数为(起始下标, 截取长度)
        }
        
        count = 0;
        i = j;
    }
    
    cout << l;
    
    return 0;
}

//偷懒写法
#include <iostream>
#include <string>
using namespace std;

string a, b;
int len;

int main ()
{
    while ( cin >> a )
    {
        //if ( a[a.size()-1] == '.' ) a.erase(a.size()-1, 1);
        if ( a.back() == '.' ) a.pop_back();
        
        if ( a.size() > len ) len = a.size(), b = a;
    }

    cout << b;

    return 0;
}