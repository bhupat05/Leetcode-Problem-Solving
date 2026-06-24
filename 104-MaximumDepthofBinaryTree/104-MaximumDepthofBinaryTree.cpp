// Last updated: 6/24/2026, 9:43:22 AM
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
14    int maxDepth(TreeNode* root) {
15        if(!root) return 0;
16
17        queue<TreeNode*> q;
18        q.push(root);
19
20        int depth = 0;
21
22        while(!q.empty()) {
23            int sz = q.size();
24            depth++;
25
26            for(int i = 0; i < sz; i++) {
27                TreeNode* node = q.front();
28                q.pop();
29
30                if(node -> left) q.push(node -> left);
31                if(node -> right) q.push(node -> right);
32            }
33        }
34        return depth;
35    }
36};