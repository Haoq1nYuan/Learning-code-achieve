#include<iostream>
#include<algorithm>

using namespace std;

int sum[400010];

int ans;

void binary_search(int x,int length)
{
    int left = 1, right = length-1;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (sum[mid] == x)
        {
            ans++;
            int i=mid,j=mid;
            //向前搜索
            while (sum[i - 1] == x)
            {
                ans++;
                i--;
            }
            //向后搜索
            while (sum[j + 1] == x)
            {
                ans++;
                j++;
            }
            return;
        }
        else if (sum[mid] > x) right = mid - 1;
        else left = mid + 1;
    }

    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[2010][10];
        int i, j;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= 4; j++)
            {
                cin >> arr[i][j];
            }
        }

        int k=1;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                sum[k] = arr[i][1] + arr[j][2];
                k++;
            }
        }

        sort(sum + 1, sum + k);
        int length = k;

        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                int sum = arr[i][3] + arr[j][4];
                binary_search(-sum, length);
            }
        }

        cout << ans << endl;
        
        ans = 0;
    }
    return 0;
}
