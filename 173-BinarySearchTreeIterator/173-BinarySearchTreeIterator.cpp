// Last updated: 3/30/2026, 4:24:32 PM
1class Solution {
2public:
3    int lh(TreeNode* root) {
4        if(!root) return 0;
5        return 1 + lh(root->left);
6    }
7
8    int rh(TreeNode* root) {
9        if(!root) return 0;
10        return 1 + rh(root->right);
11    }
12
13    int countNodes(TreeNode* root) {
14        if(!root) return 0;
15
16        int l = lh(root);
17        int r = rh(root);
18
19        if(l == r) return (1 << l) - 1;
20
21        return 1 + countNodes(root->left) + countNodes(root->right);
22    }
23};