#include <iostream>
#include <cstring>
#include <cstDio>

using namespace std;

const int N = 15;

int T, a, b, c, d, e, minl, maxl, num;
int wa[N], wb[N], wc[N], wd[N], we[N];
int stD[N], ste[N];

int check (int sum)
{
    int cnt = 0;
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            if (sum + wa[i] + wb[j] >= minl && sum + wa[i] + wb[j] <= maxl) cnt ++;

    for (int i = 1; i <= c; i++)
        if (sum + wc[i] >= minl && sum + wc[i] <= maxl) cnt++;

    return cnt;
}

int main ()
{
    cin >> T;
    while (T--)
    {
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
        for (int i = 1; i <= a; i++) scanf("%d", &wa[i]);
        for (int i = 1; i <= b; i++) scanf("%d", &wb[i]);
        for (int i = 1; i <= c; i++) scanf("%d", &wc[i]);
        for (int i = 1; i <= d; i++) scanf("%d", &wd[i]);
        for (int i = 1; i <= e; i++) scanf("%d", &we[i]);
        cin >> minl >> maxl;

        //1 + 1
        for (int i = 1; i <= d; i++)    
            for (int j = 1; j <= e; j++) 
                if (wd[i] + we[j] < maxl) num += check(wd[i] + we[j]);

        //1 + 2
        memset(ste, 0, sizeof(ste));
        for (int i = 1; i <= d; i++) 
            for (int j = 1; j <= e; j++)
            {
                ste[j] = true;
                for (int k = 1; k <= e; k++)
                    if (!ste[k]) 
                    {
                        int sum = wd[i] + we[j] + we[k];
                        if (sum < maxl) num += check(sum);
                    }
                stD[j] = false;
            }

        //2 + 1
        memset(stD, 0, sizeof(stD));
        for (int i = 1; i <= e; i++)
            for (int j = 1; j <= d; j++)
            {
                stD[j] = true;
                for (int k = 1; k <= d; k++)
                    if (!stD[k])
                    {
                        int sum = we[i] + wd[j] + wd[k];
                        if (sum < maxl) num += check(sum);
                    }
                stD[j] = false;
            }

        //2 + 2
        memset(stD, 0, sizeof(stD));
        memset(ste, 0, sizeof(ste));
        for (int i = 1; i <= d; i++)
        {
            stD[i] = true;
            for (int j = 1; j <= d; j++)
                if (!stD[i])
                    for (int k = 1; k <= e; k++)
                    {
                        ste[k] = true;
                        for (int p = 1; p <= e; p++)
                            if (!ste[p])
                            {
                                int sum = wd[i] + wd[j] + we[k] + we[p];
                                if (sum < maxl) num += check(sum);
                            }
                        ste[k] = false;
                    }
            stD[i] = false;
        }
        
        cout << num << endl;
    }

    return 0;
}