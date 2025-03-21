//繁琐写法
/* #include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string a, b;

int main ()
{
    getline(cin, a);
    getline(cin, b);
    
    for ( int i = 0; a[i] != '\0' || b[i] != '\0'; i++ )
    {
        if ( a[i] == b[i] ) continue;
        else if ( a[i] > b[i] )
        {
            if ( a[i] >= 'a' && a[i] <= 'z' ) 
            {
                if ( a[i] > b[i] + 32 )
                {
                    cout << ">";
                    return 0;
                }
                else if ( a[i] < b[i] + 32)
                {
                    cout << "<";
                    return 0;
                }
            }
            else 
            {
                cout << ">";
                return 0;
            }
        }
        else
        {
            if( b[i] >= 'a' && b[i] <= 'z' )
            {
                if ( b[i] > a[i] + 32 )
                {
                    cout << "<";
                    return 0;
                }
                else if ( b[i] < a[i] + 32 )
                {
                    cout << ">";
                    return 0;
                }
            }
            else 
            {
                cout << "<";
                return 0;
            }
        }
    }
    
    if ( a.size() == b.size() ) cout << "=";
    else if ( a.size() > b.size() ) cout << ">";
    else cout << "<";
    
    return 0;
} */

//先转换再判断
#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
using namespace std;

string a, b;

int main ()
{
    getline(cin, a);
    getline(cin, b);

    for ( int i = 0; i < a.size(); i++ ) if ( a[i] >= 'a' && a[i] <= 'z' ) a[i] = toupper(a[i]);
    for ( int i = 0; i < b.size(); i++ ) if ( b[i] >= 'a' && b[i] <= 'z' ) b[i] = toupper(b[i]);

    if ( a == b ) cout << "=";
    else if ( a < b ) cout << "<";
    else cout << ">";

    return 0;
}