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
    void deleteNode(ListNode* node) {
        //将后面一个节点的值复制到要删除的链表，再将后面一个链表删除即可
        node->val = node->next->val; 
        
        node->next = node->next->next;
    }
};