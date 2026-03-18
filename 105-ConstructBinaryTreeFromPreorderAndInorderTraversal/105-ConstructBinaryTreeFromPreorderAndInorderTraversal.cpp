// Last updated: 3/18/2026, 2:30:43 PM
class Solution {
public:
    unordered_map<int, int> pos; 
    int preIdx = 0;

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    int start, int end) {

        if (start > end) return nullptr;

        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = pos[rootVal];

        root->left  = solve(preorder, inorder, start, mid - 1);
        root->right = solve(preorder, inorder, mid + 1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();

        for (int i = 0; i < n; i++) {
            pos[inorder[i]] = i;
        }

        return solve(preorder, inorder, 0, n - 1);
    }
};
