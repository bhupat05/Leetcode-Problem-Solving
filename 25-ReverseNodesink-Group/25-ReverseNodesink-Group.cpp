// Last updated: 7/7/2026, 10:36:25 PM
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
13    ListNode* reverseKGroup(ListNode* head, int k) {
14        if(!head || k == 1) return head;
15        int cnt = 0;
16        ListNode* temp = head;
17        while(cnt < k) {
18            if(!temp) return head;
19            temp = temp -> next;
20            cnt++;
21        }
22        
23        ListNode* prev = nullptr;
24        ListNode* curr = head;
25        cnt = 0;
26        while(cnt < k) {
27            ListNode* nxt = curr -> next;
28            curr -> next = prev;
29            prev = curr;
30            curr = nxt;
31            cnt++;
32        }
33        head -> next = reverseKGroup(temp, k);
34        return prev;
35        
36    }
37};