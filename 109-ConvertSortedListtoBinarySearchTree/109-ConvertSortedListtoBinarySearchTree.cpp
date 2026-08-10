// Last updated: 8/10/2026, 8:00:17 PM
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
11/**
12 * Definition for a binary tree node.
13 * struct TreeNode {
14 *     int val;
15 *     TreeNode *left;
16 *     TreeNode *right;
17 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
18 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
19 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
20 * };
21 */
22class Solution {
23public:
24    TreeNode* solve(vector<int> v, int l, int r) {
25        if(l > r) return nullptr;
26
27        int mid = l + (r - l) / 2;
28
29        TreeNode* root = new TreeNode(v[mid]);
30        root -> left = solve(v, l, mid - 1);
31        root -> right = solve(v, mid + 1, r);
32        return root;
33        
34    }
35    TreeNode* sortedListToBST(ListNode* head) {
36        vector<int> v;
37        ListNode* temp = head;
38        while(temp != nullptr) {
39            v.push_back(temp -> val);
40            temp = temp -> next;
41        }
42        return solve(v, 0, v.size() - 1);
43    }
44};