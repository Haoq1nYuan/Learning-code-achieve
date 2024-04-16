// http://172.16.44.165/course/95/problem/1220

#include <iostream>
#include <cstring>

using namespace std;

int cnt, ans;
int p[11], pre[11][11];
int mark[11][11];

void dfs (int k)
{
    if (k == 9) 
    {   
        ans++;

        return;
    }

    for (int i = 1; i <= 8; i++)
        if (mark[k][i]) 
        {
            dfs(k + 1);
            return;
        }
    
    for ( int i = 1; i <= 8; i++ )
        if (!p[i] && !pre[k][i] && !mark[k][i])
        {
            p[i] = 1;
            for ( int j = i + 1; j <= 8 && k + j - i <= 8; j++ ) pre[k + j - i][j]++;
            for ( int j = i - 1; j >= 1 && k + i - j <= 8; j-- ) pre[k + i - j][j]++;
            mark[k][i] = 1;
            cnt ++;
            dfs(k + 1);
            p[i] = 0;
            for ( int j = i + 1; j <= 8 && k + j - i <= 8; j++ ) pre[k + j - i][j]--;
            for ( int j = i - 1; j >= 1 && k + i - j <= 8; j-- ) pre[k + i - j][j]--;
            mark[k][i] = 0;
            cnt --;
        }

    return;
}

int main () 
{
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
        {
            cin >> mark[i][j];
            if (mark[i][j]) 
            {
                cnt ++;
                p[j] = 1;

                for ( int k = i + 1; k <= 8 && i + k - j <= 8; k++ ) pre[i + k - j][k]++;
                for ( int k = i - 1; k >= 1 && i + j - k <= 8; k-- ) pre[i + j - k][k]++;
            }
        }

    dfs(1);

    cout << ans << endl;
    
    return 0;
}

// #include<iostream>

// using namespace std;

// int arr[10][10];				
// int ans;		
			
// bool judge(int x, int y)		
// {
// 	int i, j;
    
// 	for (j = 1; j <= 8; j++)
// 	{
// 		if (arr[j][y]) return false;
// 	}

// 	for (i = 1; i <= 8; i++)
// 		for (j = 1; j <= 8; j++)
// 			if (abs(x - i) == abs(y - j) && arr[i][j] == 1)	return false;

// 	return true;
// }

// void dfs(int v)					
// {
// 	if (v > 8)					
// 	{
// 		ans++;					
// 		return;
// 	}

// 	int i, j, flag = 1;							
// 	for (i = 1; i <= 8; i++)
// 	{
// 		if (arr[v][i])				
// 		{
// 			flag = 0;
// 			break;
// 		}
// 	}

// 	if (flag)
// 	{
// 		for (i = 1; i <= 8; i++)
// 		{
// 			if (judge(v, i))
// 			{
// 				arr[v][i] = 1;
// 				dfs(v + 1);
// 				arr[v][i] = 0;			
// 			}
// 		}
// 	}
// 	else
// 	{
// 		dfs(v + 1);
// 	}
// }
// int main()
// {
// 	int i, j;
    
// 	for (i = 1; i <= 8; i++)
// 	{
// 		for (j = 1; j <= 8; j++)
// 		{
// 			cin >> arr[i][j];
// 		}
// 	}

// 	dfs(1);			

// 	cout << ans << endl;

// 	return 0;
// }