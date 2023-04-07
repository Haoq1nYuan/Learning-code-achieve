#include <iostream>
#include <cstring>

using namespace std;

const int N = 2030, M = 4060;

int g[N][N];
int dist[N];
bool st[N];

int gcd (int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int dijkstra ()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;

    for (int i = 1; i <= 2021; i++)
    {
        int t = -1;

        for (int j = 1; j <= 2021; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;

        st[t] = true;

        for (int j = 1; j <= 2021; j++) 
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }

    return dist[2021];
}

int main ()
{
    memset(g, 0x3f, sizeof(g));

    for (int i = 1; i <= 2020; i++)
        for (int j = i + 1; j <= i + 21 && j <= 2021; j++)
        {
            int k = i * j / gcd(i, j);
            g[i][j] = g[j][i] = k;
        }
        
    cout << dijkstra();

    return 0;
}
