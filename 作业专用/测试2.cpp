#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <random>

// 辅助函数，用于大数计算
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long long modInverse(long long a, long long m) {
    a = a % m;
    for (long long x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

// 随机生成大素数
long long generatePrime() {
    std::vector<long long> primes = {101, 103, 107, 109, 113, 127, 131, 137, 139};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, primes.size() - 1);
    return primes[distr(gen)];
}

// 哈希函数（简单示例，用于演示）
long long simpleHash(const std::string& message) {
    long long hash = 0;
    for (char c : message) {
        hash = (hash * 31 + c) % 1000000007;
    }
    return hash;
}

int main() {
    // 生成公钥和私钥
    long long p = generatePrime();
    long long q = generatePrime();
    long long n = p * q;
    long long phi = (p - 1) * (q - 1);
    long long e = 65537; // 常用公钥指数
    long long d = modInverse(e, phi);

    if (d == -1) {
        std::cerr << "Failed to generate keys" << std::endl;
        return -1;
    }

    std::cout << "Public Key: (" << n << ", " << e << ")" << std::endl;
    std::cout << "Private Key: (" << n << ", " << d << ")" << std::endl;

    // 待签名消息
    std::string message = "Hello, RSA Digital Signature!";
    std::cout << "Message: " << message << std::endl;

    // 消息哈希
    long long messageHash = simpleHash(message);

    // 使用私钥对消息进行签名
    long long signature = modExp(messageHash, d, n);
    std::cout << "Signature: " << signature << std::endl;

    // 使用公钥验证签名
    long long decryptedHash = modExp(signature, e, n);
    if (decryptedHash == messageHash) {
        std::cout << "Signature verification succeeded." << std::endl;
    } else {
        std::cout << "Signature verification failed." << std::endl;
    }

    return 0;
}
