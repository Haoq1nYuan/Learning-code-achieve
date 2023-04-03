#include <iostream>
#include <cmath>

using namespace std;
const int N = 1000010;

int cnt, primes[N];
bool st[N];

void get_prime (int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i]) primes[cnt++] = i;
	    //确保primes[j]和i相乘不会爆n
        for (int j = 0; primes[j] <= n / i; j++) 
        {
	        //对于st数组为什么要在前面，其实这里是基于上一轮
	        //的判断，即 if (i % primes[j] == 0) break; 
	        //这句话保证只要有新的循环 primes[j] 就还是 
	        //primes[j] * i 的最小质因子
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }  
    }
}

int main ()
{
    int n;
    cin >> n;
    
    get_prime(n);
    
    cout << cnt;
    
    return 0;
}