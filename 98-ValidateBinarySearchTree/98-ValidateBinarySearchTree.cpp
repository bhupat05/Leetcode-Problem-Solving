// Last updated: 7/30/2026, 8:21:00 AM
1class Solution {
2public:
3    bool solve(TreeNode* root, long long l, long long r) {
4        if (!root) return true;
5
6        if (root->val <= l || root->val >= r)
7            return false;
8
9        return solve(root->left, l, root->val) &&
10               solve(root->right, root->val, r);
11    }
12
13    bool isValidBST(TreeNode* root) {
14        return solve(root, LLONG_MIN, LLONG_MAX);
15    }
16};