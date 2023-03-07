//https://www.acwing.com/problem/content/3780/

#include <iostream>
#include <cstring>

using namespace std;

int n, st[210], idx;
string s;
string backup;

int turn (char k)
{
    int cnt = 0;
    
    char p;
    if (k == 'W') p = 'B';
    else p = 'W';
    
    for (int i = 1; i < n; i++)
    {
        if (s[i] == k)
        {
            st[idx++] = i;
            cnt++;
            s[i] = p;
            if (s[i + 1] == k) s[i + 1] = p;
            else s[i + 1] = k;
        }
    }    
    
    if (s[n] == p) 
        if (cnt > 3 * n) return -1;
        else return cnt;
    else return -1;
}

int main ()
{
    int t;
    cin >> t;
    
    while (t--)
    {
        memset(st, 0, sizeof(st));
        idx = 0;
        cin >> n >> s;
        
        bool sim = true;
        for (auto k : s)
            if (k != s[0]) 
            {
                sim = false;
                break;
            }
        
        if (sim) 
        {
            cout << 0 << endl;
            continue;
        }
        
        s = ' ' + s;
        backup = s;
        
        int t = turn('W');
        if (t != -1) 
        {
            cout << t << endl;
            for (int i = 0; i < idx; i++) cout << st[i] << ' ';
            cout << endl;
            continue;
        }
        
        memset(st, 0, sizeof(st));
        idx = 0;
        
        s = backup;
        
        t = turn('B');
        if (t != -1)
        {
            cout << t << endl;
            for (int i = 0; i < idx; i++) cout << st[i] << ' ';
            cout << endl;
            continue;
        }
        else if (t == -1)
        {
            cout << -1 << endl;
            continue;
        }
    }
    
    return 0;
}