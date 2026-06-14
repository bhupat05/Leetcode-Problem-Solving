// Last updated: 6/14/2026, 11:48:51 AM
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
14
15    void help(TreeNode* root, vector<int>& v) {
16        if(!root) return;
17        if(!root -> left && ! root -> right) {
18            v.push_back(root -> val);
19        }
20        help(root -> left, v);
21        help(root -> right, v);
22    }
23
24    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
25        vector<int> v1;
26        vector<int> v2;
27        help(root1, v1);
28        help(root2, v2);
29
30        return v1 == v2;
31    }
32};