#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include "AES.cpp"
using namespace std;
 
unsigned char key[16];
 
int main()
{
    ios::sync_with_stdio(false);
 
    cout << "Please type the originalText(no longer than 10^6 letters):";
    cin >> P;

    cout << "Please type the key, example: '00 01 ... 0d 0e 0f'):";

    unsigned int xx;
    for(int i=0;i<16;i++)  
    {
    	cin >> hex >> xx;
    	key[i]=xx;
    }
 
    cout << "The Key is:"<< endl;
    for(int i=0; i<16; i++) 
    {
        printf("%02x  ",key[i]);
    }
    cout  << "\n" << endl;
 
    KeyExpansion(key); 

    cout << "The originalText is:" << endl;
    for(int i=0;i<strlen((char*)P);i++)
    {
        printf("%02x  ",P[i]);
    }
 
    cout << endl;
    encryption(); 
    cout << endl;
 
    cout << "The codedText is:" << endl;
    for(int i=0;i<strlen((char*)C);i++)
    {
        printf("%02x  ",C[i]);
    }
    cout  << "\n" << endl;
 
    decryption();  
 
    cout << "The Text after discoding is:" << endl;
    printf("%s\n",De_P);
 
    return 0;
}