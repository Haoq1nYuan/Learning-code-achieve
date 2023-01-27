//multiset
#include <multiset>
#include <vector>
#include <iostream>
class Solution {
public:
    int getNumberOfK(vector<int>& nums , int k) {
        multiset<int> p;
        for ( int i = 0; i < nums.size(); i++ )
            p.insert(nums[i]);
        return p.count(k);
    }
};

//遍历vector
#include <vector>
#include <iostream>
class Solution {
public:
    int getNumberOfK(vector<int>& nums , int k) {
        int ans;
        for ( int &p : nums )
            if ( p == k ) ans++;

        return ans;
    }
};

//二分函数
#include <vector>
#include <iostream>
class Solution {
public:
    int getNumberOfK(vector<int>& nums , int k) {
        auto l = lower_bound(nums.begin(), nums.end(), k) - nums.begin();
        auto r = upper_bound(nums.begin(), nums.end(), k) - nums.begin();

        return r-l;
    }
};

//count函数
#include <vector>
#include <iostream>
class Solution {
public:
    int getNumberOfK(vector<int>& nums , int k) {
        return count(nums.begin(), nums.end(), k);
    }
};