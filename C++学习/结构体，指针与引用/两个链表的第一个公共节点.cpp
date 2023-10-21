//https://www.acwing.com/problem/content/description/62/

//TLE
/* 
 //Definition for singly-linked list.
 //struct ListNode {
 //    int val;
 //    ListNode *next;
 //    ListNode(int x) : val(x), next(NULL) {}
 //};
class Solution {
public:
    ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) {
        ListNode* ans;
        while ( headA )
        {
            ListNode* k = headB;
            while ( k )
            {
                if ( headA == k ) return headA;
                k = k->next;
            }
            
            headA = headA->next;
        }
        
        return NULL;
    }
}; 
 */

//循环遍历，相同的时候必然是相交的位置
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) {
        auto a = headA, b = headB;
        
        while ( a != b )
        {
            //看作lista+listb和listb+lista两条线路，当a和b相交时经过的路程一定相等
            if (b) b = b->next;
            else b = headA;
            if (a) a = a->next;
            else a = headB;
        }
        
        return a;
    }
};