//https://www.acwing.com/problem/content/847/

//难点是如何处理状态表示：string展开
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

string start;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

queue<string> q;
unordered_map<string, int> d;

int bfs (string state)
{
    q.push(state);
    //d[state] = 0;
    
    string end = "12345678x";
    
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        
        if (t== end) return d[t];
        
        //此处存储原状态下的距离，方便下面多种情况的数据使用
        int distance = d[t];
        
        //将字符串中的位置转化为二维坐标
        int k = t.find('x');
        int x = k / 3, y = k % 3;
        
        for ( int i = 0; i < 4; i++ )
        {
            int a = x + dx[i], b = y + dy[i];
            
            if (a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                swap(t[a*3 + b], t[k]);
                //如果该种新情况没有被讨论过，则更新和它对应的距离，再将其推入队列
                if (!d.count(t))
                {
                    d[t] = distance + 1;
                    q.push(t);
                }
                //这里一定要还原状态，因为可能还会有其他新状态
                swap(t[a*3 + b], t[k]);
            }
        }
    }
    
    return -1;
}

int main ()
{
    for ( int i = 0; i < 9; i++ )
    {
        char c;
        cin >> c;
        start += c;
    }
        
    cout << bfs(start) << endl;
    
    return 0;
}