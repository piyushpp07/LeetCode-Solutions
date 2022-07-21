/**
 *Definition for singly-linked list.
 *struct ListNode {
 *  int val;
 *  ListNode * next;
 *  ListNode() : val(0), next(nullptr) {}
 *  ListNode(int x) : val(x), next(nullptr) {}
 *  ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* reverseBetween(ListNode *head, int left, int right)
        {
            vector<int> v;

            while (head)
            {
                int no = head->val;
                v.push_back(no);
                head = head->next;
            }
            reverse(v.begin() + left - 1, v.begin() + right);
            ListNode *curr = new ListNode(v[0]);
            ListNode *b = curr;
            for(int i = 1;i<v.size();i++)
            {
                    ListNode *a = new ListNode(v[i]);
                    b->next = a;
                    b = b->next;
            }
                return curr;
        }
};