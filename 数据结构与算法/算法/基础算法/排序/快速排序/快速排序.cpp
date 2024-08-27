//https://www.acwing.com/problem/content/787/

#include <iostream>
using namespace std;

const int N = 100010;

int n, q[N], l, r;

void quick_sort ( int *q, int l, int r )
{
    if ( l >= r ) return;
    
    int x = q[(l + r) / 2], i = l - 1, j = r + 1;
    while ( i < j )
    {
        do i ++; while ( q[i] < x );
        do j --; while ( q[j] > x );
        if ( i < j ) swap(q[i], q[j]);
    }
    
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main ()
{
    scanf( "%d", &n );
    //q数组从1开始存储
    for ( int i = 1; i <= n; i++ ) scanf( "%d", q+i );
    
    quick_sort(q, 1, n);
    
    for ( int i = 1; i <= n; i++ ) printf( "%d ", *(q+i) );
    
    return 0;
}