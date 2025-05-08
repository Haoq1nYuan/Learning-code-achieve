//https://www.acwing.com/problem/content/870/

//朴素筛法
#include <iostream>

using namespace std;
const int N =1000010;

int cnt;
bool st[N];

void get_prime (int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i]) cnt++;
        
        for (int j = i + i; j <= n; j += i) st[j] = true;
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

//埃氏筛法
#include <iostream>

using namespace std;
const int N =1000010;

int cnt;
bool st[N];

void get_prime (int n)
{
    for (int i = 2; i <= n; i++)
        if (!st[i])
        { 
            cnt++;
            //只需要每次把质数筛去就行，因为合数肯定能被质数整除掉
            for (int j = i + i; j <= n; j += i) st[j] = true;
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

//线性筛
#include <iostream>
#include <cmath>

using namespace std;
const int N = 1000010;

int cnt, primes[N];
bool st[N];

void get_prime (int n)
{
    for (int i = 2; i <= n; i++)-
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