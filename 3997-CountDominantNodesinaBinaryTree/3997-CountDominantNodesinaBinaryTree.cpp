// Last updated: 8/12/2026, 10:43:04 AM
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
14    int cnt = 0;
15    int solve(TreeNode* root) {
16        if(!root) return 0;
17        
18        if(!root -> left && !root -> right) {
19            cnt++;
20            return root -> val;
21           
22        }
23        
24
25        int l = solve(root -> left);
26        int r = solve(root -> right);
27
28        if(root -> val >= l && root -> val >= r) {
29            cnt++;
30            return root -> val;
31        } else {
32            return max(l, r);
33        }
34        
35        
36    }
37    int countDominantNodes(TreeNode* root) {
38        solve(root);
39        return cnt;
40    }
41};