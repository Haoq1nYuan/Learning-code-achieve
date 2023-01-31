//https://www.acwing.com/problem/content/841/

#include <iostream>
using namespace std;

const int N = 100010;

int n, h[N], Count;

//ph数组存储第k个插入到数在哪个节点上，即下标
//hp数组存储ph数组的下标，表示第k个插入的数的在数组ph中对应的下标
//即 ph[k] = j 且 hp[j] = k;
//ph -> position in tree; hp -> tree's elements' position in ph
int ph[N], hp[N], num;

string a;
int x, k;

void heap_swap ( int a, int b )
{
    //树里的节点和ph数组元素是双向指向的关系，首先ph[k]指向第k个插入的数在树中的节点(假设是j)，即ph[k] = j。
    //其次树中的j节点也指向ph[k]在ph数组中的位置，且每个树节点都会有个指向，
    //所以我们将每个树节点和ph数组元素的指向关系用另一个hp数组存储，即hp[j] = k，类似于双链表的结构
    
    //先将ph数组的指针互换
    swap(ph[hp[a]], ph[hp[b]]);
    //ph指针互换后，hp数组的指向还没有改变，所以也需要交换一下hp数组的指向
    swap(hp[a], hp[b]);
    //最后交换树中元素值
    swap(h[a], h[b]);

    //上面三种操作可以互换位置，但是为了方便理解，我们直接写成这种形式：先换指针，再换元素值
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
            //此处需要存储一下ph[k]原本的值，因为在经过heap_swap操作后ph[k]，
            //下标还是k但是它的值会改变
            k = ph[k];
            heap_swap(k, Count);
            Count--;
            up(k);
            down(k);
        }
        else
        {   
            cin >> k >> x;
            //此处同理
            k = ph[k];
            h[k] = x;
            up(k);
            down(k);
        }
    }

    return 0;
}