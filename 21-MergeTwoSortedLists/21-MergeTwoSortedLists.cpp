// Last updated: 7/7/2026, 9:45:57 PM
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
14        if(!l1) return l2;
15        if(!l2) return l1;
16
17        if(l1 -> val < l2 -> val) {
18            l1 -> next = mergeTwoLists(l1 -> next, l2);
19            return l1;
20        } else {
21            l2 -> next = mergeTwoLists(l1, l2 -> next);
22            return l2;
23        }
24
25    }
26};