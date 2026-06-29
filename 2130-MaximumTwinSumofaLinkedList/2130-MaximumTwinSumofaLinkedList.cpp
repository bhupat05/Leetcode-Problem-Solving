// Last updated: 6/29/2026, 11:44:58 AM
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
13    int pairSum(ListNode* head) {
14        vector<int> v;
15        ListNode* temp = head;
16        while(temp) {
17            v.push_back(temp -> val);
18            temp = temp -> next;
19        }
20
21        int maxi = 0;
22        int n = v.size();
23        for(int i = 0; i < n / 2; i++) {
24            int curr = v[i] + v[n - i - 1];
25            maxi = max(maxi, curr);
26        }
27        return maxi;
28    }
29};