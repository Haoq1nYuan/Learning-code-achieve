//https://www.acwing.com/problem/content/description/793/

//自己写的
/* #include <iostream>
using namespace std;
const int N = 100010;

string a, b;
int n[N], m[N], ans[N], La, Lb, k = 1;

int main ()
{
    cin >> a >> b;
    for ( auto &p : a ) n[++La] = p - '0';
    for ( auto &p : b ) m[++Lb] = p - '0';
    
    while ( La && Lb )
    {
        int u = n[La--] + m[Lb--];
        ans[k+1] = (u + ans[k]) / 10;
        ans[k] = (u + ans[k]) % 10;
        k++;
    }
    while ( La ) 
    {
        ans[k+1] = (n[La] + ans[k]) / 10;
        ans[k] = (n[La] + ans[k]) % 10;
        La--, k++;
    }
    while ( Lb ) 
    {
        ans[k+1] = (m[Lb] + ans[k]) / 10;
        ans[k] = (m[Lb] + ans[k]) % 10;
        Lb--, k++;
    }
    
    if (ans[k] == 0) k--;
    for ( int i = k; i; i-- ) cout << ans[i];
    
    return 0;
}
 */

//vector容器
#include <iostream>
#include <vector>
using namespace std;

string A, B;
vector<int> a, b;

vector<int> add ( vector<int> n, vector<int> m )
{
    vector<int> k;
    
    int t = 0;
    for ( int i = 0; i < n.size() || i < m.size(); i++ )
    {
        if ( i < n.size() ) t += n[i];
        if ( i < m.size() ) t += m[i];
        k.push_back(t % 10);
        t /= 10;
    }
    
    if (t) k.push_back(t);
    return k;
}

int main ()
{
    cin >> A >> B;
    for ( int i = A.size() - 1; i >= 0; i-- ) a.push_back(A[i]-'0'); 
    for ( int i = B.size() - 1; i >= 0; i-- ) b.push_back(B[i]-'0');     
    
    auto c = add(a, b);
    
    for ( int i = c.size() - 1; i >= 0; i-- ) cout << c[i];
    
    return 0;
}