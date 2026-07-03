// Last updated: 7/3/2026, 8:51:09 AM
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
13    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
14        ListNode* head = nullptr;
15        ListNode* temp = nullptr;
16        int carry = 0;
17        while(l1 || l2 || carry) {
18
19            int sum = (l1 ? l1 -> val : 0) + (l2 ? l2 -> val : 0) + carry;
20            int x = sum <= 9 ? sum : sum % 10;
21            ListNode* node = new ListNode(x);
22            carry = sum > 9 ? sum / 10 : 0;
23
24            l1 = l1 ? l1 -> next : nullptr;
25            l2 = l2 ? l2 -> next : nullptr;
26            if(temp == nullptr) {
27                head = node;
28                temp = node;
29            } else {
30                head->next = node;
31                head = node;
32            }
33            
34        }
35        return temp;
36    }
37};