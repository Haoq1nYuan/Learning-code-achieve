/* //https://www.acwing.com/problem/content/772/

//整体代换
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string k, a, b;

int main ()
{
    getline(cin, k);
    cin >> a >> b;
    
    int La = a.size(), Lb = b.size(), Lk = k.size();
    
    for ( int i = 0; i + La <= Lk; i++ )
        if ( k.substr(i, La) == a && ( k[i-1] == ' ' || i == 0 ) && ( k[i+La] == ' ' || i+La == k.size() ) ) 
        {
            if ( i + La == k.size() )    //注意substr()函数越界，对于函数的第一个参数，必须小于字符串长度
            {
                k = k.substr(0, i) + b;
                break;
            }
            else 
            {
                k = k.substr(0, i) + b + k.substr(i+La);
                i += La - 1;
            }
        }

    cout << k;
    
    return 0;
}

//将字符串转换为字符串流
#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

string k, a, b;

int main ()
{
    getline(k);
    cin >> a >> b;

    stringstream ssin(k);
    string str;

    while ( ssin >> str )  //详见笔记，每次流出一个不含空格的字符串
    {
        if ( str == a ) cout << b << ' ';
        else cout << str << ' ';
    }

    return 0;
} */

//巧用string函数
#include <iostream> 

using namespace std;

string s1, a, b;

int main()
{
    
    getline(cin, s1);
    cin >> a >> b;

    s1 = ' ' + s1 + ' ';    // 把单词和语句前后都加上空格 便于查找
    a = ' ' + a + ' ';
    b = ' ' + b + ' ';

    while(s1.find(a) != -1)  // 一直查找 找到就替换
        s1.replace(s1.find(a), a.size(), b);

    s1.erase(s1.begin());    // s1.erase(0, 1);
    s1.erase(s1.end() - 1);  // 别忘了把加进去的首尾空格都删除

    cout << s1;

    return 0;
}