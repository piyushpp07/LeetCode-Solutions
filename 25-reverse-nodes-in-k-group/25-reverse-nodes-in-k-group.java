/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public static ListNode th = null;
    public static ListNode tt = null;
    public int findSize(ListNode node)
    {
        ListNode temp = node;
        int i = 0;
        while(temp!=null)
        {
            temp = temp.next;
            i++;
        }
        return i;
    }
    public void addFirst(ListNode node)
    {
        if(th==null){
            th = node;
            tt = node;
        }
        else{
            node.next = th;
            th = node;
            }
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        int n = findSize(head);
        ListNode oh = null;
        ListNode ot = null;
        ListNode curr = head;
        while(n>=k)
        {
           for(int i =0 ;i<k ;i++)
           {
               ListNode forw = curr.next;
               curr.next = null;
               addFirst(curr);
               curr = forw;
           }
            if(oh == null)
            {
                oh = th;
                ot = tt;
            }
            else{
                ot.next = th;
                ot = tt;
            }
            th = null;
            tt = null;
            n = n-k;
        }
        ot.next = curr;
        return oh;
    }
}