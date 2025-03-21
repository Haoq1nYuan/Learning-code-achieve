//https://www.acwing.com/problem/content/780/

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

string k[5];
stringstream ss;
int n, head, tail;

int main ()
{
    getline(cin, k[4]);

    ss << k[4];

    while ( getline(ss, k[n], ',') ) n++;

    if ( k[0].find(k[1]) == -1 || k[0].find(k[2]) == -1 ) 
    {
        cout << "-1";
        return 0;
    }
    else 
    {
        head = k[0].find(k[1]) + k[1].size() - 1;
        
        reverse(k[0].begin(), k[0].end());
        reverse(k[2].begin(), k[2].end());
        
        tail = k[0].size() - k[0].find(k[2]) - 1 - k[2].size();
        
        if ( head >= tail + 1 ) 
        {
            cout << "-1";
            return 0;
        }

        cout << tail - head;
    }

    return 0;
}