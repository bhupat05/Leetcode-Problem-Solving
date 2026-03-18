// Last updated: 3/18/2026, 2:24:27 PM
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
    int helper(TreeNode* node, int maxSofar) {
        if(node == NULL) return 0;

        int good = (node -> val >= maxSofar) ? 1 : 0;
        maxSofar = max(maxSofar, node -> val);

        return good + helper(node -> left, maxSofar) + helper(node -> right, maxSofar);
    }
    int goodNodes(TreeNode* root) {
        return helper(root, root -> val);
    }
};