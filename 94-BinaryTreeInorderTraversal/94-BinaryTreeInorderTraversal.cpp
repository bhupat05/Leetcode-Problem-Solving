// Last updated: 3/18/2026, 3:01:31 PM
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>result;

        help(root,result);
        return result;
    }
    void help(TreeNode* root,vector<int>&result){
        if(root == nullptr){
            return;
        }
        help(root->left,result);
        result.push_back(root->val);
        help(root->right,result);
   

    }
};