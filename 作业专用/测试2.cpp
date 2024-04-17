#include<iostream>

using namespace std;

int arr[10][10];				
int ans;		
			
bool judge(int x, int y)		
{
	int i, j;
    
	for (j = 1; j <= 8; j++)
	{
		if (arr[j][y]) return false;
	}

	for (i = 1; i <= 8; i++)
		for (j = 1; j <= 8; j++)
			if (abs(x - i) == abs(y - j) && arr[i][j] == 1)	return false;

	return true;
}

void dfs(int v)					
{
	if (v > 8)					
	{
		ans++;					
		return;
	}

	int i, j, flag = 1;							
	for (i = 1; i <= 8; i++)
	{
		if (arr[v][i])				
		{
			flag = 0;
			break;
		}
	}

	if (flag)
	{
		for (i = 1; i <= 8; i++)
		{
			if (judge(v, i))
			{
				arr[v][i] = 1;
				dfs(v + 1);
				arr[v][i] = 0;			
			}
		}
	}
	else
	{
		dfs(v + 1);
	}
}
int main()
{
	int i, j;
    
	for (i = 1; i <= 8; i++)
	{
		for (j = 1; j <= 8; j++)
		{
			cin >> arr[i][j];
		}
	}

	dfs(1);			

	cout << ans << endl;

	return 0;
}