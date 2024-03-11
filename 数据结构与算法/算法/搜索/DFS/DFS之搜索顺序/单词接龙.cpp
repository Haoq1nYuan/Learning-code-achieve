// https://www.acwing.com/problem/content/1119/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 25;

int n, ans, res;
string str[N];
char ch;
int st[N];

void dfs (string tem, int len)
{
    for (int i = 1; i <= n; i++)
    {
        if (st[i] == 2) continue;

        int len_tem = tem.size() - 1, len_str = str[i].size() - 1;
    
        for (int j = 1; j < len_str && j < len_tem; j++)
            if (str[i].substr(1, j) == tem.substr(len_tem - j + 1, j)) 
            {
                st[i]++;
                dfs(str[i], len + len_str - j);
                st[i]--;
                break;
            }
    }
        
    ans = max(ans, len);
}

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> str[i];
        str[i] = ' ' + str[i];
    }
    cin >> ch;
    
    for (int i = 1; i <= n; i++) 
        if (ch == str[i][1]) 
        {
            memset(st, 0, sizeof st);
            st[i] = 1;
            
            dfs(str[i], str[i].size() - 1);
            
            res = max(ans, res);
        }
        
    cout << res << endl;
    
    return 0;
}