// Last updated: 6/22/2026, 11:03:29 AM
1class Solution {
2public:
3    ListNode* deleteMiddle(ListNode* head) {
4        if (head == nullptr || head->next == nullptr)
5            return nullptr;
6
7        int n = 0;
8        ListNode* temp = head;
9
10        while (temp) {
11            n++;
12            temp = temp->next;
13        }
14
15        int mid = n / 2;
16
17        temp = head;
18        for (int i = 1; i < mid; i++) {
19            temp = temp->next;
20        }
21
22        temp->next = temp->next->next;
23
24        return head;
25    }
26};