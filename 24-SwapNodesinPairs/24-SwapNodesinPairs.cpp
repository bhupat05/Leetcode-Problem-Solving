// Last updated: 7/7/2026, 10:11:59 PM
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
13    ListNode* swapPairs(ListNode* head) {
14        if(!head || !head -> next) return head;
15
16        ListNode* nxt = head -> next;
17        ListNode* temp = nxt -> next;
18        nxt -> next = head;
19        head -> next = temp;
20
21        head -> next = swapPairs(head -> next);
22        return nxt;
23
24
25    }
26};