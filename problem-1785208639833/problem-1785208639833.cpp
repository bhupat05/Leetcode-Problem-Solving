// Last updated: 7/28/2026, 8:47:19 AM
1class Solution {
2public:
3    bool solve(TreeNode* p, TreeNode* q) {
4        if (!p && !q) return true;
5        if (!p || !q) return false;
6
7        return (p->val == q->val) &&
8               solve(p->left, q->left) &&
9               solve(p->right, q->right);
10    }
11
12    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
13        if (!subRoot) return true;
14        if (!root) return false;
15
16        if (root->val == subRoot->val && solve(root, subRoot))
17            return true;
18
19        return isSubtree(root->left, subRoot) ||
20               isSubtree(root->right, subRoot);
21    }
22};