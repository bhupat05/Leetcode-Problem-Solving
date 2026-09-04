// Last updated: 9/4/2026, 11:36:58 AM
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
14    int help(vector<int>& nums, int l, int r) {
15        int idx = l;
16        for(int i = l; i <= r; i++) {
17            if(nums[i] > nums[idx]) {
18                idx = i;
19            }
20        }
21        return idx;
22    }
23    TreeNode* solve(vector<int>& nums, int l, int r) {
24        int n = nums.size();
25        if(l > r || l < 0 || r >= n) return nullptr;
26        
27        int idx = help(nums, l, r);
28        TreeNode* root = new TreeNode(nums[idx]);
29        root -> left =  solve(nums, l, idx - 1);
30        root -> right =  solve(nums, idx + 1, r);
31        return root;
32    }
33    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
34        int l = 0;
35        int r = nums.size() - 1;
36        return solve(nums, l, r);
37    }
38};