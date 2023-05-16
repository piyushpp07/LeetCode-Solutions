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
    ListNode* swapPairs(ListNode* head) {
        ListNode *a = head;
        if(!head)
            return head;
        if(!head->next)
            return head;
        ListNode *b = head->next;
        while(b)
        {
            int p = a->val;
            int q = b->val;
            a->val = q;
            b->val = p;
            if(a->next && a->next->next && b->next && b->next->next)
            {
                a = a->next->next;
                b = b->next->next;
            }
            else{
                break;
            }

        }
        return head;
    }
};