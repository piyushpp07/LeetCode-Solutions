/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public int size(ListNode a)
    {
        ListNode temp = a;
        int s = 0;
        while(temp!=null)
        {   s++;
            temp = temp.next;
        }
        return s;
    }
    private ListNode solver(ListNode h1 , ListNode h2,int h1s,int h2s)
    {
            int del = h1s-h2s;
            while(del>0)
            {
                h1 = h1.next;
                del--;
            }
            while(h1!=null&&h2!=null)
            {
                if(h1==h2)
                    return h1;
                else{
                    h1 = h1.next;
                    h2 = h2.next;
            }
            }
            return null;
    }
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode h1 = headA;
        ListNode h2 = headB;
        int h1s = size(headA);
        int h2s = size(headB);
        if(h1s>h2s)
        {
          return solver(h1,h2,h1s,h2s);
        }
        else{
        return  solver(h2,h1,h2s,h1s);       
        }

    }
}