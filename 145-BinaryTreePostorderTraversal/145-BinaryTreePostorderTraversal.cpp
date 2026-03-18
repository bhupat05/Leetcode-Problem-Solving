// Last updated: 3/18/2026, 2:29:54 PM
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>r;
        help(root,r);
        return r;
    }

    void help(TreeNode *root,vector<int>&r){
        if(root == nullptr) return;

      
        help(root->left,r);
        help(root->right,r);
        r.push_back(root->val);
    }
};