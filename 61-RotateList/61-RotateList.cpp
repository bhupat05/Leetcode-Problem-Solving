// Last updated: 5/5/2026, 3:07:33 PM
1class Solution {
2public:
3    ListNode* rotateRight(ListNode* head, int k) {
4        if (!head || !head->next || k == 0) return head;
5
6        int cnt = 1;
7        ListNode* tail = head;
8
9        while (tail->next) {
10            tail = tail->next;
11            cnt++;
12        }
13
14        k %= cnt;
15        if (k == 0) return head;
16
17        tail->next = head;
18
19        ListNode* temp = head;
20
21        for (int i = 1; i < cnt - k; i++) {
22            temp = temp->next;
23        }
24
25        ListNode* newHead = temp->next;
26        temp->next = NULL;
27
28        return newHead;
29    }
30};