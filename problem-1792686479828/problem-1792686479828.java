// Last updated: 10/22/2026, 9:57:59 PM
1/**
2 * Definition for singly-linked list.
3 * public class ListNode {
4 *     int val;
5 *     ListNode next;
6 *     ListNode() {}
7 *     ListNode(int val) { this.val = val; }
8 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
9 * }
10 */
11
12class Solution {
13    public ListNode deleteDuplicates(ListNode head) {
14        ListNode res = head;
15
16        while (head != null && head.next != null) {
17            if (head.val == head.next.val) {
18                head.next = head.next.next;
19            } else {
20                head = head.next;
21            }
22        }
23
24        return res;
25    }
26}
27