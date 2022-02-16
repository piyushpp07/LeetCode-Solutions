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
    public ListNode sortList(ListNode head) {
       if(head==null||head.next==null)
           return head;
        ListNode mid = findMid(head);
        ListNode nHead = mid.next;
        mid.next = null;
        ListNode l1 = sortList(head);
        ListNode l2 = sortList(nHead);
        return merger(l1,l2);
    }

    public ListNode merger(ListNode list1, ListNode list2)
    {	ListNode mainNode = new ListNode();
		ListNode ahead = mainNode;
		while (list1 != null && list2 != null) {
			if (list1.val < list2.val) {
				ahead.next = list1;
				list1 = list1.next;
				ahead = ahead.next;
			} else {
				ahead.next = list2;
				list2 = list2.next;
				ahead = ahead.next;
			}
		}
		ahead.next = list1 != null ? list1 : list2;
		return mainNode.next;
     }
    public ListNode findMid(ListNode head)
    {

            ListNode f = head;
            ListNode s = head;
            while(f.next!=null&&f.next.next!=null)
            {
                f=f.next.next;
                s= s.next;
            }
            return s;            
        
    }
}