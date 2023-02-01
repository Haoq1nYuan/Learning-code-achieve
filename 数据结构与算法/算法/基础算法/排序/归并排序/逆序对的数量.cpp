//https://www.acwing.com/problem/content/790/

#include <iostream>
using namespace std;
const int N = 100010;

int n, q[N], ans[N];

long long merge_sort ( int *q, int l, int r ) 
{
    if ( l >= r ) return 0;
    
    int mid = (l + r) / 2;
    long long res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
    
    int k = 0, i = l, j = mid + 1;
    while ( i <= mid && j <= r )
        if ( q[i] <= q[j] ) ans[++k] = q[i++];
        else 
        {
            ans[++k] = q[j++];
            //多了一个维护操作，维护一个res
            res += mid - i + 1;
        }
    while ( i <= mid ) ans[++k] = q[i++];
    while ( j <= r ) ans[++k] = q[j++];
    
    for ( int i = l, j = 1; j <= k; j++, i++ ) q[i] = ans[j];
    
    return res;
}

int main ()
{
    cin >> n;
    for ( int i = 1; i <= n; i++ ) cin >> q[i];
    
    cout << merge_sort(q, 1, n);
    
    return 0;
}