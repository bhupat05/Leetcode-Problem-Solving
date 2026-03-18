// Last updated: 3/18/2026, 2:22:51 PM
class Solution {
public:
    int result = 0;

    int help(TreeNode* root, int &count) {
        if (!root) {
            count = 0;
            return 0;
        }

        int leftCount = 0, rightCount = 0;
        int leftSum = help(root->left, leftCount);
        int rightSum = help(root->right, rightCount);

        count = leftCount + rightCount + 1;
        int sum = leftSum + rightSum + root->val;

        if (root->val == sum / count)
            result++;

        return sum;
    }

    int averageOfSubtree(TreeNode* root) {
        result = 0;
        int count = 0;
        help(root, count);
        return result;
    }
};
