//https://www.acwing.com/problem/content/description/3387/

//对于一个前序遍历的序列，当且仅当出现连续两个空树标识符时才向上回溯
//这表示一个子结点的两个儿子都为空，也就是最深的子节点
#include <iostream>

using namespace std;

void dfs ()
{
    char h;
    cin >> h;
    
    if (h == '#') return;
    
    dfs();
    cout << h << ' ';
    dfs();
}

int main ()
{
    dfs();
    
    return 0;
}