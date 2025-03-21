//https://www.acwing.com/problem/content/description/768/

//整行读入
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string k;

int main ()
{
    getline(cin, k);
    
    for ( int i = 0; k[i] != '\0'; i++ )
        if ( k[i] == ' ' )
        {
            int j;
            for ( j = i+1; k[j] == ' '; j++ );
            k = k.substr(0, i+1) + k.substr(j);
        }
    
    cout << k;
    
    return 0;
}

//单个读入
#include <iostream>
using namespace std;

string s;

int main ()
{
    while ( cin >> s ) cout << s << " ";

    return 0;
}