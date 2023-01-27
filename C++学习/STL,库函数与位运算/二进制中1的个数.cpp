//ÓÒÒÆ
class Solution {
public:
    int NumberOf1(int n) {
        int ans = 0;

        for ( int i = 0; i < 32; i++ )
            if ( n >> i & 1 ) ans++;
            
        return ans;
    }
};

//lowbit
class Solution {
public:
    int NumberOf1(int n) {
        int ans = 0;

        while (n) n -= n & -n, ans++;
            
        return ans;
    }
};

//bitset
#include <bitset>
class Solution {
public:
    int NumberOf1(int n) {
        bitset<32> k(n);
        return k.count();
    }
};