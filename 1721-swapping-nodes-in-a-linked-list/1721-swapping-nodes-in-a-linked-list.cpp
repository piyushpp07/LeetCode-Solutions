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
    ListNode* swapNodes(ListNode* head, int k) {
       ListNode * a = head;
       ListNode * b = head;
       ListNode *c = head;
        int cnt = 0;
        k--;
        while(a!= NULL)
        {
            a = a->next;
            cnt++;
        }
        cnt--;
        int no = cnt - k;
        while(k)
        {
            k--;
            b = b->next;
        }
        while(no)
        {
            no--;
            c = c->next;
        }
        int p = c->val;
        int q = b->val;
        c->val = q;
        b->val = p;
        return head;
    }
};