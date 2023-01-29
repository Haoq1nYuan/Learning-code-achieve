//https://www.acwing.com/problem/content/841/

#include <iostream>
using namespace std;

const int N = 100010;

int n, h[N], Count;

//ph数组存储第k个插入到数在哪个节点上，即下标
//hp数组存储ph数组的下标，表示第k个插入的数的在数组ph中对应的下标
//即 ph[k] = j 且 hp[j] = k;
int ph[N], hp[N], num;

string a;
int x, k;

void heap_swap ( int a, int b )
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down ( int u )
{
    int t = u;
    if ( u*2 <= Count && h[u*2] < h[u] ) t = u*2;
    if ( u*2 + 1 <= Count && h[u*2+1] < h[t] ) t = u*2 + 1;
    if ( t != u )
    {
        heap_swap(t, u);
        down(t);
    }
}

void up ( int u )
{
    while ( u > 1 && h[u/2] > h[u] )
    {
        heap_swap(u/2, u);
        u /= 2;
    }
}

int main ()
{
    cin >> n;

    while ( n-- )
    {
        cin >> a;
        if ( a[0] == 'I' )
        {
            cin >> x;
            h[++Count] = x;
            ph[++num] = Count, hp[Count] = num;
            up(Count);
        }
        else if ( a[0] == 'P' )
        {
            cout << h[1] << endl;
        }
        else if ( a == "DM" )
        {
            heap_swap(1, Count);
            Count--;
            down(1);
        }
        else if ( a[0] == 'D' )
        {
            cin >> k;
            k = ph[k];
            heap_swap(k, Count);
            Count--;
            up(k);
            down(k);
        }
        else
        {   
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            up(k);
            down(k);
        }
    }

    return 0;
}