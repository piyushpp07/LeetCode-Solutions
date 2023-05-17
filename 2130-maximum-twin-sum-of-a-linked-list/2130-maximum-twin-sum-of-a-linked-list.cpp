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
    int pairSum(ListNode* head) {
        vector<int>v,z;
        
        while(head)
        {
            int no = head->val;
            v.push_back(no);
            head = head->next;
        }
        int n = v.size();
        for(int i = 0;i<v.size()/2;i++)
        {
            z.push_back(v[i] + v[n-i-1]);
        }
        return *max_element(z.begin(),z.end());
        
    }
    
};