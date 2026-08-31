// Last updated: 8/31/2026, 2:34:08 PM
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
13    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
14        if(!head || !head -> next || !head -> next -> next) return {-1, -1};
15
16        int l = -1;
17        int r = -1;
18        int maxi = INT_MIN;
19        int mini = INT_MAX;
20        ListNode* temp = head -> next;
21        ListNode* prev = head;
22        int cnt = 1;
23        while(temp && temp -> next) {
24            cnt++;
25            if((temp -> val > prev -> val && temp -> val > temp -> next -> val) || (temp -> val < prev -> val && temp -> val < temp -> next -> val)) {
26                if(r != -1) {
27                    mini = min(mini, cnt - r);
28                }
29                if(l != -1) {
30                    maxi = max(maxi, cnt - l);
31                }
32                r = cnt;
33                if(l == -1) l = cnt;
34            }
35            prev = prev -> next;
36            temp = temp -> next;
37        }
38
39        if(maxi == INT_MIN || mini == INT_MAX) return {-1, -1};
40
41        return {mini, maxi};
42
43    }
44};