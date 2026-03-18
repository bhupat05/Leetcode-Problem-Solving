// Last updated: 3/18/2026, 2:25:14 PM
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
        if(!root) return;

        inorder(root -> left, v);
        v.push_back(root -> val);
        inorder(root -> right, v);
    }

    TreeNode* solve(vector<int>& v, int l, int r) {
        if(l > r) return NULL;

        int mid = l + (r - l) / 2;

        TreeNode* node = new TreeNode(v[mid]);

        node -> left = solve(v, l, mid - 1);
        node -> right = solve(v, mid + 1, r);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return NULL;
        vector<int> v;
        inorder(root, v);

        return solve(v, 0, v.size() - 1);
    }
};