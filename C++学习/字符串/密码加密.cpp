/* #include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string k;

int main ()
{
    getline(cin, k);
    
    for ( char &c : k ) 
    {
        if ( ( c >= 'a' && c <= 'y' ) || ( c >= 'A' && c <= 'Y' ) ) c++;
        else if ( c == 'Z' || c == 'z' ) c -= 25;
    }
    
    cout << k;
    
    return 0;
} */

//公式优化
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string k;

int main ()
{
    getline(cin, k);
    
    for ( char &c : k ) 
    {
        if ( c >= 'a' && c <= 'z' ) c = ( c - 'a' + 1 ) % 26 + 'a';
        else if ( c >= 'A' && c <= 'Z' ) c = ( c - 'A' + 1 ) % 26 + 'A';
    }
    
    cout << k;
    
    return 0;
}