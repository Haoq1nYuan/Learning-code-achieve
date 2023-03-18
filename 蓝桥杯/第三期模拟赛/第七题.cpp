#include <iostream>

using namespace std;

typedef pair<int, int> PII;
 
int w, h, n, r;
PII m[105];
bool st[105][105];
int cnt;

int main ()
{
    cin >> w >> h >> n >> r;
    for (int i = 1; i <= n; i++) 
    {
        int x, y;
        cin >> x >> y;
        m[i] = {x, y};
    }

    for (int k = 1; k <= n; k++)
        for (int i = 0; i <= w; i++)
            for (int j = 0; j <= h; j++)
            {
                int d = (i - m[k].first) * (i - m[k].first) + (j - m[k].second) * (j - m[k].second); 
                if (d <= r * r && !st[i][j]) 
                {
                    st[i][j] = true;
                    cnt ++;
                }
            }

    cout << cnt << endl;

    return 0;
}