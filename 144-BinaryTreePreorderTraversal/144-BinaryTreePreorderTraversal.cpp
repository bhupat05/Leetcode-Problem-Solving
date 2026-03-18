// Last updated: 3/18/2026, 2:29:55 PM
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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int>result;
        help(root,result);
        return result;

    }

    void help(TreeNode *root,vector<int>&result){
        if(root == nullptr) return;
        result.push_back(root->val);
        help(root->left,result);
        help(root->right,result);

        
    }
};