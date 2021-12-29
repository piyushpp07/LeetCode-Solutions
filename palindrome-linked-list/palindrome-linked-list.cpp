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
    private: 
    ListNode* reverse(ListNode *dummy){
        if(!dummy) return NULL;
        ListNode* prev = NULL;
        while(dummy->next){
            ListNode *temp = dummy->next;
            dummy->next = prev;
            prev = dummy;
            dummy = temp;
        }
        dummy->next = prev;
        return dummy;
    }
public:
    bool isPalindrome(ListNode* head) {
      ListNode *slow = head, *fast = head;
        
        // slow will reach to mid
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // reversing all nodes after the mid node(second half)
        slow->next = reverse(slow->next);
        
        // again starting
        ListNode* start = head;
        slow = slow->next;
        
        // comparing the start and slow, and simultaneously moving one step ahead
        while(slow){
            if(slow->val != start->val) return false;
            slow = slow->next;
            start = start->next;
        }
        return true;
    }
};