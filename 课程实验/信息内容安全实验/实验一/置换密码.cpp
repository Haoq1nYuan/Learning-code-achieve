#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

FILE * file1;
char plaintext[64], ciphertext[64];
char * meassage;
vector<int> key;

int main()
{
    for (int i = 0; i < 64; i++) key.push_back(i);

    random_device rd; 
    mt19937 gen(rd()); 
    shuffle(key.begin(), key.end(), gen);

    // 读取明文
    file1 = fopen(".\\message.txt", "r");
    fgets(plaintext, 64, file1);
    fclose(file1);

    // 输出明文
    cout << "Plaintext: " << endl;
    for (int i = 0; i < 64; i++) 
        cout << plaintext[i] << ' ';

    // 置换操作
    for (int i = 0; i < 64; i++)
    {
        int j = key[i];
        ciphertext[i] = plaintext[j];
    }

    cout << "\nCiphertext: " << endl;
    for (int i = 0; i < 64; i++) cout << ciphertext[i] << ' ';

    return 0;
}