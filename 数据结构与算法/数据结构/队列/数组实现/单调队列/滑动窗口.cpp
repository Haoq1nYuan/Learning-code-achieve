//https://www.acwing.com/problem/content/156/

//双指针暴力
/* #include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 100010;

int n, k, a[N];
int maxn[N], minn[N];

int main ()
{
    cin >> n >> k;
    for ( int i = 0; i < n; i++ ) cin >> a[i];

    memset(minn, 0x3f, sizeof(minn));
    
    memset(maxn, -0x3f, sizeof(maxn));

    for ( int i = 0; i + k <= n; i++ )
    {
        for ( int l = i, r = l + k - 1; r >= l; l++, r-- )
        {
            maxn[i] = max( max( maxn[i], a[l] ), a[r] );
            minn[i] = min( min( minn[i], a[l] ), a[r] );
        }
    }

    for ( int i = 0; i + k <= n; i++ ) cout << minn[i] << ' ';
    cout << endl;
    for ( int i = 0; i + k <= n; i++ ) cout << maxn[i] << ' ';
    cout << endl;

    return 0;
} */

//单调队列优化

/*
所谓队列，就是先入队的是队头，后入队的在队尾。
所以滑动窗口的队头是与窗口移动方向相反的，即从左向右移的时候队头在左侧，反之同理
*/

//最大最小分开遍历
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1000010;

int q[N], h = 0, t = -1;   //队列中存储元素下标而非元素值
int n, k, a[N];

int main ()
{
    cin >> n >> k;
    for ( int i = 0; i < n; i++ ) cin >> a[i];
    
    //i表示窗口的最右端
    for ( int i = 0; i < n; i++ )
    {
        //判断队头是否脱离窗口
        if ( h <= t && i - k + 1 > q[h] ) h++;  

        //队尾下标对应元素 < 新元素时新下标下标入列
        //这样可以保证队列是一个小根堆，呈单调递增状态，窗口中的最小值下标就是队头的元素
        while ( h <= t && a[q[t]] >= a[i] ) t--;

        //新下标入列
        q[++t] = i;

        //由于i是从0开始遍历，所以i要 > 窗口长度才能输出结果
        if ( i >= k - 1 ) cout << a[q[h]] << ' ';
    }
    cout << endl;

    //memset(q, 0, sizeof(q));  可以省略初始化操作，后面都会覆盖
    h = 0, t = -1;

    //同理
    for ( int i = 0; i < n; i++ )
    {
        if ( h <= t && i - k + 1 > q[h] ) h++;

        while ( h <= t && a[q[t]] <= a[i] ) t--;

        q[++t] = i;

        if ( i >= k - 1 ) cout << a[q[h]] << ' ';        
    }
    cout << endl;
    
    return 0;
}
