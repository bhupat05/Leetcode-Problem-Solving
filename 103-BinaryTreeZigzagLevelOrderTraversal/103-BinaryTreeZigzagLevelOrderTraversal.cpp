// Last updated: 3/18/2026, 2:30:48 PM
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> curr;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                curr.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (!leftToRight) {
                reverse(curr.begin(), curr.end());
            }

            result.push_back(curr);
            leftToRight = !leftToRight;
        }

        return result;
    }
};
