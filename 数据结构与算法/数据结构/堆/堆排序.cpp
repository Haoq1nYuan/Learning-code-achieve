//https://www.acwing.com/problem/content/840/

//ST大法
/* #include <iostream>
#include <set>
using namespace std;

int n, m, x;
multiset<int> a;

int main ()
{
    cin >> n >> m;
    for ( int i = 0; i < n; i++ )
    {
        cin >> x;
        a.insert(x);
    }
    
    multiset<int>::iterator it = a.begin();
    
    for ( int i = 0; i < m; i++ )
        cout << *it++ << ' ';
    
    return 0;
} */

//模拟堆
#include <iostream>

using namespace std;

const int N = 100010;
typedef long long ll;

int n, m, h[N], Size;

void down ( int kk )
{
    int tem = kk;
    //判断左儿子是否存在和大小关系
    if ( kk * 2 <= Size && h[kk*2] < h[tem] ) tem = kk * 2;
    //判断右儿子是否存在和大小关系
    if ( kk * 2 + 1 <= Size && h[kk*2+1] < h[tem] ) tem = kk * 2 + 1;
    //如果说tem!=kk，则说明子节点有更小的值，
    //我们需要交换父节点和该子节点的值，并将该子节点的下标继续做down操作
    if ( kk != tem )
    {
        swap(h[tem], h[kk]);
        down(tem);
    }
    //当该值下降到不能再下降时，kk必定等于tem，自然就跳出函数了
}

int main ()
{
    cin >> n >> m;
    Size = n;

    for ( int i = 1; i <= n; i++ ) cin >> h[i];

    //对于一个有n节点的完全二叉树的叶子节点(即最底层的元素)为n/2(向上取整)、
    //所以只需要对倒数第二层开始往上的所有元素做down操作了
    for ( int i = n/2; i > 0; i-- ) down(i);
    //循环结束后堆已经建立好了，但是h数组的下标也就此打乱

    //接下来就是不断重复输出头节点并删除的操作
    while ( m-- )
    {
        cout << h[1] << ' ';
        h[1] = h[Size];
        Size--;
        down(1);
    } 

    return 0;
}