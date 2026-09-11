// Last updated: 9/11/2026, 11:12:48 PM
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
14    int widthOfBinaryTree(TreeNode* root) {
15        if(!root) return 0;
16        long long ans = 1;
17        queue<pair<TreeNode*, long long>> q;
18        q.push({root, 0});
19
20        while(!q.empty()) {
21            int sz = q.size();
22            long long base = q.front().second;
23            long long mn = INT_MAX;
24            long long mx = INT_MIN;
25            while(sz--) {
26                auto [node, idx] = q.front();
27                q.pop();
28                idx -= base;
29                mn = min(mn, idx);
30                mx = max(mx, idx);
31                if(node -> left) q.push({node -> left, idx * 2});
32                if(node -> right) q.push({node -> right, idx * 2 + 1});
33            }
34            ans = max(ans, mx - mn + 1);
35        }
36        return ans;
37    }
38};