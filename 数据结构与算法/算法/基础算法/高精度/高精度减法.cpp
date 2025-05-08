//https://www.acwing.com/problem/content/794/

//只能在 a >= b 的时候计算，如果 a < b，则需要调换参数位置
#include <iostream>
#include <vector>
using namespace std;

vector<int> a, b;
string A, B;
bool flag = true;

bool cmp ( vector<int> &a, vector<int> &b )
{
    if ( a.size() > b.size() ) return true;
    else if ( a.size() == b.size() ) 
    {
        for ( int i = a.size() - 1; i >= 0; i-- )
            if ( a[i] != b[i] ) return a[i] > b[i];
            
        if ( a[0] == b[0] ) return true;
    }
    else return false;
}

vector<int> Minor ( vector<int> &a, vector<int> &b )
{
    vector<int> c;
    
    int t = 0;
    for ( int i = 0; i < a.size(); i++ )
    {
        if ( i < a.size() ) t += a[i];
        if ( i < b.size() ) t -= b[i];
        if ( t >= 0 ) c.push_back(t), t = 0;
        else c.push_back(10+t), t = -1;
    }
    
    //抹去前导0
    while ( c.size() > 1 && c.back() == 0 ) c.pop_back();

    return c;
}

int main ()
{
    cin >> A >> B;
    for ( int i = A.size() - 1; i >= 0; i-- ) a.push_back(A[i]-'0');
    for ( int i = B.size() - 1; i >= 0; i-- ) b.push_back(B[i]-'0');

    if ( cmp(a, b) )
    {
        auto c = Minor(a, b);
        for ( int i = c.size() - 1; i >= 0; i-- ) cout << c[i];
    }
    else 
    {
        auto c = Minor(b, a);
        cout << '-';
        for ( int i = c.size() - 1; i >= 0; i-- ) cout << c[i];
    }
    
    return 0;
}