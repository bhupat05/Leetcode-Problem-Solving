// Last updated: 3/18/2026, 2:30:37 PM
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left || !root->right)
            return 1 + (root->left ? minDepth(root->left) : minDepth(root->right));
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
