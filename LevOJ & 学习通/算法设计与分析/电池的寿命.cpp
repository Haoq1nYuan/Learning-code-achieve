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

// Αν½β
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1005;

int n, t[N];

int main ()
{   
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) cin >> t[i];
        
        if (n == 2) printf("%.1f\n", min(t[1], t[2]) * 1.0);
        else 
        {
            int sum = 0;

            sort (t + 1, t + 1 + n);

            for (int i = 1; i < n; i++) sum += t[i];

            if (sum >= t[n]) printf("%.1f\n", t[n] + (sum - t[n]) * 1.0 / 2);
            else printf("%.1f\n", sum);
        }
    }

    return 0;
}