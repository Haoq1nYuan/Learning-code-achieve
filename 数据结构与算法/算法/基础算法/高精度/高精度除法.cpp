//https://www.acwing.com/problem/content/796/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100010;

vector<int> a;

vector<int> Divition (vector<int> a, int b, int &r)
{
    vector<int> c;

    //这里采用逐位计算的方式，与正常除法思维不同
    r = 0;
    for ( int i = a.size() - 1; i >= 0; i-- ) 
    {
        r = r*10 + a[i];
        c.push_back(r / b);
        r %= b;
    }

    reverse(c.begin(), c.end());

    //注意删去前导零
    for ( int i = c.size() - 1; i > 0; i-- ) 
    {
        if ( c[i] == 0 ) c.pop_back();
        else break;
    }

    return c; 
}

int main ()
{
    string A;
    int b;
    cin >> A >> b;

    for ( int i = A.size() - 1; i >= 0; i-- ) a.push_back(A[i] - '0');

    int r;
    auto c = Divition(a, b, r);

    for ( int i = c.size() - 1; i >= 0; i-- ) cout << c[i];
    cout << endl << r << endl;

    return 0;
}