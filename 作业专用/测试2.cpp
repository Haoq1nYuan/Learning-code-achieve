#include <iostream>
#include <vector>
using namespace std;
const int N = 100010;

string A, B;
int n[N], m[N], ans[N], k;
vector<int> a, b;

int main ()
{
    cin >> A >> B;
    
    for ( int i = A.size() - 1; i >= 0; i-- ) a.push_back(A[i]-'0');
    for ( int i = B.size() - 1; i >= 0; i-- ) b.push_back(B[i]-'0');
    
    for ( int i = a.size() - 1; i >= 0; i-- ) cout << a[i];

    return 0;
}