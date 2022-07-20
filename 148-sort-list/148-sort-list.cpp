/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* sortList(ListNode *head)
        {
            if (!head)
                return NULL;
            vector<int> v;
            ListNode *p = head;
            while (p)
            {
                v.push_back(p->val);
                p = p->next;
            }
            sort(v.begin(), v.end());
            ListNode *h2 = new ListNode(v[0]);
            ListNode *a = h2;
            for (int i = 1; i < v.size(); i++)
            {
                ListNode *p = new ListNode(v[i]);
                a->next = p;
                a = a->next;
            }
            return h2;
        }
};