//https://www.acwing.com/problem/content/779/

#include <iostream>
#include <string>
using namespace std;

string a;
int num;

int main ()
{
    while ( cin >> a, a != "." )
        for ( int i = 1; i <= a.size(); i++ )
        {
            if ( a.size() % i ) continue;  //只讨论能够平分的情况
            
            num = a.size() / i;  //num表示份数

            string b = a.substr(0, i);  //b表示一小份字符串

            for ( int j = 1; j < num; j++ ) b = b + a.substr(0, i); //按照份数累加

            if ( b == a )  //最后判断是否相等
            {
                cout << num << endl;
                break;
            }
        }

    return 0;
}