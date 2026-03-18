// Last updated: 3/18/2026, 2:30:21 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxsum;

    int help(TreeNode *root){
        if(root == NULL) return 0;

        int l = help(root->left);
        int r = help(root->right);

        int c1 = l+r+root->val;
        int c2 = max(l,r)+root->val;
        int c3 = root->val;
        maxsum = max({maxsum,c1,c2,c3});
        return max(c2,c3);
    }
    int maxPathSum(TreeNode* root) {
        maxsum=INT_MIN;
        help(root);
        return maxsum;
    }
};