// Last updated: 3/18/2026, 2:27:24 PM
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node found
            if (root->left == NULL) return root->right;
            else if (root->right == NULL) return root->left;

            // Node with two children
            root->val = minValue(root->right);
            root->right = deleteNode(root->right, root->val);
        }
        return root;
    }

    static int minValue(TreeNode* root) {
        while (root->left != NULL) {
            root = root->left;
        }
        return root->val;
    }
};
