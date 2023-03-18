//https://www.acwing.com/problem/content/description/1294/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1000010;

int n;
int prime[N];
bool st[N];

void get_primes (int n)
{
    int cnt = 0;
    memset(st, 0, sizeof(st));
    st[1] = true;
    
    for (int i = 2; i <= n; i++)
    {
        if (!st[i]) prime[cnt++] = i;
        
        for (int j = 0; prime[j] <= n / i; j++)
        {
            st[prime[j] * i] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

int main ()
{
    get_primes(N - 10);
    
    while (cin >> n, n)
    {
        int i = 1;
        while (i)
        {
            if (!st[n - prime[i]]) 
            {
                printf("%d = %d + %d\n", n, prime[i], n - prime[i]);
                break;
            }
            i++;
        }
    }
    
    return 0;
}