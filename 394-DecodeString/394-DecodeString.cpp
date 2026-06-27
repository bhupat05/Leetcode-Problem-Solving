// Last updated: 6/27/2026, 10:12:09 PM
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
14    void help(TreeNode* root, int level, vector<int>& r) {
15        if(!root) return;
16        if(r.size() < level) {
17            r.push_back(root -> val);
18        }
19        help(root -> right, level + 1, r);
20        help(root -> left, level + 1, r);
21    }
22    vector<int> rightSideView(TreeNode* root) {
23        vector<int> r;
24        help(root, 1, r);
25        return r;
26    }
27};