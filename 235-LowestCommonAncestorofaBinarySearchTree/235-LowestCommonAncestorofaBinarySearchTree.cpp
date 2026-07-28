// Last updated: 7/28/2026, 8:59:58 AM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10
11class Solution {
12public:
13    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
14        if(!root) return NULL;
15        if(root == p || root == q) return root;
16
17        TreeNode* l = lowestCommonAncestor(root -> left, p, q);
18        TreeNode* r = lowestCommonAncestor(root -> right, p, q);
19        if(l && r) return root;
20        
21        return l ? l : r;
22    }
23};