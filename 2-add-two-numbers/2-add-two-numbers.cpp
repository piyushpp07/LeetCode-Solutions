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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* ll= new ListNode();
    ListNode* pl = ll;
    int carry = 0;
    while(l1!=nullptr&&l2!=nullptr)
    {   int no=0;
        int a = l1->val;
        int b = l2->val;
        if(a + b +carry>=10)
        {
            no = l1->val + l2->val +carry - 10;
            carry=1;
        }
        else{
            no = l1->val + l2->val + carry ;
            carry = 0;
        }
        ListNode *adder = new ListNode(no);
        pl->next=adder;
        l1=l1->next;
        l2=l2->next;
        pl=pl->next;
    }
    while(l1!=nullptr)
    {   int no = 0;
        if(carry+l1->val>=10)
        {
            no = carry + l1->val - 10;
            carry = 1;
        }
        else {
            no = carry +l1->val;
            carry = 0; 
            
        }
        ListNode *adder = new ListNode(no);
        pl->next=adder;
        l1=l1->next;
        pl = pl->next;
    }
    while(l2!=nullptr)
    {   int no = 0;
        if(carry+l2->val>=10)
        {
            no = carry + l2->val - 10;
            carry = 1;
        }
        else {
            no = carry +l2->val;
            carry = 0; 
            
        }
        ListNode *adder = new ListNode(no);
        pl->next=adder;
        l2=l2->next;
        pl = pl->next;
    }
    if(carry  == 1)
    {
        ListNode *adder = new ListNode(1);
        pl->next=adder;
    }
        
        return ll->next;
        
    }
    
};