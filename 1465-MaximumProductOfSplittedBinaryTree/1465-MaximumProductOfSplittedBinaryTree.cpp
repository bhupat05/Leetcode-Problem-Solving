// Last updated: 3/18/2026, 2:24:44 PM
class Solution {
public:
    long long totalSum = 0;        
    long long bestProduct = 0;    
    const int MOD = 1e9 + 7;

    long long getTotalSum(TreeNode* root) {
        if (root == nullptr) return 0;
        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
    }

    long long dfs(TreeNode* root) {
        if (root == nullptr) return 0;

        long long leftSum = dfs(root->left);
        long long rightSum = dfs(root->right);

        long long subTreeSum = leftSum + rightSum + root->val;

        long long product = subTreeSum * (totalSum - subTreeSum);
        bestProduct = max(bestProduct, product);

        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {
        
        totalSum = getTotalSum(root);

        dfs(root);

        return bestProduct % MOD;
    }

    
};
