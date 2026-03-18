// Last updated: 3/18/2026, 2:27:31 PM
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
private:
    unordered_map<long long, int> mp;
    long long running_sum = 0;
    int ans = 0;
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        running_sum += root -> val;

        long long prefix_sum = running_sum - targetSum;
        ans += mp[prefix_sum];
        if(running_sum == targetSum) ans += 1;
        mp[running_sum]++;

        pathSum(root -> left, targetSum);
        pathSum(root -> right, targetSum);
        mp[running_sum]--;
        running_sum -= root -> val;

        return ans;
    }
};