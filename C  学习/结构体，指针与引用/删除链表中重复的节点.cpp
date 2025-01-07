//https://www.acwing.com/problem/content/27/

//写法一

Definition for singly-linked list. 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteDuplication(ListNode* head) {
        if (!head) return head;
        
        ListNode* q = new ListNode(-1);
        q->next = head;
        auto p = q;  //p为保留的链表的尾节点
        
        while (p->next)
        {
            ListNode* k = p->next;  //k用来遍历链表
            while ( k && p->next->val == k->val ) k = k->next;
            
            if ( k == p->next->next ) p = p->next;
            else p->next = k;
        }
        
        return q->next;
    }
};