// Last updated: 3/31/2026, 1:59:13 AM
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
14    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
15        vector<vector<int>> r;
16        if(!root) return r;
17        queue<TreeNode*> q;
18        q.push(root);
19        int cnt = 0;
20
21        while(!q.empty()) {
22            int sz = q.size();
23
24            vector<int> ans;
25
26            for(int i = 0; i < sz; i++) {
27                TreeNode* nd = q.front();
28                q.pop();
29                ans.push_back(nd -> val);
30
31                if(nd -> left) q.push(nd -> left);
32                if(nd -> right) q.push(nd -> right);
33            }
34
35            if(cnt % 2 == 0) {
36                r.push_back(ans);
37            } else {
38                reverse(ans.begin(), ans.end());
39                r.push_back(ans);
40            }
41
42            cnt++;
43        }
44        return r;
45    }
46};