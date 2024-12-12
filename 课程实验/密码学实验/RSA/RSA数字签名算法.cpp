#include <iostream>
#include <sstream>
#include <ctime>
#include <chrono>  // 添加这个库来测量时间
#include <vector>
#include <cstdlib>

using namespace std::chrono;  // 添加这个命名空间来使用时间函数

using namespace std;

typedef long long ll;

vector<int> primes;
int public_Key, private_Key;
int n, fn, e, d;

// 辗转相除求最大公因数
int gcd (int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

// 快速幂
int qmi (int a, int b, int p)
{
    int res = 1;

    while (b)
    {
        if (b & 1) res = (ll)res * a % p;

        b >>= 1;
        
        a = (ll)a * a % p;
    }

    return res;
}

// 辅助函数：计算模逆元
int modInverse(int a, int m)
{
    a = a % m;
    for (int x = 1; x < m; x++) 
    {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

// 辅助函数：埃拉托色尼筛法生成素数
void generatePrimes(int maxNum) 
{
    std::vector<bool> isPrime(maxNum + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= maxNum; ++i) 
    {
        if (isPrime[i]) 
        {
            primes.push_back(i);
            for (int j = i * i; j <= maxNum; j += i)
                isPrime[j] = false;
        }
    }
}

// 初始化密钥
void Init() 
{
    srand(static_cast<unsigned>(time(nullptr)));
    generatePrimes(100);

    do {
        public_Key = primes[rand() % primes.size()];
        private_Key = primes[rand() % primes.size()];
    } while (public_Key == private_Key || public_Key * private_Key < 122);
}

// 生成 n, φ(n), e 和 d
void Get() 
{
    n = public_Key * private_Key;
    fn = (public_Key - 1) * (private_Key - 1);

    // 随机选择 e，使得 e 与 φ(n) 互素
    std::vector<int> coprimes;
    for (int i = 2; i < fn; ++i) 
    {
        if (gcd(fn, i) == 1) coprimes.push_back(i);
    }
    e = coprimes[rand() % coprimes.size()];

    // 计算 d，使得 d 是 e 在 φ(n) 下的模逆元
    d = modInverse(e, fn);
}

// 哈希函数
int simpleHash (const string& message) 
{ 
    int hash = 0; 
    for (char c : message) 
    { 
        hash = (hash * 31 + c) % 1000000007; 
    } 
    
    return hash;
}

int main ()
{
	Init(); 
	
	Get();
	
	cout << "The public_Key is: " << "(" << e << ", " << n << ")" << endl;
    cout << "The private_Key is: " << "(" << d << ", " << n<< ")" << endl;

    string message = "Hello, World!";
    cout << "Message: " << message << endl;

    int messageHash = simpleHash(message);
    cout << "messageHash: " << messageHash << endl;

    int signature = qmi(messageHash, d, n);
    cout << "Signature: " << signature << endl;

    int decryptedHash = qmi(signature, e, n);
    cout << "decryptedHash: " << decryptedHash << endl;

    if (decryptedHash == signature) cout << "Signature verification succeeded." << endl;
    else cout << "Signature verification failed." << endl;

    return 0;
}

