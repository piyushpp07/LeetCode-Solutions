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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *ans = NULL;
        while(slow != NULL && fast->next != nullptr && fast->next->next != nullptr)
        {
            fast  =  fast->next->next;
            slow  = slow -> next;
            bool flag  = false;
            if(fast == slow)
            {
                slow = head;
                while(slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                    
                }
                ans = slow;
                flag = true;
            }
            if(flag)
                break;
        }
        return ans;
    }
};