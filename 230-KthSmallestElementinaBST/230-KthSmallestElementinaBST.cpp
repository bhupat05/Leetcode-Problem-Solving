// Last updated: 8/5/2026, 7:30:48 AM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    int ans = 0;
15    void solve(TreeNode* root, int k, int &cnt) {
16        if(!root) return;
17        solve(root -> left, k, cnt);
18        cnt++;
19        if(cnt == k) {
20            ans = root -> val;
21            return;
22        }
23        solve(root -> right, k, cnt);
24        
25    }
26    int kthSmallest(TreeNode* root, int k) {
27        int cnt = 0;
28        solve(root, k, cnt);
29        return ans;
30    }
31};