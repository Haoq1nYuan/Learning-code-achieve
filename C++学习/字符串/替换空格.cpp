//https://www.acwing.com/problem/content/17/

//±éÀú
#include <iostream>
#include <string>
using namespace std;

string k;

string replaceSpaces (string &str) {
    string ans;
    
    for ( int i = 0; i < str.size(); i++ )
    {
        if ( str[i] == ' ' && i == 0 ) 
        {
            ans = "%20";
            continue;
        }
        if ( str[i] == ' ' && ans[i-1] != ' ' ) ans += "%20";
        else if ( str[i] != ' ' ) ans += str[i];  
    }
    
    return ans;
}

int main ()
{
    getline(cin, k);

    cout << replaceSpaces(k) << endl;

    return 0;
}

//autoÌæ»»
#include <iostream>
#include <string>
using namespace std;

string k;

string replaceSpaces (string &str) {
    string ans;

    for ( auto x : str )
        if ( x == ' ' ) ans += "%20";
        else ans += x;
    
    return ans;
}

int main ()
{
    getline(cin, k);

    cout << replaceSpaces(k) << endl;

    return 0;
}
