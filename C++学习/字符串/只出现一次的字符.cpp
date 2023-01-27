#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

string k;
int count[30];

int main ()
{
    cin >> k;
    
    int len = k.size();
    
    for ( int i = 0; i < len; i++ ) count[k[i] - 'a']++;
    
    for ( int i = 0; i < len; i++ )
        if ( count[k[i] - 'a'] == 1 ) 
        {
            cout << k[i] << endl;
            return 0;
        }
        
    cout << "no" << endl;
    
    return 0;
}