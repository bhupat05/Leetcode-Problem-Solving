// Last updated: 7/28/2026, 8:10:45 AM
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
13    ListNode* ms(ListNode* p, ListNode* q) {
14        if (!p) return q;
15        if (!q) return p;
16
17        if (p->val < q->val) {
18            p->next = ms(p->next, q);
19            return p;
20        } else {
21            q->next = ms(p, q->next);
22            return q;   
23        }
24    }
25
26    ListNode* mergeKLists(vector<ListNode*>& lists) {
27        int k = lists.size();
28        if (k == 0) return nullptr;
29
30        ListNode* result = lists[0];
31        for (int i = 1; i < k; i++) {
32            result = ms(result, lists[i]);
33        }
34
35        return result;
36    }
37};