//https://www.acwing.com/problem/content/800/

//b[i][j]反应了a数组的变化关系（二维），反过来就是a[i][j]为以b[1][1]为左上角，以b[i][j]为右下角的子矩阵
//所以我们再反推a的值时只需要用二维前缀和公式

//所以,整个二维差分的过程都是在对差分数组做操作,只需时刻记得差分数组的二维前缀和是a数组即可
//题目中的"对a数组某个范围内的元素加减c"其实就可以理解为b数组的改变
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1010;

int n, m, q;
int a[N][N], b[N][N];

void insert ( int x1, int y1, int x2, int y2, int c )
{
    b[x1][y1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

int main ()
{
    cin >> n >> m >> q;

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            scanf( "%d", &a[i][j] );

    //虚拟一个a数组,即用差分的方式构建好b数组,
    //在这同时初始的a数组也就以b矩阵二维前缀和的方式构建好了
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            insert( i, j, i, j, a[i][j] );

    while ( q-- )
    {
        int x1, x2, y1, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }
    
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            //此时b数组就是一个前缀和数组，我们需要求b矩阵以b[1][1]为左上角，
            //以b[i][j]为右下角的子矩阵的和，这个和就是a[i][j]
            b[i][j] += b[i - 1][j] + b[i][j - 1] + a[i - 1][j - 1];

    for ( int i = 1; i <= n; i++ )
    {
        for ( int j = 1; j <= m; j++ )
            cout << a[i][j] << ' ';
        puts("");
    }

    return 0;
}