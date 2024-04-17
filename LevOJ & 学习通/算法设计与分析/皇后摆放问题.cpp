#include <iostream>
#include <cstring>

using namespace std;

int ans;
int p[11];
int mark[11][11];
string tem;
int pre[11][11];

void dfs (int i)
{
    if (i == 9) 
    {   
        ans++;

        return;
    }

    for (int j = 1; j <= 8; j++)
        if (mark[i][j]) 
        {
            dfs(i + 1);
            return;
        }
    
    for ( int j = 1; j <= 8; j++ )
        if (!p[j] && !pre[i][j])
        {
            p[j] = 1;
            for ( int k = j + 1; k <= 8 && i + k - j <= 8; k++ ) pre[i + k - j][k] ++;
            for ( int k = j - 1; k >= 1 && i + j - k <= 8; k-- ) pre[i + j - k][k] ++;
            mark[i][j] = 1;
            dfs(i + 1);
            p[j] = 0;
            for ( int k = j + 1; k <= 8 && i + k - j <= 8; k++ ) pre[i + k - j][k] --;
            for ( int k = j - 1; k >= 1 && i + j - k <= 8; k-- ) pre[i + j - k][k] --;
            mark[i][j] = 0;
        }

    return;
}

int main () 
{
    for (int i = 1; i <= 8; i++)
    {
        getline(cin, tem);
        int j = 1;
        for (auto ch: tem)
        {
            if (ch == ' ') continue;

            if (ch == '1') 
            {
                mark[i][j] = 1;
                p[j] = 1;

                pre[i][j] ++;
                for ( int k = j + 1; k <= 8 && i + k - j <= 8; k++ ) pre[i + k - j][k] ++;
                for ( int k = j + 1; k <= 8 && i - k + j >= 1; k++ ) pre[i - k + j][k] ++;
                for ( int k = j - 1; k >= 1 && i + j - k <= 8; k-- ) pre[i + j - k][k] ++;
                for ( int k = j - 1; k >= 1 && i - j + k >= 1; k-- ) pre[i - j + k][k] ++;
            }
            else mark[i][j] = 0;

            j++;
        }
    }

    dfs(1);

    cout << ans << endl;
    
    return 0;
}