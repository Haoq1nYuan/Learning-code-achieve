//https://www.acwing.com/problem/content/150/

#include <iostream>
#include <queue>

using namespace std;

int main ()
{
    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, greater<int>> heap;
    while (n--)
    {
        int x;
        cin >> x;
        heap.push(x);
    }
    
    int res = 0;
    while (heap.size() > 1)
    {
        int a = heap.top();
        heap.pop();
        int b = heap.top();
        heap.pop();
        res += a + b;
        heap.push(a + b);
    }
    
    cout << res;
    
    return 0;
}

