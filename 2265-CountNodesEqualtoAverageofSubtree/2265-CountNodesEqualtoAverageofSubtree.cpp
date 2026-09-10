// Last updated: 9/10/2026, 9:42:22 AM
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
15    int help(TreeNode* root) {
16        if(!root) return 0;
17        return 1 + help(root -> left) + help(root -> right);
18    }
19    int solve(TreeNode* root) {
20        if(!root) return 0;
21        if(!root -> left && ! root -> right) {
22            cnt++;
23            return root -> val;
24        }
25
26        int l = solve(root -> left);
27        int r = solve(root -> right);
28
29        int sum = l + r + root -> val;
30        int n = help(root);
31        cout << sum / n << " " << n << " " << root -> val << "\n";
32        if((sum / n) == root -> val) {
33            
34            cnt++;
35        } 
36        return sum;
37    }
38    int averageOfSubtree(TreeNode* root) {
39        solve(root);
40        return cnt;
41    }
42};