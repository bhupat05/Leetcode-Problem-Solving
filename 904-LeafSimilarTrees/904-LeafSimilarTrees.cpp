// Last updated: 3/18/2026, 2:26:01 PM
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
    void inorder(TreeNode* root, vector<int>& v) {
        if(root == NULL) return;

        if(root -> left == NULL && root -> right == NULL) {
            v.push_back(root -> val);
            return;
        }
        inorder(root -> left, v);
        inorder(root -> right, v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;

        inorder(root1, v1);
        inorder(root2, v2);

        return v1 == v2;
    }
};