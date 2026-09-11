// Last updated: 9/11/2026, 11:25:47 AM
1class Solution {
2public:
3    void reorderList(ListNode* head) {
4        if (!head || !head->next) return;
5
6        ListNode* slow = head;
7        ListNode* fast = head;
8
9        while (fast->next && fast->next->next) {
10            slow = slow->next;
11            fast = fast->next->next;
12        }
13
14        ListNode* curr = slow->next;
15        slow->next = nullptr;
16
17        ListNode* prev = nullptr;
18
19        while (curr) {
20            ListNode* next = curr->next;
21            curr->next = prev;
22            prev = curr;
23            curr = next;
24        }
25
26        ListNode* first = head;
27        ListNode* second = prev;
28
29        while (second) {
30            ListNode* nextFirst = first->next;
31            ListNode* nextSecond = second->next;
32
33            first->next = second;
34            second->next = nextFirst;
35
36            first = nextFirst;
37            second = nextSecond;
38        }
39    }
40};