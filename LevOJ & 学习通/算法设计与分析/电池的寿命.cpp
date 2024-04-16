#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1005;

int n, a[N];

int main()
{
    while(cin >> n)
    {
        int max = -1, sum = 0;

        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            sum += a[i]; 

            if(max < a[i]) max = a[i]; 
        }

        if(sum - max < max) printf("%.1f\n", (sum - max) * 1.0); 
        else printf("%.1f\n", (sum - max - max) * 1.0 / 2 + max);
    }

    return 0;
} 