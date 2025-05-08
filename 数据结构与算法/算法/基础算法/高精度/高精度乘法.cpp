//https://www.acwing.com/problem/content/795/

#include <iostream>
#include <vector>
using namespace std;
const int N = 100010;

vector<int> a, b;
string A, B;

vector<int> Plus ( vector<int> &a, vector<int> &b )
{
    vector<int> c;
    
    int t[N];
    for ( int i = 0; i < b.size(); i++ )
    {
        int tem = 0;
        for ( int j = 0; j < a.size(); j++ )
        {
            tem = a[j]*b[i];
            t[j+i+1] += ( t[i+j] + tem ) / 10;
            t[j+i] = ( t[i+j] + tem ) % 10;
        }
    }
    
    int length = b.size() + a.size() - 1;
    
    while ( length && t[length] == 0 ) length--;  // 去除前导零，如 131 * 0 = 000
    
    for ( int i = 0; i <= length; i++ ) c.push_back(t[i]);
    
    return c;
}

int main ()
{
    cin >> A >> B;
    
    for ( int i = A.size() - 1; i >= 0; i-- ) a.push_back(A[i]-'0');
    for ( int i = B.size() - 1; i >= 0; i-- ) b.push_back(B[i]-'0');
    
    auto c = Plus(a, b);
    
    for ( int i = c.size() - 1; i >= 0; i-- ) cout << c[i];
    
    return 0;
}