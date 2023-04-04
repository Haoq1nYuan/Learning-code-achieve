//https://www.acwing.com/problem/content/118/

#include <iostream>
#include <cstring>

using namespace std;

char g[6][6], backup[6][6];
int tema[17], temb[17], ansa[17], ansb[17];

void turn (int a, int b)
{
    for (int i = 0; i < 4; i++) g[a][i] = (g[a][i] == '+') ? '-' : '+';
    for (int i = 0; i < 4; i++) g[i][b] = (g[i][b] == '+') ? '-' : '+';
    g[a][b] = (g[a][b] == '+') ? '-' : '+';
}

int main ()
{
    for (int i = 0; i < 4; i++) cin >> g[i];
        
    memcpy(backup, g, sizeof(g));
    
    int cnt = 17;
    //枚举每一种位置上的操作组合，将这些把手看作一个16位数，1表示改变状态，0不改变
    for (int i = 0; i < (1 << 16); i++)
    {
        int count = 0;
        for (int x = 0; x < 16; x++)
            if (i >> x & 1)    
            {
                int a = x / 4, b = x % 4;
                tema[count] = a + 1, temb[count] = b + 1;
                turn(a, b);
                count++;
            }
        
        bool flag = true;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (g[i][j] == '+') 
                {
                    flag = false; 
                    break;
                }
                
        if (flag && count < cnt) 
        {
            cnt = count;
            for (int i = 0; i < count; i++) ansa[i] = tema[i], ansb[i] = temb[i];
        }
        
        memcpy(g, backup, sizeof(backup));
    }
    
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) cout << ansa[i] << ' ' << ansb[i] << endl;
    
    return 0;
}