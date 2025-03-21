//https://www.acwing.com/problem/content/83/

//可能最后会爆long long, 所以要及时判断return掉

//如果num是int型变量：
//INT_MAX = 2147483647 , INT_MIN = -2147483648
//如果正负号情况一起讨论，在最后再加上符号会导致
//原本为负数的num在for循环中累加到达2147483648后越界转变为负数

class Solution {
public:
    int strToInt(string str) {
        long long num = 0;
        
        int i = 0;
        while ( str[i] == ' ' ) i++;
        
        if ( str[i] == '-' )
            for ( int j = i + 1; str[j] <= '9' && str[j] >= '0' && j < str.size(); j++ )
            {
                num = num*10 - (str[j] - '0');
                if ( num < INT_MIN ) return INT_MIN;
            }

        if ( str[i] == '+' ) i++;

        for ( int j = i; str[j] <= '9' && str[j] >= '0' && j < str.size(); j++ )
        {
            num = num*10 + (str[j] - '0');
            if ( num > INT_MAX ) return INT_MAX;
        }
            
        return num;
    }
};

//整合写法
class Solution {
public:
    int strToInt(string str) {
        int k = 0;
        while (k < str.size() && str[k] == ' ') k ++ ;
        long long res = 0;

        int minus = 1;
        if (k < str.size())
        {
            if (str[k] == '-') minus = -1, k ++ ;
            else if (str[k] == '+') k ++ ;
        }
        while (k < str.size() && str[k] >= '0' && str[k] <= '9')
        {
            res = res * 10 + str[k] - '0';
            if (res > 1e11) break;  //防止long long越界
            k ++ ;
        }

        res *= minus;
        if (res > INT_MAX) res = INT_MAX;
        if (res < INT_MIN) res = INT_MIN;

        return res;
    }
};