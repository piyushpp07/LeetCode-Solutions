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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode s = head;
        ListNode f = head;
        ListNode ans = s;
        while(f!=null)
        {
            if(f.val == s.val)
            {
                s.next = f.next;
                f = f.next;
            }
            else{
                s = f;
            }
        }
        return ans;
    }
}