// Last updated: 3/31/2026, 1:33:37 AM
1class Solution {
2public:
3    vector<int> rightSideView(TreeNode* root) {
4        vector<int> r;
5        if (!root) return r;
6
7        queue<TreeNode*> q;
8        q.push(root);
9
10        while (!q.empty()) {
11            int sz = q.size();
12
13            for (int i = 0; i < sz; i++) {
14                TreeNode* nd = q.front();
15                q.pop();
16                
17                if (i == sz - 1) {
18                    r.push_back(nd->val);
19                }
20
21                if (nd->left) q.push(nd->left);
22                if (nd->right) q.push(nd->right);
23            }
24        }
25        return r;
26    }
27};