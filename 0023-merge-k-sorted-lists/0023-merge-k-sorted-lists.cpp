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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int ,vector<int>,greater<int>>pq;
        for(int i = 0;i<lists.size();i++)
        {
            ListNode *a = lists[i];
            while(a)
            {
                pq.push(a->val);
                a = a->next;
            }
        }
        ListNode *ans = new ListNode();
        ListNode *temp = ans;
        while(pq.size())
        {
            ListNode *p = new ListNode(pq.top());
            pq.pop();
            temp->next= p;
            temp = temp -> next;
        }
        return ans->next;
    }
};