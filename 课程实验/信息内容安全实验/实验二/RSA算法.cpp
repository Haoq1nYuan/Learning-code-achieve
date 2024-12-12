#include <iostream>
#include <sstream>
#include <ctime>
#include <chrono>  // 添加这个库来测量时间

using namespace std::chrono;  // 添加这个命名空间来使用时间函数

using namespace std;

typedef long long ll;

int public_Key, private_Key;
int Keys[30], idx1;
int n, fn, e, d;
int Es[10000], idx2;

int choice;

string originalText, codedText;

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

// 生成公私钥，满足n一定大于int('z')，即确保能够加解密所有的字母
void Init ()
{
    srand(static_cast<unsigned>(time(nullptr)));

	for (int i = 2; i <= 100; i++)
	{
		bool flag = true;
		for (int j = 2; j < i; j++)
			if (i % j == 0) 
			{
				flag = false;
				break;
			}	
			
		if (flag) Keys[idx1++] = i;
	}
	
	// 随机生成公私钥 
	int public_key_idx = rand() % idx1, private_key_idx = rand() % idx1;
	while (public_key_idx == private_key_idx || Keys[public_key_idx] * Keys[private_key_idx] < 122)
	{
		public_key_idx = rand() % idx1;
		private_key_idx = rand() % idx1;
	}
	
	public_Key = Keys[public_key_idx];
	private_Key = Keys[private_key_idx];
}

// 求出 n, fn , e 和 d 
void Get ()
{
	n = public_Key * private_Key;
	fn = (public_Key - 1) * (private_Key - 1);
	
	// 随机生成e 
	for (int i = 2; i < fn; i++)
		if (gcd(fn, i) == 1)
			Es[idx2++] = i;
			
	int e_idx = rand() % idx2;
	e = Es[e_idx];

	// 取出最小的逆元 
    for (int k = 1; ; k++)
        if ((k * e - 1) % fn == 0)
        {
            d = k;
            break;
        }
}

void Coding ()
{
    auto start = high_resolution_clock::now();

    cout << "The codedText is: ";
	for (char ch: originalText)
    {
        int tem = int(ch);

        cout << qmi(tem, e, n) << ' ';
    }
    cout << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by Coding: " << duration.count() << " microseconds" << endl;
}

void DisCoding ()
{
    auto start = high_resolution_clock::now();

    stringstream str(codedText);
    string sstr;

    cout << "The originalText is: ";
    while (str >> sstr)
    {
        int idx = 0, tem = 0;
        while (sstr[idx])
        {
            tem = tem * 10 + int(sstr[idx] - '0');
            idx++;
        }

        cout << char(qmi(tem, d, n));
    }
    cout << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by DisCoding: " << duration.count() << " microseconds" << endl;
}

int main ()
{
	Init(); 
	
	Get();
	
	cout << "The public_Key is: " << "(" << e << ", " << n << ")" << endl;
    cout << "The private_Key is: " << "(" << d << ", " << n<< ")" << endl;

    cout << "Coding or DisCoding (1. Coding, 2. DisCoding, 3. Exit): ";
    cin >> choice;
    while (choice != 1 && choice != 2)
    {
        cout << "Type again, coding or disCoding (1. Coding, 2. DisCoding, 3. Exit): ";
        cin >> choice;
    }

    while (choice != 3)
    {
        getchar();

        if (choice == 1)
        {
            cout << "Now give me the originalText: ";
            getline(cin, originalText);
            codedText = originalText;

            cout << "The originalText is: ";
            for (char ch: originalText) cout << ch;
            cout << endl;
            
            Coding();
        }

        if (choice == 2)
        {
            cout << "Now give me the codedText: ";
            getline(cin, codedText);

            cout << "The codedText is: ";
            for (char ch: codedText) cout << ch;
            cout << endl;
            
            DisCoding();
        }

        cout << "Coding or DisCoding (1. Coding, 2. DisCoding, 3. Exit): ";
        cin >> choice;
        while (choice != 1 && choice != 2 && choice != 3)
        {
            cout << "Type again, coding or disCoding (1. Coding, 2. DisCoding, 3. Exit): ";
            cin >> choice;
        }
    }

	return 0;
}
