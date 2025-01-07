#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[50][50];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};   //上右下左四个方向的偏移量
int d = 1;   //d表示方向：1向右，2向下，3向左，0向上，作为偏移量下标，二者一一对应

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            cin >> arr[i][j];

    bool st[50][50] = {false};  //判重数组，防止重复输出相同位置的值

    int x = 0, y = 0;   //初始化坐标  

    for (int i = 0; i < n * m; i ++ )
    {
        int a = x + dx[d], b = y + dy[d];
        
        if (a < 0 || a >= n || b < 0 || b >= m || st[a][b])
        {
            d = (d + 1) % 4;  //转换方向
            a = x + dx[d], b = y + dy[d];
        }

        cout << arr[x][y] << ' ';

        st[x][y] = true;  //将当前位置标记为“用过”

        x = a, y = b;  //更新坐标
    }

    cout << endl;

    return 0;
}