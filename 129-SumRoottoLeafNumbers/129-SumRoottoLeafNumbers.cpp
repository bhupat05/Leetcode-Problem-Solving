// Last updated: 3/30/2026, 10:43:18 AM
1class Solution {
2public:
3    int solve(TreeNode* root, int sum) {
4        if(!root) return 0;
5
6        sum = sum * 10 + root->val;
7
8        if(!root->left && !root->right) return sum;
9
10        int l = solve(root->left, sum);
11        int r = solve(root->right, sum);
12
13        return l + r;
14    }
15
16    int sumNumbers(TreeNode* root) {
17        return solve(root, 0); 
18    }
19};