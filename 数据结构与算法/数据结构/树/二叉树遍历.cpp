//https://www.acwing.com/problem/content/description/3387/

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