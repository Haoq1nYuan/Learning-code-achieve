//https://www.acwing.com/problem/content/34/

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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* p = head;
        
        while ( l1 && l2 )
        {
            if ( l1->val > l2->val ) 
            {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
            else 
            {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            }
        }
        
        while ( l1 )
        {
            p->next = l1;
            p = p->next;
            l1 = l1->next;
        }
        
        while ( l2 )
        {
            p->next = l2;
            p = p->next;
            l2 = l2->next;
        }
        
        return head->next;
    }
};