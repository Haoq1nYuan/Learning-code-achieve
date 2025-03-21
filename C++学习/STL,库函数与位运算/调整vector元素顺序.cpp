//https://www.acwing.com/problem/content/description/30/

//双指针+快排
class Solution {
public:
    void reOrderArray(vector<int> &array) {
         int i = 0, j = array.size() - 1;
         while (i < j)
         {
             while (i < j && array[i] % 2) i ++ ;
             while (i < j && array[j] % 2 == 0) j -- ;
             if (i < j) swap(array[i], array[j]);
         }
    }
};

//直接遍历
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        sort(array.begin(), array.end());
        vector<int>::iterator i = array.begin();
        int count = 0;
         
        while ( i+count < array.end() )
        {
            if ( *i % 2 == 0 ) 
            {
                array.push_back(*i);
                array.erase(i);
                count++;
            }
            else i++;
        }
    }
};
