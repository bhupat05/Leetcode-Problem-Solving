// Last updated: 6/27/2026, 10:32:20 PM
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
14    vector<int> rightSideView(TreeNode* root) {
15        vector<int> r;
16        if(!root) return r;
17        queue<TreeNode*> q;
18        q.push(root);
19        // r.push_back(root);
20        while(!q.empty()) {
21            int sz = q.size();
22            for(int i = 0; i < sz; i++) {
23                TreeNode* nd = q.front();
24                q.pop();
25                if(i == sz - 1) r.push_back(nd -> val);
26
27                if(nd -> left) q.push(nd -> left);
28                if(nd -> right) q.push(nd -> right);
29            }
30            
31        }
32        return r;
33    }
34};