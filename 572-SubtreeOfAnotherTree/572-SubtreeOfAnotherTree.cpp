// Last updated: 3/18/2026, 2:27:06 PM
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
    bool isIdentical(TreeNode* p, TreeNode* q){
        if(p == NULL || q == NULL) {
            return p == q;
        }

        return p -> val == q -> val 
            && isIdentical(p -> left, q -> left) 
            && isIdentical(p -> right, q -> right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(root == NULL || subroot == NULL) {
            return root == subroot;
        }

        if(root ->val == subroot -> val && isIdentical(root, subroot)){
            return true;
        }
        return isSubtree(root -> left, subroot) || isSubtree(root -> right, subroot);
    }
};