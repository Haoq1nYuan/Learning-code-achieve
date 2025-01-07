//https://www.acwing.com/problem/content/description/775/

//用substr()函数
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

string a, b;

int main ()
{
    while ( cin >> a >> b )
    {
        int Max = 0;
        
        for ( int i = 1, len = a.size(); i < len; i++ )
            if ( a[Max] < a[i] ) Max = i;
            
        cout << a.substr(0, Max+1) + b + a.substr(Max+1) << endl;
    }
    
    return 0;
}

//用insert()函数
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

string a, b;

int main ()
{
    while ( cin >> a >> b )
    {
        int Max = 0;
        
        for ( int i = 1, len = a.size(); i < len; i++ )
            if ( a[Max] < a[i] ) Max = i;
            
        a.insert(Max+1, b);

        cout << a << endl;
    }
    
    return 0;
}