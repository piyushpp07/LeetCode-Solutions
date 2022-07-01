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

    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode p = new ListNode();
        ListNode a = p;

        while (list1 != null && list2 != null) {
            if (list1.val > list2.val) {
                ListNode z = new ListNode(list2.val);
                list2 = list2.next;
                a.next = z;
                a = a.next;
            } else {
                ListNode z = new ListNode(list1.val);
                list1 = list1.next;
                a.next = z;
                a = a.next;
            }
        }
        while (list1 != null) {
            ListNode z = new ListNode(list1.val);
            list1 = list1.next;
            a.next = z;
            a = a.next;
        }
        while (list2 != null) {
            ListNode z = new ListNode(list2.val);
            list2 = list2.next;
            a.next = z;
            a = a.next;
        }
        return p.next;
    }
}
