/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1);
        dummy->next=head;
        ListNode *second=dummy->next;
        ListNode *first=dummy;
        while(second)
        {
            if(second->val==val)
                first->next=second->next;
            else 
                first=second;
            second = second->next;
        }
        return dummy->next;
    } 
};