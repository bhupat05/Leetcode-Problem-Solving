// Last updated: 9/8/2026, 8:10:28 PM
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
13    ListNode* removeElements(ListNode* head, int val) {
14        while (head != nullptr && head->val == val) {
15            head = head->next;
16        }
17
18        ListNode* curr = head;
19        while (curr != nullptr && curr->next != nullptr) {
20            if (curr->next->val == val) {
21                curr->next = curr->next->next; 
22            } else {
23                curr = curr->next; 
24            }
25        }
26
27        return head;
28    }
29};