// Last updated: 3/30/2026, 9:53:04 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Solution {
11public:
12    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
13        if(!root) return NULL;
14
15        if(root == p || root == q) return root;
16
17        TreeNode* l = lowestCommonAncestor(root -> left, p, q);
18        TreeNode* r = lowestCommonAncestor(root -> right, p, q);
19
20        if(l && r) return root;
21        if(l) return l;
22        else return r;
23    }
24};