#include <iostream>

using namespace std;
const int N = 100010;

//s数组类似于判重数组,存储每个数出现的个数
int n, a[N], maxl, s[N];

int main ()
{
    cin >> n;
    for ( int i = 1; i <= n; i++ ) cin >> a[i];
    
    for ( int i = 1, j = 1; i <= n; i++ )
    {
        //更新s数组
        s[a[i]]++;
        
        //因为这个序列中的i指针是从左往右走的,所以但出现重复数字时,
        //那个重复的数字一定是新加入的数,所以此时以j为左端点的不重复连续序列已经到达最大长度
        //我们记录该长度并于最长长度比较,并将j指针右移一个元素,
        //同时将s数组中对于下表的元素值-1
        //直到j不断右移后的序列又变成不重复序列,再右移i.
        while ( s[a[i]] > 1 )
        {
            maxl = max(maxl, i-j);
            s[a[j]]--;
            j++;
        }
        
        if ( i == n ) maxl = max(maxl, i-j+1);
    }
    
    cout << maxl;
    
    return 0;
}