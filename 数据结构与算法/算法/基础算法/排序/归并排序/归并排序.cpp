//https://www.acwing.com/problem/content/789/

#include <iostream>
using namespace std;

const int N = 100010;

int n, q[N], ans[N];

void merge_sort ( int *q, int l, int r )
{
    if ( l >= r ) return;
    
    int mid = (l + r) / 2;
    
    merge_sort(q, mid+1, r);
    merge_sort(q, l, mid);
    
    int k = 0, i = l, j = mid + 1;
    while ( i <= mid && j <= r )
    {
        if ( q[i] < q[j] ) ans[++k] = q[i++];
        else ans[++k] = q[j++];
    }
    
    while ( i <= mid ) ans[++k] = q[i++];
    while ( j <= r ) ans[++k] = q[j++];
    
    for ( int i = l, j = 1; j <= k; j++, i++ ) q[i] = ans[j]; 
}

int main ()
{
    cin >> n;
    for ( int i = 1; i <= n; i++ ) cin >> q[i];
    
    merge_sort(q, 1, n);
    
    for ( int i = 1; i <= n; i++ ) cout << q[i] << ' ';
    
    return 0;
}