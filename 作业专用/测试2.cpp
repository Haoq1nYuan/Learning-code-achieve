#include <iostream>
#include <vector>
using namespace std;
const int N = 100010;

string A, B;
int n[N], m[N], ans[N], k;
vector<int> a, b;

int main ()
{
    int pre[11][11] = {0};
    int i = 6, k = 2;
    for ( int j = i - 1; j >= 1 && k + i - j <= 6; j-- ) pre[k + i - j][j] = 1;

    for ( int i = 1; i <= 6 ; i++ )
    {
        for ( int j = 1; j <= 6; j++ ) cout << pre[i][j] << ' ';
        cout << endl;
    }
    
    return 0;
}