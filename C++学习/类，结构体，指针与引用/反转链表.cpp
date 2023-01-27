//https://www.acwing.com/problem/content/33/

//迭代
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
    ListNode* reverseList(ListNode* head) {
        if ( !head || !head->next ) return head;
        
        ListNode* p = head;
        ListNode* q = head->next;

        while (q)
        {
            ListNode* tem = q->next;
            q->next = p;
            p = q;
            q = tem;
        }
        
        head->next = NULL;
        
        return p;
    }
};

//递归
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
    ListNode* reverseList(ListNode* head) {
        if ( !head || !head->next ) return head;  //防止空链表和递归的出口
        
        auto Head = reverseList(head->next);  
        //翻转的是这一层调用中的头节点head之后的链表，反转链表后头节点是head->next，它向左指向NULL;

        head->next->next = head;   
        //我们要让翻转头节点向左指向前面一个节点（即head），就可以让head->next->next = head;
        head->next = NULL;
        //再让这一层调用中的头节点向左指向NULL

        return Head;
    }
};