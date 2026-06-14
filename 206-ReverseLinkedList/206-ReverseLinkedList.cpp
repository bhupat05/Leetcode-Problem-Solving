// Last updated: 6/14/2026, 12:02:28 PM
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
14    int help(TreeNode* root, int mx) {
15        if(!root) return 0;
16        if(root -> val < mx) return help(root->left, mx) + help(root->right, mx);
17        
18        mx = root -> val;
19        return 1 + help(root -> left, mx) + help(root -> right, mx);
20        
21    }
22    int goodNodes(TreeNode* root) {
23        
24        return help(root, root -> val);
25    }
26};