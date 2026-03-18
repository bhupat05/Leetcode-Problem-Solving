// Last updated: 3/18/2026, 2:28:45 PM
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
    int count = 0; // to track the number of nodes visited
    int ans = -1;  // to store the kth smallest value

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }

private:
    void inorder(TreeNode* root, int k) {
        if (!root || ans != -1) return; // stop if root null or answer found

        inorder(root->left, k); // visit left subtree

        count++;
        if (count == k) {
            ans = root->val; // found kth smallest
            return;
        }

        inorder(root->right, k); // visit right subtree
    }
};
