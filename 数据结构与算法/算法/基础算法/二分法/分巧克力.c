//https://www.acwing.com/problem/content/1229/

#include<stdio.h>

long k, n, h[100010], w[100010];
long i, j, r, l, mid, box;

int check ()
{
    long count = 0;
    for (i = 1; i <= n; i++) 
    {
        long min = h[i] > w[i] ? w[i] : h[i];
        if (mid <= min) count += (h[i] / mid) * (w[i] / mid);
    }

    return count >= k;
}

int main (int argc, char *argv[])
{
    scanf("%ld%ld", &n, &k);
    for (i = 1; i <= n; i++) 
    {
        scanf("%ld%ld", &h[i], &w[i]);
        box = h[i] > w[i] ? h[i] : w[i];
        r = box > r ? box : r;
    }

    l = 1;
    while (l < r) 
    {
        mid = (l + r + 1) / 2;
        if (check()) l = mid;
        else r = mid - 1;
    }

    printf("%ld\n", l);

    return 0;
}